//RA 220407 Lindon Jonathan S S P Monroe
//09-bst

struct node{
    int key;
    struct node *left, *right, *next; 
};
typedef struct node node;

struct queue{
    node *ini,*fim;
};
typedef struct queue queue;

int inserir(int x,node **root);
int buscar(int x,node **root);
void pre_ordem(node *root);
void em_ordem(node *root);
void pos_ordem(node *root);
void largura(node *root);
int enqueue(queue *f, node *root);
node* dequeue(queue *f);
void freetree(node *root);
