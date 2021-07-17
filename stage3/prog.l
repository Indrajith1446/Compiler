

%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
#include "prog.h"

int no;
%}

%%
[0-9]+ {printf("l0 ");no=atoi(yytext);yylval.tn=intnode(no);return NUM;}
[a-z] {printf("l1%c ",*yytext);yylval.tn=varnode(*yytext);return ID;}
"=" {printf("l2 ");return EQUAL;}
";" {printf("l3 ");return SEMCL;}
"+" {printf("l4 ");return PLUS;}
"-" {printf("l5 ");return MINUS;}
"/" {printf("l6 ");return DIV;}
"*" {printf("l7 ");return MUL;}
"begin" {printf("l8 ");return BEGN;}
"end" {printf("l9 ");return END;}
"read" {printf("l10 ");return READ;}
"write" {printf("l11 ");return WRITE;}
"if" {printf("l12 ");return IF;}
"then" {printf("l13 ");return THEN;}
"else" {printf("l14 ");return ELSE;}
"endif" {printf("l15 ");return ENDIF;}
"while" {printf("l16 ");return WHILE;}
"do" {printf("l17 ");return DO;}
"endwhile" {printf("l18 ");return ENDWHILE;}
"(" {printf("l19 ");return LP;}
")" {printf("l20 ");return RP;}
"<" {printf("l21 ");return LT;}
">" {printf("l22 ");return GT;}
"!" {printf("l23 ");return NOT;}
[\t] {printf("l24 ");}
[\n] {printf("l25 ");}
" " {}
[.] {printf("le ");exit(1);}

%%

int yywrap()
{
  return 1;
}
int inp()
{
  yyin=fopen("input.sil","r");
}
