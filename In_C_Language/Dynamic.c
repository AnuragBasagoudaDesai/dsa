#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
void DynamicMemoryDemo()
{
    int number = 8;
    int *num = (int*) malloc ( number * sizeof(num));


    for( int i = 0 ; i < number ; i++)
    {
        num[i] = i;
    }
      for( int i = 0 ; i < number ; i++)
    {
        Sleep(1000);
        printf("\n%d",num[i]);
    }

    
    
}
 void  DynamicMemoryDemo2()
 {
    int count = 1;
    
    while(count < 10000)
    {
        char* string = (char*) malloc (100000*sizeof(string));
        if(string != NULL)
        {
            Sleep(100);
            printf("memory allocated this times %d ",count);
        }
        else
        {
            printf("memory is not allocated ");
            break;
        }
        count++;
    }


 }


int main()
{
    //DynamicMemoryDemo();
    DynamicMemoryDemo2();
}