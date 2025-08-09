#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char name[10];

int main()
{
    FILE *fUser = fopen("username1.txt", "a");
    if(fUser == NULL)
    {
        printf("Error , could not open file\n");
        return -1;
    }
    printf("Enter your name: ");
    scanf("%s", name);
    fputs(name, fUser);
 

    
    return 0;
}


