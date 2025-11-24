#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create a node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
//for this new node is inserted before the head and at last head is repointed to newnode
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);

    if(head == NULL) {
        head = newNode;
        newNode->next = head; 
        return;
    }

    // move to last node
    struct Node *temp = head;
    while(temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
//same as the insert at beginning but no need to repoint the head
void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
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

    while(i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }
    //used to check if not at the correct position if not it must be out of range
    if(i != pos - 1) {
        printf("position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at beginning
void deleteAtBeginning() {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }

    // only one node
    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    //here the current head is to be deleted which is temp
    //head is changed to the next node
    //after traversing we get last node and the last node is then pointed to the new head
    struct Node *temp = head;
    struct Node *last = head;

    while(last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    free(temp);
}

// Delete at end
void deleteAtEnd() {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }

    // only one node
    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *curr = head;
    struct Node *prev = NULL;

    while(curr->next != head) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = head;
    free(curr);
}

// Delete at given 1-based position
void deleteAtPosition(int pos) {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }

    if(pos == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node *curr = head;
    struct Node *prev = NULL;
    int i = 1;

    while(i < pos && curr->next != head) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    if(i != pos) {
        printf("position out of range\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
}

// Display
void display() {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }

    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("HEAD\n");
}

int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(100, 3);

    printf("Circular Linked List: ");
    display();

    deleteAtBeginning();
    deleteAtEnd();
    deleteAtPosition(2);

    printf("After deletions: ");
    display();

    return 0;
}
