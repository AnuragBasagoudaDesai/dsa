
//header files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct stack
{
    int items[MAX_SIZE];
    int topIndex;
}Stack;


//intialising the stack  
void intialize(Stack* pstack)
{
    pstack->topIndex = -1;
    return;
}

//check the stack is empty or not
bool isEmpty(Stack* pstack)
{
    if(pstack->topIndex == -1)
        return true;
    else
        return false;
}

//is full checking function 
bool isFull(Stack* pstack)
{
    if(pstack->topIndex == MAX_SIZE - 1)
        return true;
    else
        return false;
}


void push(int data , Stack* pstack)
{
    if(isFull(pstack))
    {
        printf("\n the stack is full,you can not push element");
        return;
    }

    pstack->topIndex = (pstack->topIndex)+1;//increment the topIndex
    pstack->items[pstack->topIndex] = data;//inserting the value
    printf("\nthe value %d pushed succesfully ",data);
}

int pop(Stack* pstack)
{
    if(isEmpty(pstack))
    {
        printf("\nstack is empty,you can not do the pop operation");
        return -1;
    }

    int value = pstack->items[pstack->topIndex];
    pstack->topIndex--;
    printf("\nthe element %d deleted",value);

    return value;

}

int peek(Stack* pstack)
{
    if(pstack->topIndex == -1)
    {
        printf("\nstack is empty");
        return -1;
    }
    
    int peekValue = pstack->items[pstack->topIndex];
    return peekValue;
}

void use_stack()
{
    Stack mystack1;

    intialize(&mystack1);

    push(10,&mystack1);
    push(10,&mystack1);
    push(12,&mystack1);

    int peek_value = peek(&mystack1);
    printf("\npeek value is %d : ",peek_value);



}

int main()
{
    Stack mystack;

    intialize(&mystack);

    // push(10,&mystack);
    // push(20,&mystack);
    // push(30,&mystack);
    // push(40,&mystack);
    // push(50,&mystack);


    use_stack();

    
    // push(30,&mystack);
    // push(40,&mystack);

   // int value = pop(&mystack);

    //printf("\nthe deleted value is %d",value);

    int peekValue = peek(&mystack);

    //Note : if stack is empty peekValue always -1;

    printf("\nthe peek value is %d",peekValue);


}
