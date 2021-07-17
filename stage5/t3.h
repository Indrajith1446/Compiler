
typedef struct tnode
{
  int val;
  int type; //0->integer
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
  int type;
  int size;
  int binding;
  struct Paramstruct *paramlist;
  int flabel;
  struct Gsymbol *next;
}gnode;

typedef struct Lsymbol
{
  char *name;
  int type;
  int binding;
  struct Lsymbol *next;
}LNODE;

typedef struct Paramstruct
{
    char *name;
    int type;
    int binding;
    struct Paramstruct *next;
}pnode;

struct regpool * Reg;

struct Gsymbol * Symbolhead;

struct Gsymbol * node;

struct Gsymbol * tmpnode;

struct Paramstruct * paramhead;

struct Lsymbol * lhead;

struct Lsymbol * lnode;

FILE *outputfile;

int loopflag[3];

int bindval;

int lbindval;

int nlbindval;

int functionargflag;

int generate_flag;

int ml;

char * currentfname;

struct tnode * intnode(int val);

struct tnode * stringnode(char *word);

struct tnode * varnode(char *vname,struct Lsymbol *lentry,struct Gsymbol *gentry);

struct tnode * Inode(struct tnode *l);

struct tnode * Onode(struct tnode *l);

struct tnode * connector(struct tnode *l,struct tnode *r);

struct tnode * opnode(char op,struct tnode *l,struct tnode *r);

struct tnode * relnode(char *op,struct tnode *l,struct tnode *r);

struct tnode * ifnode(struct tnode *l,struct tnode *r);

struct tnode * ifelsenode(struct tnode *l,struct tnode *r);

struct tnode * whilenode(struct tnode *l,struct tnode *r);

struct tnode * breaknode();

struct tnode * continuenode();

struct tnode * retnode(struct tnode *l);

struct Gsymbol *lookup(char * name);

struct Lsymbol *llookup(char * name);

struct Gsymbol *makesymbolnode(char *name,int type,int size);

struct Lsymbol *makelnode(char *name,int type,int bind);

struct Paramstruct *makepnode(char *name,int type);

void sizeupdate(struct Gsymbol *temp,int size);

void updatetype(struct Gsymbol *temp,int type);

void install(char *name,int type,int size);

void linstall(char *yytext,int type,int bind);

void finstall(char *name,int vtype);

void printsymbols(struct Gsymbol *head);

void printlsymbols(struct Lsymbol *head);

void printparam(struct Paramstruct *temp);

void lpop();

struct Paramstruct * checkfor(struct Paramstruct * temp,char * yytext,int ptype);

int checkname(char * yytext);

int plook(char *name,struct Paramstruct * p);

int inp();

int generate(struct tnode *t);

int getfreereg();

void releasereg();

void resetreg();

int getlabel();

int r_val(int loc);

int p_val(int reg);

int loc_for_name(char var);

//regvalues from a-z 4096-4121
