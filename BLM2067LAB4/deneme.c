#include<stdio.h>
#include<stdlib.h>
int top=0,size=2;
int *dizi;
int pop(){
    return dizi[--top];
}
void push(int id){
    if(top>=size){
        int *newarr;
        size*=2;
        newarr = (int*)malloc(sizeof(int)*size);
        for(int i=0;i<top;i++){
            newarr[i] = dizi[i];
        }
        free(dizi);
        dizi = newarr;
    }
    dizi[top++] = id;
    
}
void print(){
    for(int i=0;i<top;i++){
        printf("%d ",dizi[i]);
    }
    printf("boyut: %d\n",size);
}
int main(){
    dizi = (int*)malloc(sizeof(int)*size);
    push(10);
    push(20);
    printf("popped %d\n",pop());
    print();
    push(30);
    print();
    push(40);
    print();
    return 0;
}