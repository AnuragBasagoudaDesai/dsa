#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*) malloc (sizeof(Node));

    if(newNode == NULL)
    {
        printf("\nmemory allocation is failed");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;

}

void PrintList(Node* tail)
{
    if(tail == NULL)
    {
        printf("\n the list is empty");
        return;
    }
    Node* currentNode = tail->next;
    printf("\n<->");
    do
    {
        printf(" %d -->",currentNode->data);
        currentNode = currentNode->next;
    } while (currentNode != tail->next);
    printf(" tail ->");
    
}

void insertAtstart(Node** tail,int data)
{
    Node* newNode = createNode(data);

    if(*tail == NULL)
    {
        newNode->next = newNode;
        *tail = newNode;
        return;
    }

    newNode->next = (*tail)->next;
    (*tail)->next = newNode;

}

void insertAtEnd(Node** tail,int data)
{
    Node* newNode = createNode(data);
    if(*tail == NULL)
    {
        newNode->next = newNode;
        *tail = newNode;
        return;
    }

    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
    *tail = newNode;
    
}

void deleteAtStart(Node** tail)
{
    if(*tail == NULL)
    {
        printf("\n the liat is empty");
        return;
    }

    if((*tail)->next ==  *tail)
    {
        Node* temp = *tail;
        *tail = NULL;
        free(temp);
        return;
    }

    Node* temp = (*tail)->next;
    (*tail)->next = temp->next;
    free(temp);

}

void insertatPosition(Node** tail,int data,int position)
{
    if(position < 1)
    {
        printf("\nenter the valid positon");
        return;
    }
    
    if(position == 1)
    {
        insertAtstart(tail,data);
        return;
    }

    Node* currentnode = (*tail)->next;
    int currentposition = 1;

    while((currentposition < position -1) && currentnode != *tail)
    {
        currentnode = currentnode->next;
        currentposition++;
    }
    if(currentnode == *tail)
    {
        insertAtEnd(tail,data);
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = currentnode->next;
    currentnode->next = newNode;
    

}
void deleteAtend(Node** tail)
{
    if(*tail == NULL)
    {
        printf("\nthe list is empty");
        return;
    }
    if((*tail)->next ==  *tail)
    {
        Node* temp = *tail;
        *tail = NULL;
        free(temp);
        return;
    }

    Node* lastsecond = *tail;
    while(lastsecond->next != *tail)
    {
        lastsecond = lastsecond->next;
    }
    Node* temp = *tail;
    lastsecond->next = (*tail)->next;
    *tail = lastsecond;
    free(temp);

}

void deleteAtposition(Node** tail ,int Position)
{
    if(Position < 1)
    {
        printf("enter the valid position");
        return;
    }
    if(*tail == NULL)
    {
        printf("\nthe list is empty");
        return;
    }
    if(Position == 1)
    {
        deleteAtStart(tail);
        return;
    }
    int currentposition = 1;
    Node* currentNode = (*tail)->next;

    while((currentposition < Position - 1) && currentNode != *tail)
    {
        currentNode = currentNode->next;
        currentposition++;
    }

    if(currentNode == *tail)
    {
        printf("\ninsufficient nodes");
        return;
    }
    if(currentNode->next == *tail)
    {
        deleteAtend(tail);
        return;
    }
    Node* temp = currentNode->next;
    currentNode->next = temp->next;
    free(temp);

}
int main()
{
    Node* tail = NULL;

    insertAtstart(&tail,4);
    PrintList(tail);

    insertAtstart(&tail,4);
    PrintList(tail);

    insertAtstart(&tail,3);
    PrintList(tail);

    insertAtstart(&tail,2);
    PrintList(tail);

    insertAtEnd(&tail,5);
    PrintList(tail);

    deleteAtStart(&tail);
    PrintList(tail);

    deleteAtend(&tail);
    PrintList(tail);

    deleteAtposition(&tail,3);
    PrintList(tail);

    insertAtstart(&tail,0);
    PrintList(tail);

    insertAtstart(&tail,-1);
    PrintList(tail);

    deleteAtposition(&tail,3);
    PrintList(tail);
    
    deleteAtposition(&tail,4);
    PrintList(tail);

    insertatPosition(&tail,5,4);
    PrintList(tail);

    insertatPosition(&tail,3,3);
    PrintList(tail);

    insertatPosition(&tail,1,4);
    PrintList(tail);

    insertatPosition(&tail,2,3);
    PrintList(tail);
    

}