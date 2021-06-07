#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){

    printf("\n\nDisplay All ElEMENT\n\n");
    for(int i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);

}
int Add(struct Array *arr,int x){

    arr->A[arr->length]=x;
    arr->length++;

    return 0;
}

int insert(struct Array *arr,int index,int x){

    for(int i=arr->length;i>index;i--)
    arr->A[i]=arr->A[i-1];

    arr->A[index]=x;
    arr->length++;

    return 0;

}

int Delete(struct Array *arr,int index){

    for(int i=index;i<arr->length-1;i++)
    arr->A[i]=arr->A[i+1];

    arr->length--;

    return 0;
}

int main(){
    struct Array arr={{1,2,3,4,5,6},10,6};
    // int n,i;
    // printf("\nEnter size of an element\n");
    // scanf("%d",&arr.size);
    // arr.A=(int *)malloc(arr.size*sizeof(int));
    // arr.length=0;

    // printf("\nEnter number of numbers\n");
    // scanf("%d",&n);

    // printf("\nEnter all element\n");
    // for(i=0;i<n;i++)
    // scanf("%d",&arr.A[i]);

    // arr.length=n;
    Display(arr);
    Add(&arr,10);
    Display(arr);
    insert(&arr,4,20);
    Display(arr);
    Delete(&arr,1);
    Display(arr);

    return 0;
}