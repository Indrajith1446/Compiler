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

//relational node
struct tnode * relnode(char *op,struct tnode *l,struct tnode *r)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  //temp->type=0;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='R';
  temp->varname=malloc(2*sizeof(char));
  temp->varname=op;
  temp->left=l;
  temp->right=r;
  return temp;
}

//ifnode
struct tnode * ifnode(struct tnode *l,struct tnode *r)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  //temp->type=0;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='f';
  temp->varname=NULL;
  temp->left=l;
  temp->right=r;
  return temp;
}

//ifelse node
struct tnode * ifelsenode(struct tnode *l,struct tnode *r)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  //temp->type=0;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='F';
  temp->varname=NULL;
  temp->left=l;
  temp->right=r;
  return temp;
}

//while node
struct tnode * whilenode(struct tnode *l,struct tnode *r)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  //temp->type=0;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='W';
  temp->varname=NULL;
  temp->left=l;
  temp->right=r;
  return temp;
}

//break node
struct tnode * breaknode()
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  //temp->type=0;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='B';
  temp->varname=NULL;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

//continue node
struct tnode * continuenode()
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  //temp->type=0;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='c';
  temp->varname=NULL;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

//funtion to generate code
int generate(struct tnode *t)
{
  int p,q,loc,lval,rval,rval2,l1=0,l2=0,l3=0,t1,t2;
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
    case 'S': lval=generate(t->left);
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
    case 'R': lval=generate(t->left);
              rval=generate(t->right);
              if(strcmp((t->varname),"<")==0)
              {
                printf("%s",t->varname);
                fprintf(outputfile,"LT R%d, R%d\n",lval,rval);
              }
              else if(strcmp((t->varname),">")==0)
              {
                printf("%s",t->varname);
                fprintf(outputfile,"GT R%d, R%d\n",lval,rval);
              }
              else if(strcmp((t->varname),"<=")==0)
              {
                printf("%s",t->varname);
                fprintf(outputfile,"LTE R%d, R%d\n",lval,rval);
              }
              else if(strcmp((t->varname),">=")==0)
              {
                printf("%s",t->varname);
                fprintf(outputfile,"GTE R%d, R%d\n",lval,rval);
              }
              else if(strcmp((t->varname),"!=")==0)
              {
                printf("%s",t->varname);
                fprintf(outputfile,"NEQ R%d, R%d\n",lval,rval);
              }
              else if(strcmp((t->varname),"==")==0)
              {
                printf("%s",t->varname);
                fprintf(outputfile,"EQ R%d, R%d\n",lval,rval);
              }
              else
              {
                printf("\nrelational operator error \n");
              }
              releasereg();
              return lval;
              break;
    case 'f': l1=getlabel();
              l2=getlabel();
              fprintf(outputfile,"L%d:\n",l1);
              lval=generate(t->left);
              fprintf(outputfile,"JZ R%d, L%d\n",lval,l2);
              releasereg();
              rval=generate(t->right);
              fprintf(outputfile,"L%d:\n",l2);
              break;
    case 'F': l1=getlabel();
              l2=getlabel();
              l3=getlabel();
              fprintf(outputfile,"L%d:\n",l1);
              lval=generate(t->left);
              fprintf(outputfile,"JZ R%d, L%d\n",lval,l2);
              releasereg();
              rval=generate(t->right->left);
              fprintf(outputfile,"JMP L%d\n",l3);
              fprintf(outputfile,"L%d:\n",l2);
              rval2=generate(t->right->right);
              fprintf(outputfile,"L%d:\n",l3);
              break;
    case 'W': l1=getlabel();
              l2=getlabel();
              t1=loopflag[1];
              t2=loopflag[2];
              loopflag[0]+=1;
              loopflag[1]=l1;
              loopflag[2]=l2;
              fprintf(outputfile,"L%d:\n",l1);
              lval=generate(t->left);
              fprintf(outputfile,"JZ R%d, L%d\n",lval,l2);
              releasereg();
              rval=generate(t->right);
              fprintf(outputfile,"JMP L%d\n",l1);
              fprintf(outputfile,"L%d:\n",l2);
              loopflag[0]-=1;
              loopflag[1]=t1;
              loopflag[2]=t2;
              break;
    case 'B': if(loopflag[0]>0)
                fprintf(outputfile,"JMP L%d\n",loopflag[2]);
              break;
    case 'c': if(loopflag[0]>0)
                fprintf(outputfile,"JMP L%d\n",loopflag[1]);
              break;
    default:printf("\nERROR IN PARSING TREE\n");
  }
}

//function to get free register from register pool
int getfreereg()
{
  (Reg->reg)+=1;
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

//function to return free label number
int getlabel()
{
  Reg->label+=1;
  printf("%d",Reg->label);
  return (Reg->label);
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
