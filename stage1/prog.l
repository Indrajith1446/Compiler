

%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
#include "exprtree.h"

int no;
%}

%%

[0-9]+ {no=atoi(yytext);yylval.tn=leafnode(no);return NUM;}
"+" {return PLUS;}
[()] {return *yytext;}
[\t] {}
[\n] {return END;}
[.] {exit(1);}

%%

int yywrap()
{
  return 1;
}
