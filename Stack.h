#include<iostream>
#include "Queue.h"
using namespace std;

struct stack{
    int size;
    int top;
    struct node **S;

};

void createStack(struct stack *st){
    printf("\nEnter Size of Stack\n");
    scanf("%d",&st->size);
    st->S=(node **)malloc(st->size*sizeof(node *));
    st->top=-1;
}

void push(struct stack *st,struct node *x){

    if(st->top==st->size-1){
        printf("Stack is Overflow\n");
    }
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

struct node *pop(struct stack *st){

    struct node *x=NULL;

    if(st->top==-1){
        printf("Stack is Empty\n");
    }
    else{
        x=st->S[st->top--];
    }
    return x;
}
int isEmpty(stack *p){

    if(p->top=-1){
        return true;
    }
    return false;
    
}