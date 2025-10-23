#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_CITI 30
#define MAX_NAME_SIZE 20
#define MAX_DELI 50
#define FUEL_PRIZ 310.0f
#define INF 1000000000

char cityName[MAX_CITI][MAX_NAME_SIZE];
float distanceBetweenCits[MAX_CITI][MAX_CITI];
float deliveries[MAX_DELI];
int avlCityCount = 0, deliCount = 0 ;

struct vehicle
{
    char type[20];
    int capacity;
    float rate;
    float avgSpeed;
    float fuelEfficincy;
};
struct vehicle vehi[3] = {{"Van", 1000, 30.0, 60.0, 12.0},{"Truck", 5000, 40.0, 50.0, 6.0},{"Lorry", 10000, 80.0, 45.0, 4.0}
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
void RemoveDistncsWhenCityRemove(int index);
//for distance management function
void inputAndEditDis();
void displyDisMatrx();
//for handle delivery function
void calculAndMiniStat(int sourceIndex,int destiIndex,float weight,int vehiType,int distance,int shortDis[],int shortLen);
float findLeastCostRoute(int sourceIndex,int destiIndex,int shortDis[],int shortLen);
void printShortDis(int shortDis[],int shortLen);

int main()
{
    printf("LOGISTICS MANAGEMENT SYSTEM\t\n");
    printf("----------------------------\t\n");
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
            handleDistance();
            break;
        case 3:
            showVehicles();

            printf("Press Enter to back...\n");
            getchar(); //clear  new line
            int b;
            while ((b = getchar())!='\n'&&b!=EOF) {}

            break;
        case 4:
            handleDelivery();
            break;
        case 5:
            showReport();
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
    printf("\n1. City Management\n");
    printf("2. Distance Management\n");
    printf("3. Vehicle Management\n");
    printf("4. New Delivery\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter your choice : ");
}



void toHandleCities()
{
    printf("\n---City Management Section---");
    int ChoiceTHC=0;

    do
    {
        printf("\n1. Add city\n");
        printf("2. Show Cities\n");
        printf("3. Remove City\n");
        printf("4. Rename City\n");
        printf("5. Main menu\n");
        printf("Enter Your choice : ");
        scanf("%d", &ChoiceTHC);
        getchar();
        switch(ChoiceTHC)
        {
        case 1:
            addCity();
            break;
        case 2:
            showCity();
            break;
        case 3:
            removeCity();
            break;
        case 4:
            renameCity();
            break;
        case 5:
            printf("Main menu...\n");
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
    if(avlCityCount >=MAX_CITI)// if array full
    {
        printf("Array is Full... You can't add...\n");
    }
    else
    {
        printf("Enter the City name : ");
        fgets(tempCity, sizeof(tempCity),stdin);
        tempCity[strcspn(tempCity, "\n")] = 0;
        int avalbl =0;//if new added city availabale chack it
        for(int j=0; j<avlCityCount; j++)
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
            strcpy(cityName[avlCityCount],tempCity);
            avlCityCount++ ;
            printf("City added successfully\n");
        }
    }
}

void renameCity()
{
    int index = 0;
    char tempCity[20];
    if(avlCityCount==0)
    {
        printf("No available Cities yet...\n\n");
    }
    else
    {
        showCity();
        printf("Enter city index to rename city : ");
        scanf("%d", &index);
        getchar();
        if(index<1||index>avlCityCount)
        {
            printf("Invalid index...\n\n");
        }
        else
        {
            printf("Enter new City name : ");
            fgets(tempCity,sizeof(tempCity),stdin);
            tempCity[strcspn(tempCity, "\n")]=0;

            int avalbl=0;//if new name available in city list check it
            for(int j; j<avlCityCount; j++)
            {
                if(j!= (index-1)&&strcmp(cityName[j],tempCity)==0)
                {
                    avalbl=1;
                    break;
                }
            }
            if(avalbl)
            {
                printf("City name already exists...\n\tCanceled...\n\n");
            }
            else
            {
                strcpy(cityName[index-1],tempCity);
                printf("Successfully renamed...\n\n");
            }
        }
    }
}

void removeCity()
{
    int index=0;
    if(avlCityCount==0)
    {
        printf("No available Cities yet...\n\n");
    }
    else
    {
        showCity();
        printf("Enter city index to remove city : ");
        scanf("%d", &index);
        getchar();
        if(index<1||index>avlCityCount)
        {
            printf("Invalid index...\n\n");
        }
        else
        {
            for(int j=index-1; j<avlCityCount-1; j++)
            {
                strcpy(cityName[j], cityName[j+1]);
            }
            RemoveDistncsWhenCityRemove(index-1);
            avlCityCount--;
            printf("Removed City successfully...\n\n");
        }
    }
}

void showCity()
{
    if(avlCityCount==0)
    {
        printf("No available Cities yet...\n\n");
    }
    else
    {
        printf("\n---City List---\n");
        for (int i=0; i<avlCityCount; i++)
        {
            printf("%2d\t |   %s\n",i+1, cityName[i]);
        }
    }
}

void RemoveDistncsWhenCityRemove(int index)
{
    int n=avlCityCount;
    if(index<0||index>=n)
    {
        return;
    }
    for (int i = index; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            distanceBetweenCits[i][j] = distanceBetweenCits[i + 1][j];
        }
    }
    for (int j = index; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            distanceBetweenCits[i][j] = distanceBetweenCits[i][j + 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        distanceBetweenCits[i][n - 1] = 0;
        distanceBetweenCits[n - 1][i] = 0;
    }
}



void handleDistance()
{
    int choiceHD =0;
    if(avlCityCount==0)
    {
        printf("No Cities added yet...\n");
        return;  //no loop here so can't add break
    }
    printf("\n---Distance Management Section---");
    do
    {
        printf("\n1. Input and Edit distance\n");
        printf("2. Show distance table\n");
        printf("3. Main menu\n");
        printf("Enter your choice : ");
        scanf("%d", &choiceHD);
        getchar();
        switch(choiceHD)
        {
        case 1:
            inputAndEditDis();
            break;
        case 2:
            displyDisMatrx();
            break;
        case 3:

            for(int i=0; i<avlCityCount; i++) // for safety distance from city to itself=0
            {
                distanceBetweenCits[i][i]=0;
            }

            printf("Main menu...\n");
            break;
        default:
            printf("Invalid choice... Enter choice again...\n");
        }
    }
    while(choiceHD!=3);
}

void inputAndEditDis()
{
    int startIndex= 0, destinationIndex= 0 ;
    float distance=0.0;
    if(avlCityCount<2)
    {
        printf("You must add 2 cities to set distance\n");
        return;// cant add break to break this
    }

    showCity();

    printf("Enter the source city number      : ");
    scanf("%d", &startIndex);
    getchar();
    if(startIndex<1||startIndex>avlCityCount)
    {
        printf("Invalid City Number...\n");
        return;
    }

    printf("Enter the destination city number : ");
    scanf("%d", &destinationIndex);
    getchar();
    if(destinationIndex<1||destinationIndex>avlCityCount)
    {
        printf("Invalid City Number...\n");
        return;
    }

    if(startIndex==destinationIndex)
    {
        printf("Distance must be 0, Because start and destination is same...\n");
        return;
    }

    printf("Enter distance in kilometers      : ");
    scanf("%f", &distance);
    getchar();
    if(distance<=0)
    {
        printf("Distance must be positive integer...\n");
    }
    else
    {
        distanceBetweenCits[startIndex-1][destinationIndex-1]  = distance;
        distanceBetweenCits[destinationIndex-1][startIndex-1]  = distance;

        distanceBetweenCits[startIndex-1][startIndex-1]  = 0.0;
        distanceBetweenCits[destinationIndex-1][destinationIndex-1]  = 0.0;

        printf("Distance set to %s <--> %s = %.1f\n", cityName[startIndex-1],cityName[destinationIndex-1],distance);
    }
}

void displyDisMatrx()
{
    if(avlCityCount<2)
    {
        printf("\n");
        return;
    }
    printf("\n\t\t--Distance Matrix-- \n");
    printf("%-12s","");
    for(int x=0; x<avlCityCount; x++)
    {
        printf("%-12s", cityName[x]);
    }
    printf("\n");
    for(int y=0; y<avlCityCount; y++)
    {
        printf("%-12s", cityName[y]);
        for(int z=0; z<avlCityCount; z++)
        {
            if(y==z)
            {
                printf("%-12s","0");
            }
            else
            {
                if(distanceBetweenCits[y][z]<= 0)
                {
                    printf("%-12s","-");
                }
                else
                {
                    printf("%-12.2f",distanceBetweenCits[y][z]);
                }
            }
        }
        printf("\n");
    }

}



void showVehicles()
{
    printf("\n---Vehicle Informations---\n");
    printf("%-6s | %-10s | %12s | %-10s | %-12s | %15s\n","No","Type","Capacity(Kg)","RatePerKm","Speed(Km/h)","Fuel Efficiency");
    for (int i =0; i<3; i++)
    {
        printf("%-6d | %-10s | %12d | %10.2f | %12.1f | %15.1f\n", i +1,vehi[i].type,vehi[i].capacity,vehi[i].rate,vehi[i].avgSpeed,vehi[i].fuelEfficincy);
    }
}

//hanlde only 50 deliveries

void handleDelivery()
{
    int sourceIndex=0,destiIndex=0,vehiType=0;
    float weight=0;

    if(avlCityCount<2)
    {
        printf("Add more than 2 cities...\n");
        return;
    }

    showCity();

    printf("Enter source city number      : ");
    scanf("%d", &sourceIndex);
    getchar();
    if(sourceIndex<1||sourceIndex>avlCityCount)
    {
        printf("Invalid source city number...\n");
        return;
    }

    printf("Enter destination city number : ");
    scanf("%d", &destiIndex);
    getchar();
    if(destiIndex<1||destiIndex>avlCityCount)
    {
        printf("Invalid destination city number...\n");
        return;
    }
    if(destiIndex==sourceIndex)
    {
        printf("You entered same city for source and destination\n");
        return;
    }

    showVehicles();
    printf("Enter the vehicle number : ");
    scanf("%d", &vehiType);
    getchar();
    if(vehiType<1||vehiType>3)
    {
        printf("Invalid vehicle index...\n");
        return;
    }

    printf("Enter the weight in kg        : ");
    scanf("%f", &weight);
    getchar();
    if(vehiType==1)
    {
        if(weight>1000.0||weight<0)
        {
            printf("Weight is higher than capacity...\n");
            return;
        }
    }
    if(vehiType==2)
    {
        if(weight>5000.0||weight<0)
        {
            printf("Weight is higher than capacity...\n");
            return;
        }
    }
    if(vehiType==3)
    {
        if(weight>10000.0||weight<0)
        {
            printf("Weight is higher than capacity...\n");
            return;
        }
    }

    int shortDis[MAX_CITI];
    int shortLen=0;
    int distance=findLeastCostRoute(sourceIndex-1, destiIndex-1,shortDis,&shortLen);//here distance int or float...........................
    if(distance==-1)
    {
        printf("Please check distance matrix between %s and %s... No route found\n",cityName[sourceIndex-1],cityName[destiIndex-1]);
        return;
    }
    printf("Short distance route : ");
    printShortDis(shortDis,shortLen);
    printf("Minimum distance : %d \n", distance);

    calculAndMiniStat(sourceIndex-1, destiIndex-1,weight,vehiType-1,distance,shortDis,shortLen);
}

float findLeastCostRoute(int sourceIndex,int destiIndex,int shortDis[],int shortLen)
{
    float distanceShortRoute=0;
    //distance float or int, change one ............................................................................if

    return distanceShortRoute;
}

void printShortDis(int shortDis[],int shortLen)
{
    if(shortLen<=0)
    {
        printf("No path \n");
        return;
    }
    for(int i=0; i<shortLen; i++)
    {
        printf("%s", cityName[shortDis[i]]);
        if(i<shortLen-1)
        {
            printf(" -> ");
        }
    }
    printf("\n");
}

void calculAndMiniStat(int sourceIndex,int destiIndex,float weight,int vehiType,int distance,int shortDis[],int shortLen)
{
    float W=weight;
    float D=(float)distance;
    float R=vehi[vehiType].rate;
    float S=vehi[vehiType].avgSpeed;
    float E=vehi[vehiType].fuelEfficincy;
    float F=FUEL_PRIZ;

//calculations
    float deliveryCost=D*R*(1.0f+(W/10000.0f));
    float estimaDeliTime=D/S;
    float fuelUsed=D/E;
    float fuelCost=fuelUsed*F;
    float TotlOperaCost=deliveryCost+fuelCost;
    float profit=TotlOperaCost*0.25;
    float finlCharCustomer=profit+TotlOperaCost;


    printf("\n\n====================================================== \n");
    printf("DELIVERY COST ESTIMATION\n");
    printf("------------------------------------------------------\n");
    printf("From\t: %s\n", cityName[sourceIndex]);
    printf("To  \t: %s\n", cityName[destiIndex]);
    printf("Minimum Distance: %.2f\n", D);
    printf("Vehicle  : %s\n", vehi[vehiType].type);
    printf("Weight   : %.2f kg\n", W);
    printf("------------------------------------------------------\n");
    printf("Base Cost: %.2f*%.2f*(1+%.2f/10000) = %.2f LKR\n", D, R, W, deliveryCost);
    printf("Fuel Used : %.2f L\n", fuelUsed);
    printf("Fuel Cost : %.2f LKR\n", fuelCost);
    printf("Operational Cost : %.2f LKR\n", TotlOperaCost);
    printf("Profit : %.2f LKR\n", profit);
    printf("Customer Charge : %.2f LKR\n", finlCharCustomer);
    printf("Estimated Time : %.2f Hours\n", estimaDeliTime);
    printf("======================================================\n\n");

    if(deliCount>=MAX_DELI)
    {
        printf("Delivery history full...Not saved...\n\n");
        return;
    }

    /*
    Delivery d;
    d.source=sourceindex;
    d.destination=destinationindex;
    d.vehicletype=vehicleindex;
    d.weight=W;
    d.distance=D;
    d.cost=basecost;
    d.fuelused=fuelused;
    d.fuelcost=fuelcost;
    d.totalcosr=totaloperatiancost;
    d.profit=profit;
    d.custemercharge=customercharge;
    d.time=estimatedtime;

    deliveries[deliveryCount++]=d;
    printf("Delivery saved as record #%d. \n", deliveryCount);
    */
}

int totalDistanceCovered(int way[])
{
    int sum =0;
    for(int i=0; i<avlCityCount-1,i++)
    {
        int d= distanceBetweenCits[way[i]][way[i+1]];
        if (d<=0)
        {
            return INF;
        }
        sum += d;
    }
    return sum;
}


void showReport()
{
    if(deliCount==0)
    {
        printf("No deliveries added yet...\n");
        return;
    }

    printf("\n----Report Section----\n");
    printf("\nTotal Deliveries Completed : %d\n", deliCount);
    printf("Total Distance Covered : %.2f km \n", ................);
    printf("Average Delivery Time : %.2f hours \n", ................ );
    printf("Total Revenue and Profit : %.2f LKR \n", ................ );
    printf("Longest Route Completed\n");
    printf("Shortest Route Completed\n");
}
