
%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "y.tab.h"
#include "t3.h"

int declflag=0,functionflag=0,fdefflg=0;
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
"decl" {declflag=1;bindval=1;return DECL;}
"enddecl" {declflag=0;return ENDDECL;}
"int" {if(functionflag==0)
        vtype=1;
      else
        ptype=1;
      yylval.i=1;return INT;}
"str" {if(functionflag==0)
        vtype=2;
      else
        ptype=2;
      yylval.i=2;return STR;}
[a-z|A-Z][a-z|A-Z|0-9]* {
        printf("---%s---",yytext);
        if(declflag==0)
        {
          if(functionflag==1)
          {
            lnode=llookup(yytext);
            if(lnode!=NULL)
            {
              yylval.tn=varnode(yytext,lnode,NULL);
              return VAR;
            }
            struct Paramstruct * temp=node->paramlist;
            temp=checkfor(temp,yytext,ptype);
            if(temp!=NULL)
            {
              printf("+lptest+");
              linstall(yytext,ptype,(0-nlbindval));
              nlbindval-=1;
              yylval.pn=temp;
              printf("this");
              return PM;
            }

            printf("\nSame type and name of arguments is expected\n");
          }
          if(fdefflg==0)
          {
            node=lookup(yytext);
            if(node!=NULL)
            {
              lhead=NULL;
              yylval.gn=node;
              return ID;
            }

          }

          lnode=llookup(yytext);
          if(lnode!=NULL)
          {
            yylval.tn=varnode(yytext,lnode,NULL);
            return VAR;
          }

          int chkflg=checkname(yytext);
          if(chkflg==1)
          {
            printf("test 1");
            yylval.tn=varnode(yytext,NULL,lookup(yytext));
            return VAR;
          }
          printf("\nimplicit decleration of %s\n",yytext);
        }
        else
        {
          if(lookup(yytext)!=NULL)
            printf("SEMANTIC error:Variable of the name  %s already declared",yytext);
          if(functionflag==0)
          {
            if(fdefflg==1)
            {
              lbindval+=1;
              linstall(yytext,1,lbindval);
              yylval.ln=lhead;
              return LID;
            }
            install(yytext,vtype,1);
            yylval.gn=Symbolhead;
            return ID;
          }
          else
          {
            finstall(yytext,ptype);
            yylval.pn=paramhead;
            return PM;
          }
        }}
\"(\\.|[^\\\"])*\" {printf("idnetified string %s",yytext);
                    yylval.tn=stringnode(yytext);
                    return STRING;}
"(" {functionflag=1;paramhead=NULL;
      if(node!=NULL)
      {
      struct Gsymbol *gt;
      gt=node;
      struct Paramstruct *pt;
      if(gt->paramlist!=NULL)
        pt=gt->paramlist;
      while(pt!=NULL)
      {
        nlbindval+=1;
        pt=pt->next;
        }
      }
      return LP;}
")" {functionflag=0;return RP;}
"[" {return LSB;}
"]" {return RSB;}
"{" {fdefflg=1;lbindval=0;nlbindval=0;tmpnode=node;return LCB;}
"}" {fdefflg=0;return RCB;tmpnode=NULL;}
"<" {return LT;}
">" {return GT;}
"!" {return NOT;}
"," {return COMMA;}
[\t] {}
[\n] {}
" " {}
. {exit(1);}


%%

int yywrap()
{
  return 1;
}
int inp()
{
  yyin=fopen("input.sil","r");
  currentfname=malloc(10*sizeof(char));
}
