

%{
#include<stdio.h>
#include<stdlib.h>
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
%type <tn> expr program NUM END AsgStmt OutputStmt InputStmt Stmt Slist ID
%token NUM PLUS END MINUS DIV MUL ID BEGN READ WRITE EQUAL SEMCL LP RP
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
      ;
InputStmt : READ LP expr RP SEMCL {printf("8\n");$$=Inode($3);}
      ;
OutputStmt : WRITE LP expr RP SEMCL {printf("9\n");$$=Onode($3);}
      ;
AsgStmt : expr EQUAL expr SEMCL {printf("10\n");$$=opnode('=',$1,$3);}
      ;
expr : expr PLUS expr   {printf("11\n");$$=opnode('+',$1,$3);}
      | expr MUL expr   {printf("12\n");$$=opnode('*',$1,$3);}
      | expr MINUS expr {printf("13\n");$$=opnode('-',$1,$3);}
      | expr DIV expr   {printf("14\n");$$=opnode('/',$1,$3);}
      | LP expr RP   {printf("15\n");$$=$2;}
      | NUM            {printf("16\n");$$=$1;}
      | ID             {printf("17\n");$$=$1;}
      ;

%%

int yyerror(char const *s)
{
  printf("yyerror %s",s);
}
int main()
{
  outputfile=fopen("output.xsm","w");
  Reg=(struct regpool *)malloc(sizeof(struct regpool));
  Reg->reg=-1;
  fprintf(outputfile,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
  inp();
  yyparse();
  return 0;
}
