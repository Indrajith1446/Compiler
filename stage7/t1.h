
typedef struct tnode
{
  int val;
  struct Typetable *type; //stores pointer to type
  char *nodetype;//information about leaf node like read write etc.
  char *varname;//name of the variable in case of variable node also stores operator type
  struct Gsymbol *Gentry;
  struct Lsymbol *Lentry;
  struct tnode *Arglist;
  struct tnode *left,*right;
}tnode;

typedef struct regpool
{
  int reg;
  int label;
}regpool;

typedef struct Gsymbol
{
  char * name;
  struct Typetable * type;
  struct Classtable * Ctype;
  int size;
  int binding;
  struct Paramstruct *paramlist;
  int flabel;
  struct tnode *  fbinding;
  struct Gsymbol *next;
}gnode;

typedef struct Lsymbol
{
  char *name;
  struct Typetable * type;
  int binding;
  struct Lsymbol *next;
}LNODE;

typedef struct Paramstruct
{
    char *name;
    struct Typetable * type;
    int binding;
    struct Paramstruct *next;
}pnode;

typedef struct Fieldlist
{
  char *name;
  int fieldindex;
  struct Typetable *type;
  struct Classtable *ctype;
  struct Fieldlist *next;
}fieldnode;

typedef struct Typetable
{
    char *name;
    int size;
    struct Fieldlist *fields;
    struct Typetable *next;
}typenode;

typedef struct Classtable
{
  char * name;
  struct Fieldlist *Memberfield;
  struct Memberfunlist *funlist;
  struct Classtable *parent;
  int classindex;
  int fieldcount;
  int methodcount;
  struct Classtable *next;
}ctnode;

typedef struct Memberfunlist
{
  char *name;
  struct Typetable *type;
  struct Paramstruct *paramlist;
  int functionposition;
  int flabel;
  struct Memberfunlist *next;
}memfunnode;

struct regpool * Reg;

struct Gsymbol * Symbolhead;

struct Gsymbol * node;

struct Gsymbol * tmpnode;

struct Gsymbol * tmoidnode;

struct Paramstruct * paramhead;

struct Lsymbol * lhead;

struct Lsymbol * lnode;

struct Typetable * Typenode;

struct Fieldlist * Fieldnode;

struct Classtable * Cptr;

struct Classtable * Classnode;

FILE *outputfile;

int loopflag[3];

int bindval;

int lbindval;

int nlbindval;

int ci;

int functionargflag;

int generate_flag;

int ml;

char * currentfname;

struct tnode * intnode(int val);

struct tnode * stringnode(char *word);

struct tnode * varnode(char *vname,struct Lsymbol *lentry,struct Gsymbol *gentry);

struct tnode * funnode(char *vname,struct Lsymbol *lentry,struct Gsymbol *gentry,struct tnode *Arglist);

struct tnode * Inode(struct tnode *l);

struct tnode * Onode(struct tnode *l);

struct tnode * connector(struct tnode *l,struct tnode *r);

struct tnode * fldnode(char *name,struct tnode *l);

struct tnode * opnode(char op,struct tnode *l,struct tnode *r);

struct tnode * relnode(char *op,struct tnode *l,struct tnode *r);

struct tnode * ifnode(struct tnode *l,struct tnode *r);

struct tnode * ifelsenode(struct tnode *l,struct tnode *r);

struct tnode * whilenode(struct tnode *l,struct tnode *r);

struct tnode * breaknode();

struct tnode * continuenode();

struct tnode * initnode();

struct tnode * retnode(struct tnode *l);

struct tnode * newnode(struct tnode *l,struct tnode *r);

struct tnode * deletenode(struct tnode *l);

struct tnode * fieldfunnode(struct tnode *l,struct tnode *r,struct tnode *arglist);

struct Gsymbol *lookup(char * name);

struct Lsymbol *llookup(char * name);

struct Gsymbol *makesymbolnode(char *name,struct Typetable * type,int size);

struct Lsymbol *makelnode(char *name,struct Typetable * type,int bind);

struct Paramstruct *makepnode(char *name,struct Typetable * type,int bind );

struct Typetable * maketypeentry(char *name,int size , struct Fieldlist *fields );

struct Typetable * gettype(char *name);

struct Fieldlist * makefieldnode(char *name,int index,struct Typetable *type);

struct Gsymbol * concatid(struct Gsymbol *h1,struct Gsymbol *h2);

struct Lsymbol * concatlid(struct Lsymbol *h1,struct Lsymbol *h2);

struct Classtable * Cinstall(char *name,char *parentname);

struct Classtable * makeclassnode(char *name,char *parentname);

struct Classtable * Clookup(char *name);

void ClassFinstall(struct Classtable *cptr, char *typename, char *name);

void ClassMinstall(struct Classtable *cptr, char *name, struct Typetable *type, struct Paramstruct *Paramlist);

void typetableistall(char *name,int size,struct Fieldlist *fields);

struct Fieldlist* ClassFlookup(struct Classtable* Ctype,char* Name);

struct Memberfunlist* ClassMlookup (struct Classtable* Ctype,char* Name);

void sizeupdate(struct Gsymbol *temp,int size);

void updatetype(struct Gsymbol *temp,struct Typetable * type);

void updatetypelist(struct Gsymbol *temp,struct Typetable *type);

void updatectypelist(struct Gsymbol *temp,struct Gsymbol *type);

void updateltypelist(struct Lsymbol *temp,struct Typetable *type);

void install(char *name,struct Typetable * type,int size);

void linstall(char *yytext,struct Typetable * type,int bind);

void finstall(char *name,struct Typetable * type,int bind);

void printsymbols(struct Gsymbol *head);

void printlsymbols(struct Lsymbol *head);

void printparam(struct Paramstruct *temp);

void fieldinstall(char *name , int index ,struct Typetable *type );

void lpop();

void initialisetype();

void printtype();

void printclass();

void printmemfield(struct Fieldlist *fld);

void printmemfun(struct Memberfunlist *mem);

struct Paramstruct * checkfor(struct Paramstruct * temp,char * yytext,struct Typetable * type);

int checkname(char * yytext);

int plook(char *name,struct Paramstruct * p);

int getfieldindex(char *name,struct Typetable *tbt);

struct Typetable * getfieldtype(char *name,struct Typetable *tbt);

int inp();

int generate(struct tnode *t);

int getfreereg();

void releasereg();

void resetreg();

int getlabel();

int r_val(int loc,char t);

int p_val(int reg);

int p_initialize();

int p_alloc(int size);

int p_free(int pointer);

int loc_for_name(char var);

//regvalues from a-z 4096-4121
