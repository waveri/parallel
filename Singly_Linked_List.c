#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void insert_at_beginning(int value){
    struct Node *NewNode=(struct Node*)malloc(sizeof(struct Node));

    NewNode->data=value;
    NewNode->next=head;
    head=NewNode;
}

void insert_at_end(int value){
    struct Node *NewNode= (struct Node*)malloc(sizeof(struct Node));
    NewNode->data=value;
    NewNode->next=NULL;

    if(head==NULL){
        head=NewNode;
    }
    else{
        struct Node *current=head;
        while(current -> next!=NULL){
            current=current->next;
        }
        current->next=NewNode;
    }
}

void insert_at(int index, int value){
    int get_length();
    int length = get_length();
    if (index < 0 || index > length){
        printf("Invalid index\n");
        return;
    }
    if (index == 0){
        insert_at_beginning(value);
        return;
    }
    if (index == length){
        insert_at_end(value);
        return;
    }
    struct Node *current = head;
    for (int i = 0; i < index - 1; i++){
        current = current->next;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;
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

struct Node *search(int value){
    struct Node *current=head;
    if(head==NULL){
        printf("linked list is empty");
    }

    while(current!=NULL){
            if(current->data==value){
                printf("%d is present\n",value);
            }
            current=current->next;
    }
    return NULL;
}

void remove_val(int value){
    struct Node *current=head;
    struct Node *previous=NULL;

    if(head==NULL){
        printf("linked list is empty");
    }

    
    while(current!=NULL){
            if(current->data==value){
                if(previous==NULL){
                    head=current->next;
                }
                else{
                    previous->next=current->next;
                }
                free(current);
                return;
            }
            previous=current;
            current=current->next;
    }
    printf("element not found in the list");
        
}

void remove_at(int index){
    int get_length();
    int length = get_length();
    if (index < 0 || index > length){
        printf("Invalid index\n");
        return;
    }
    struct Node *current = head;
    struct Node *previous = NULL;
    if(index==0){
        head=head->next;
    }
    if(index==length){
        while(current!=NULL){
            previous->next=current->next;
            free(current);
        }
        return;
    }
    for (int i = 0; i < index - 1; i++){
        previous=current;
        current=current->next;
        if(current==NULL){
            previous->next=NULL;
        }
        else{
            previous->next=current->next;
            free(current);
        }
    }
}
int get_length(){
    struct Node *current=head;
    if(head==NULL){
        return 0;
    }
    int count=0;
    while(current!=NULL){
        count+=1;
        current=current->next;
    }
    return count;
}

int main(){
    insert_at_beginning(23);
    insert_at_end(45);
    insert_at_end(90);
    insert_at(2,55);
    traverse();
}