//RA  220407 Lindon Jonathan S S P Monroe
//08-lista-sim

struct node{
    int position;
    double value;
    struct node* A, *B;
};
typedef struct node node;

int inserir(node **head,int *started);
int imprimir(node **head,int* started);
int reverter(node **head,int* started);
int liberar(node ** head, int *started);