#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;

struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void push(int data) {
    struct Node *newNode = createNode(data);
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n",data);
}

void pop() {
    if(top == NULL) {
        printf("stack underflow (empty stack)\n");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    free(temp);
}

void display() {
    if( top == NULL) {
        printf("stack is empty\n");
        return;
    }
    struct Node *temp = top;
    printf("stack:");
    while(temp != NULL) {
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();
    
    return 0;
}