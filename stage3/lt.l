%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lt.h"

int labelno=0;
int count=2048;
int roundno=0;


FILE *outputfile;
%}

letter [a-z|A-Z]
number [0-9]+
label1 ([L])([0-9]+)([:])(\n)
label2 ([L])([0-9]+)([\n])
line [\n]
col [:]
space [' ']

%%
{label1} {printf("\nlabel type 1 %s\n",yytext);
  labelno=getno(yytext[1],yytext[2]);
  if(roundno==0)
    inlabel(labelno,count);
  }
{label2} {
  printf("\nlabel type 2\n");
  if(roundno==1)
    {
      printf("secondround");
      labelno=getno(yytext[1],yytext[2]);
      printf(" %d ",labelno);
      int ad=getadd(head,labelno);
      fprintf(outputfile,"%d\n",ad);
    }
    else
      fprintf(outputfile,"%s",yytext);
    count+=2;
}
{line} {fprintf(outputfile,"\n");
  if(count>=2056)
    count+=2;
  else
    count+=1;}
. {print_line(yytext,count);
}


%%


void print_line(char *text,int count)
{
  fprintf(outputfile,"%s",text);
}

int getno(char a,char b)
{
  printf("%c %c",a,b);
  int x=a-'0';
  int y=b-'0';
  if(b>='0'&&b<='9')
    return (x*10+y);
  else
    return x;
}
int inlabel(int labelno,int address)
{
  if(head==NULL)
    head=labelentry(labelno,address);
  else
  {
    struct lnode * temp;
    temp=head;
    temp->next=head->next;
    head=labelentry(labelno,address);
    head->next=temp;
  }
}
int getadd(struct lnode *head,int labelno)
{
  while(head!=NULL)
  {
    if(head->label==labelno)
      return (head->labeloc);
    head=head->next;
  }
  printf("Error coudlnt find the right label");
  return 0;
}
struct lnode * labelentry(int labelno,int address)
{
  printf("%d %d \n",labelno,address);
  struct lnode *temp;
  temp=(struct lnode *)malloc(sizeof(struct lnode));
  temp->label=labelno;
  temp->labeloc=address;
  temp->next=NULL;
}

void printd(struct lnode *head)
{
  while(head!=NULL)
  {
    printf("\n\t%d - %d \n",head->label,head->labeloc);
    head=head->next;
  }
}
int isheader(char *text)
{
  if(strcmp(text,"0")==0||strcmp(text,"2056")==0)
  {
    printf("header");
    return 1;
    }
  return 0;
}


int yywrap()
{
  printd(head);
  printf("roundo-%d",roundno);
  if(roundno==0)
  {
    printf("test in");
    roundno=1;
    fclose(outputfile);

    yyin=fopen("output.txt","r");
    outputfile=fopen("output.xsm","w");
    return 0;
  }
  else
  {
    printf("elseing");
    return 1;
  }
}

int main()
{
  printf("mroundno-%d",roundno);
  yyin=fopen("input.xsm","r");
  outputfile=fopen("output.txt","w");
  yylex();
  return 0;
}
