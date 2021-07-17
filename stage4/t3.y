

%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "t3.h"
#include "t3.c"
int yylex();
int yywrap();
struct regpool * Reg;
FILE *outputfile;
int printval;
int loopflag[3];
int yyerror(char const *s);

%}

%union{
struct tnode * tn;
struct Gsymbol * gn;
int i;
}

%type <i> NUP
%type <gn> ID DeclList Decl VarList Declerations
%type <tn> expr program NUM STRING END AsgStmt OutputStmt InputStmt VAR Stmt Slist E IfStmt WhileStmt BreakStmt ContinueStmt 
%token NUM PLUS END MINUS DIV MUL ID BEGN READ WRITE EQUAL SEMCL LP RP IF THEN ENDIF BREAK CONTINUE COMMA DECL ENDDECL INT STR STRING
ELSE WHILE DO ENDWHILE LT GT NOT VAR NUP LSB RSB
%right EQUAL
%left PLUS MINUS
%left MUL DIV


%%

start : Declerations program {printf(" y1 ");printsymbols(Symbolhead);}
      ;
program : BEGN Slist END SEMCL {printf(" y2 ");generate($2);$$=$2;}
      | BEGN END SEMCL  {printf(" y3 ");}
      ;
Declerations : DECL DeclList ENDDECL {printf(" y4 ");$$=$2;}
      | DECL ENDDECL  {printf(" y5 ");}
      ;
DeclList : DeclList Decl {printf(" y6 ");$$=$2;}
      | Decl {printf(" y7 ");$$=$1;}
      ;
Decl : Type VarList SEMCL {printf(" y8 ");$$=$2;}
      ;
Type : INT {printf(" y9 ");}
      | STR {printf(" y10 ");}
      ;
VarList : VarList COMMA ID {printf(" y11 ");$$=$3;}
      | VarList COMMA ID LSB NUP RSB {printf(" y12 ");sizeupdate($3,$5);$$=$3;}
      | ID LSB NUP RSB {printf(" y13 ");sizeupdate($1,$3);$$=$1;}
      | ID {printf(" y14 ");$$=$1;}
      ;
Slist : Slist Stmt {printf(" y15 ");$$=connector($1,$2);}
      | Stmt {printf(" y16 ");$$=$1;}
      ;
Stmt : InputStmt {printf(" y17 ");$$=$1;}
      | OutputStmt {printf(" y18 ");$$=$1;}
      | AsgStmt {printf(" y19 ");$$=$1;}
      | IfStmt {printf(" y20 ");$$=$1;}
      | WhileStmt {printf(" y21 ");$$=$1;}
      | BreakStmt {printf(" y22 ");$$=$1;}
      | ContinueStmt {printf(" y23 ");$$=$1;}
      ;
InputStmt : READ LP expr RP SEMCL {printf(" y24 ");$$=Inode($3);}
      ;
OutputStmt : WRITE LP expr RP SEMCL {printf(" y25 ");$$=Onode($3);}
      ;
AsgStmt : expr EQUAL expr SEMCL {printf(" y26 ");$$=opnode('=',$1,$3);}
      ;
IfStmt : IF LP E RP THEN Slist ELSE Slist ENDIF SEMCL {printf(" y27 ");struct tnode *t;
        t=connector($6,$8);$$=ifelsenode($3,t);}
      | IF LP E RP THEN Slist ENDIF SEMCL {printf(" y28 ");$$=ifnode($3,$6);}
      ;
WhileStmt : WHILE LP E RP DO Slist ENDWHILE SEMCL {printf(" y29 ");$$=whilenode($3,$6);}
      ;
BreakStmt : BREAK SEMCL {printf(" y30 ");$$=breaknode();}
      ;
ContinueStmt : CONTINUE SEMCL {printf(" y31 ");$$=continuenode();}
      ;
E : expr LT expr {printf(" y32 ");$$=relnode("<",$1,$3);}
      | expr GT expr {printf(" y33 ");$$=relnode(">",$1,$3);}
      | expr LT EQUAL expr {printf(" y34 ");$$=relnode("<=",$1,$4);}
      | expr GT EQUAL expr {printf(" y35 ");$$=relnode(">=",$1,$4);}
      | expr NOT EQUAL expr {printf(" y36 ");$$=relnode("!=",$1,$4);}
      | expr EQUAL EQUAL expr {printf(" y37 ");$$=relnode("==",$1,$4);}
      ;
expr : expr PLUS expr   {printf(" y38 ");$$=opnode('+',$1,$3);}
      | expr MUL expr   {printf(" y39 ");$$=opnode('*',$1,$3);}
      | expr MINUS expr {printf(" y40 ");$$=opnode('-',$1,$3);}
      | expr DIV expr   {printf(" y41 ");$$=opnode('/',$1,$3);}
      | LP expr RP   {printf(" y42 ");$$=$2;}
      | NUM            {printf(" y43 ");$$=$1;}
      | STRING         {$$=$1;}
      | VAR           {printf(" y44 ");$$=$1;}
      ;

%%

int yyerror(char const *s)
{
  printf("yyerror %s",s);
}
int main()
{
  loopflag[0]=0;
  outputfile=fopen("input.xsm","w");
  Reg=(struct regpool *)malloc(sizeof(struct regpool));
  Reg->reg=-1;
  Reg->label=-1;
  fprintf(outputfile,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
  inp();
  yyparse();
  return 0;
}
