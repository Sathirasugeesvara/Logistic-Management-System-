#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITI 30
#define MAX_NAME_SIZE 20
#define MAX_DELI 50
#define FUEL_PRIZ 310

char cityName[MAX_CITI][MAX_NAME_SIZE];
int count = 0;

struct vehicle
{
    char type[20];
    int capacity;
    int rate;
    int avgSpeed;
    int fuelEfficincy;
};
struct vehicle vehi[3] = {{"Van", 1000, 30, 60, 12},{"Truck", 5000, 40, 50, 6},{"Lorry", 10000, 80, 45, 4}
};


//main functions
void mainMenuShow();
void toHandleCities();
void handleDistance();
void showVehicles();
void handleDelivery();
void showReport();

//for city management function
void addCity();
void renameCity();
void removeCity();
void showCity();


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
    int ChoiceTHC=0, index = 0;

    do
    {
        printf("\n1. Add city\n");
        printf("2. Rename City\n");
        printf("3. Remove City\n");
        printf("4. Show Cities\n");
        printf("5. Main menu\n");
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
            showCity();
            break;
        case 5:
            printf("Main menu...\n\n");
            break;
        default:
            printf("Invalid choice... Enter choice again...\n");
        }

    }
    while(ChoiceTHC!=5);
}

void addCity()
{
    char tempCity[20];
    if(count >=MAX_CITI)// if array full
    {
        printf("Array is Full... You can't add...\n");
    }
    else
    {

        printf("Enter the City name : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // clear stdin
        fgets(tempCity, sizeof(tempCity),stdin);
        tempCity[strcspn(tempCity, "\n")] = 0;
        int avalbl =0;
        for(int j=0; j<count; j++)
        {
            if(strcmp(cityName[j],tempCity)==0)
            {
                avalbl=1;
                break;
            }
        }
        if (avalbl)
        {
            printf("Entered City already available\n");
        }
        else
        {
            strcpy(cityName[count],tempCity);
            count++ ;
            printf("City added successfully\n");
        }
    }
}
void renameCity()
{

}
void removeCity()
{

}
void showCity()
{
    if(count==0)
    {
        printf("No available Cities yet...\n\n");
    }
    else
    {
        printf("---City List---\n");
        for (int i=0; i<count; i++)
        {
            printf("%d\t%s\n",i+1, cityName[i]);
        }
    }
}


void vehicleDeta()
{

}
