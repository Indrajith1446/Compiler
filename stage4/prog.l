

%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "y.tab.h"
#include "prog.h"

int declflag=0;
int no;
int vtype=0;

%}

%%
[0-9]+ {no=atoi(yytext);yylval.tn=intnode(no);return NUM;}
"=" {return EQUAL;}
";" {vtype=0;return SEMCL;}
"+" {return PLUS;}
"-" {return MINUS;}
"/" {return DIV;}
"*" {return MUL;}
"begin" {return BEGN;}
"end" {return END;}
"read" {return READ;}
"write" {return WRITE;}
"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}
"break" {return BREAK;}
"continue" {return CONTINUE;}
"decl" {declflag=1;bindval=4096;return DECL;}
"enddecl" {declflag=0;return ENDDECL;}
"int" {vtype=1;return INT;}
"str" {vtype=2;return STR;}
[a-z|A-Z]+ {if(declflag==0)
        {
          yylval.tn=varnode(yytext);
          return VAR;
        }
        else
        {
          install(yytext,vtype,1);
          yylval.gn=Symbolhead;
          return ID;
        }}
"(" {return LP;}
")" {return RP;}
"<" {return LT;}
">" {return GT;}
"!" {return NOT;}
"," {return COMMA;}
[\t] {}
[\n] {}
" " {}
[.] {exit(1);}


%%

int yywrap()
{
  return 1;
}
int inp()
{
  yyin=fopen("input.sil","r");
}
