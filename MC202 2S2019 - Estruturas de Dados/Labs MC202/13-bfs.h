//RA 220407 Lindon Jonathan S S P Monroe
//13-bfs
#include <stdio.h>
#include <stdlib.h> 

struct vert{
    int key,adjs, dist, ant, marked;
    struct vert *next;
};
typedef struct vert vert; 

struct vert2{
    int key;
    struct vert2 *next;
};
typedef struct vert2 vert2; 

struct queue{
    vert *ini,*fim;
};
typedef struct queue queue;

void bfs(vert *v, int *e);
int enqueue(queue *f,vert *p);
vert* dequeue(queue *f);