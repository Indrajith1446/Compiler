
typedef struct tnode
{
  int val;
  int type; //0->integer
  char *nodetype;//information about leaf node like read write etc.
  char *varname;//name of the variable in case of variable node also stores operator type
  struct Gsymbol *Gentry;
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
  struct Gsymbol *next;
}gnode;

struct regpool * Reg;

struct Gsymbol * Symbolhead;

FILE *outputfile;

int loopflag[3];

int bindval;

struct tnode * intnode(int val);

struct tnode * varnode(char *vname);

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

struct Gsymbol *lookup(char * name);

struct Gsymbol *makesymbolnode(char *name,int type,int size);

void install(char *name,int type,int size);

void printsymbols(struct Gsymbol *head);

int inp();

int generate(struct tnode *t);

int getfreereg();

void releasereg();

int getlabel();

int r_val(int loc);

int p_val(int reg);

int loc_for_name(char var);

//regvalues from a-z 4096-4121
