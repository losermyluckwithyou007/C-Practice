#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *lchild;
    int data;
    struct node *rchild;     
};
struct Queue{
    int size;
    int front;
    int rear;
    node **Q;
};
void enqueue(Queue *q,node *x){
        
    if((q->rear+1)%q->size==q->front){
        printf("Queue is full");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x; 
    } 
}

struct node * dequeue( Queue *q){
    node* x=NULL;

    if(q->front==q->rear){
        printf("Queue is empty");
    }
    else{
        q->front=(q->front + 1)%q->size;
        x=q->Q[q->front];
        
    }
    return x;
}
void create(struct Queue *q,int x){

    q->size=x;
    q->Q=(struct node**)malloc(q->size*sizeof(struct node *));
    q->front=q->rear=0;
}
int isEmpty(struct Queue q){

    return q.front==q.rear;
}