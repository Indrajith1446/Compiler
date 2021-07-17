

%{
#include<stdio.h>
#include<stdlib.h>
#include "ex2.h"
#include "ex2.c"
int yylex();
struct regpool * Reg;
FILE *outputfile;
int printval;
%}

%union{
struct tnode * tn;
}
%type <tn> expr start NUM END
%token NUM PLUS END MINUS DIV MUL
%left PLUS MINUS
%left MUL DIV

%%
start : expr END {$$=$2;
                  printval=generate($1);
                  printf("test");
                  p_val(printval);
                  exit(1);}
                  ;
expr : expr PLUS expr   {$$=opnode('+',$1,$3);}
      | expr MUL expr   {$$=opnode('*',$1,$3);}
      | expr MINUS expr {$$=opnode('-',$1,$3);}
      | expr DIV expr   {$$=opnode('/',$1,$3);}
      | '(' expr ')'   {$$=$2;}
      | NUM            {$$=$1;}
      ;
%%

yyerror(char const *s)
{
  printf("yyerror %s",s);
}
int main()
{
  outputfile=fopen("output.xsm","w");
  Reg=(struct regpool *)malloc(sizeof(struct regpool));
  Reg->reg=-1;
  fprintf(outputfile,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
  yyparse();
  return 0;
}
