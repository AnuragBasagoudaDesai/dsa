#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} Queue;

typedef struct ListNode {
    int vertex;
    struct ListNode* next;
} ListNode;

typedef struct Graph {
    int Vertices;
    struct ListNode** adjLists;
    int* visited;
} Graph;

// Queue functions
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

void enQueue(Queue* q, int data) {
    if (q->rear == SIZE - 1) {
        printf("Queue is Full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++(q->rear)] = data;
}

int deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    int item = q->items[q->front++];
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return item;
}

// Graph functions
ListNode* createNode(int v) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* creategraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->Vertices = vertices;

    graph->adjLists = (ListNode**)malloc(vertices * sizeof(ListNode*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    ListNode* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->Vertices; i++) {
        ListNode* temp = graph->adjLists[i];
        printf("\nNode %d neighbours:", i);
        while (temp) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void BFS(Graph* graph, int startVertex) {
    Queue* q = createQueue();
    graph->visited[startVertex] = 1;
    enQueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = deQueue(q);
        printf("Visited %d\n", currentVertex);

        ListNode* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enQueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

// Main function
int main() {
    Graph* g = creategraph(8); // 8 vertices: 0 to 7

    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);
    addEdge(g, 2, 5);
    addEdge(g, 4, 5);
    addEdge(g, 4, 6);
    addEdge(g, 4, 7);

    displayGraph(g);

    printf("\nBFS traversal starting from vertex 2:\n");
    BFS(g, 2);

    return 0;
}
