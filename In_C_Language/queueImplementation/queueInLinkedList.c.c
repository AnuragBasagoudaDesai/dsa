#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// Properly allocate memory for queue
Queue* initialize() {
    Queue* q1 = (Queue*)malloc(sizeof(Queue));
    if( q1 == NULL)
    {
        printf("Memory Allocation is Failed\n");
        return NULL;
    }
    q1->front = NULL;
    q1->rear = NULL;
    return q1;
}

void PrintQueue(Queue* queue)
{
    Node* cur = queue->front;
    printf("\n\nQueue is ...");
    while( cur != NULL)
    {
        printf("%d ->",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int data, Queue* queue) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("The element %d is inserted successfully\n", data);
}

void dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = queue->front;
    queue->front = queue->front->next;

    // If the queue becomes empty
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    printf("The element %d is deleted successfully\n", temp->data);
    free(temp);
}

int peek(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return queue->front->data;
    }
}

int main() {
    Queue* q1 = initialize();

    enqueue(10, q1);
    enqueue(20, q1);
    enqueue(30, q1);
    PrintQueue(q1);

    printf("Peek: %d\n", peek(q1));

    dequeue(q1);
    printf("Peek after dequeue: %d\n", peek(q1));

    return 0;
}
