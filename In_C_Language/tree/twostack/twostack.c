#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct TwoStack
{
    int top1 , top2;
    int capacity;
    char* Array;
}TwoStack;


//creating stack of two side using a one array
TwoStack* createTwoStack(int capacity)
{
    TwoStack* twoStack = (TwoStack*)malloc(sizeof(twoStack));

    if(twoStack == NULL)
    {
        printf("memory allocation is failed\n");
        return NULL;
    }

    twoStack->capacity = capacity;//total capacity of the stack
    twoStack->top1 = -1;//intialising top index for 1stack
    twoStack->top2 = capacity;//intialising top index for stack2

    twoStack->Array = (char*)malloc(sizeof(char) * twoStack->capacity);
    //alloacating dynamic memory for stack opeartion

    if(twoStack->Array == NULL)
    {
        printf("Memory allocation is failed");
        return NULL;
    }


    return twoStack;
}

//getting the size of an particular array
int size(TwoStack* stk , int sNumber)
{
    if(sNumber == 1)
    {
        return stk->top1+1;
    }
    else
    {
        return (stk->capacity - stk->top2);
    }
}

//checking whether stack is reached there capacity
bool isFull(TwoStack* TwoStack)
{
    if(TwoStack->capacity == size(TwoStack,1) + size(TwoStack,2))
    {
        return true;
    }

    return false;
}


//pushing char data into stack by usimg stack Number
void push(TwoStack* stk , int stackNumber , char data)
{
    if(isFull(stk))
    {
        printf("stack Overflow");
        return;
    }

    if(stackNumber == 1)
    {
        stk->Array[++stk->top1] = data;
        return;
    }

    if(stackNumber == 2)
    {
        stk->Array[--stk->top2] = data;
        return;
    }

    else
    {
        printf("enter the valid stack Numbers\n");
        
    }
}

//checking particular stack is empty
bool isEmpty(TwoStack* stk , int stackNumber)
{
    if(stackNumber == 1)
    {
        if(stk->top1 == -1)
        {
            return true;
        }
        return false;
    }

    if(stackNumber == 2)
    {
        if(stk->top2 == stk->capacity)
        {
            return true;
        }
        return false;
    }
    
    
    printf("enter the valid stack number\n");

    return false;

}

//poping the character from stack
char pop(TwoStack* stk , int StackNumber )
{
    if(isEmpty(stk,StackNumber))
    {
        printf("stack underFlow\n");
        return '\0' ;
    }
    if(StackNumber == 1)
    {
        return stk->Array[stk->top1--];
    }
    else
    {
        return stk->Array[stk->top2++];
    }
}

//getting peek value from stack
char peek(TwoStack* stk , int StackNumber)
{
    char poped;
    if(StackNumber == 1)
    {
        poped = stk->Array[stk->top1];
    }
    else if(StackNumber == 2)
    {
        poped = stk->Array[stk->top2];
    }

    return poped;
}

//main function
int main()
{
    TwoStack* stk = createTwoStack(100);

    push(stk,1,2);
    push(stk,1,3);
    push(stk,1,4);
    push(stk,1,6);

    char poped_data = pop(stk,1);
    printf("poped value of stack 1 is %d\n",poped_data);

    push(stk,2,12);
    push(stk,2,5);
    push(stk,2,3);

    char poped_data1 = pop(stk,2);
    printf("poped value of stack 2 is %d \n",poped_data1);


    printf("peek value of stack  1   is %d \n",peek(stk,1));
    printf("peek value of stack 2 is %d \n",peek(stk,2));


}