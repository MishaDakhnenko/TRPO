#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TicketSelling
{
	int NumberOfFlight; //Номер рейса
	char AirplaneType;  //Тип самолета
	char Destination;  //Пункт назначения
	int DepartureTime; //Время вылета
	int ArrivalTime; //Время прилета
	int AirplaneCapacity; //Вместимость самолета
	int NumberOfRemainingBusinessClassTickets; //Количество оставшихся билетов бизнесс класса
	int PriceOfBussinessClassTicket; //Стоимость билета бизнес класса
	int NumberOfRemainingEconomyClasssTickets; //Количество оставшихся билетов эконом класса
	int PriceOfEconomyClassTicket; //Стоимость билета эконом класса
};

struct users
{
	int role;
	char password;
	char login;
};

void array_nulling(char *array, int *size)
{
	for(int i=0;i<*size;i++)
	{
		*(array+i)=0;
	}
}

void pass(int *k, struct users *a1, int *size, int *stopmain)
{
	int n, stop, maxNumOfLetters;
	char login[maxNumOfLetters], password[maxNumOfLetters];
	*k=0;
	while(*k==0)
	{
		stop=0;
		array_nulling(login, &maxNumOfLetters);
		array_nulling(password, &maxNumOfLetters);
		printf("Login:");
		scanf("%s", &login);
		printf("Password:");
		scanf("%s", &password);
		for(int i=0;i<*size;i++)
	{
		if(memcmp((a1+i)->login,login,maxNumOfLetters)==0 && memcmp((a1+i)->password,password,maxNumOfLetters)==0)
		{
			if((a1+i)->role==1)
			{
				*k=1;
				printf("You have entered as a user\n");
				break;
			}
		else *k=2;
		printf("You have entered as a user\n");
		break;	
		}
		}
	if(*k==0)
	printf("\nWrong login or password\n");
	while((*k==0) && stop!=1)
	{
		printf("1 - Try log in again\n 2 - Close program\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
		    stop=1;
		    break;
		    case 2:
		    *k=-1;
		    *stopmain=1;
		    break;
		    default:
		    printf("\nWrong number, please try again\n");
		}
	}		
}
 if(*k!=-1)	system("pause");
}

void outputInformationAboutTicketSelling(struct ticketselling *a, int *size)
{
	for(int i=0;i<*size;i++)
	{
	printf("%d.|Number of flight: &2d | Airplane type: %2s | Destination: %2s %2s | Departure time: %2d %2d | Arrival time: %2d %2d | Airplane capacity: %3d | Number of remaining business class tickets: %3d | Price of bussiness class ticket: %2d | Number of remaining economy class tickets: %3d | Price of economy class ticket: %2d"\n);
	
	}
	
}
