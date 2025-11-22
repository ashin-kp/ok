#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

struct Node *head=NULL;

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
//insert at the beginning

void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);
    newNode->next=head;
    head=newNode;
}

//insert at end

void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//insert at given 1-based index

void insertAtPosition(int data,int pos) {
    struct Node *newNode = createNode(data);

    //insert at beginning
    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    for(int i = 1; i< pos - 1 && temp != NULL;i++) { 
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

//delete at beginning
void deleteAtBeginning() {
    if(head == NULL) {
        printf("list is empty");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// delete at end 

void deleteAtEnd() {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }
    if(head->next == NULL) { //only one node
        free(head);
        head = NULL;
        return;
    }
    struct Node *prev = NULL, *curr = head;
    while(curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
}

//delete at given 1-based position

void deleteAtPosition(int pos) {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }
    if(pos == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node *prev=NULL, *curr = head;

    for(int i=1; i < pos && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL) {
        printf("position out of range\n");
        return;
    }
    prev->next = curr->next; 
    free(curr);
}

void display() {
    struct Node *temp = head;
    if(temp == NULL) {
        printf("this list is empty\n");
        return;
    }
    while(temp != NULL) {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(100,3);
    printf("linked list: ");
    display();

    return 0;
}