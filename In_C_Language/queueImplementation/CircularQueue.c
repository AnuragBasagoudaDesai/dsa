#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 3

typedef struct 
{
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void intialize(Queue* pQueue)
{
    pQueue->front = -1;
    pQueue->rear = -1;
}

bool isQueueFull(Queue* pQueue)
{
    if ((pQueue->rear + 1) % MAX_SIZE == pQueue->front)
    {
        return true;
    }
    return false;
}

bool isQueueEmpty(Queue* pQueue)
{
    if(pQueue->front == -1)
    {
        return true;
    }
    return false;
}

void enqueue(Queue* pQueue, int data)
{
    if (isQueueFull(pQueue))
    {
        printf("\nQueue is Full...");
        return;
    }

    if (isQueueEmpty(pQueue))
    {
        pQueue->front = 0;
    }

    pQueue->rear = (pQueue->rear + 1) % MAX_SIZE;
    
    pQueue->items[pQueue->rear] = data;
}

int dequeue(Queue* pQueue)
{
    if (isQueueEmpty(pQueue))
    {
        printf("\nQueue is empty...");
        return -1;
    }

    int data = pQueue->items[pQueue->front];

    if (pQueue->front == pQueue->rear)
    {
        pQueue->front = -1;
        pQueue->rear = -1;
    }
    else
    {
        pQueue->front = (pQueue->front + 1) % MAX_SIZE;
    }

    printf("\nThe deleted item is %d", data);
    return data;
}

void PrintQueue(Queue* pQueue)
{
    if (isQueueEmpty(pQueue))
    {
        printf("\nQueue is empty");
        return;
    }

    printf("\nThe Queue is: ");
    
    int index = pQueue->front;
    while (index != pQueue->rear)
    {
        printf("[ %d ] %d  ", index, pQueue->items[index]);
        index= (index + 1) % MAX_SIZE;
    }

    
    printf("[ %d ] %d\n", pQueue->rear, pQueue->items[pQueue->rear]);
}


int main()
{
    Queue queue;
    intialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
  
    PrintQueue(&queue);

    dequeue(&queue);
    PrintQueue(&queue);

    enqueue(&queue, 40); // Now it can be inserted
    PrintQueue(&queue);

    return 0;
}
