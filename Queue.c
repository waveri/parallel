#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

typedef struct {
    int arr[SIZE];
    int front;
    int rear;
} Queue;
void initialize(Queue *queue){
    queue->front=-1;
    queue->rear=-1;
}
void enqueue(Queue *queue,int x){
    if(queue->rear==SIZE-1){
        printf("overflow");
    }
    else if(queue->front==-1 && queue->rear==-1){
        queue->front=queue->rear=0;
        queue->arr[queue->rear]=x;
    }
    else{
        queue->arr[++queue->rear]=x;
    }
}
int dequeue(Queue *queue){
    if(queue->front==-1 && queue->rear==-1){
        printf("underflow");
    }
    else if(queue->front==queue->rear){
        queue->front=queue->rear=-1;
    }
    else{
        return queue->arr[queue->front++];
    }
}
void traverse(Queue *queue){
    if(queue->front==-1 && queue->rear==-1){
        printf("no items to display");
    }
    else{
        for(int i=queue->front;i<queue->rear+1;i++){
            printf("%d \n",queue->arr[i]);
        }
    }
}
int peek(Queue *queue){
    if(queue->front==-1 && queue->rear==-1){
        printf("no items in Queue");
    }
    else{
        return queue->arr[queue->front];
    }
}
bool is_Empty(Queue *queue){
    return (queue->front==queue->rear);
}
bool is_Full(Queue *queue){
    return (queue->front!=queue->rear);
}

int main(){
    Queue queue;
    initialize(&queue);
    enqueue(&queue,12);
    enqueue(&queue,14);
    dequeue(&queue);
    peek(&queue);
    traverse(&queue);
}