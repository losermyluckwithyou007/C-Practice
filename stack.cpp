#include<iostream>
using namespace std;

struct stack{
    int size;
    int top;
    int *S;

};

void create(struct stack *st){
    printf("\nEnter Size of Stack\n");
    scanf("%d",&st->size);
    st->S=(int *)malloc(st->size*sizeof(int));
    st->top=-1;
}

void push(struct stack *st,int x){

    if(st->top==st->size-1){
        printf("Stack is Overflow\n");
    }
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct stack *st){

    int x=-1;

    if(st->top==-1){
        printf("Stack is Empty\n");
    }
    else{
        x=st->S[st->top--];
    }
    return x;
}

void Display(struct stack st){

    for(int i=st.top;i>=0;i--){
        printf("%d ",st.S[i]);
    }
    printf("\n");
}
int max(struct stack st){

    int larg=INT32_MAX;

    for(int i=st.top;i>=0;i--){
        if(larg>st.S[i]){
            larg=st.S[i];
        }
    }
    return larg;
}
int main(){

    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    push(&st,60);
    printf("pop=%d \n",pop(&st));
    Display(st);
    printf("Max=%d\n",max(st));

    return 0;
}
