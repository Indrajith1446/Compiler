

//function to initialize typetable
void initialisetype()
{
    typetableistall("int",1,NULL);
    typetableistall("str",1,NULL);
    typetableistall("boolean",1,NULL);
}

//fuction to create typetable entry
void typetableistall(char *name,int size,struct Fieldlist *fields )
{
  if(Typenode==NULL)
    Typenode=maketypeentry(name,size,fields );
  else
  {
    struct Typetable *temp;
    temp=Typenode;
    temp->next=Typenode->next;
    Typenode=maketypeentry(name,size,fields );
    Typenode->next=temp;
  }
}

//fuction to make a node for typetable
struct Typetable * maketypeentry(char *name,int size , struct Fieldlist *fields )
{
  struct Typetable * temp;
  temp=(struct Typetable*)malloc(sizeof(struct Typetable));
  temp->name=malloc(10*sizeof(char));
  strcpy(temp->name ,name);
  temp->size=size;
  temp->fields=fields;
  temp->next=NULL;
  return temp;
}

//function to return type for the given name
struct Typetable * gettype(char *name)
{
  struct Typetable * temp;
  temp=Typenode;
  while(temp!=NULL)
  {
    if(strcmp(temp->name,name )==0)
      return temp;
    temp=temp->next;
  }
  return NULL;
}

//function to print typetable entries
void printtype()
{
    struct Typetable *temp;
    temp=Typenode;
    while(temp!=NULL)
    {
      printf("\nType - %s Size - %d ",temp->name,temp->size );
      if(temp->fields!=NULL)
      {
        struct Fieldlist *f;
        f=temp->fields;
        while(f!=NULL)
        {
          printf("\n\tField name - %s field index - %d field type - %s",f->name,f->fieldindex,f->type->name);
          f=f->next;
        }
      }
      temp=temp->next;
    }
}

//function to make field entry
void fieldinstall(char *name , int index ,struct Typetable *type )
{
    if(Fieldnode==NULL)
      Fieldnode=makefieldnode(name,index,type );
    else
    {
      struct Fieldlist * temp;
      temp=Fieldnode;
      temp->next=Fieldnode->next;
      Fieldnode=makefieldnode(name,index,type );
      Fieldnode->next=temp;
    }
}

//fuction to make Fieldnode
struct Fieldlist * makefieldnode(char *name,int index,struct Typetable *type)
{
    struct Fieldlist * temp;
    temp=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
    temp->name=malloc(10*sizeof(char));
    strcpy(temp->name,name);
    temp->fieldindex=index;
    temp->type=type;
    temp->next=NULL;
    return temp;
}

//creates node for integers
struct tnode * intnode(int val)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  temp->val=val;
  temp->type=gettype("int");
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='N';
  temp->varname=NULL;
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

//creates string node
struct tnode * stringnode(char *word)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  temp->type=gettype("str");
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='L';
  temp->varname=malloc(8*sizeof(char));
  strcpy(temp->varname,word);
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

//creates nodes for variable
struct tnode * varnode(char *vname,struct Lsymbol *lentry,struct Gsymbol *gentry)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='V';
  temp->varname=malloc(10*sizeof(char));
  strcpy(temp->varname,vname);
  temp->Arglist=NULL;
  temp->Gentry=gentry;
  temp->Lentry=lentry;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

//creates nodes for function
struct tnode * funnode(char *vname,struct Lsymbol *lentry,struct Gsymbol *gentry,struct tnode *Arglist)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='n';
  temp->varname=malloc(10*sizeof(char));
  strcpy(temp->varname,vname);
  temp->Arglist=Arglist;
  temp->Gentry=gentry;
  temp->Lentry=lentry;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

//field node
struct tnode * fldnode(char *name,struct tnode *l)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='l';
  temp->varname=malloc(10*sizeof(char));
  strcpy(temp->varname,name);
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
  temp->left=l;
  temp->right=NULL;
  return temp;
}

//operator node
struct tnode * opnode(char op,struct tnode *l,struct tnode *r)
{
  struct tnode *temp;
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  //temp->val=val;
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='S';
  temp->varname=malloc(sizeof(char));
  *(temp->varname)=op;
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
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
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='I';
  temp->varname=NULL;
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
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
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='O';
  temp->varname=NULL;
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
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
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='C';
  temp->varname=NULL;
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
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
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='R';
  temp->varname=malloc(2*sizeof(char));
  temp->varname=op;
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
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
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='f';
  temp->varname=NULL;
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
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
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='F';
  temp->varname=NULL;
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
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
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='W';
  temp->varname=NULL;
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
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
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='B';
  temp->varname=NULL;
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
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
  temp->type=NULL;
  temp->nodetype=malloc(sizeof(char));
  *(temp->nodetype)='c';
  temp->varname=NULL;
  temp->Arglist=NULL;
  temp->Gentry=NULL;
  temp->Lentry=NULL;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

//return node
struct tnode * retnode(struct tnode *l)
{
    struct tnode *temp;
    temp=(struct tnode*)malloc(sizeof(struct tnode));
    //temp->val=val;
    temp->type=NULL;
    temp->nodetype=malloc(sizeof(char));
    *(temp->nodetype)='r';
    temp->varname=NULL;
    temp->Arglist=NULL;
    temp->Gentry=NULL;
    temp->Lentry=NULL;
    temp->left=l;
    temp->right=NULL;
    return temp;
}

//initialize node
struct tnode * initnode()
{
    struct tnode *temp;
    temp=(struct tnode*)malloc(sizeof(struct tnode));
    //temp->val=val;
    temp->type=NULL;
    temp->nodetype=malloc(sizeof(char));
    *(temp->nodetype)='i';
    temp->varname=NULL;
    temp->Arglist=NULL;
    temp->Gentry=NULL;
    temp->Lentry=NULL;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

//alloc node
struct tnode * allocnode(struct tnode *l)
{
    struct tnode *temp;
    temp=(struct tnode*)malloc(sizeof(struct tnode));
    //temp->val=val;
    temp->type=NULL;
    temp->nodetype=malloc(sizeof(char));
    *(temp->nodetype)='M';
    temp->varname=NULL;
    temp->Arglist=NULL;
    temp->Gentry=NULL;
    temp->Lentry=NULL;
    temp->left=l;
    temp->right=NULL;
    return temp;
}
//free node
struct tnode * freenode(struct tnode *l)
{
    struct tnode *temp;
    temp=(struct tnode*)malloc(sizeof(struct tnode));
    //temp->val=val;
    temp->type=NULL;
    temp->nodetype=malloc(sizeof(char));
    *(temp->nodetype)='E';
    temp->varname=NULL;
    temp->Arglist=NULL;
    temp->Gentry=NULL;
    temp->Lentry=NULL;
    temp->left=l;
    temp->right=NULL;
    return temp;
}
//funtion to look for the variable in symbol table
struct Gsymbol *lookup(char * name)
{
  struct Gsymbol *temp;
  temp=Symbolhead;
  while(temp!=NULL)
  {
    if(strcmp(temp->name,name)==0)
    {
      return temp;
    }
    temp=temp->next;
  }
  return NULL;
}

//function to look for the local Variable
struct Lsymbol *llookup(char * name)
{
  struct Lsymbol *temp;
  temp=lhead;
  while(temp!=NULL)
  {
    if(strcmp(temp->name,name)==0)
    {
      return temp;
    }
    temp=temp->next;
  }
  return NULL;
}

//function to make entry to symbol table
void install(char *name,struct Typetable * type,int size)
{
  if(Symbolhead==NULL)
    Symbolhead=makesymbolnode(name,type,size);
  else
  {
    struct Gsymbol *tmp;
    tmp=Symbolhead;
    tmp->next=Symbolhead->next;
    Symbolhead=makesymbolnode(name,type,size);
    Symbolhead->next=tmp;
  }
}

//function to make entry to local symbol table
void linstall(char *yytext,struct Typetable * type,int bind)
{
  if(lhead==NULL)
    lhead=makelnode(yytext,type,bind);
  else
  {
    struct Lsymbol *tmp;
    tmp=lhead;
    tmp->next=lhead->next;
    lhead=makelnode(yytext,type,bind);
    lhead->next=tmp;
  }
}

//function to make parameter table entrry
void finstall(char *name,struct Typetable * type,int bind)
{
  if(paramhead==NULL)
    paramhead=makepnode(name,type,bind);
  else
  {
    struct Paramstruct *temp;
    temp=paramhead;
    temp->next=paramhead->next;
    paramhead=makepnode(name,type,bind );
    paramhead->next=temp;
  }
}

//function to create global symbol node
struct Gsymbol *makesymbolnode(char *name,struct Typetable * type,int size)
{
  struct Gsymbol * temp;
  temp=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
  temp->name=malloc(10*sizeof(char));
  strcpy(temp->name,name);
  temp->type=type;
  temp->size=size;
  temp->binding=bindval;
  temp->paramlist=NULL;
  temp->next=NULL;
  return temp;
}

//function to create local symbol node
struct Lsymbol *makelnode(char *name,struct Typetable * type,int bind)
{
  struct Lsymbol * temp;
  temp=(struct Lsymbol *)malloc(sizeof(struct Lsymbol));
  temp->name=malloc(10*sizeof(char));
  strcpy(temp->name,name);
  temp->type=type;
  temp->binding=bind;
  temp->next=NULL;
  return temp;
}
//function to create parameter nodes
struct Paramstruct * makepnode(char *name,struct Typetable * type,int bind)
{
    struct Paramstruct *temp;
    temp=(struct Paramstruct *)malloc(sizeof(struct Paramstruct));
    temp->name=malloc(10*sizeof(char));
    strcpy(temp->name,name);
    temp->type=type;
    temp->binding=bind;
    temp->next=NULL;
    return temp;
}

//function to update size of arrays
void sizeupdate(struct Gsymbol *temp,int size)
{
  temp->size=size;
  bindval+=(size-1);
  return;
}

//function to update type
void updatetype(struct Gsymbol *temp,struct Typetable * type)
{
  temp->type=type;
  return;
}

//function to update type of a list of global types
void updatetypelist(struct Gsymbol *temp,struct Typetable *type)
{
    while(temp!=NULL)
    {
      temp->type=type;
      temp=temp->next;
    }
}

//function to update type of a list of local variables
void updateltypelist(struct Lsymbol *temp,struct Typetable *type)
{
  while(temp!=NULL)
  {
    if(temp->type==NULL)
      temp->type=type;
    temp=temp->next;
  }
}

//function to update local variable type
void updateltype(struct Lsymbol *temp,struct Typetable * type)
{
  temp->type=type;
  return;
}

//function to print symbol table
void printsymbols(struct Gsymbol *temp)
{
  while(temp!=NULL)
  {
    printf("\nNAME-%s  Size-%d Type-%s Binding-%d",temp->name,temp->size,temp->type->name,temp->binding);
    if(temp->paramlist!=NULL)
      printparam(temp->paramlist);
    temp=temp->next;
  }
  return;
}

//function for printing local symboltable
void printlsymbols(struct Lsymbol *head)
{
  while(head!=NULL)
    {
    printf("\nNAME-%s Binding-%d Type-%s",head->name,head->binding,head->type->name);
    head=head->next;
  }
  return;
}

//function to print parameters
void printparam(struct Paramstruct *temp)
{
  while(temp!=NULL)
  {
    printf("\n\tNAME-%s ",temp->name);
    temp=temp->next;
  }
}

//function to check parameter name and type correctness
struct Paramstruct * checkfor(struct Paramstruct * temp,char * yytext,struct Typetable * type)
{
    int flg=0;
    while(temp!=NULL)
    {
      if(strcmp(temp->name,yytext)==0)
      {
        if(temp->type==type)
          return temp;
      }
      temp=temp->next;
    }
    return temp;
}

//function to chceck wether the name exists in global table
int checkname(char * yytext)
{
  if(lookup(yytext)!=NULL)
    return 1;
  if(llookup(yytext)!=NULL)
    return 1;
  return 0;
}

//function to check validity in parameters
int plook(char *name,struct Paramstruct * p)
{
  while(p!=NULL)
  {
    if(strcmp(p->name,name)==0)
    {
      return 1;
    }
    p=p->next;
  }
  return 0;
}

//function to concatenate two global symbol ndes
struct Gsymbol * concatid(struct Gsymbol *h1,struct Gsymbol *h2)
{
  struct Gsymbol * temp;
  temp=h1;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=h2;
  return h1;
}

//function to concatenate two local symbol ndes
struct Paramstruct * concatpid(struct Paramstruct *h1,struct Paramstruct *h2)
{
  struct Paramstruct * temp;
  temp=h1;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=h2;
  return h1;
}

//function to add parameter to local symbol
void makelocalentry(struct Paramstruct *ph,int bind)
{
  linstall(ph->name,ph->type,bind);
}

//funtion to generate code
int generate(struct tnode *t)
{
  printf(" AST %s type %s",t->varname,t->nodetype );
  if(generate_flag==0)
  {
    fprintf(outputfile,"PUSH BP\n");
    fprintf(outputfile,"MOV BP,SP\n");
    struct Lsymbol *lv;
    lv=lhead;
    while(lv!=NULL)
    {
      if(lv->binding>=0)
        fprintf(outputfile,"PUSH R0\n");
      lv=lv->next;
    }
    generate_flag=1;
  }
  struct Gsymbol *gn;
  struct Lsymbol *ln;
  struct Paramstruct *pn;
  struct tnode *tn;
  if(t==NULL)
    return 0;
  int p,q,loc,lval,rval,rval2,l1=0,l2=0,l3=0,t1,t2,no,count;
  switch(*(t->nodetype))
  {
    case 'N': p=getfreereg();
              fprintf(outputfile,"MOV R%d, %d\n",p,t->val);
              return p;
              break;
    case 'L': p=getfreereg();
              fprintf(outputfile,"MOV R%d, %s\n",p,t->varname);
              return p;
              break;
    case 'V': p=getfreereg();
              if(t->Lentry!=NULL)
              {
                fprintf(outputfile,"MOV R%d, BP\n",p);
                loc=t->Lentry->binding;
              }
              else if(t->Gentry!=NULL)
              {
                fprintf(outputfile,"MOV R%d, 4097\n",p);
                loc=t->Gentry->binding;
              }
              else
              {
                printf(" no proper variable entry found %s",t->varname );
                exit(0);
              }
              if(loc>0)
                fprintf(outputfile,"ADD R%d, %d\n",p,loc);
              else
                fprintf(outputfile,"SUB R%d, %d\n",p,(2-loc));
              fprintf(outputfile,"MOV R%d, [R%d]\n",p,p);
              return p;
              break;
    case 'S':
              switch(*(t->varname))
              {
                case '+': lval=generate(t->left);
                          rval=generate(t->right);
                          fprintf(outputfile,"ADD R%d, R%d\n",lval,rval);
                          break;
                case '-': lval=generate(t->left);
                          rval=generate(t->right);
                          fprintf(outputfile,"SUB R%d, R%d\n",lval,rval);
                          break;
                case '*': lval=generate(t->left);
                          rval=generate(t->right);
                          fprintf(outputfile,"MUL R%d, R%d\n",lval,rval);
                          break;
                case '/': lval=generate(t->left);
                          rval=generate(t->right);
                          fprintf(outputfile,"DIV R%d, R%d\n",lval,rval);
                          break;
                case '%': lval=generate(t->left);
                          rval=generate(t->right);
                          fprintf(outputfile,"MOD R%d, R%d\n",lval,rval);
                          break;
                case '=': p=getfreereg();
                          if(t->right==NULL)
                          {
                            if(*(t->left->nodetype)=='l')
                            {
                              lval=generate(t->left->left);
                              q=getfieldindex(t->left->varname,t->left->left->type);
                              fprintf(outputfile,"ADD R%d, %d\n",lval,q);
                              fprintf(outputfile,"MOV [R%d], \"NULL\"\n",lval);
                              break;
                            }
                            if(t->left->Lentry!=NULL)
                            {
                              fprintf(outputfile,"MOV R%d, BP\n",p);
                              loc=t->left->Lentry->binding;
                            }
                            else if(t->left->Gentry!=NULL)
                            {
                              fprintf(outputfile,"MOV R%d, 4097\n",p);
                              loc=t->left->Gentry->binding;
                            }
                            else
                              {
                                lval=generate(t->left);
                                fprintf(outputfile,"MOV [R%d], \"NULL\"\n",lval);
                                break;
                              }
                            if(loc>0)
                              fprintf(outputfile,"ADD R%d, %d\n",p,loc);
                            else
                              fprintf(outputfile,"SUB R%d, %d\n",p,(2-loc));
                            fprintf(outputfile,"MOV [R%d], \"NULL\"\n",p);
                            break;
                          }
                          rval=generate(t->right);
                          if(*(t->left->nodetype)=='l')
                          {
                            lval=generate(t->left->left);
                            q=getfieldindex(t->left->varname,t->left->left->type);
                            fprintf(outputfile,"ADD R%d, %d\n",lval,q);
                            fprintf(outputfile,"MOV [R%d], R%d\n",lval,rval);
                            releasereg();
                            break;
                          }
                          if(t->left->Lentry!=NULL)
                          {
                            fprintf(outputfile,"MOV R%d, BP\n",p);
                            loc=t->left->Lentry->binding;
                          }
                          else if(t->left->Gentry!=NULL)
                          {
                            fprintf(outputfile,"MOV R%d, 4097\n",p);
                            loc=t->left->Gentry->binding;
                          }
                          else
                            {
                              lval=generate(t->left);
                              fprintf(outputfile,"MOV [R%d], R%d\n",lval,rval);
                              releasereg();
                              break;
                            }
                          if(loc>0)
                            fprintf(outputfile,"ADD R%d, %d\n",p,loc);
                          else
                            fprintf(outputfile,"SUB R%d, %d\n",p,(2-loc));

                          fprintf(outputfile,"MOV [R%d], R%d\n",p,rval);
                          releasereg();
                          break;
                default: printf("\nerror in operator node \n");
              }
              releasereg();
              return lval;
    case 'I': gn=t->left->Gentry;
              if(gn!=NULL)
              {
                r_val(gn->binding,'g');
              }
              ln=t->left->Lentry;
              if(ln!=NULL)
              {
                r_val(ln->binding,'l');
              }
              break;
    case 'O': q=generate(t->left);
              p_val(q);
              releasereg();
              break;
    case 'C': generate(t->left);
              generate(t->right);
              break;
    case 'R': lval=generate(t->left);

              if(strcmp((t->varname),"<")==0)
              {
                rval=generate(t->right);
                printf("%s",t->varname);
                fprintf(outputfile,"LT R%d, R%d\n",lval,rval);
              }
              else if(strcmp((t->varname),">")==0)
              {
                rval=generate(t->right);
                printf("%s",t->varname);
                fprintf(outputfile,"GT R%d, R%d\n",lval,rval);
              }
              else if(strcmp((t->varname),"<=")==0)
              {
                rval=generate(t->right);
                printf("%s",t->varname);
                fprintf(outputfile,"LE R%d, R%d\n",lval,rval);
              }
              else if(strcmp((t->varname),">=")==0)
              {
                rval=generate(t->right);
                printf("%s",t->varname);
                fprintf(outputfile,"GE R%d, R%d\n",lval,rval);
              }
              else if(strcmp((t->varname),"!=")==0)
              {
                if(t->right!=NULL)
                {
                  rval=generate(t->right);
                  printf("%s",t->varname);
                  fprintf(outputfile,"NE R%d, R%d\n",lval,rval);
                }
                else
                {
                  p=getfreereg();
                  printf("%s",t->varname);
                  fprintf(outputfile,"MOV R%d, \"NULL\"\n",p);
                  fprintf(outputfile,"NE R%d, R%d\n",lval,p);
                  releasereg();
                }
              }
              else if(strcmp((t->varname),"==")==0)
              {
                if(t->right!=NULL)
                {
                  rval=generate(t->right);
                  printf("%s",t->varname);
                  fprintf(outputfile,"EQ R%d, R%d\n",lval,rval);
                }
                else
                {
                  p=getfreereg();
                  printf("%s",t->varname);
                  fprintf(outputfile,"MOV R%d, \"NULL\"\n",p);
                  fprintf(outputfile,"EQ R%d, R%d\n",lval,p);
                  releasereg();
                }
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
    case 'B': fprintf(outputfile,"JMP L%d\n",loopflag[2]);
              break;
    case 'c':fprintf(outputfile,"JMP L%d\n",loopflag[1]);
              break;
    case 'r': gn=lookup(currentfname);
              printf("   $$ %s  $$  ",currentfname);
              if(strcmp(currentfname,"main")==0)
              {
                fprintf(outputfile,"JMP L%d\n",ml);
                break;
              }
              else
              {
                l2=gn->binding+1;
                if(t->left!=NULL)
                {
                  lval=generate(t->left);
                  l1=getfreereg();
                  fprintf(outputfile,"MOV R%d, BP\n",l1);
                  fprintf(outputfile,"SUB R%d, 2\n",l1);
                  fprintf(outputfile,"MOV [R%d], R%d\n",l1,lval);
                }
                fprintf(outputfile,"JMP L%d\n",(l2));
              }
              break;
      case 'E' :lval=generate(t->left);
                rval=p_free(lval);
                return lval;
                releasereg();
                releasereg();
                break;
      case 'M' :lval=p_alloc(8);
                if(*(t->left->nodetype)=='l')
                {
                  p=generate(t->left);
                  {
                    lval=generate(t->left->left);
                    q=getfieldindex(t->left->varname,t->left->left->type);
                    fprintf(outputfile,"ADD R%d, %d\n",lval,q);
                    fprintf(outputfile,"MOV [R%d], R%d\n",lval,rval);
                    releasereg();

                    break;
                  }
                }
                else
                {
                  p=getfreereg();
                  if(t->left->Lentry!=NULL)
                  {
                    fprintf(outputfile,"MOV R%d, BP\n",p);
                    loc=t->left->Lentry->binding;
                  }
                  else if(t->left->Gentry!=NULL)
                  {
                    fprintf(outputfile,"MOV R%d, 4097\n",p);
                    loc=t->left->Gentry->binding;
                  }
                  else
                  {
                    printf(" no proper variable entry found %s",t->left->varname );
                    exit(0);
                  }
                  if(loc>0)
                  fprintf(outputfile,"ADD R%d, %d\n",p,loc);
                  else
                  fprintf(outputfile,"SUB R%d, %d\n",p,(2-loc));

                }
                fprintf(outputfile,"MOV [R%d], R%d\n",p,lval);
                releasereg();

                break;
      case 'i' :return (p_initialize());
                break;
      case 'n' :no=-1;
                struct tnode *ta;
                for(int i=0;i<Reg->reg;i++)
                {
                  fprintf(outputfile,"PUSH R%d\n",i);
                  no+=1;
                }
                p=getfreereg();
                ta=t->Arglist;
                count=0;
                while(ta!=NULL)
                {
                  p=generate(ta);
                  fprintf(outputfile,"PUSH R%d\n",p);
                  releasereg();
                  ta=ta->Arglist;
                  count+=1;
                }
                struct Gsymbol *gn;
                gn=lookup(t->varname);
                fprintf(outputfile,"PUSH R0\n");
                fprintf(outputfile,"CALL L%d\n",gn->binding);
                fprintf(outputfile,"POP R%d\n",p);
                for(int i=0;i<count;i++)
                  fprintf(outputfile,"POP R0\n");
                for(int i=no;i>=0;i--)
                  fprintf(outputfile,"POP R%d\n",i);
                return p;
                break;
      case 'l' :lval=generate(t->left);
                q=getfieldindex(t->varname,t->left->type);
                fprintf(outputfile,"ADD R%d, %d\n",lval,q);
                fprintf(outputfile,"MOV R%d, [R%d]\n",lval,lval);
                return lval;
                break;
    default:printf("\nERROR IN PARSING TREE %c\n",*(t->nodetype));
  }
}

//function to return field index of a user defined variable
int getfieldindex(char *name,struct Typetable *tbt)
{
    int count=0;
    struct Fieldlist *fl;
    if(tbt!=NULL)
    {
      fl=tbt->fields;
      while(fl!=NULL)
      {
        if(strcmp(fl->name,name)==0)
          return fl->fieldindex;
        fl=fl->next;
      }
    }
    printf("hmm no entry");
    return -1;
}

//functin to return field type for a user defined variable
struct Typetable * getfieldtype(char *name,struct Typetable *tbt)
{
  int count=0;
  struct Fieldlist *fl;
  if(tbt!=NULL)
  {
    fl=tbt->fields;
    while(fl!=NULL)
    {
      if(strcmp(fl->name,name)==0)
        return fl->type;
      fl=fl->next;
    }
  }
  printf("hmm no entry");
  return NULL;
}

//function to pop local elements code
void lpop()
{
  struct Lsymbol *temp;
  printf("\netrd");
  temp=lhead;
  while(temp!=NULL)
  {
    if(temp->binding>0)
      fprintf(outputfile,"POP R0\n");
    temp=temp->next;
  }
  fprintf(outputfile,"MOV BP, [SP]\n");
  fprintf(outputfile,"POP R0\n");
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
  return (Reg->label);
}

//function to release register to register pool
void releasereg()
{
  Reg->reg-=1;
}

//function to reset registers to 0
void resetreg()
{
  Reg->reg=-1;
}
//funtion to generate readvalue code
int r_val(int loc,char t)
{
  int r=getfreereg();
  int r_1=getfreereg();
  int r_2=getfreereg();
  if(t=='l')
  {
    fprintf(outputfile,"MOV R%d,BP\n",r_2);
    if(loc>0)
      fprintf(outputfile,"ADD R%d,%d\n",r_2,loc);
    else
    fprintf(outputfile,"SUB R%d,%d\n",r_2,(2-loc));
  }
  if(t=='g')
  {
    fprintf(outputfile,"MOV R%d, 4097\n",r_2);
    fprintf(outputfile,"ADD R%d, %d\n",r_2,loc);
  }
  fprintf(outputfile,"MOV R%d, R%d\n",r,r_2);
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

//funtion to generate initialize library call code
int p_initialize()
{
  int size=8;
  int r=getfreereg();
  int r_2=getfreereg();
  fprintf(outputfile,"MOV R%d, \"Heapset\"\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"MOV R%d, %d\n",r_2,size);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"CALL 0\n");
  fprintf(outputfile,"POP R%d\n",r);
  fprintf(outputfile,"POP R%d\n",r_2);
  fprintf(outputfile,"POP R%d\n",r_2);
  fprintf(outputfile,"POP R%d\n",r_2);
  fprintf(outputfile,"POP R%d\n",r_2);
  releasereg();
  return r;
}

//funtion to generate alloc library call code
int p_alloc(int size)
{
  int r=getfreereg();
  int r_2=getfreereg();
  fprintf(outputfile,"MOV R%d, \"Alloc\"\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"MOV R%d, %d\n",r_2,size);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"CALL 0\n");
  fprintf(outputfile,"POP R%d\n",r);
  fprintf(outputfile,"POP R%d\n",r_2);
  fprintf(outputfile,"POP R%d\n",r_2);
  fprintf(outputfile,"POP R%d\n",r_2);
  fprintf(outputfile,"POP R%d\n",r_2);
  releasereg();
  return r;
}

//funtion to generate free  library call code
int p_free(int pointer)
{
  int r=getfreereg();
  int r_2=getfreereg();
  fprintf(outputfile,"MOV R%d, \"FREE\"\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"MOV R%d, R%d\n",r_2,pointer);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"PUSH R%d\n",r_2);
  fprintf(outputfile,"CALL 0\n");
  fprintf(outputfile,"POP R%d\n",r);
  fprintf(outputfile,"POP R%d\n",r_2);
  fprintf(outputfile,"POP R%d\n",r_2);
  fprintf(outputfile,"POP R%d\n",r_2);
  fprintf(outputfile,"POP R%d\n",r_2);
  releasereg();
  return r;
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
