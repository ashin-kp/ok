#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *second = NULL;

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
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
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at position (1-based)
void insertAtPosition(int data, int pos) {
    struct Node *newNode = createNode(data);

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++) {
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

// Delete at beginning
void deleteAtBeginning() {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// Delete at end
void deleteAtEnd() {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }
    if(head->next == NULL) {
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

// Delete at position
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
    struct Node *prev = NULL, *curr = head;
    for(int i = 1; i < pos && curr != NULL; i++) {
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

// Display
void display(struct Node *list) {
    struct Node *temp = list;
    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ----------------------------
// MERGE TWO LINKED LISTS
// ----------------------------
void mergeLists() {
    if(head == NULL) {
        head = second;   // If first list empty
        return;
    }

    struct Node *temp = head;

    // Traverse to last node of first list
    while(temp->next != NULL) {
        temp = temp->next;
    }

    // Attach second list
    temp->next = second;
}

int main() {

    // First Linked List
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(100, 3);

    printf("First Linked List: ");
    display(head);

    // Creating Second Linked List
    second = createNode(5);
    second->next = createNode(15);
    second->next->next = createNode(25);

    printf("Second Linked List: ");
    display(second);

    // Merge
    mergeLists();

    printf("Merged Linked List: ");
    display(head);

    return 0;
}
