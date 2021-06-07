#include<iostream>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(Queue *q,int x){

    if(q->rear==q->size-1){
        printf("Queue is full");
    }
    else{
        q->rear++;
        q->Q[q->rear]=x; 
    } 
}

void Display(Queue q){

    printf("\n Display\n");

    for(int i=q.rear ; i > q.front ; i-- ){
        printf(" %d",q.Q[i]);
    }
}

int dequeue( Queue *q){
    int x=-1;

    if(q->front==q->rear){
        printf("Queue is empty");
    }
    else{
        q->front++;
        x=q->Q[q->front];
        
    }
    return x;
}
void create(struct Queue *q,int x){

    q->size=x;
    q->Q=(int *)malloc(q->size*sizeof(int));
    q->front=q->rear=-1;
}

int main(){

    struct Queue q;

    create(&q,6);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    printf("%d",dequeue(&q));
    Display(q);


    return 0;
}
