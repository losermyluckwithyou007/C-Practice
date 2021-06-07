#include<iostream>
using namespace std;

class node{
    public:
      node *lchild;
        int data;
      node *rchild;
};
class Queue{

    private:
        int size;
        int front;
        int rear;
        node **Q;
    public:
        Queue(int size);
        ~Queue();
        bool isEmpty();
        bool Full();
        void enqueue(node* x);
        node* dequeue();
};
Queue::Queue(int size){

    this->size=size;
    front=rear=-1;
    Q=new node * [size];

}
Queue::~Queue(){
    delete [] Q;
}
bool Queue::isEmpty(){
    if(front==rear){
        return true;
    }
    return false;
}
bool Queue::Full(){

    if(rear==size-1){
        return true;
    }
    return false;

}
void Queue::enqueue(node* x){
    if(Full()){
        cout<<"Queue is overflow"<<endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }
}
node* Queue::dequeue(){
    node* x=nullptr;
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        front++;
        x=Q[front];
    }
    return x;
}

class Tree{

    private:
        node* root;

    public:
        Tree() {root=nullptr;}
        ~Tree();
        void createTree();
        void preOrder(){ preOrder(root);} 
        void preOrder(node* root);

};

Tree::~Tree(){
    
}

void Tree::createTree(){
    node *p,*t;
    int x;
    Queue q(25);
    root=new node;
    cout<<"Root value : ";
    cin>>x;
    root->data=x;
    root->lchild=nullptr;
    root->rchild=nullptr;
    q.enqueue(root);

    while(!q.isEmpty()){

        p=q.dequeue();

        cout<<"Enter the left-Child of "<<p->data<<" : "<<flush;
        cin>>x;
        if( x !=  -1){

            t=new node;
            t->data=x;
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->lchild=t;
            q.enqueue(t);
        }
        cout<<"Enter the right-Child of "<<p->data<<" : "<<flush;
        cin>>x;
        if( x != -1){

            t=new node;
            t->data=x;
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(node *p){
    if(p){
        cout<< p->data <<", "<<flush;
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

int main(){

    Tree t;

    t.createTree();
    cout<<"PreOrder :"<<flush;
    t.preOrder();
    return 0;
}