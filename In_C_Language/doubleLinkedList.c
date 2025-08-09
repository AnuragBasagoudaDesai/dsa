#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;


Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    //check if memory is allocated
    if(newNode == NULL)
    {
        printf("Memory not allocated\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;

}

void PrintList(Node* head)
{
    if(head == NULL)
    {
        printf("list is empty\n");
        return;
    }

    Node* currentNode = head;
    int totalNodes = 0;
    printf("\nhead-> ");

    while(currentNode !=NULL)
    {
        printf("%d <-> ",currentNode->data);
        currentNode = currentNode->next;
        totalNodes++;
    }
    printf("NULL\t");
    printf("(Number of nodes:%d)\n",totalNodes);
}

void insertAtbegining(Node** head, int data)
{
    Node* newNode = createNode(data);

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertAtEnd(Node** head , int data)
{
    Node* newNode = createNode(data);

    //if list is empty
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node* currentNode = *head;
    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    newNode->prev = currentNode;
    
}

void insertAtposition(Node** head, int data,int position)
{
    if(position < 1)
    {
        printf("Invalid position\n");
        return;
    }
    Node* newNode = createNode(data);
    if(position == 1)
    {
        insertAtbegining(head,data);
    }

    Node* currentNode = *head;
    int currentPosition = 1;

    while((currentPosition < position - 1) &&(currentNode != NULL))
    {
        currentNode = currentNode->next;
        currentPosition++;
    }

    if(currentNode == NULL)
    {
        printf("Number of nodes are less than the position \n");
        return;
    }

    newNode->prev = currentNode;
    if(currentNode->next != NULL)
    {
        newNode->next = currentNode->next;
        currentNode->next->prev = newNode;
    }
    currentNode->next = newNode;
}

void deleteAtbegining(Node** head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node* temp = *head;//temporary variable to store the address of the node to be deleted

    *head = (*head)->next;
    

    printf("Deleted node is %d\n",temp->data);

    free(temp);
    temp = NULL;

}

void  deleteAtend(Node** head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    
    }

    Node* currentNode = *head;

    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    Node* temp = currentNode;
    currentNode->prev->next = NULL;
    free(temp);
    temp = NULL;
}

void deleteAtpositon(Node** head, int position)
{
    if( position < 1)
    {
        printf("\n enter the valid position");
        return;
    }

    if(position == 1 )
    {
        deleteAtbegining(head);
        return;
    }

    Node* currentNode = *head;
    int currentposition = 1;

    while( (currentposition < position -1) && currentNode != NULL)
    {
        currentNode = currentNode->next;
        currentposition++;
    }

    if(currentNode == NULL)
    {
        printf("\nthe positon is greater than the number of nodes");
        return;
    }

    Node* temp = currentNode->next;
    currentNode->next = temp->next;
    
    //handling special condition when positon == number of nodes
    if(temp->next == NULL)
    {
        currentNode->next = NULL;
    }
    //otherwise position < number of nodes
    else
        temp->next->prev = currentNode;

    free(temp);


}

void deleteFirstOcuurence(int data , Node** head)
{
    if(*head == NULL)
    {
        printf("the Node is not yet created");
        return;
    }

    if((*head)->data == data)
    {
        deleteAtbegining(head);
        return;
    }

    Node* finder = *head;
    Node* follower = NULL;

    while(finder != NULL)
    {
        follower = finder;
        finder = finder->next;

        if(finder->data == data)
        {
            Node* temp = finder;
            if(finder->next == NULL)
            {
                follower->next = NULL;
                free(temp);
                temp = NULL;
                return;
            }
            follower->next = finder->next;
            follower->next->prev = finder;
            free(temp);
            temp = NULL;
            return;
        }
    }

    if(finder == NULL)
    {
        printf("\nthe data is not present in list");
    }


}


Node* reverseList(Node** head )
{
    if(*head == NULL || (*head)->next == NULL)
    {
        printf("list is empty\n");
        return *head;
    }

    Node* currentNode = *head;
    Node* last = NULL;

    while(currentNode != NULL)
    {
        last = currentNode->prev;
        currentNode->prev = currentNode->next;
        currentNode->next = last;

        currentNode = currentNode->prev;
    }

    if(last != NULL)
    {
        *head = last->prev;
    }

    return *head;

}




int main()
{
    Node* head = NULL;

    insertAtbegining(&head,4);
    insertAtbegining(&head,3);
    insertAtbegining(&head,2);
    insertAtbegining(&head,1);
    PrintList(head);


    insertAtEnd(&head,6);
    PrintList(head);

    insertAtposition(&head,7,6);
    PrintList(head);

    insertAtposition(&head,8,7);
    PrintList(head);

    insertAtposition(&head,9,8);
    PrintList(head);
    
    // insertAtposition(&head,5,5);
    // PrintList(head);

    // insertAtposition(&head,200,2);
    // PrintList(head);

    // insertAtposition(&head,300,10);
    // PrintList(head);

    // insertAtposition(&head,300,3);
    // PrintList(head);

    // deleteAtbegining(&head);
    // PrintList(head);
    

    // deleteAtend(&head);
    // PrintList(head);

    // deleteAtpositon(&head , 3);
    // PrintList(head);

    // deleteAtpositon(&head , 5);
    // PrintList(head);

    // deleteAtpositon(&head , 1);
    // PrintList(head);

    // insertAtposition(&head,400,4);
    // PrintList(head);


    head = reverseList(&head);
    PrintList(head);
    

    


    return 0;
}
