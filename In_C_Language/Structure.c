                    /*Dynamic memory allocation in c */


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


//structer syntax and example
struct Student
{
    int rollnumber;
    char name[20];
};

//special typedef  structure having name Emp
typedef struct employee
{
    char ename[80];
    int e_id;
}Emp;

void DynamicAllocation()
{
    //Emp* employee1 = (Emp*) malloc (sizeof(Emp));//memory allocation using malloc
    Emp* employee1 = (Emp*) calloc (1,sizeof(Emp));//memory alllocationn using calloc
    employee1->e_id = 100;
    strcpy(employee1->ename , "Anurag");

    
    printf("the employer Name is : %s \n",employee1->ename);
    printf("the employer id  is : %d \n",employee1->e_id);

    Emp employee2;
    employee2.e_id = 2;
    strcpy(employee2.ename , "AnuragS desai");
  
    printf("the employer name is : %s \n",employee2.ename);
    printf("the employer id is : %d \n",employee2.e_id);

    free(employee1);
        
}

int main()
{
    // struct Student s1;
    // strcpy(s1.name , "Anurag");
    // s1.rollnumber = 117;

    // printf("the Name is : %s \n",s1.name);
    // printf("the roll number is : %d \n",s1.rollnumber);

    // Emp e1;
    // e1.e_id = 100;
    // strcpy(e1.ename , "Anurag Basagouda desai");
    
    // printf("the employer Name is : %s \n",e1.ename);
    // printf("the employer id  is : %d \n",e1.e_id);

    //Dynamic Demo
    DynamicAllocation();
}

