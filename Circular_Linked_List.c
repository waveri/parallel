#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void insert_at_beginning(int value){
    struct Node *NewNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node *current=head;
    NewNode->data=value;
    if(head==NULL){
        head=NewNode;
        NewNode->next=head;
    }
    else{
        while(current->next!=head){
        current=current->next;
    }
    current->next=NewNode;
    NewNode->next=head;
    head=NewNode;
    }
}

void insert_at_end(int value){
    struct Node *NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=value;
    struct Node *current=head;
    if(head==NULL){
        head=NewNode;
        NewNode->next=head;
    }
    else{
        while(current->next!=head){
            current=current->next;
        }
        current->next=NewNode;
        NewNode->next=head;
    }
}

void insert_at(int index,int value){
    int get_length();
    int a=get_length();
    if(index<0 || index>a){
        printf("invalid index input\n");
        return;
    }
    if(index==0){
        insert_at_beginning(value);
        return;
    }
    if(index==a){
        insert_at_end(value);
        return;
    }
    struct Node *current=head;
    for(int i=0;i<index-1;i++){
        current=current->next;
    }
    struct Node *NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=value;
    NewNode->next=current->next;
    current->next=NewNode;
}

int get_length() {
    if (head == NULL) {
        return 0;
    }

    int count = 1;
    struct Node *current = head;

    while (current->next != head) {
        count += 1;
        current = current->next;
    }

    return count;
}

void traverse(){
    struct Node *current=head;
    if(current==NULL){
        printf("empty linked list");
        return;
    }
    else{
        do{
            printf("%d \n",current->data);
            current=current->next;
        }while(current!=head);
    }
}

struct Node *search(int value){
    struct Node *current = head;
    if (head == NULL) {
        printf("Linked list is empty\n");
        return NULL;
    }

    do {
        if (current->data == value) {
            printf("%d is present\n", value);
            return current;
        }
        current = current->next;
    } while (current != head);

    printf("%d is not present\n", value);
    return NULL;
}

void remove_val(int value){
    struct Node *previous = head;
    struct Node *current = head->next;

    if(head == NULL){
        printf("Linked list is empty\n");
        return;
    }

    if(head->data == value){
        // Special case: head node is the node to be removed
        if(head->next == head){
            // Only one node in the list
            free(head);
            head = NULL;
        } else {
            // More than one node in the list
            while(current->next != head){
                current = current->next;
            }
            current->next = head->next;
            free(head);
            head = current->next;
        }
        return;
    }

    while(current != head){
        if(current->data == value){
            previous->next = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Element not found in the list\n");
}

void remove_at(int index){ //this function doesn't work correctly yet
    int get_length;
    int a=get_length;
    if(index<0 || index>=a){
        printf("invalid index input");
        return;
    }
    if(index==0){
        if (head == head->next) {  
            free(head);
            head = NULL;
            return;
        }
        struct Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = head->next;
        free(head);
        head = current->next;
        return;
    }
    struct Node *previous=head;
    struct Node *current=previous->next;
    for(int i=0;i<index-1;i++){
        previous = previous->next;
    }
    previous->next=current->next;
    free(current);
}

int main(){
    insert_at_beginning(12);
    insert_at_end(45);
    insert_at(1,2);
    insert_at(3,42);
    traverse();
}