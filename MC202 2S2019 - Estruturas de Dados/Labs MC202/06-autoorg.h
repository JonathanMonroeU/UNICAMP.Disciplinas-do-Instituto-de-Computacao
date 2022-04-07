#ifndef AUTOORG
#define AUTOORG

//RA 220407 Lindon Jonathan S dos S P Monroe
struct node{
    int chave, contador;
    struct node* next;
};
typedef struct node node;

int create(int N,node **head);
int freelista(node **head);
int mtf(int R,int *acessos,node **head);
int tr(int R,int *acessos,node **head);
int count(int R,int *acessos,node **head);

#endif