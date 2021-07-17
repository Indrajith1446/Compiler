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
  int p;
  if(t->op==NULL)
  {
    printf(" num ");
    p=getfreereg();
    fprintf(outputfile,"MOV R%d, %d\n",p,t->val);
    return p;
  }
  else
  {
      printf(" op ");
      if(*(t->op)=='+')
      {
          printf(" + ");
          int lval,rval;
          lval=generate(t->left);
          rval=generate(t->right);
          fprintf(outputfile,"ADD R%d, R%d\n",lval,rval);
          releasereg();
          return (lval);
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
