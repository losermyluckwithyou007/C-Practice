#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
#include "Stack.h"
using namespace std;

struct node *root=NULL;

void TreeCreate(){
    struct node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    printf("\nEnter root value\n");
    scanf("%d",&x);
    root=(struct node *)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("Enter left child of %d = ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("Enter right child of %d = ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void preOrder(struct node *p){
    if(p){
        printf(" %d",p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
void iterativepreOder(node *t){

    struct stack *st;
    createStack(st);

    while(t!=NULL || !isEmpty(st)){
        if(t!=NULL){
            printf("%d ",t->data);
            push(st,t);
            t=t->lchild;
        }
        else{
            t=pop(st);
            t=t->rchild;
        }
    }


}


int main(){

    TreeCreate();
    preOrder(root);
    iterativepreOder(root);



    return 0;

}