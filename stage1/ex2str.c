struct tnode * leafnode(int val)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  temp->val=val;
  temp->op=NULL;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

struct tnode * opnode(char op,struct tnode *l,struct tnode *r)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  temp->op=malloc(sizeof(char));
  *(temp->op)=op;
  temp->left=l;
  temp->right=r;
  return temp;
}

int generate(struct tnode *t)
{
  int p,q;
  if(t->op==NULL)
  {
    printf(" num ");
    return t->val;
  }
  else
  {
      printf(" op %c",*(t->op));
      if(*(t->op)=='+')
      {
          printf(" + ");
          int lval,rval;
          lval=generate(t->left);
          p=getfreereg();
          fprintf(outputfile,"MOV R%d, %d\n",p,lval);
          rval=generate(t->right);
          q=getfreereg();
          fprintf(outputfile,"MOV R%d, %d\n",q,rval);
          fprintf(outputfile,"ADD R%d, R%d\n",p,q);
          releasereg();
          return (lval+rval);
      }
      else if(*(t->op)=='-')
      {
          printf(" - ");
          int lval,rval;
          lval=generate(t->left);
          p=getfreereg();
          fprintf(outputfile,"MOV R%d, %d\n",p,lval);
          rval=generate(t->right);
          q=getfreereg();
          fprintf(outputfile,"MOV R%d, %d\n",q,rval);
          fprintf(outputfile,"SUB R%d, R%d\n",p,q);
          releasereg();
          return (lval-rval);
      }
      else if(*(t->op)=='*')
      {
          printf(" * ");
          int lval,rval;
          lval=generate(t->left);
          p=getfreereg();
          fprintf(outputfile,"MOV R%d, %d\n",p,lval);
          rval=generate(t->right);
          q=getfreereg();
          fprintf(outputfile,"MOV R%d, %d\n",q,rval);
          fprintf(outputfile,"MUL R%d, R%d\n",p,q);
          releasereg();
          return (lval*rval);
      }
      else if(*(t->op)=='/')
      {
          printf(" / ");
          int lval,rval;
          lval=generate(t->left);
          p=getfreereg();
          fprintf(outputfile,"MOV R%d, %d\n",p,lval);
          rval=generate(t->right);
          q=getfreereg();
          fprintf(outputfile,"MOV R%d, %d\n",q,rval);
          fprintf(outputfile,"DIV R%d, R%d\n",p,q);
          releasereg();
          return (lval/rval);
      }
  }
}

int getfreereg()
{
  Reg->reg+=1;
  if(Reg->reg==20)
  {
    printf("error max no of registeres exceeded");
    exit (1);
  }
  return (Reg->reg);
}
void releasereg()
{
  Reg->reg-=1;
}
int p_val(int val)
{
  int r=getfreereg();
  int r_1=getfreereg();
  int r_2=getfreereg();
  fprintf(outputfile,"MOV R%d, %d\n",r,val);
  fprintf(outputfile,"PUSH R%d\n",r);
  fprintf(outputfile,"MOV SP, 4095\n");
  fprintf(outputfile,"MOV R%d, \"Write\"\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  releasereg();
  fprintf(outputfile,"MOV R%d, -2\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r);
  fprintf(outputfile,"PUSH R%d\n",r_1);
  fprintf(outputfile,"PUSH R%d\n",r_1);
  fprintf(outputfile,"CALL 0\n");
  fprintf(outputfile,"POP R%d\n",r);
  fprintf(outputfile,"POP R%d\n",r_1);
  fprintf(outputfile,"POP R%d\n",r_1);
  fprintf(outputfile,"POP R%d\n",r_1);
  fprintf(outputfile,"POP R%d\n",r_1);
  releasereg();
  fprintf(outputfile,"RET\n");
  releasereg();
}
