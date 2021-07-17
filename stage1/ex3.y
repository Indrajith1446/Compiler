

%{
#include<stdio.h>
#include<stdlib.h>
#include "ex3.h"
#include "ex3.c"
int yylex();
struct regpool * Reg;
FILE *outputfile;
int printval;
%}

%union{
struct tnode * tn;
char ch;
}
%type <tn> expr start NUM END
%type <ch> oper
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
expr : oper expr expr   {printf("1");$$=opnode($1,$2,$3);}
      | '(' expr ')'   {printf("2");$$=$2;}
      | NUM            {printf("3");$$=$1;}
      ;
oper : PLUS {printf("4");$$='+';}
      | MINUS {printf("5");$$='-';}
      | DIV {printf("6");$$='/';}
      | MUL {printf("7");$$='*';}
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
