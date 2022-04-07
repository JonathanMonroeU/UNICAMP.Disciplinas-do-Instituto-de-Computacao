//RA  220407 Lindon Jonathan S S P Monroe
//07-dinamico
typedef struct{
int ini, fim,*vetor1,*vetor2,tam, tamtot;
}stru_array;

int insert_first(stru_array *v);
int remove_first(stru_array *v);
int print_first(stru_array *v);
int insert_last(stru_array *v);
int remove_last(stru_array *v);
int print_last(stru_array *v);
int is_empty(stru_array *v);