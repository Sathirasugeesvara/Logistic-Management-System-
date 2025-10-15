#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITI 30
#define MAX_NAME_SIZE 20
#define MAX_DELI 50

char cityName[MAX_CITI][MAX_NAME_SIZE];
int count = 0;

void mainMenuShow();
void toHandleCities();


//for city management function
void addCity();
void renameCity();
void removeCity();

//for distance management function


int main()
{
    printf("LOGISTICS MANAGEMENT SYSTEM\t\n");
    printf("----------------------------\t\n\n");
    int choice;
    do
    {
        mainMenuShow();
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            toHandleCities();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            break;

        case 5:

            break;
        case 6:
            printf("Exiting...\n\n");
            break;

        default:
            printf("Invalid choice... Enter choice again...\n\n");
        }
    }
    while(choice!=6);


    return 0;
}

void mainMenuShow()
{
    printf("1. City Management\n");
    printf("2. Distance Management\n");
    printf("3. Vehicle Management\n");
    printf("4. New Delivery\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter your choice : ");
}

void toHandleCities()
{
    printf("\nCity Management Section\n");
    int ChoiceTHC=0;

    do
    {
        printf("1. Add city\n");
        printf("2. Rename City\n");
        printf("3. Remove City\n");
        printf("4. Main menu\n");
        printf("Enter Your choice : ");
        scanf("%d", &ChoiceTHC);
        switch(ChoiceTHC)
        {
        case 1:
addCity();
            break;
        case 2:
renameCity();
            break;
        case 3:
removeCity();
            break;
        case 4:
            printf("Main menu...\n\n");
            break;
        default:
            printf("Invalid choice... Enter choice again...\n");
        }

    }
    while(ChoiceTHC!=4);
}

void addCity()
{
    char tempCity[MAX_NAME_SIZE] ;
    char YOrN;
    do
    {
    if(count >=MAX_CITI)// if array full
    {
    printf("Array is Full... You can't add...\n");
    break;
    }

     printf("Enter the City name : ");
     fgets(tempCity, MAX_NAME_SIZE,stdin);
     tempCity[strcspn(tempCity, "\n")]= '\0';

//call city available function
     /*if()
    {
        // check using another function or in for loop before assign to the array after fget
        }//city avilable?*/


        strcpy(cityName[count], tempCity);
        count++ ;
        printf("Do you want to add a city again(Y or N) : ");
        scanf(" %c", &YOrN);
        //problem
        getchar();

    }while(YOrN != 'N');

}
//call city available function
     /*if()
    {
        // check using another function or in for loop before assign to the array after fget
        }//city avilable?*/

void renameCity()
{

}

void removeCity()
{

}


