#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int data;
    struct Queue *next;
};

struct Queue *front=NULL;
struct Queue *rear=NULL;

void enqueue(int value){
    struct Queue *Newnode=(struct Queue*)malloc(sizeof(struct Queue));
    Newnode->data=value;
    if(rear==NULL){
        front=rear=Newnode;
        rear->next=front;
    }
    else{
        rear->next=Newnode;
        rear=Newnode;
        rear->next = front;
    }
}
int dequeue(){
    struct Queue *temp=front;
    int popped_val=front->data;
    if(front==NULL){
        printf("queue is empty");
        return 0;
    }
    else if (front==rear)
    {
        front=rear=NULL;
        free(temp);
        return popped_val;
    }
    else{
        front=front->next;
        rear->next=front;
        free(temp);
        return popped_val;
    }
}
void traverse(){
    if(front==NULL){
        printf("queue is empty");
    }
    else{
        struct Queue *current=front;
        do {
            printf("%d ", current->data);
            current = current->next;
        } while(current != front);
    }
}
int peek(){
    if(front==NULL){
        printf("queue is empty");
    }
    else{
        return front->data;
    }
}

int main(){
    enqueue(23);
    enqueue(24);
    enqueue(25);
    printf("%d\n",peek());
    traverse();
}