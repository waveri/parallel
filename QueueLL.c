#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue{
    int data;
    struct Queue *next;
};

struct Queue *front=NULL;
struct Queue *rear=NULL;

void enqueue(int value){
    struct Queue *Newnode=(struct Queue*)malloc(sizeof(struct Queue));
    Newnode->data=value;
    Newnode->next=0;
    if(front==0 && rear==0){    //when queue is empty
        front=rear=Newnode;
    }
    else{
        rear->next=Newnode;     //when element already present, rear increments after rear.next
        rear=Newnode;
    }
}
int dequeue(){
    if(front==0 && rear==0){
        printf("queue is empty");
        return 0;
    }
    else{
        int popped_value=front->data;
        struct Queue *temp=front;
        front=front->next;
        free(temp);
        return popped_value;
    }
}
int traverse(){
    struct Queue *current;
    if(front==0 && rear==0){
        printf("Queue is empty");
        return 0;
    }
    else{
        current=front;
        while(current!=NULL){
            printf("%d",current->data);
            current=current->next;
        }
    }
}
void peek(){
    if(front==0 && rear==0){
        printf("queue is empty");
        return;
    }
    printf("%d",front->data);
}

int main(){
    enqueue(90);
    enqueue(91);
    dequeue();
    enqueue(23);
    enqueue(24);
    peek();
    traverse();
    return 0;
}