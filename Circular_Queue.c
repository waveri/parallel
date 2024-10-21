#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

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
    if(queue->front==-1 && queue->rear==-1){
        queue->front=queue->rear=0;
        queue->arr[queue->rear]=x;
    }
    else if ((queue->rear+1)%SIZE==queue->front)
    {
        printf("queue is full");
    }
    else{
        queue->rear=(queue->rear+1)%SIZE;
        queue->arr[queue->rear]=x;
    }
}
int dequeue(Queue *queue){
    if(queue->front==-1 && queue->rear==-1){
        printf("queue is empty");
    }
    else if (queue->front==queue->rear)
    {
        queue->front=queue->rear=-1;
    }
    else{
        int popped_val=queue->arr[queue->front];
        queue->front=(queue->front+1)%SIZE;
        return popped_val;
    }
}
void traverse(Queue *queue){
    if(queue->front==-1 && queue->rear==-1){
        printf("queue is empty");
    }
    else{
        int i=queue->front;
        while (i != queue->rear) {
            printf("%d ", queue->arr[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n",queue->arr[queue->rear]);
    }
}
int peek(Queue *queue){
    if(queue->front==-1 && queue->rear==-1){
        printf("queue is empty");
        return 0;
    }
    else{
        return queue->arr[queue->front];
    }
}

int main(){
    Queue queue;
    initialize(&queue);
    enqueue(&queue,12);
    enqueue(&queue,13);
    enqueue(&queue,14);
    printf("%d\n",dequeue(&queue));
    enqueue(&queue,15);
    enqueue(&queue,16);
    enqueue(&queue,17);
    printf("%d\n",dequeue(&queue));
    enqueue(&queue,18);
    traverse(&queue);
    printf("%d",peek(&queue));
}