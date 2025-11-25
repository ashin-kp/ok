#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);

    if(head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);

    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at given 1-based position
void insertAtPosition(int data, int pos) {
    struct Node *newNode = createNode(data);

    if(pos == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node *temp = head;
    int i = 1;

    while(i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if(temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    //check whether there is a another node if there is make its pre as newnode
    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete at beginning
void deleteAtBeginning() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    if(head->next == NULL) {  // only one node
        head = NULL;
        free(temp);
        return;
    }

    head = head->next;
    head->prev = NULL;
    free(temp);
}

// Delete at end
void deleteAtEnd() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    if(head->next == NULL) { // only one node
        head = NULL;
        free(temp);
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Delete at given position
void deleteAtPosition(int pos) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(pos == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node *curr = head;
    int i = 1;

    while(i < pos && curr != NULL) {
        curr = curr->next;
        i++;
    }

    if(curr == NULL) {
        printf("Position out of range\n");
        return;
    }

    if(curr->next != NULL)
        curr->next->prev = curr->prev;

    if(curr->prev != NULL)
        curr->prev->next = curr->next;

    free(curr);
}

// Display list forward
void display() {
    struct Node *temp = head;

    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(100, 3);

    printf("Doubly Linked List: ");
    display();

    deleteAtBeginning();
    deleteAtEnd();
    deleteAtPosition(2);

    printf("After deletions: ");
    display();

    return 0;
}
