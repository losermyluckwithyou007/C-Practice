#include<iostream>

struct node{

    int data;
    struct node *next;

}*first=NULL;

void create(int A[],int n){

    int i; 
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for( i=1;i<n;i++){
    t=(struct node*)malloc(sizeof(struct node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
    }

}
void display(struct node *p){

    printf("Display All Element\n");

    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
void Rdisplay(struct node *p){

    while(p){
        printf("\n%d ",p->data);
        return Rdisplay(p->next);
    }
}
int count(struct node *p){

    int n=0;
    while(p){
        n++;
        p=p->next;
    }
    return n;
}

int sum(struct node *p){

    int x=0;
    while(p){
        x+=p->data;
        p=p->next;
    }
    return x;
}
int max(struct node *p){

    int max=INT32_MIN;
    while (p)
    {
        if(max<p->data){
            max=p->data;
        }
        p=p->next;
    }
    return max;
    
}
int search(node *p,int key){

    while(p!=NULL){

        if(key==p->data){
        return (p->data);
        }
        p=p->next;
    }
    return -1;
}

int insert(node *p,int index,int x){

    if(index==1){
        node *t=new node;
        t->data=x;
        t->next=first;
        first=t;
    }
    else
    {
        node *t=new node;
        t->data=x;
        p=first;
        for(int i=0;i<index-2;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
    return 0;
}

void SortedInsert(node *p,int x){

    struct node *q=NULL;
    
    node *t=new node;
    t->data=x;
    t->next=NULL;
    if(first==NULL){
        first=t;
    }
    else{
        while(p && p->data < x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
        t->next=q->next;
        q->next=t;
        }
    }
}

int main(){

    int A[]={4,2,10,4,5};
    create(A,5);
    display(first);
    printf("\nCount = %d ",count(first));
    printf("\nSum = %d ",sum(first));
    printf("\nmax = %d ",max(first));
    printf("\nKey found = %d ",search(first,10));
    insert(first,1,20);
    insert(first,5,50);

    SortedInsert(first,60);

    Rdisplay(first);
    return 0;
    
}