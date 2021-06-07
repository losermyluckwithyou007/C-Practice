#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
}*top=NULL;

void push(int x){
    node *t=new node;
    if(t==NULL){
        printf("Stack overflow");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
void Display(struct node *p){

    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}
int main(){
    struct node st;
    push(10);
    Display(&st);
}