#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    //check if memory is allocated
    if(newNode == NULL)
    {
        printf("Memory not allocated\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;

}

void insertAtStart(Node** head,int data)
{
    Node* newNode  = createNode(data);
    
    if(*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
        return;
    }

    Node* lastNode = *head;
    while(lastNode->next != *head)
    {
        lastNode = lastNode->next;
    }

    newNode->next = *head;
    lastNode->next = newNode;
    *head = newNode;
}

void insertAtEnd(Node** head,int data)
{
    Node* newNode = createNode(data);
    if(*head == NULL)
    {
        insertAtStart(head,data);
        return;
    }

    Node* lastNode = *head;
    while(lastNode->next != *head)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->next = *head;
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


void insertATgivenPosition(Node** head, int data, int Positon)
{
    Node* newNode = createNode(data);

    //check if the list is empty
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    if(Positon == 1)
    {
        insertAtStart(head,data);
        return;
    }

    Node* currentNode = *head;
    int currentPosition = 1;

    while( (currentPosition < Positon-1) && currentNode->next != *head)
    {
        currentNode = currentNode->next;
        currentPosition++;
    }
    if(currentNode->next == *head && currentPosition == Positon-1)
    {
        insertAtEnd(head,data);
        return;
    }
    if(currentPosition < Positon -1)
    {
        printf("\nthe position is greater than it should be\n");
        return;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;

}

void deletAtbegining(Node** head)
{
    //case 1:check if the list empty
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    //case 2:delete first node of the list
    Node* temp = *head;
    Node* lastNode = *head;
    while(lastNode->next != *head)
    {
        lastNode = lastNode->next;
    }
    if(*head == lastNode)
    {
        *head = NULL;
    }
    else
    {
    lastNode->next = (*head)->next;
    (*head) = (*head)->next;
    }
    printf("\ndeleted data is %d\n",temp->data);
    free(temp);
    temp = NULL;
}

void deleteAtend(Node** head)
{
    if(*head == NULL)
    {
        printf("\nthe list is empty");
        return;
    }
    if((*head)->next == *head)
    {
        Node* temp = *head;
        free(temp);
        *head = NULL;
        return;
    }

    Node* lastSecond = *head;
    while(lastSecond->next->next != *head)
    {
        lastSecond = lastSecond->next;
    }
    Node* temp = lastSecond->next;
    lastSecond->next = temp->next;
    free(temp);
}

void deletATGivenPosiotion(Node** head,int Position)
{
    if(Position < 1)
    {
        printf("\nInvalid position");
        return;
    }

    if(Position == 1 )
    {
        deletAtbegining(head);
        return;
    }

    if((*head)->next == *head )
    {
        if(Position > 1)
        {
            printf("\n Number of nodes less than position");
            return;
        }
        else
        {
            deletAtbegining(head);
            return;
        }
    }

    Node* currentNode = *head;
    int currentPosition = 1;

    while((currentPosition < Position-1) && currentNode->next != *head)
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
        deleteAtend(head);
        return;
    }

    Node* temp = currentNode->next;
    currentNode->next = temp->next;
    free(temp);
}

void deleteFirstOcuurence(Node** head, int data)
{
    if(*head == NULL)
    {
        printf("list is empty");
        return;
    }

    if((*head)->data == data)
    {
        deletAtbegining(head);
        return;
    }

    Node* finder = *head;
    Node* follwer = NULL;

    while(finder->data != data && finder->next != *head)
    {
        follwer = finder;
        finder = finder->next;
    }

    if(finder->data == data)
    {
        Node* temp = finder;
        follwer->next = finder->next;
        free(temp);
    }
    else
    {
        printf("\n the data is not present");

    }

}


void Split_CLinked_list(Node* head ,Node** New_head1 , Node** New_head2)
{
    if(head == NULL)
    {
        printf("the list is empty");
        return;
    }

    if(head->next == NULL)
    {
        printf("the list can not be divided into two Linked List");
        return;
    }

    //this means the list has atleast two nodes

    Node* slow = head;
    Node* fast = head;

    while(fast->next != head && fast->next->next != head)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast->next != head)
    {
        fast = fast->next;
        slow = slow->next;
    }

    *New_head1 = head;
    *New_head2 = slow->next;
    
    fast->next = slow->next;

    slow->next = *New_head1;


     

    printf("the  Circular Linked list after splitting\n");
    PrintList(*New_head1);
    printf("\n");
    
    PrintList(*New_head2);



}


int main()
{
    Node* head = NULL;

    insertAtStart(&head , 3);
    PrintList(head);




    insertAtStart(&head , 2);
    PrintList(head);

    insertAtStart(&head , 1);
    PrintList(head);
    Node* head1 = NULL;
    Node* head2 = NULL;
    Split_CLinked_list(head , &head1 , &head2);
  


    // insertAtEnd(&head,4);
    // PrintList(head);

    // insertAtEnd(&head,5);
    // PrintList(head);

    // insertATgivenPosition(&head,6,6);
    // PrintList(head);
    
    // insertATgivenPosition(&head,7,8);
    

    // insertATgivenPosition(&head,7,7);
    // PrintList(head);

    // deletATGivenPosiotion(&head,2);
    // PrintList(head);

    // deletATGivenPosiotion(&head,1);
    // PrintList(head);

    // deletATGivenPosiotion(&head,1);
    // PrintList(head);

    // deletATGivenPosiotion(&head,1);
    // PrintList(head);

    // deleteFirstOcuurence(&head,3);
    // PrintList(head);


}