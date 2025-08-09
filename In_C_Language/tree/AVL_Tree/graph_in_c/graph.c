#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_VERTICES 50
#define MAX_DEGREE 50


typedef struct
{
    int Vertices;
    int edges;
    int **adjMatrix;
}Graph;

typedef struct
{
    int source;
    int destination;
}Edge;

void rand_init(void)
{
    time_t time1;
    srand((unsigned) time(&time1));
}

Graph* createGraph(const int numVertices)
{
    assert(numVertices >= 0);
    assert(numVertices <= MAX_VERTICES);

    Graph* graph = (Graph*)malloc(sizeof(graph));

    graph->Vertices = numVertices;
    graph->edges = 0;

    //allocate memory for each row
    graph->adjMatrix = malloc(sizeof(int*) * numVertices);

    assert(graph != NULL);

    for( int index = 0 ; index < numVertices ; index++)
    {
            graph->adjMatrix[index] = calloc(numVertices , sizeof(int));
            assert(graph->adjMatrix[index] != NULL);
    }

    return graph;

}

void displayGraph(const Graph* pgraph)
{
    int rowIndex , columnIndex ,  vertices;

    vertices = pgraph->Vertices;

    printf("number of vertices %d and number of edges %d \n",pgraph->Vertices , pgraph->edges);

    for ( rowIndex = 0 ; rowIndex < vertices ; rowIndex++)
    {
        for( columnIndex = 0 ; columnIndex < vertices ; columnIndex++)
        {
            printf("%d ",(pgraph->adjMatrix[rowIndex][columnIndex]));
            printf("\n");
        }
    }

}


void insertEdge( Graph*  pgraph , const int source , const int destination)
{

    int vertices , x ,y;

    vertices = pgraph->Vertices;
    x = source ;
    y = destination;
    assert(x >= 0 && x < vertices);
    assert(y >= 0 && y < vertices);
    if(pgraph->adjMatrix[x][y] == 0)
    {
        pgraph->adjMatrix[x][y] = 1;
        pgraph->adjMatrix[y][x] = 1;
        pgraph->edges = pgraph->edges + 1;
    }
    else
    {
        printf("Edge already exists\n");
    }
}




int main()
{
    int numVertices , i , j;
    Graph* graph;
    Edge* edge;

    rand_init();

    numVertices = rand() % MAX_VERTICES + 1;

    graph = createGraph(numVertices);

    for( i = 0 ; i < numVertices ; i++)
    {
        for( j = 0 ; j < MAX_DEGREE ; j++)
        {
            int source = rand() % numVertices;
            int destination = rand() % numVertices;
            insertEdge(graph , source , destination);
        }
    }

    displayGraph(graph);

    return 0;
}
