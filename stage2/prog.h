
typedef struct tnode
{
  int val;
  int type; //0->integer
  char *nodetype;//information about leaf node like read write etc.
  char *varname;//name of the variable in case of variable node also stores operator type
  struct tnode *left,*right;
}tnode;

typedef struct regpool
{
  int reg;
}regpool;

struct regpool * Reg;

FILE *outputfile;

struct tnode * intnode(int val);

struct tnode * varnode(char vname);

struct tnode * Inode(struct tnode *l);

struct tnode * Onode(struct tnode *l);

struct tnode * connector(struct tnode *l,struct tnode *r);

struct tnode * opnode(char op,struct tnode *l,struct tnode *r);

struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r);

int inp();

int generate(struct tnode *t);

int getfreereg();

void releasereg();

int r_val(char var);

int p_val(int reg);

int loc_for_name(char var);

//regvalues from a-z 4096-4121
