

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
struct Lsymbol * ln;
struct Paramstruct * pn;
int i;
}

%type <ln> LID LdeclBlock LDecList LDecl IdList
%type <i> NUP Type
%type <pn> ParamList Param PM
%type <gn> GDeclBlock GDeclList GDecl GidList GID ID
%type <tn> expr Body NUM STRING END AsgStmt OutputStmt InputStmt VAR Stmt Slist E IfStmt WhileStmt BreakStmt ContinueStmt
ArgList ReturnStmt
%token NUM PLUS END MINUS DIV MUL ID BEGN READ WRITE EQUAL SEMCL LP RP IF THEN ENDIF BREAK CONTINUE COMMA DECL ENDDECL INT STR
ELSE WHILE DO ENDWHILE LT GT NOT VAR NUP LID LSB RSB STRING MAIN LCB RCB PM RETURN
%right EQUAL
%left PLUS MINUS
%left MUL DIV


%%

Program : GDeclBlock FdefBlock MainBlock {printf(" y1 ");}
      | GDeclBlock MainBlock  {printf(" y2 ");}
      | MainBlock {printf(" y3 ");}
      ;
GDeclBlock : DECL GDeclList ENDDECL {printsymbols($2);printf(" y4 ");$$=$2;}
      | DECL ENDDECL  {printf(" y5 ");}
      ;
GDeclList : GDeclList GDecl {printf(" y6 ");$$=$2;}
      | GDecl {printf(" y7 ");$$=$1;}
      ;
GDecl : Type GidList SEMCL {printf(" y8 ");updatetype($2,$1);$$=$2;}
      ;
GidList : GidList COMMA GID {printf(" y9 ");$$=$3;}
      | GID {printf(" y10 ");$$=$1;}
      ;
GID : ID LP ParamList RP {printf(" y11 ");$1->paramlist=$3;$$=$1;}
      | ID LSB NUP RSB {printf(" y12 ");sizeupdate($1,$3);$$=$1;}
      | ID {printf(" y13 ");$$=$1;}
      ;
FdefBlock : FdefBlock Fdef {printf(" y14 ");}
      | Fdef {printf(" y15 ");}
      ;
MainBlock : Type MAIN LP RP LCB LdeclBlock Body RCB {printf(" y16 ");int l=0;
                                  fprintf(outputfile,"L%d:\n",l);
                                  ml=1;
                                  strcpy(currentfname,"main");
                                  generate($7);
                                  fprintf(outputfile,"L%d:\n",ml);
                                  lpop();
                                  fprintf(outputfile,"RET\n");
                                  l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);}
      ;
Fdef : Type ID LP ParamList RP LCB LdeclBlock Body RCB {printf(" y17 ");int l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);
                                  $2->binding=l;
                                  l=getlabel();
                                  strcpy(currentfname,$2->name);
                                  generate($8);
                                  fprintf(outputfile,"L%d:\n",l);
                                  lpop();
                                  fprintf(outputfile,"RET\n");
                                  l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);
                                  resetreg();}
      ;
ParamList : ParamList COMMA Param {printf(" y18 ");$$=$3;}
      | Param {printf(" y19 ");$$=$1;}
      ;
Param : Type PM {printf(" y20 ");$$=$2;}
      ;
Type : INT {printf(" y21 ");$$=1;}
      | STR {printf(" y22 ");$$=2;}
      ;
LdeclBlock : DECL LDecList ENDDECL {printf(" y23 ");printlsymbols(lhead);$$=$2;}
      | DECL ENDDECL {printf(" y24 ");$$=NULL;}
      ;
LDecList : LDecList LDecl {printf(" y25 ");$$=$2;}
      | LDecl {printf(" y26 ");$$=$1;}
      ;
LDecl : Type IdList SEMCL {printf(" y27 ");updateltype($2,$1);$$=$2;}
      ;
IdList : IdList COMMA LID  {printf(" y28 ");$$=$3;}
      | LID {printf(" y29 ");$$=$1;}
      ;
ArgList : ArgList COMMA expr {printf(" y30 ");$1->Arglist=$3;$$=$1;}
      | expr {printf(" y31 ");$$=$1;}
      ;
Body : BEGN Slist END {printf(" y32 ");generate_flag=0;$$=$2;}
      | BEGN END  {printf(" y33 ");$$=NULL;}
      ;
Slist : Slist Stmt {printf(" y34 ");$$=connector($1,$2);}
      | Stmt {printf(" y35 ");$$=$1;}
      ;
Stmt : InputStmt {printf(" y36 ");$$=$1;}
      | OutputStmt {printf(" y37 ");$$=$1;}
      | AsgStmt {printf(" y38 ");$$=$1;}
      | IfStmt {printf(" y39 ");$$=$1;}
      | WhileStmt {printf(" y40 ");$$=$1;}
      | BreakStmt {printf(" y41 ");$$=$1;}
      | ContinueStmt {printf(" y42 ");$$=$1;}
      | ReturnStmt {printf(" yr ");$$=$1;}
      ;
InputStmt : READ LP expr RP SEMCL {printf(" y43 ");$$=Inode($3);}
      ;
OutputStmt : WRITE LP expr RP SEMCL {printf(" y44 ");$$=Onode($3);}
      ;
AsgStmt : expr EQUAL expr SEMCL {printf(" y45 ");$$=opnode('=',$1,$3);}
      ;
IfStmt : IF LP E RP THEN Slist ELSE Slist ENDIF SEMCL {printf(" y46 ");struct tnode *t;
        t=connector($6,$8);$$=ifelsenode($3,t);}
      | IF LP E RP THEN Slist ENDIF SEMCL {printf(" y47 ");$$=ifnode($3,$6);}
      ;
WhileStmt : WHILE LP E RP DO Slist ENDWHILE SEMCL {printf(" y48 ");$$=whilenode($3,$6);}
      ;
BreakStmt : BREAK SEMCL {printf(" y49 ");$$=breaknode();}
      ;
ContinueStmt : CONTINUE SEMCL {printf(" y50 ");$$=continuenode();}
      ;
ReturnStmt : RETURN expr SEMCL {$$=retnode($2);}
      | RETURN SEMCL {$$=retnode(NULL);}
      ;
E : expr LT expr {printf(" y51 ");$$=relnode("<",$1,$3);}
      | expr GT expr {printf(" y52 ");$$=relnode(">",$1,$3);}
      | expr LT EQUAL expr {printf(" y53 ");$$=relnode("<=",$1,$4);}
      | expr GT EQUAL expr {printf(" y54 ");$$=relnode(">=",$1,$4);}
      | expr NOT EQUAL expr {printf(" y55 ");$$=relnode("!=",$1,$4);}
      | expr EQUAL EQUAL expr {printf(" y56 ");$$=relnode("==",$1,$4);}
      ;
expr : expr PLUS expr   {printf(" y57 ");$$=opnode('+',$1,$3);}
      | expr MUL expr   {printf(" y58 ");$$=opnode('*',$1,$3);}
      | expr MINUS expr {printf(" y59 ");$$=opnode('-',$1,$3);}
      | expr DIV expr   {printf(" y60 ");$$=opnode('/',$1,$3);}
      | LP expr RP   {printf(" y61 ");$$=$2;}
      | NUM            {printf(" y62 ");$$=$1;}
      | STRING        {printf(" y63 ");$$=$1;}
      | VAR           {printf(" y64 ");$$=$1;}
      | VAR LP RP {printf(" y65 ");$$=$1;}
      | VAR LP ArgList RP {printf(" y66 ");$1->Arglist=$3;$$=$1;}
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
  Reg->label=1;
  fprintf(outputfile,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nMOV SP,4095\nMOV BP,4096\nPUSH R0\nCALL L0\nINT 10\n",0,2056,0,0,0,0,0,0);
  inp();
  yyparse();
  return 0;
}
