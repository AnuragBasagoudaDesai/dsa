#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, TreeNode* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

TreeNode* dequeue(Queue* queue) {
    if (queue->front == NULL) return NULL;

    QueueNode* temp = queue->front;
    TreeNode* node = temp->treeNode;
    queue->front = queue->front->next;

    if (queue->front == NULL) queue->rear = NULL;

    free(temp);
    return node;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}
