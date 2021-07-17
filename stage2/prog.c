//creates node for integers
struct tnode * intnode(int val)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  temp->val=val;
  temp->type=0;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='N';
  temp->varname=NULL;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

//creates nodes for
struct tnode * varnode(char vname)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  //temp->type=0;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='V';
  temp->varname=malloc(sizeof(char));
  *(temp->varname)=vname;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

//operator node
struct tnode * opnode(char op,struct tnode *l,struct tnode *r)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  //temp->type=0;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='S';
  temp->varname=malloc(sizeof(char));
  *(temp->varname)=op;
  temp->left=l;
  temp->right=r;
  return temp;
}

//input node
struct tnode * Inode(struct tnode *l)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  //temp->type=0;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='I';
  temp->varname=NULL;
  temp->left=l;
  temp->right=NULL;
  return temp;
}

//output node
struct tnode * Onode(struct tnode *l)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  //temp->type=0;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='O';
  temp->varname=NULL;
  temp->left=l;
  temp->right=NULL;
  return temp;
}

//connector node
struct tnode * connector(struct tnode *l,struct tnode *r)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  //temp->type=0;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='C';
  temp->varname=NULL;
  temp->left=l;
  temp->right=r;
  return temp;
}
int generate(struct tnode *t)
{
  int p,q,loc,lval,rval;
  switch(*(t->nodetype))
  {
    case 'N': p=getfreereg();
              fprintf(outputfile,"MOV R%d, %d\n",p,t->val);
              return p;
              break;
    case 'V': p=getfreereg();
              loc=loc_for_name(*(t->varname));
              fprintf(outputfile,"MOV R%d, [%d]\n",p,loc);
              return p;
              break;
    case 'S': lval,rval;
              lval=generate(t->left);
              rval=generate(t->right);
              switch(*(t->varname))
              {
                case '+': fprintf(outputfile,"ADD R%d, R%d\n",lval,rval);
                          break;
                case '-': fprintf(outputfile,"SUB R%d, R%d\n",lval,rval);
                          break;
                case '*': fprintf(outputfile,"MUL R%d, R%d\n",lval,rval);
                          break;
                case '/': fprintf(outputfile,"DIV R%d, R%d\n",lval,rval);
                          break;
                case '=': loc=loc_for_name(*(t->left->varname));
                          fprintf(outputfile,"MOV [%d], R%d\n",loc,rval);
                          break;
                default: printf("\nerror in operator node \n");
              }
              releasereg();
              return lval;
    case 'I': q=*(t->left->varname);
              r_val(q);
              break;
    case 'O': q=generate(t->left);
              p_val(q);
              releasereg();
              break;
    case 'C': generate(t->left);
              generate(t->right);
              break;
    default:printf("\nERROR IN PARSING TREE\n");
  }
}

//function to get free register from register pool
int getfreereg()
{
  Reg->reg+=1;
  if(Reg->reg==20)
  {
    printf("error max no of registeres exceeded");
    exit (1);
  }
  if(Reg->reg<0)
  {
    printf("\nerror in releasing register");
    exit (1);
  }
  return (Reg->reg);
}

//function to release register to register pool
void releasereg()
{
  Reg->reg-=1;
}

//funtion to generate readvalue code
int r_val(char var)
{
  int loc=loc_for_name(var);
  int r=getfreereg();
  int r_1=getfreereg();
  int r_2=getfreereg();
  fprintf(outputfile,"MOV R%d, %d\n",r,loc);
  fprintf(outputfile,"MOV SP, 4121\n");
  fprintf(outputfile,"MOV R%d, \"Read\"\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  releasereg();
  fprintf(outputfile,"MOV R%d, -1\n",r_2);
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
  releasereg();
}

//function to generate printvalue code
int p_val(int reg)
{
  int r=getfreereg();
  int r_1=getfreereg();
  int r_2=getfreereg();
  fprintf(outputfile,"MOV R%d, R%d\n",r,reg);
  fprintf(outputfile,"PUSH R%d\n",r);
  fprintf(outputfile,"MOV SP, 4121\n");
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

//function that returns location in stack for a variable
int loc_for_name(char var)
{
  for(int i=0;i<26;i++)
  {
    if(var-'a'==i)
      return i+4096;
  }
}
