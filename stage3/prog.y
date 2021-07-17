

%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "prog.h"
#include "prog.c"
int yylex();
int yywrap();
struct regpool * Reg;
FILE *outputfile;
int printval;

%}

%union{
struct tnode * tn;
}
%type <tn> expr program NUM END AsgStmt OutputStmt InputStmt Stmt Slist ID E IfStmt WhileStmt
%token NUM PLUS END MINUS DIV MUL ID BEGN READ WRITE EQUAL SEMCL LP RP IF THEN ENDIF
ELSE WHILE DO ENDWHILE LT GT NOT
%right EQUAL
%left PLUS MINUS
%left MUL DIV


%%

program : BEGN Slist END SEMCL {printf("1\n");generate($2);yywrap();}
      | BEGN END SEMCL  {printf("2\n");yywrap();}
      ;
Slist : Slist Stmt {printf("3\n");$$=connector($1,$2);}
      | Stmt {printf("4\n");$$=$1;}
      ;
Stmt : InputStmt {printf("5\n");$$=$1;}
      | OutputStmt {printf("6\n");$$=$1;}
      | AsgStmt {printf("7\n");$$=$1;}
      | IfStmt {printf("8\n");$$=$1;}
      | WhileStmt {printf("9\n");$$=$1;}
      ;
InputStmt : READ LP expr RP SEMCL {printf("10\n");$$=Inode($3);}
      ;
OutputStmt : WRITE LP expr RP SEMCL {printf("11\n");$$=Onode($3);}
      ;
AsgStmt : expr EQUAL expr SEMCL {printf("12\n");$$=opnode('=',$1,$3);}
      ;
IfStmt : IF LP E RP THEN Slist ELSE Slist ENDIF SEMCL {printf("13\n");struct tnode *t;
        t=connector($6,$8);$$=ifelsenode($3,t);}
      | IF LP E RP THEN Slist ENDIF SEMCL {printf("14\n");$$=ifnode($3,$6);}
      ;
WhileStmt : WHILE LP E RP DO Slist ENDWHILE SEMCL {printf("15\n");$$=whilenode($3,$6);}
      ;
E : expr LT expr {printf("16\n");$$=relnode("<",$1,$3);}
      | expr GT expr {printf("17\n");$$=relnode(">",$1,$3);}
      | expr LT EQUAL expr {printf("18\n");$$=relnode("<=",$1,$4);}
      | expr GT EQUAL expr {printf("19\n");$$=relnode(">=",$1,$4);}
      | expr NOT EQUAL expr {printf("20\n");$$=relnode("!=",$1,$4);}
      | expr EQUAL EQUAL expr {printf("21\n");$$=relnode("==",$1,$4);}
      ;
expr : expr PLUS expr   {printf("22\n");$$=opnode('+',$1,$3);}
      | expr MUL expr   {printf("23\n");$$=opnode('*',$1,$3);}
      | expr MINUS expr {printf("24\n");$$=opnode('-',$1,$3);}
      | expr DIV expr   {printf("25\n");$$=opnode('/',$1,$3);}
      | LP expr RP   {printf("26\n");$$=$2;}
      | NUM            {printf("27\n");$$=$1;}
      | ID             {printf("28\n");$$=$1;}
      ;

%%

int yyerror(char const *s)
{
  printf("yyerror %s",s);
}
int main()
{
  outputfile=fopen("input.xsm","w");
  Reg=(struct regpool *)malloc(sizeof(struct regpool));
  Reg->reg=-1;
  Reg->label=-1;
  fprintf(outputfile,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
  inp();
  yyparse();
  return 0;
}
