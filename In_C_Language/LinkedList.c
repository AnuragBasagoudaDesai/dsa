#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


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

void InsertAtbegining(int data,Node** head1)
{
    Node* newNode = createNode(data);
    //check linked list is empty
    if(*head1 == NULL)
    {
        *head1 = newNode;
        return;
    }

    newNode->next = *head1;
    *head1 = newNode;
}

void insertAtend(int data, Node** head1)
{
    Node* newNode = createNode(data);

    //check if the list is empty
    if(*head1 == NULL)
    {
        *head1 = newNode;
        return;
    }

    Node* currentNode = *head1;

    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next =newNode;
}

//functiom is insert element at given position
void insertAtPosition(int data,int position , Node** head1)
{

    if(position < 1)
    {
        printf("position is not valid, enter the positon greater than 0\n");
        return;
    }

    Node* newNode = createNode(data);
    //check if the list is empty
    if(*head1 == NULL)
    {
        *head1 = newNode;
        return;
    }

    if(position == 1)
    {
        InsertAtbegining(data,head1);
        return;
    }

    Node* currentNode = *head1;
    int currentposition = 1;

    while((currentposition < position-1) && (currentNode != NULL) )
    {
        currentNode = currentNode->next;
        currentposition++;
    }
    if(currentNode == NULL)
    {
        printf("Position is greater than the length of the list\n");
        return;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void deletAtbegining(Node** head1)
{
    //case 1:check if the list empty
    if(*head1 == NULL)
    {
        printf("List is empty\n");
        return;
    }

    //case 2:delete first node of the list
    Node* temp = *head1;
    (*head1) = (*head1)->next;
    
    printf("\ndeleted data is %d\n",temp->data);
    free(temp);
}

void deleteAtend(Node** head1)
{
     //case 1:check if the list empty
    if(*head1 == NULL)
    {
        printf("List is empty\n");
        return;
    }

    //case 2: if the list has onl;y one node
    if((*head1)->next == NULL)
    {
        printf("\ndeleted data is %d\n",(*head1)->data);
        free(*head1);
        *head1 = NULL;
        return;
    }
    Node* currentNode = *head1;

    while(currentNode->next->next != NULL)
    {
        currentNode = currentNode->next;
    }

    Node* temp = currentNode->next;
    currentNode->next = NULL;
    printf("the deleted data is  %d\n ",temp->data);
    free(temp);
}

void deleteAtposition(Node** head1 , int positon)
{
    if(positon < 1)
    {
        printf("position is not valid, enter the positon greater than 0\n");
        return;
    }
       //case 1:check if the list empty
    if(*head1 == NULL)
    {
        printf("List is empty\n");
        return;
    }

    //case 2: if the position is 1
    if(positon == 1)
    {
        deletAtbegining(head1);
        return;
    }

    int currentposition = 1;
    Node* currentNode = *head1;

    while( currentposition < positon -1 &&  currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        currentposition++;
    }

    if(currentNode->next == NULL)
    {
        printf("postion is greater than the length of the list\n");
        return;
    }

    Node* temp = currentNode->next;
    currentNode->next = temp->next;
    printf("the deleted data is %d at position %d\n",temp->data,positon);
    free(temp);
    temp = NULL;
    

}

void deleteFirstOcurrence(Node** head1 , int data)
{
    //case 1:check if the list empty
    if(*head1 == NULL)
    {
        printf("List is empty\n");
        return;
    }

    //case 2: if the data is at first node
    if((*head1)->data == data)
    {
        deletAtbegining(head1);
        return;
    }

    Node* currentNode = *head1;
    while(currentNode->next != NULL)
    {
        if(currentNode->next->data == data)
        {
            Node* temp = currentNode->next;
            currentNode->next = temp->next;
            printf("the deleted data is %d\n",temp->data);
            free(temp);
            temp = NULL;
            return;
        }
        currentNode = currentNode->next;
    }
    printf("data is not found\n");
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
    while(currentNode != NULL)
    {
        printf("%d ->",currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");

}

void searchKey(int key,Node* head1)
{
    if(head1 == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node* currentNode = head1;
    while(currentNode != NULL)
    {
        if(currentNode->data == key)
        {
            printf("key is found \n");
            return;
        }
        currentNode = currentNode->next;
    }
    printf("key is  not found\n");

}   



Node* AddTwoLinkedList(Node** head1 , Node** head2)
{
    Node* dummyNodeHead = createNode(-1);//creating DummyNode for intialising Answer Linked list
    Node* curr = dummyNodeHead;

    Node* temp1 = *head1;
    Node* temp2 = *head2;

    int carry = 0;

    while( temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;

        if(temp1) sum = sum + temp1->data;

        if(temp2) sum = sum + temp2->data;

        Node* newNode = createNode(sum % 10);

        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if(temp1) temp1 = temp1->next;

        if(temp2) temp2 = temp2->next;
    
    }

    if(carry)
    {
        Node* newNode = createNode(carry);
        curr->next = newNode;
    }

    return dummyNodeHead->next;
}


Node* OddEvenArrange(Node** head)
{
    if(*head == NULL || (*head)->next == NULL)
        return *head;

    Node* odd = *head ;
    Node* even = (*head)->next;
    Node* evenHead = even;

    while(even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;

    }

    odd->next = evenHead;

    return *head;
}

Node* revereList(Node** head)
{
    if(*head == NULL || (*head)->next == NULL)
    {
        return *head;
    }

    Node* currentNode = *head;
    Node* prev = NULL;
    Node* next = NULL;

    while(currentNode != NULL)
    {
        next = currentNode->next;
        currentNode->next = prev;
        prev = currentNode;
        currentNode = next;
    }

    return prev;
}

void MiddleNode(Node* head)
{
    if(head == NULL )
    {
        printf("\nList is empty");
        return;
    }

    if(head->next == NULL)
    {
        printf("\nlist has only one node");
        return;
    }

    Node* slow =  head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("\nMiddle Node is %d ",slow->data);
    printf("\n");
}

Node* deleteMiddleNode(Node** head)
{
    if(*head == NULL || (*head)->next == NULL)
        return *head;

    Node* slow = *head;
    Node* fast = *head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* PrevMiddle = *head;

    while(PrevMiddle->next != slow)
    {
        PrevMiddle = PrevMiddle->next;
    }

    PrevMiddle->next = slow->next;

    free(slow);
    
    return *head;
}


void deleteNodesOccurenceWithKey(Node** head , int key)
{
    if(*head == NULL)
    {
        printf("\nList is empty");
        return;
    }

    Node* currentNode = *head;
    Node* prevCurrent = NULL;

    
    while (currentNode != NULL && currentNode->data == key)
    {
        Node* temp = currentNode;
        *head = currentNode->next;
        currentNode = currentNode->next;
        free(temp);
    }

    while(currentNode != NULL)
    {
        if(currentNode->data != key)
        {
            prevCurrent = currentNode;
            currentNode = currentNode->next;
        }

        else
        {
            Node* temp = currentNode;
            if(prevCurrent != NULL)
                prevCurrent->next = temp->next;
            currentNode = temp->next;
            
            free(temp);
        }
    }
}


bool CheckPalindrome(Node** head)
{
    if(*head == NULL || (*head)->next == NULL)
    {
        return true;
    }

    Node* slow = *head;
    Node* fast = *head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = revereList(&(slow->next));

    Node* first = *head;
    Node* second = newHead;

    while(second != NULL)
    {
        if(first->data != second->data)
        {
            revereList(&newHead);
            return false;
        }

        first = first->next;
        second = second->next;

    }

    revereList(&newHead);

    return true;
}

Node* ZipList(Node** head1 , Node** head2)
{
    if(*head1 == NULL && *head2 == NULL)
    {
        printf(" both List are empty");
        return *head1;
    }

    if(*head1 == NULL)
    {
        return *head2;
    }

    Node* first_current = *head1;
    Node* second_current = *head2;

    Node* first_next = NULL;
    Node* second_next = NULL;

    while(first_current->next != NULL && second_current->next != NULL)
    {
        first_next = first_current->next;
        second_next = second_current->next;

        first_current->next = second_current;
        second_current->next = first_next;

        first_current = first_next;
        second_current = second_next;
    }

    if(first_current->next == NULL)
    {
        first_current->next = second_current;
    }

    return *head1;

}

void Sort012(Node** head)
{
    if(head == NULL)
    {
        printf("\nList is empty");
        return ;
    }

    int arr[] = {0,0,0};

    Node* current = *head;

    while(current != NULL)
    {
        int index = current->data;
        arr[index] = arr[index] + 1;
        current = current->next;
    }

    current = *head;

    int index = 0;

    while(current != NULL)
    {
        if(arr[index] == 0)
        {
            index = index + 1;
        }
        current->data = index;
        arr[index] = arr[index] - 1;
        
        current = current->next;

    }

}


void invoke_sort012(Node** head)
{
    insertAtend(2,head);
    insertAtend(1,head);
    insertAtend(0,head);
    insertAtend(2,head);
    insertAtend(1,head);
    insertAtend(0,head);
    PrintList(*head);
    Sort012(head);
    PrintList(*head);

    // PrintList(head4);
}

int findLength(Node* num)
{
    Node* cur = num;
    int len = 0;
    while(cur != NULL)
    {
        len = len + 1;
        cur = cur->next;
    }

    return len;
}

void Multipliaction(Node* num1 ,  Node * num2)
{
    if(num1 == NULL || num2 == NULL)
    {
        printf("\nmultiplication is not possible");
        return;
    }

    int first_number = 0 , second_number = 0;

    int len1 = findLength(num1);

    Node* num1_cur = num1;

    while( num1_cur != NULL)
    {
        first_number = first_number + num1_cur->data * pow(10 , len1 - 1);
        len1 = len1 - 1;
        num1_cur = num1_cur->next;

    }

    int len2 = findLength(num2);

    Node* num2_cur = num2;

    while( num2_cur != NULL)
    {
        second_number  = second_number + num2_cur->data * pow(10 , len2 - 1);
        len2 = len2 - 1;
        num2_cur = num2_cur->next;

    }

    printf("product of numbers is  %d * %d = %d",first_number ,second_number,first_number * second_number);
}

void isLoop(Node* head)
{
    Node* slow ;
    Node* fast;

    slow = fast = head;
    bool isLoopexist = false;

    while(fast  != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast)
        {
            printf("\n Loop is exist");
            isLoopexist = true;
            break;
        }
        
    }

    if(isLoopexist == false)
        printf("\nthe loop is does not exist");

    if(isLoopexist == true)
    {
        int  len = 1;
        fast = fast->next;

        while(slow != fast)
        {
            fast = fast->next;
            len = len+1;
        }

        printf("\nthe lenght of the loop  is %d",len);
        
    }

}

void findStartLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    bool isLoopExist = false;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
      
        if(slow ==  fast)
        {
            printf("\nloop exist");
            isLoopExist = true;
            break;
        }
    }

    if(isLoopExist)
    {
        slow = head;

        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        printf("\nthe start of the loop is %d",slow->data);
    }
}

void invoke_loopList()
{
    Node* head = NULL;

    insertAtend(2,&head);
    insertAtend(3,&head);
    insertAtend(4,&head);
    insertAtend(5,&head);
    insertAtend(6,&head);
    insertAtend(7,&head);

    Node* curr  = head;

    Node* LoopStartnode = NULL;

    while(curr->next != NULL)
    {
        if(curr->data  == 4)
        {
            LoopStartnode = curr;
        }
        curr = curr->next;
    }

    curr->next = LoopStartnode;

    //isLoop(head);

    findStartLoop(head);
}


//inversing List particular position from left to right

void inverseFromLtoR(Node** head, int left , int right)
{
    if(*head == NULL)
    {
        printf("\nLinked List is empty");
        return ;
    }

    if(left > right)
    {
        printf("\n enter the valid positon \n ");
        return ;
    }

    Node* dummy = NULL;//creating dummy node 

    InsertAtbegining(0,&dummy);//and intalising with zero head->0;
    dummy->next = *head;

    Node* leftPrev = dummy;

    //getting the position of the left previous  node
    for ( int position  = 0; position < left-1;position++)
    {
        leftPrev = leftPrev->next;
    }

    Node* prev = NULL;
    Node* cur = leftPrev->next;

    //revrsing list from left to right
    for( int pos = 0 ; pos < (right - left +1); pos++)
    {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    leftPrev->next->next = cur;
    leftPrev->next = prev;



    *head = dummy->next;

}

//return the peek value of the of the Linked List

int peek(Node* head)
{
    if(head == NULL)
        return 0;

    Node* cur = head;

    while( cur->next != NULL)
    {
        cur = cur->next;
    }

    return cur->data;
}

int main()
{
    Node* head1 = NULL;
    //PrintList(head1);
    InsertAtbegining(2,&head1);
    InsertAtbegining(3,&head1);
    InsertAtbegining(4,&head1);
    InsertAtbegining(5,&head1);
    InsertAtbegining(6,&head1);
    InsertAtbegining(7,&head1);

    PrintList(head1);
    inverseFromLtoR(&head1,3,3);
    PrintList(head1);

    int PeekValue = peek(head1);
    printf("Peek value is %d ", PeekValue);


    
    //InsertAtbegining(8,&head1);
    // InsertAtbegining(9,&head1);
    // // InsertAtbegining(6,&head1);
    // //InsertAtbegining(4,&head1);
    // PrintList(head1);

    // insertAtend(11,&head1);
    // insertAtend(12,&head1);
    // PrintList(head1);

    // insertAtPosition(2,2,&head1);
    // insertAtPosition(2,3,&head1);
    // PrintList(head1);

    // insertAtPosition(9,9,&head1);
    // PrintList(head1);

    // insertAtPosition(2,33,&head1);
    // PrintList(head1);

    
    // insertAtPosition(99,9,&head1);
    // PrintList(head1);

    // deletAtbegining(&head1);
    // PrintList(head1);

    // deleteAtend(&head1);
    // PrintList(head1);

    // deleteAtend(&head1);
    // PrintList(head1);

    // deleteAtposition(&head1,2);
    // PrintList(head1);

    // deleteAtposition(&head1,7);
    // PrintList(head1);

    // deleteAtposition(&head1,7);
    // PrintList(head1);

    // deleteAtposition(&head1,9);
    // PrintList(head1);

    // deleteFirstOcurrence(&head1,8);
    // PrintList(head1);

    //reverseList(&head1);
    // PrintList(head1);

    // Node* head2 = NULL;

    // insertAtend(1,&head2);
    // insertAtend(0,&head2);
    // insertAtend(4,&head2);
    // insertAtend(100,&head2);

    // PrintList(head2);

    // Node* head3 = AddTwoLinkedList(&head1,&head2);
    // PrintList(head3);

    // Node* head4 = AddTwoLinkedList(&head3,&head2);
    // PrintList(head4);


    // Node* head5 = OddEvenArrange(&head1);
    // PrintList(head5);

    // head5 = revereList(&head5);
    // PrintList(head5);

    // MiddleNode(head3);

    // Node* head6 = deleteMiddleNode(&head3);
    // PrintList(head6);

    // Node* head7 = NULL;
    // insertAtend(1,&head7);
    // insertAtend(2,&head7);
    // insertAtend(1,&head7);
    // // insertAtend(1,&head7);
    // // insertAtend(3,&head7);
    // PrintList(head7);
    

    // deleteNodesOccurenceWithKey(&head7,2);
    // PrintList(head7);

    // bool isPalindrome = CheckPalindrome(&head7);
    // if(isPalindrome)
    // {
    //     printf("\nthe Linked list  is palindrome data");
    // }
    // else
    // {
    //     printf("\nthe linked list is Not palindrome");
    // }
    // printf("\n");
    // PrintList(head7);


    // Node* head = ZipList(&head1 , &head2);

    // PrintList(head);


    // Node* head012 = NULL;

    // invoke_sort012(&head012);

    // Multipliaction(head1 , head2);

    //invoke_loopList();




    
}