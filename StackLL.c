#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int data;
    struct Stack *next;
};

struct Stack *top=NULL;

void push(int value){
    struct Stack *NewNode=(struct Stack*)malloc(sizeof(struct Stack));

    NewNode->data=value;
    NewNode->next=top;
    top=NewNode;
}
int pop(){
    int popped_value=top->data;
    struct Stack *temp=top;
    top=top->next;
    free(temp);
    return popped_value;
}
void peek(){
    printf("%d \n", top->data);
}
int traverse(){
    struct Stack *current=top;
    while(current!=NULL){
        printf("%d \n",current->data);
        current=current->next;
    }
}
int is_Empty(){
    return top==NULL;
}

int main(){
    push(10);
    push(12);
    pop();
    peek();
    traverse();
}