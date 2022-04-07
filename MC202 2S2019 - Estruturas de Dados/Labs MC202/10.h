//RA 220407 Lindon Jonathan S S P Monroe
//10-bst

struct node{
    int key;
    struct node *left, *right, *next, *pai; 
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

//SO FAR, IT'S EQUIVALENT TO THE LAB 9

int remover (int x,node** root);
node* minimo(node** root);
node* maximo(node** root);
int predecessor(int x, node** root);
int sucessor(int x, node** root);
int buscar_intervalo(int x, int y,node** root);
void buscar_intervalo2(int x, int y, node *root);

