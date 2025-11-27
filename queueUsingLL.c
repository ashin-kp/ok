#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int data) {
    struct Node *newNode = createNode(data);
    if(rear == NULL) {                          //queue empty
        front = rear = newNode;
        printf("enqueued data:",data);
        return;
    }
    rear->next = newNode;
    rear = newNode;
    printf("enqueued data:",data);
}

void dequeue() {
    if(front == NULL) {
        printf("queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("%d dequeued",front->data);

    front = front->next;

    if(front == NULL) {     //queue becomes empty
        rear = NULL;
    }

    free(temp);
}

void display() {
    struct Node *temp = front;
    printf("queue\n");
    while(temp != NULL) {
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}