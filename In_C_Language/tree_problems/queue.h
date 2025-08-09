#ifndef QUEUE_H
#define QUEUE_H

#include "tree.h"

typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue();
void enqueue(Queue* queue, TreeNode* node);
TreeNode* dequeue(Queue* queue);
int isEmpty(Queue* queue);
void freeQueue(Queue* queue);

#endif
