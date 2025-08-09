
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

void checkbalance(char*);
void transfermoney(void);
void display(char*);
void person(char*);
void login(void);
void loginsu(void);
void account(void);
void accountcreated(void);
void afterlogin(void);
void logout(void);


void account()
{
    
}
 



void gotoXY(int x , int y)
{
    MyCoord c;

    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);

    
}

typedef struct COORD
{
    int X;
    int Y;

}MyCoord;

typedef struct User
{
    char FirstName[10];
    char LastName[10];
    char FatherName[10];
    char MotherName[10];
    int date , month , Year;
    char Address[20];
    char PhoneNumber[10];
    
}User[100];


int main()
{
    int choice;
 
    gotoxy(20, 3);
 
    // Creating a Main
    // menu for the user
    printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
    gotoxy(18, 5);
 
    printf("**********************************");
    gotoxy(25, 7);
 
    printf("DEVELOPER-Anurag Desai");
 
    gotoxy(20, 10);
    printf("1.... CREATE A BANK ACCOUNT");
 
    gotoxy(20, 12);
    printf("2.... ALREADY A USER? SIGN IN");
    gotoxy(20, 14);
    printf("3.... EXIT\n\n");
 
    printf("\n\nENTER YOUR CHOICE..");
 
    scanf("%d", &choice);
 
    switch (choice) {
    case 1:
        system("cls");
        printf("\n\n USERNAME 50 CHARACTERS MAX!!");
        printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
        account();
        break;
 
    case 2:
        login();
        break;
 
    case 3:
        exit(0);
        break;
 
        getch();
    }
}
 


