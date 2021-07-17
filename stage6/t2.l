
%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "y.tab.h"
#include "t2.h"

int declflag=0,functionflag=0,fdefflg=0,typedefflag=0,typflg=0;
int no;
int vtype=0,ptype=0;

%}

%%
[0-9]+ {if(declflag==0)
        {
          no=atoi(yytext);
          yylval.tn=intnode(no);
          return NUM;
        }
        else
        {
          yylval.i=atoi(yytext);
          return NUP;
        }
        }
"=" {return EQUAL;}
";" {vtype=0;return SEMCL;}
"+" {return PLUS;}
"-" {return MINUS;}
"/" {return DIV;}
"%" {return MOD;}
"*" {return MUL;}
"main" {lhead=NULL;return MAIN;}
"begin" {return BEGN;}
"end" {node=NULL;return END;}
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
"return" {return RETURN;}
"type" {typedefflag=1;return TYPE;}
"endtype" {typedefflag=0;return ENDTYPE;}
"decl" {declflag=1;bindval=1;return DECL;}
"enddecl" {declflag=0;return ENDDECL;}
"initialize" {yylval.tn=initnode();return INIT;}
"alloc" {return ALLOC;}
"free" {return FREE;}
"null" {return NUL;}
[a-z|A-Z][a-z|A-Z|0-9]* {
        printf("---%s---",yytext);
        if(typedefflag==1)
        {
          if(typflg==1)
          {
            struct Typetable *t;
            t=gettype(yytext);
            if(t!=NULL)
            {
              if(strcmp(yytext,"int")==0)
                return INT;
              if(strcmp(yytext,"str")==0)
                return STR;
              else
              {
                struct Gsymbol *temp;
                temp=makesymbolnode(yytext,NULL,1);
                yylval.gn=temp;
                return ID;
              }
            }
            else
            {
            struct Gsymbol *temp;
            temp=makesymbolnode(yytext,NULL,1);
            yylval.gn=temp;
            return ID;
            }
            printf("error in %s",yytext);
          }
          else
          {
            typetableistall(yytext,1,NULL);
            struct Gsymbol *temp;
            temp=makesymbolnode(yytext,NULL,1);
            yylval.gn=temp;
            return ID;
          }
        }

        struct Typetable *temp;
        temp=gettype(yytext);
        if(temp!=NULL)
        {
          printf("type%s ",yytext);
          if(strcmp(yytext,"int")==0)
            return INT;
          if(strcmp(yytext,"str")==0)
            return STR;
          else
          {
            struct Gsymbol *temp;
            temp=makesymbolnode(yytext,NULL,1);
            yylval.gn=temp;
            return ID;
          }
        }

        struct Gsymbol *gtemp;
        gtemp=makesymbolnode(yytext,NULL,1);
        node=lookup(yytext);
        if(functionflag==0)
          nlbindval=0;
        yylval.gn=gtemp;
        return ID;
        printf("error in %s ",yytext);
        exit(0);
        }
\"(\\.|[^\\\"])*\" {printf("idnetified string %s",yytext);
                    yylval.tn=stringnode(yytext);
                    return STRING;}
"(" {functionflag=1;paramhead=NULL;
      if(node!=NULL&&fdefflg==0)
      {
        struct Gsymbol *gt;
        gt=node;
        struct Paramstruct *pt;
        if(gt->paramlist!=NULL)
          pt=gt->paramlist;
        while(pt!=NULL)
        {
          nlbindval++;
          pt=pt->next;
        }
      }
      return LP;}
")" {functionflag=0;return RP;node=NULL;}
"[" {return LSB;}
"]" {return RSB;}
"{" {fdefflg=1;tmpnode=node;
      if(typedefflag==1)
        typflg=1;
      return LCB;}
"}" {fdefflg=0;tmpnode=NULL;
      if(typedefflag==1)
        typflg=0;
      return RCB;}
"<" {return LT;}
">" {return GT;}
"!" {return NOT;}
"," {return COMMA;}
[\t] {}
[\n] {}
" " {}
"\." {return DOT;}
. {printf("  unidentified %s  ",yytext);exit(1);}


%%

int yywrap()
{
  return 1;
}
int inp()
{
  Typenode=NULL;
  initialisetype();
  yyin=fopen("input.sil","r");
  currentfname=malloc(10*sizeof(char));
}
