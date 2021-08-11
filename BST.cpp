#include<stdio.h>
#include<iostream>
#include <stack>

using namespace std;

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;

void insert(int key){
    struct node *t=root;
    struct node *r,*p;

    if(root==NULL){
        p=new node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return ;
    }

    while(t!=NULL){
        
        r=t;
        if(key < t->data){
            t=t->lchild;
        }
        else if(key > t->data){
            t=t->rchild;
        }
        else
            return ;
    }
    p=new node;
    p->data=key;
    p->lchild=p->rchild=NULL;

    if(key < r->data){
        r->lchild=p;
    }
    else  r->rchild=p;        
    
}

void inOrder(struct node *p){

    if(p){
        inOrder(p->lchild);
        printf("%d ",p->data);
        inOrder(p->rchild);
    }
} 

void preOrder(struct node *p){

    if(p){
        printf("%d ",p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
} 

void postOrder(struct node *p){

    if(p){
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ",p->data);
        
    }
}
struct node *search(int key){
    struct node *t=root;

    while(t!=NULL){
        if(key==t->data)
        return t;

        else if(key <t->data)
        t=t->lchild;
        
        else
        t=t->rchild;
    }
    return NULL;
}

int Height(struct node *p){
    
    int x,y;
    
    if(p==NULL)
    return 0;

    x=Height(p->lchild);
    y=Height(p->rchild);

    return x>y?x+1:y+1;

}

struct node *InPre(struct node *p){

    while(p && p->rchild!=NULL){
        p=p->rchild;
    }
    return p;
}

struct node *InSucc(struct node *p){

    while(p && p->lchild!=NULL){
        p=p->lchild;
    }
    return p;

}

struct node *Delete(struct node *p,int key){
    struct node *q;

    if(p==NULL)
    return NULL;

    if(p->lchild==NULL && p->rchild==NULL){
        if(p==root)
        root=NULL;
        free(p);
        return NULL;
    }
    if(key < p->data){

        p->lchild=Delete(p->lchild,key);

    }
    else if(key > p->data){
        p->rchild=Delete(p->rchild,key);
    }
    else{
        if(Height(p->lchild) > Height(p->rchild)){
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,key);
        }
        else{
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,key);
        }

        return p;
    }
    return NULL;
}

struct node *Rinsert(struct node *p,int key){

    struct node *t=NULL;

    if(p==NULL){
        t=new node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }

    if(key < p->data)
    p->lchild=Rinsert(p->lchild,key);
    
    else if(key > p->data)
    p->rchild=Rinsert(p->rchild,key);
    
    return p;
}


void createPre(int Pre[],int n){
    //Create new Root
    int i=0;
    root=new node;
    root->data=Pre[i++];
    root->lchild=root->rchild=NULL;
    //Iterate Step
    struct node *t,*p;
    p=root;
    stack<node*> stk;
    
    while(i<n){
        if(Pre[i] < p->data){
            t=new node;
            t->data=Pre[i++];
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            stk.push(p);
            p=t;
        }
        else {
            if(Pre[i] > p->data && Pre[i] < stk.empty() ? 32767 : stk.top()->data){
                t=new node;
                t->data=Pre[i++];
                t->lchild=p->rchild=NULL;
                p->rchild=t;
                p=t;
            }
            else{
                p=stk.top();
                stk.pop();
            }
        }
    }
}

int main(){

    int Pre[]={30,20,10,15,25,40,50,45};
    int n=sizeof(Pre)/sizeof(Pre[0]);

    // insert(9);
    // insert(15);
    // insert(5);
    // insert(20);
    // insert(16);
    // insert(8);
    // insert(12);
    // insert(3);
    // insert(6);
    // Rinsert(root,10);
    // Delete(root,3);

    createPre(Pre, n);
    printf("Inoder = ");
    inOrder(root);
    printf("\n");
    printf("preoder = ");
    preOrder(root);
    printf("\n");
    printf("postOrder = ");
    postOrder(root);
    printf("\n");

    printf("Key Search at address of this = %d ",search(20));
    printf("\n");



    return 0;
}