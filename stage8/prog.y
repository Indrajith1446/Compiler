

%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "prog.h"
#include "prog.c"
int yylex();
int yywrap();
int classflag=1;
struct regpool * Reg;
struct Gsymbol * Ghold=NULL;
FILE *outputfile;
int printval,findex=0,size=0,deflag=0;
int loopflag[3];
int yyerror(char const *s);


%}

%union{
struct tnode * tn;
struct Gsymbol * gn;
struct Lsymbol * ln;
struct Paramstruct * pn;
struct Typetable * tyn;
struct Fieldlist * fn;
char * id;
int i;
}

%type <tyn> TypeName
%type <fn> FieldDecl FieldDeclList
%type <ln> LID LdeclBlock LDecList LDecl IdList
%type <i> NUP
%type <pn> ParamList Param PM
%type <gn> GDeclBlock GDeclList GDecl GidList GID ID Cname
%type <tn> expr Body NUM STRING END AsgStmt OutputStmt InputStmt VAR Stmt Slist E IfStmt WhileStmt BreakStmt ContinueStmt
ArgList ReturnStmt INIT FreeStmt FIELD AllocStmt NewStmt DeleteStmt FieldFuntion
%token NUM PLUS END MINUS DIV MUL MOD ID BEGN READ WRITE EQUAL SEMCL LP RP IF THEN ENDIF BREAK CONTINUE COMMA DECL ENDDECL INT STR
ELSE WHILE DO ENDWHILE LT GT NOT VAR NUP LID LSB RSB STRING MAIN LCB RCB PM RETURN TYPE ENDTYPE DOT ALLOC FREE INIT NUL
CLASS ENDCLASS EXTENDS NEW SELF DELETE
%right EQUAL
%left PLUS MINUS
%left MUL DIV MOD


%%

Program : TypeDefBlock ClassDefBlock GDeclBlock FdefBlock MainBlock {printf(" y1 ");}
      | TypeDefBlock ClassDefBlock GDeclBlock MainBlock {printf(" y2 ");}
      ;


TypeDefBlock : TYPE TypeDefList ENDTYPE {printf(" n1 ");printtype();
                                          fprintf(outputfile,"CALL L0\nINT 10\n");}
      | {printf(" Typ ");fprintf(outputfile,"CALL L0\nINT 10\n");}
      ;
TypeDefList : TypeDefList TypeDef {printf(" n2 ");}
      | TypeDef {printf(" n3 ");}
      ;
TypeDef : ID LCB FieldDeclList RCB {printf(" n4 ");
                              struct Typetable *temp;
                              temp=gettype($1->name);
                              temp->fields=$3;
                              temp->size=findex;
                              Fieldnode=NULL;findex=0;}
      ;
FieldDeclList : FieldDeclList FieldDecl {printf(" n5 ");$$=$2;}
      | FieldDecl {printf(" n6 ");$$=$1;}
      ;
FieldDecl : TypeName ID SEMCL {printf(" n7 ");fieldinstall($2->name,findex,$1);findex+=1;$$=Fieldnode;}
      ;
TypeName : INT {printf(" n8 ");$$=gettype("int");}
      | STR {printf(" n9 ");$$=gettype("str");}
      | ID {printf(" n10 ");if(gettype($1->name)!=NULL)
                              $$=gettype($1->name);
                            else
                            {
                              $$=NULL;
                              Ghold=$1;
                              }}
      ;


ClassDefBlock : CLASS ClassDefList ENDCLASS {printf(" c1 ");printclass();classflag=0;}
      | {printf(" c2 ");}
      ;
ClassDefList : ClassDefList ClassDef {printf(" c3 ");}
      | ClassDef {printf(" c4 ");}
      ;
ClassDef : Cname LCB DECL FieldLists MethodDecl ENDDECL MethodDefns RCB {printf(" c5 ");}
      | Cname LCB DECL MethodDecl ENDDECL MethodDefns RCB {printf(" c5 ");}
      | Cname LCB DECL FieldLists ENDDECL MethodDefns RCB {printf(" c5 ");}
      ;
Cname : ID {printf(" c6 ");Cptr=Cinstall($1->name,NULL);}
      | ID EXTENDS ID {printf(" c7 ");Cptr=Cinstall($1->name,$3->name);}
      ;
FieldLists : FieldLists Fld {printf(" c8 ");}
      | Fld {printf(" c9 ");}
      ;
Fld : ID ID SEMCL {printf(" c10 ");ClassFinstall(Cptr,$1->name,$2->name);}
      ;
MethodDecl : MethodDecl MDecl {printf(" c11 ");}
      | MDecl {printf(" c12 ");}
      ;
MDecl : ID ID LP ParamList RP SEMCL {printf(" c13 ");ClassMinstall(Cptr,$2->name,gettype($1->name),$4);}
      ;
MethodDefns : MethodDefns Fdef {printf(" c14 ");}
      | Fdef {printf(" c15 ");}
      ;


GDeclBlock : DECL GDeclList ENDDECL {printf(" y4 ");
                                    Symbolhead=$2;Symbolhead->next=$2->next;
                                    printsymbols(Symbolhead);deflag=1;lhead=NULL;nlbindval=bindval;lbindval=1;

                                    }
      | DECL ENDDECL  {printf(" y5 ");Symbolhead=NULL;lhead=NULL;nlbindval=bindval;lbindval=1;
                        fprintf(outputfile,"CALL L0\nINT 10\n");}
      | {printf(" global ");}
      ;
GDeclList : GDeclList GDecl {printf(" y6 ");$$=concatid($1,$2);bindval++;}
      | GDecl {printf(" y7 ");$$=$1;bindval++;}
      ;
GDecl : TypeName GidList SEMCL {printf(" y8 ");
                                updatetypelist($2,$1);
                                if($1==NULL)
                                {
                                  updatectypelist($2,Ghold);
                                }$$=$2;}
      ;
GidList : GidList COMMA GID {printf(" y9 ");$$=concatid($1,$3);}
      | GID {printf(" y10 ");$$=$1;}
      ;
GID : ID LP ParamList RP {printf(" y11 ");$1->paramlist=$3;$$=$1;}
      | ID LSB NUP RSB {printf(" y12 ");sizeupdate($1,$3);$$=$1;}
      | ID {printf(" y13 ");$$=$1;}
      ;


FdefBlock : FdefBlock Fdef {printf(" y14 ");lhead=NULL;lbindval=1;}
      | Fdef {printf(" y15 ");lhead=NULL;lbindval=1;}
      ;


MainBlock : TypeName MAIN LP RP LCB LdeclBlock Body RCB {printf(" y16 ");int l=0;
                                  fprintf(outputfile,"L%d:\n",l);
                                  ml=1;
                                  strcpy(currentfname,"main");
                                  int i;
                                  for(i=0;i<bindval;i++)
                                    fprintf(outputfile,"PUSH R0\n");

                                  generate($7);

                                  fprintf(outputfile,"L%d:\n",ml);
                                  lpop();

                                  for(int j=i;j>0;j--)
                                    fprintf(outputfile,"POP R0\n");

                                  fprintf(outputfile,"RET\n");
                                  l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);}
      ;
Fdef : TypeName ID LP ParamList RP LCB LdeclBlock Body RCB {printf(" y17 ");
                                  if(classflag==0)
                                  {
                                  int l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);
                                  struct Gsymbol *gn;
                                  gn=lookup($2->name);
                                  gn->binding=l;
                                  l=getlabel();
                                  strcpy(currentfname,$2->name);

                                  generate($8);

                                  fprintf(outputfile,"L%d:\n",l);
                                  lpop();
                                  fprintf(outputfile,"RET\n");
                                  l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);
                                  resetreg();
                                  }
                                  else
                                  {

                                  struct Memberfunlist *mem;
                                  mem=ClassMlookup(Cptr,$2->name);

                                  int l=getlabel();
                                  mem->flabel=l;
                                  fprintf(outputfile,"L%d:\n",l);
                                  l=getlabel();
                                  strcpy(currentfname,$2->name);

                                  generate($8);

                                  fprintf(outputfile,"L%d:\n",l);
                                  lpop();
                                  fprintf(outputfile,"RET\n");
                                  l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);
                                  resetreg();
                                  }lhead=NULL;lbindval=1;}
      ;


ParamList : ParamList COMMA Param {printf(" y18 ");$$=concatpid($1,$3);}
      | Param {printf(" y19 ");$$=$1;}
      | {$$=NULL;lhead=NULL;}
      ;
Param : TypeName ID {printf(" y20 ");
                      $$=makepnode($2->name,$1,0);

                        makelocalentry($$,0-nlbindval);nlbindval--;
                      }
      ;


LdeclBlock : DECL LDecList ENDDECL {printf(" y23 ");printlsymbols($2);}
      | DECL ENDDECL {printf(" y24 ");lhead=NULL;}
      | {$$=NULL;}
      ;
LDecList : LDecList LDecl {printf(" y25 ");$$=lhead;}
      | LDecl {printf(" y26 ");$$=$1;}
      ;
LDecl : TypeName IdList SEMCL {printf(" y27 ");updateltypelist($2,$1);$$=lhead;}
      ;
IdList : IdList COMMA ID  {printf(" y28 ");linstall($3->name,NULL,lbindval);lbindval++;$$=lhead;}
      | ID {printf(" y29 ");linstall($1->name,NULL,lbindval);lbindval++;$$=lhead;}
      ;
ArgList : ArgList COMMA expr {printf(" y30 ");$1->Arglist=$3;}
      | expr {printf(" y31 ");$$=$1;}
      | {$$=NULL;}
      ;


Body : BEGN Slist END {printf(" y32 ");generate_flag=0;$$=$2;}
      | BEGN END  {printf(" y33 ");$$=NULL;}
      ;
Slist : Slist Stmt {printf(" y34 ");$$=connector($1,$2);}
      | Stmt {printf(" y35 ");$$=$1;}
      ;
Stmt : InputStmt {printf(" y36 ");$$=$1;}
      | OutputStmt {printf(" y37 ");$$=$1;}
      | AsgStmt {printf(" y38 ");$$=$1;}
      | IfStmt {printf(" y39 ");$$=$1;}
      | WhileStmt {printf(" y40 ");$$=$1;}
      | BreakStmt {printf(" y41 ");$$=$1;}
      | ContinueStmt {printf(" y42 ");$$=$1;}
      | ReturnStmt {printf(" yr ");$$=$1;}
      | AllocStmt {printf(" n11 ");$$=$1;}
      | FreeStmt {printf(" n12 ");$$=$1;}
      | NewStmt {printf(" c16 ");$$=$1;}
      | DeleteStmt {printf(" c17 ");$$=$1;}
      ;
InputStmt : READ LP expr RP SEMCL {printf(" y43 ");$$=Inode($3);}
      ;
OutputStmt : WRITE LP expr RP SEMCL {printf(" y44 ");$$=Onode($3);}
      ;
AsgStmt : ID EQUAL expr SEMCL {printf(" y45 ");
                               struct tnode *t;
                               struct Gsymbol *gt;
                               struct Lsymbol *lt;
                               lt=llookup($1->name);
                               if(lt==NULL)
                                 gt=lookup($1->name);
                               else
                                 gt=NULL;
                               t=varnode($1->name,lt,gt);
                               $$=opnode('=',t,$3);}
      | FIELD EQUAL expr SEMCL {printf(" n13 ");$$=opnode('=',$1,$3);}
      ;
IfStmt : IF LP E RP THEN Slist ELSE Slist ENDIF SEMCL {printf(" y46 ");struct tnode *t;
        t=connector($6,$8);$$=ifelsenode($3,t);}
      | IF LP E RP THEN Slist ENDIF SEMCL {printf(" y47 ");$$=ifnode($3,$6);}
      ;
WhileStmt : WHILE LP E RP DO Slist ENDWHILE SEMCL {printf(" y48 ");$$=whilenode($3,$6);}
      ;
BreakStmt : BREAK SEMCL {printf(" y49 ");$$=breaknode();}
      ;
ContinueStmt : CONTINUE SEMCL {printf(" y50 ");$$=continuenode();}
      ;
ReturnStmt : RETURN expr SEMCL {$$=retnode($2);}
      | RETURN SEMCL {$$=retnode(NULL);}
      ;
AllocStmt : ID EQUAL ALLOC LP RP SEMCL {printf(" n14 ");struct tnode *t;
                                        struct Gsymbol *gt;
                                        struct Lsymbol *lt;
                                        lt=llookup($1->name);
                                        if(lt==NULL)
                                          gt=lookup($1->name);
                                        else
                                          gt=NULL;
                                        t=varnode($1->name,lt,gt);$$=allocnode(t);}
      | FIELD EQUAL ALLOC LP RP SEMCL {printf(" n15 ");$$=allocnode($1);}
      ;
FreeStmt : FREE LP ID RP SEMCL {printf(" n16 ");
                                struct tnode *t;
                                struct Gsymbol *gt;
                                struct Lsymbol *lt;
                                lt=llookup($3->name);
                                if(lt==NULL)
                                  gt=lookup($3->name);
                                else
                                  gt=NULL;
                                t=varnode($3->name,lt,gt);$$=freenode(t);}
      | FREE LP FIELD RP SEMCL {printf(" n17 ");$$=freenode($3);}
      ;
NewStmt : ID EQUAL NEW LP ID RP SEMCL {printf(" c18 ");struct tnode *t1,*t2;
                                        struct Gsymbol *gt;
                                        struct Lsymbol *lt;
                                        lt=llookup($1->name);
                                        if(lt==NULL)
                                          gt=lookup($1->name);
                                        else
                                          gt=NULL;
                                        t1=varnode($1->name,lt,gt);
                                        lt=llookup($5->name);
                                        if(lt==NULL)
                                          gt=lookup($5->name);
                                        else
                                          gt=NULL;
                                        t2=varnode($5->name,lt,gt);
                                        $$=newnode(t1,t2);}
      | FIELD EQUAL NEW LP ID RP SEMCL {printf(" c19 ");struct tnode *t;
                                        struct Gsymbol *gt;
                                        struct Lsymbol *lt;
                                        lt=llookup($5->name);
                                        if(lt==NULL)
                                          gt=lookup($5->name);
                                        else
                                          gt=NULL;
                                        t=varnode($5->name,lt,gt);
                                        $$=newnode($1,t);}
      ;
DeleteStmt : DELETE LP FIELD RP SEMCL {printf(" c20 ");
                                        $$=deletenode($3);}
      ;


FIELD : ID DOT ID {printf(" n18 ");
                    struct tnode *t;
                    struct Gsymbol *gt;
                    struct Lsymbol *lt;
                    struct Typetable *tp;
                    lt=llookup($1->name);
                    if(lt==NULL)
                    {
                      gt=lookup($1->name);
                      tp=gt->type;
                    }
                    else
                    {
                      tp=lt->type;
                      gt=NULL;
                    }
                    t=varnode($1->name,lt,gt);
                    t->type=tp;
                    $$=fldnode($3->name,t);
                    $$->type=getfieldtype($3->name,tp);
                    }
      | FIELD DOT ID {printf(" n19 ");
                      $$=fldnode($3->name,$1);
                      $$->type=getfieldtype($3->name,$1->type);
                      }
      | SELF DOT ID {printf(" c21 ");struct tnode *s;
                      s=selfnode();
                      $$=fldnode($3->name,s);
                      struct Typetable *tp;
                      struct Fieldlist *fl;
                      fl=ClassFlookup(Cptr,$3->name);
                      tp=fl->type;
                      $$->type=tp;}
      ;

FieldFuntion : SELF DOT ID LP ArgList RP {printf(" c22 ");struct tnode *s,*t;
                                          s=selfnode();
                                          struct Gsymbol *gt;
                                          struct Lsymbol *lt;
                                          lt=llookup($3->name);
                                          if(lt==NULL)
                                            gt=lookup($3->name);
                                          else
                                            gt=NULL;
                                          t=varnode($3->name,lt,gt);
                                          $$=fieldfunnode(s,t,$5);}
      | ID DOT ID LP ArgList RP {printf(" c23 ");
                                  struct tnode *t1,*t2;
                                  struct Gsymbol *gt;
                                  struct Lsymbol *lt;
                                  lt=llookup($1->name);
                                  if(lt==NULL)
                                    gt=lookup($1->name);
                                  else
                                    gt=NULL;
                                  t1=varnode($1->name,lt,gt);
                                  lt=llookup($3->name);
                                  if(lt==NULL)
                                    gt=lookup($3->name);
                                  else
                                    gt=NULL;
                                  t2=varnode($3->name,lt,gt);
                                  $$=fieldfunnode(t1,t2,$5);
                                  }
      | FIELD DOT ID LP ArgList RP {printf(" c24 ");
                                    struct tnode *t;
                                    struct Gsymbol *gt;
                                    struct Lsymbol *lt;
                                    lt=llookup($3->name);
                                    if(lt==NULL)
                                      gt=lookup($3->name);
                                    else
                                      gt=NULL;
                                    t=varnode($3->name,lt,gt);
                                    $$=fieldfunnode($1,t,$5);}
      ;


E : expr LT expr {printf(" y51 ");$$=relnode("<",$1,$3);}
      | expr GT expr {printf(" y52 ");$$=relnode(">",$1,$3);}
      | expr LT EQUAL expr {printf(" y53 ");$$=relnode("<=",$1,$4);}
      | expr GT EQUAL expr {printf(" y54 ");$$=relnode(">=",$1,$4);}
      | expr NOT EQUAL expr {printf(" y55 ");$$=relnode("!=",$1,$4);}
      | expr EQUAL EQUAL expr {printf(" y56 ");$$=relnode("==",$1,$4);}
      ;
expr : expr PLUS expr   {printf(" y57 ");$$=opnode('+',$1,$3);}
      | expr MUL expr   {printf(" y58 ");$$=opnode('*',$1,$3);}
      | expr MINUS expr {printf(" y59 ");$$=opnode('-',$1,$3);}
      | expr DIV expr   {printf(" y60 ");$$=opnode('/',$1,$3);}
      | expr MOD expr   {printf(" y60.1 ");$$=opnode('%',$1,$3);}
      | LP expr RP   {printf(" y61 ");$$=$2;}
      | NUM            {printf(" y62 ");$$=$1;}
      | STRING        {printf(" y63 ");$$=$1;}
      | FIELD {printf(" n20 ");$$=$1;}
      | FieldFuntion {printf(" c25 ");$$=$1;}
      | INIT LP RP {printf(" n21 ");$$=$1;}
      | NUL {printf(" n22 ");$$=NULL;}
      | ID          {printf(" y64 ");
                      struct Lsymbol *lt;
                      struct Gsymbol *gt;
                      lt=llookup($1->name);
                      if(lt==NULL)
                        gt=lookup($1->name);
                      else
                        gt=NULL;
                      if(lt==NULL&&gt==NULL)
                        printf(" \\no entry found//");
                      $$=varnode($1->name ,lt ,gt);}
      | ID LP ArgList RP {printf(" y66 ");
                          struct Lsymbol *lt;
                          struct Gsymbol *gt;
                          lt=llookup($1->name);
                          if(lt==NULL)
                            gt=lookup($1->name);
                          else
                            gt=NULL;
                          $$=funnode($1->name ,lt ,gt ,$3);}
      ;

%%

int yyerror(char const *s)
{
  printf("yyerror %s",s);
}
int main()
{
  loopflag[0]=0;
  lhead=NULL;
  ci=0;
  outputfile=fopen("input.xsm","w");
  Reg=(struct regpool *)malloc(sizeof(struct regpool));
  Reg->reg=-1;
  Reg->label=1;
  fprintf(outputfile,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nMOV SP,4095\nMOV BP,4096\nPUSH R0\n",0,2056,0,0,0,0,0,0);
  inp();
  yyparse();
  return 0;
}
