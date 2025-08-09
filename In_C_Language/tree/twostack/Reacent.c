#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1000

typedef struct
{
   int queue[MAX_QUEUE_SIZE];
   int front ;
   int rear;
}RecentCounter;

RecentCounter* createRecentCounter()
{
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->front = 0;
    obj->rear = -1;

    return obj;
    
}
int ping(RecentCounter* obj , int time)
{
    obj->rear++;
    obj->queue[obj->rear] = time;

    while(obj->queue[obj->front] < time - 3000)
        obj->front++;
    
    return obj->rear - obj->front + 1;
}
int main()
{
    RecentCounter* obj = createRecentCounter();

    printf("%d \n",ping(obj, 100));
    printf("%d \n",ping(obj,3001));
}
