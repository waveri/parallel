#include <stdio.h>
#include <stdbool.h>

#define SIZE 100
typedef struct{
    int arr[SIZE];
    int top;
}Stack;

void initialize(Stack *stack){
    stack->top=-1;
}
void push(Stack *stack, int value){
    if(stack->top==SIZE-1){
        printf("stack overflow");
        return;
    }
    else{
        stack->arr[++stack->top]=value;
    }
}
int pop(Stack *stack){
    if(stack->top==-1){
        printf("stack underflow");
    }
    else{
        return stack->arr[stack->top--];
    }
}   
int peek (Stack *stack){  
    if (stack->top==-1){  
        printf("Stack is empty!\n");  
        return -1;
    }  
    return stack->arr[stack->top];  
}
void traverse(Stack *stack){
    for (int i = stack->top; i >= 0; i--) {
        printf("%d \n", stack->arr[i]);
    }
}
bool is_Full(Stack* stack){
    return stack->top==SIZE-1;
}
bool is_Empty(Stack* stack){
    return stack->top==-1;
}

int main(){
    Stack stack;
    initialize(&stack);
    push(&stack,10);
    push(&stack,90);
    traverse(&stack);
    printf("%s",is_Empty(&stack) ? "YES":"NO");
}