#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*) malloc (sizeof(Node));

    if(newNode == NULL)
    {
        printf("node is not created");
        return NULL;
    }
    
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;

    return newNode;
}

void PrintList(Node* head)
{
    //check if List is empty
    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    Node *currentNode = head;
    printf("head->");
    int count = 1;
    while(currentNode->next != head)
    {
        printf("%d ->",currentNode->data);
        currentNode = currentNode->next;
        count++;
    }
    printf("%d ->",currentNode->data);
    printf("NULL \t");
    printf("(total nodes = %d)\n",count);
}


void insertAtbegininig(Node** head,int data)
{
    Node* newNode = createNode(data);

    if(*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
        return;
    }

    Node* lastNode = *head;
    while(lastNode->next != *head)
    {
        lastNode = lastNode->next;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    lastNode->next = newNode;
    newNode->prev = lastNode;
    *head = newNode;
    
}

void insertAtend(Node** head,int data)
{
    Node* newNode = createNode(data);
    if(*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
        return;
    }

    Node* lastNode = *head;
    while(lastNode->next != *head)
    {
        lastNode = lastNode->next;
    }
    newNode->prev = lastNode;
    newNode->next = *head;
    lastNode->next = newNode;
    (*head)->prev = newNode;
    
}

void insertATPosition(Node** head, int data, int Position)
{
    Node* newNode = createNode(data);
    if(*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
        return;
    }
    if(Position == 1)
    {
        insertAtbegininig(head,data);
        return;
    }

    int currentPosition = 1;
    Node* currentNode = *head;

    while((currentPosition < Position - 1) && (currentNode->next != *head))
    {
        currentNode = currentNode->next;
        currentPosition++;
    }
    if(currentPosition < (Position-1))
    {
        printf("position is greater than number of nodes");
        return;
    }
    if(currentNode->next == *head)
    {
        insertAtend(head,data);
        return;
    }
    newNode->next = currentNode->next;
    newNode->prev = currentNode;
    newNode->next->prev = newNode;
    currentNode->next = newNode;
}

void deletefirstNode(Node** head)
{
    if(*head == NULL)
    {
        printf("\n list is empty");
        return;
    }
    if((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node* temp = *head;
    Node* lastNode = *head;

    while(lastNode->next != *head)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = temp->next;
    temp->next->prev = lastNode;
    *head = temp->next;
    free(temp);
}

void deleteLastNode(Node** head)
{
    if(*head == NULL)
    {
        printf("\n the list is empty");
        return;
    }
    if((*head)->next == *head)
    {
        Node* temp = *head;
        *head = NULL;
        free(temp);
        return;
    }
    Node* lastSecond = *head;
    while(lastSecond->next->next != *head)
    {
        lastSecond = lastSecond->next;
    }
    Node* temp = lastSecond->next;
    lastSecond->next = *head;
    (*head)->prev = lastSecond;
    free(temp);
}




int main()
{
    Node* head = NULL;

    insertAtbegininig(&head,1);
    PrintList(head);

    insertAtbegininig(&head,2);
    PrintList(head);

    insertAtbegininig(&head,3);
    PrintList(head);

    insertAtbegininig(&head,4);
    PrintList(head);

    insertAtend(&head,0);
    PrintList(head);

    insertAtend(&head,-1);
    PrintList(head);

    insertATPosition(&head,200,3);
    PrintList(head);

    deletefirstNode(&head);
    PrintList(head);

    deleteLastNode(&head);
    PrintList(head);




}
