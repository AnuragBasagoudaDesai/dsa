#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void SinglepointerDemo()
{
    int number = 6;
    int *pnumber = &number;
    printf("adress of number is : %p\n",&number);
    printf("adress of number is : %p\n",pnumber);
    printf("value of number is  : %d\n",number);
    printf("value of number is  : %d\n",*pnumber);

}
void DoublePointerDemo()
{
    int num = 8;
    int *pnum = &num;
   
    int *ppnum = pnum;
    

    printf("adress of num is : %p\n",&num);
    printf("adress of num is : %p\n",pnum);
    printf("adress of num is : %p\n",ppnum);
    printf("value of num is  : %d\n",num);
    printf("value  of num is : %d\n",*pnum);
    printf("value  of num is : %d\n",*ppnum);
}

void swapValues(int *pn1 , int* pn2)
{
    int temp = *pn1;
    *pn1 = *pn2;
    *pn2  =  temp;
}

void invoke_swapdemo()
{
    int n1 = 10 , n2 = 30;
    printf("before swap : n1 = %d n2 = %d\n",n1 ,n2);
    swapValues(&n1 , &n2);
    printf("after swap : n1 = %d n2 = %d\n",n1 ,n2);

}
void invoke_DPdemo()
{
    int number = 10;
   
    int* pnumber = &number;
    int** ppnumber = &pnumber;
 

    int*** pppnumber = &ppnumber;

     // Print addresses
    printf("Address of number: %p\n", (void*)&number);
    printf("Address of pnumber: %p\n", (void*)&pnumber);
    printf("Address of ppnumber: %p\n", (void*)&ppnumber);

    // Print pointer values
    printf("Value of pnumber (address of number): %p\n", (void*)pnumber);
    printf("Value of ppnumber (address of pnumber): %p\n", (void*)ppnumber);
    printf("value of pppnumber (adress of ppnumber): %p\n",(void*)pppnumber);

    // Print values using pointers
    printf("Value of number using single pointer: %d\n", *pnumber);
    printf("Value of number using double pointer: %d\n", **ppnumber);
    printf("value of number using three pointer : %d\n",***pppnumber);

}
int main()
{
    //SinglepointerDemo();
    //DoublePointerDemo();
    //invoke_swapdemo();
    invoke_DPdemo();
}