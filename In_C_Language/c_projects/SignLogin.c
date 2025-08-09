#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[10];
    char FatherName[10];
    char LastName[10];
    int date, month, year;
    char mobileNumber[11];
    char address[50];
    char AadharNumber[13];
} User;

typedef struct {
    char password[15];
} Password;

bool isValidMobile(const char number[]) {
    if (strlen(number) != 10 || number[0] == '0') return false;
    for (int i = 0; i < 10; i++) {
        if (number[i] < '0' || number[i] > '9') return false;
    }
    return true;
}

bool isValidAadhar(const char aadhar[]) {
    if (strlen(aadhar) != 12 || aadhar[0] == '0') return false;
    for (int i = 0; i < 12; i++) {
        if (aadhar[i] < '0' || aadhar[i] > '9') return false;
    }
    return true;
}

bool isMobileAlreadyExist(const char mobileNumber[]) {
    FILE* fUser = fopen("username.txt", "rb");
    if (!fUser) return false;

    User user;
    while (fread(&user, sizeof(User), 1, fUser) == 1) {
        if (strcmp(user.mobileNumber, mobileNumber) == 0) {
            fclose(fUser);
            return true;
        }
    }

    fclose(fUser);
    return false;
}

bool isAadharAlreadyExist(const char aadhar[]) {
    FILE* fUser = fopen("username.txt", "rb");
    if (!fUser) return false;

    User user;
    while (fread(&user, sizeof(User), 1, fUser) == 1) {
        if (strcmp(user.AadharNumber, aadhar) == 0) {
            fclose(fUser);
            return true;
        }
    }

    fclose(fUser);
    return false;
}

bool isValidNames(const char Name[])
{
    int strlength = strlen(Name);

    for( int index = 0 ; index < strlength ; index++)
    {
        if(Name[index ] >= '0' && Name[index] <= '9')
            return false;
    }

    return true;
}

bool isValidDate(const int date,const int month , const int year)
{
    if(date > 31 || month > 12 || year > 2025)
        return false;
    else
    {
        return true;
    }
}

void printDetails(User user)
{
    printf("\nName is %s :",user.name);
    printf("\nMobile Number is %s :",user.mobileNumber);
    printf("\nAdhar Number is %s: ",user.AadharNumber);
    printf("\ndate od birth is :(%d %d %d) ",user.date , user.month , user.year);

}
void login() {
    char inputMobile[11];
    char inputPassword[15];
    bool found = false;

    FILE* fUser = fopen("username.txt", "rb");
    FILE* fPass = fopen("password.txt", "rb");

    if (!fUser || !fPass) {
        perror("File open failed during login");
        return;
    }

    printf("\n\nEnter your registered Mobile Number: ");
    scanf("%s", inputMobile);

    printf("\n\nEnter your Password: ");
    int i = 0;
    char ch;
    while (i < 14) {
        ch = getch();
        if (ch == 13) break;
        inputPassword[i++] = ch;
        printf("*");
    }
    inputPassword[i] = '\0';

    User user;
    Password pass;

    while (fread(&user, sizeof(User), 1, fUser) == 1 &&
            fread(&pass, sizeof(Password), 1, fPass) == 1) {
        if (strcmp(user.mobileNumber, inputMobile) == 0 &&
            strcmp(pass.password, inputPassword) == 0) {
            found = true;
            break;
        }
    }

    fclose(fUser);
    fclose(fPass);

    if (found) {
        printf("\n\nLogin Successful! your details");
        printDetails(user);

    } else {
        printf("\n\nInvalid credentials. Please try again.\n");
    }

    getch();
}

void accountCreated() {
    printf("\n\nPlease wait, processing your data...\n");
    Sleep(2000);
    printf("\nYour account has been created. Press Enter to continue...\n");
    getch();
}

void createAccount() {
    User user;
    Password userPassword;

    FILE* fUser = fopen("username.txt", "ab");
    if (!fUser) {
        perror("Unable to open username.txt");
        exit(1);
    }

    FILE* fPass = fopen("password.txt", "ab");
    if (!fPass) {
        perror("Unable to open password.txt");
        fclose(fUser);
        exit(1);
    }

    printf("\nEnter First Name: ");
    scanf("%s", user.name);

    while(! isValidNames(user.name))
    {
        printf("\nYour name contain numbers , re-enter name: ");
        scanf("%s" , user.name);
    }

    printf("Enter Last Name: ");
    scanf("%s", user.LastName);

    while(! isValidNames(user.LastName))
    {
        printf("\nYour Lastname contain numbers , re-enter name: ");
        scanf("%s" , user.LastName);
    }

    printf("Enter Father's Name: ");
    scanf("%s", user.FatherName);

    while(! isValidNames(user.FatherName))
    {
        printf("\nYour FatherName contain numbers , re-enter name: ");
        scanf("%s" , user.FatherName);
    }

    printf("Enter Mobile Number: ");
    scanf("%s", user.mobileNumber);

    while (!isValidMobile(user.mobileNumber) || isMobileAlreadyExist(user.mobileNumber)) {
        printf("\nInvalid or already existing Mobile Number. try differnt: ");
        scanf("%s", user.mobileNumber);
    }

    printf("Enter Aadhar Number: ");
    scanf("%s", user.AadharNumber);

    while (!isValidAadhar(user.AadharNumber) || isAadharAlreadyExist(user.AadharNumber)) {
        printf("\nInvalid or already existing Aadhar Number. Enter again: ");
        scanf("%s", user.AadharNumber);
    }

    printf("Enter Date of Birth (DD MM YYYY): ");
    scanf("%d %d %d", &user.date, &user.month, &user.year);

    while( isValidDate(user.date , user.month , user.year) == false)
    {
        printf("\n Invalid date of birth,re-enter (DD MM YYYY)");
        scanf("%d %d %d",&user.date , &user.month , &user.year);
    }

    printf("Enter Address: ");
    scanf(" %[^\n]", user.address); // accepts spaces in address

    printf("\nEnter Password (max 14 characters): ");
    int index = 0;
    char ch;
    while (index < 14) {
        ch = getch();
        if (ch == 13) break;
        userPassword.password[index++] = ch;
        printf("*");
    }
    userPassword.password[index] = '\0';

    fwrite(&user, sizeof(User), 1, fUser);
    fwrite(&userPassword, sizeof(Password), 1, fPass);

    fclose(fUser);
    fclose(fPass);

    accountCreated();
}

void menu() {
    printf("\n============ BANK MANAGEMENT SYSTEM ============\n");
    printf("1. Create Account\n");
    printf("2. Already Registered? Login\n");
    printf("3. Exit\n");
    printf("===============================================\n");
}

int main() {
    int choice;
    do {
        system("cls");
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("\nThank you for using the system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                getch();
        }
    } while (choice != 3);


    return 0;
}
