typedef struct lnode
{
  int label;
  int labeloc;
  struct lnode *next;
}lnode;

struct lnode * labelentry(int labelno,int address);
void print_line(char *text,int count);
int getno(char a,char b);
int inlabel(int labelno,int address);
int getadd(struct lnode *head,int labelno);
void printd(struct lnode *head);
int isheader(char *yytext);

FILE * outputfile;
struct lnode *head=NULL;
