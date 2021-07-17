
typedef struct tnode
{
  int val;
  char *op;
  struct tnode *left,*right;
}tnode;

typedef struct regpool
{
  int reg;
}regpool;

struct regpool * Reg;

FILE *outputfile;

struct tnode * leafnode(int val);

struct tnode * opnode(char op,struct tnode *l,struct tnode *r);

int generate(struct tnode *t);

int getfreereg();

void releasereg();

int p_val(int val);
