//RA 220407 Lindon Jonathan S S P Monroe
//12-heapsort

struct heap{
    int vsize,hsize,*v;
}; 
typedef struct heap heap;
int create(heap *A);
int heapsort(heap *A);
int max_heapify(heap *A);