#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    if(top == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    int popped_value=top->data;
    struct Stack *temp=top;
    top=top->next;
    free(temp);
    return popped_value;
}
void peek(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("%d \n", top->data);
}
int traverse(){
    if(top == NULL){
        printf("Stack is empty\n");
        return 0;
    }
    struct Stack *current=top;
    while(current!=NULL){
        printf("%d \n",current->data);
        current=current->next;
    }
}
bool is_Empty(){
    return top==NULL;
}
bool is_Full(){
    return top!=NULL;
}

int main(){
    push(10);
    push(12);
    pop();
    peek();
    traverse();
    pop();
    printf("Is stack empty? %s\n", is_Empty() ? "YES" : "NO");
    printf("Is stack full? %s\n", is_Full() ? "YES" : "NO");
}