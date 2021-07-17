

%{
#include<stdio.h>
#include<stdlib.h>
#include "exprtree.h"
#include "exprtree.c"
int yylex();
struct regpool * Reg;
FILE *outputfile;
%}

%union{
struct tnode * tn;
}
%type <tn> expr start NUM END
%token NUM PLUS END
%left PLUS

%%
start : expr END {$$=$2;
                  generate($1);
                  exit(1);}
                  ;
expr : expr PLUS expr   {$$=opnode('+',$1,$3);}
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
