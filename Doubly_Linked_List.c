#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head=NULL;
struct Node *tail=NULL;

void insert_at_beginning(int value) {
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = value;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if (head == NULL) {
        // List is empty; new node becomes both the head and tail
        head = NewNode;
        tail = NewNode;
    } else {
        // Insert the new node at the beginning
        NewNode->next = head;
        head->prev = NewNode;
        head = NewNode;
    }
}
void insert_at_end(int value) {
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = value;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if (head == NULL) {
        // List is empty; new node becomes the head and tail
        head = NewNode;
        tail = NewNode;
    } else {
        // Add the new node at the end
        tail->next = NewNode;
        NewNode->prev = tail;
        tail = NewNode;
    }
}
void insert_at(int index, int value) {
    int length = get_length();
    if (index < 0 || index > length) {
        printf("Invalid Index\n");
        return;
    }

    if (index == 0) {
        // Insert at the beginning
        insert_at_beginning(value);
        return;
    }

    if (index == length) {
        // Insert at the end
        insert_at_end(value);
        return;
    }

    // Insert in the middle
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = value;

    struct Node *current = head;

    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    NewNode->next = current->next;
    NewNode->prev = current;
    current->next->prev = NewNode;
    current->next = NewNode;
}
void remove_at(int index) {
    int length = get_length();
    if (index < 0 || index >= length) {
        printf("Invalid Index\n");
        return;
    }

    struct Node *current = head;

    if (index == 0) {
        // Remove the first node
        if (head == tail) {
            free(head);
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
            free(current);
        }
        return;
    }

    if (index == length - 1) {
        // Remove the last node
        current = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(current);
        return;
    }

    // Remove a node in the middle
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}
void traverse(){
    struct Node *current=head;
    if(head==NULL){
        printf("linked list is empty");
    }

    while(current!=NULL){
            printf("%d \n",current->data);
            current=current->next;
    }
}
int get_length() {
    int count = 0;
    struct Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
int main(){
    insert_at_beginning(23);
    insert_at_beginning(12);
    insert_at_end(33);
    traverse();
}