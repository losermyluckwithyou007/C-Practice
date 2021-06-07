#include<stdio.h>
using namespace std;

struct node{

    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
}*root=NULL;

int NodeHieght(struct node *p){

    int hL,hR;

    hL=p && p->lchild?p->lchild->height:0;
    hR=p && p->rchild?p->rchild->height:0;

    return hL>hR?hL+1:hR+1;
}

int BalanceFactor(struct node *p){

    int hL,hR;

    hL=p && p->lchild?p->lchild->height:0;
    hR=p && p->rchild?p->rchild->height:0;

    return hL-hR;
}

struct node *LL_Rotation(struct node *p){

    struct node *pl=p->lchild;
    struct node *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;
    
    p->height=NodeHieght(p);
    pl->height=NodeHieght(pl);

    if(root==p)
    root=pl;

    return pl;
}

struct node *LR_Rotation(struct node *p){
    return NULL;
}

struct node *RR_Rotation(struct node *p){
    return NULL;
}

struct node *RL_Rotation(struct node *p){
    return NULL;
}




struct node *Rinsert(struct node *p,int key){

    struct node *t=NULL;

    if(p==NULL){
        t=new node;
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if( key < p->data){
        p->lchild=Rinsert(p->lchild,key);
    }
    else if( key > p->data){
        p->rchild=Rinsert(p->rchild,key);
    }

    p->height=NodeHieght(p);

        if( BalanceFactor(p) == 2 && BalanceFactor(p->lchild)==1 ){
        return LL_Rotation(p);
    }
        else if( BalanceFactor(p) == 2 && BalanceFactor(p->lchild)==-1 ){
        return LR_Rotation(p);

    } 
        else if( BalanceFactor(p) == -2 && BalanceFactor(p->rchild)==-1 ){
        return RR_Rotation(p);

    }   
        else if( BalanceFactor(p) == -2 && BalanceFactor(p->rchild)==1 ){
        return RL_Rotation(p);
    }
    
    return p;
}

void Inorder(struct node *p){

    while(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

int main(){

    root=Rinsert(root,50);
    Rinsert(root,10);
    Rinsert(root,20);

    Inorder(root);
    
    return 0;
}