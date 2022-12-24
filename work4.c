#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ticketselling
{
	int numberofflight; //Номер рейса
	char airplanetype[30];  //Тип самолета
	char destination[30];  //Пункт назначения
	int departuredate; //Дата вылета
	int departuretime; //Время вылета
	int arrivaltime; //Время прилета
	int airplanecapacity; //Вместимость самолета
	int numberofremainingbusinessclasstickets; //Количество оставшихся билетов бизнесс класса
	int priceofbusinessclassticket; //Стоимость билета бизнес класса
	int numberofremainingeconomyclasstickets; //Количество оставшихся билетов эконом класса
	int priceofeconomyclassticket; //Стоимость билета эконом класса
};

struct users
{
	char login[30];
	char password[30];
	int role;
};

void array_nulling(char *array, int *size)
{
	for(int i=0;i<*size;i++)
	{
	*(array+i)=0;
	}
}

void password(int *k, struct users *a1, int *size)
{
	int n, stop, maxNumOfLetters=30;
	char login[maxNumOfLetters], password[maxNumOfLetters];
	while(*k==0)
	{
		array_nulling(login, &maxNumOfLetters);
		array_nulling(password, &maxNumOfLetters);
		printf("Enter your login:");
		scanf("%s", &login);
		printf("Enter your password:");
		scanf("%s", &password);
		for(int i=0;i<*size;i++)
	{
		if (memcmp((a1+i)->login, login, maxNumOfLetters)==0 && memcmp((a1+i)->password, password, maxNumOfLetters)==0)
		{
		    if((a1+i)->role==1)
			{
			*k=2;
			printf("You have entered as a admin\n");
			break;
			}
		else *k=3;
		printf("You have entered as a user\n");
		break;	
		}
	}
	if(*k==0)
	printf("\nSorry,you entered wrong login or password\n");
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
		break;
		default:
		printf("\nYou entered an invalid number, try again\n");
		}
	}		
}
 if(*k!=-1)	system("pause");
}

void outputInformationAboutTicketSelling(struct ticketselling *a, int *size)
{
	for(int i=0;i<*size;i++)
	{
	printf("%d.|Number of flight: %2d | Airplane type: %2s | Destination: %2s  | Departure date: %2d | Departure time: %2d | Arrival time: %2d | Airplane capacity: %3d | Number of remaining business class tickets: %3d | Price of business class ticket: %2d | Number of remaining economy class tickets: %3d | Price of economy class ticket: %2d\n", i+1, (a + i)->numberofflight,(a + i)->airplanetype,(a + i)->destination,(a + i)->departuredate,(a + i)->departuretime,(a + i)->arrivaltime,(a + i)->airplanecapacity,(a + i)->numberofremainingbusinessclasstickets,(a + i)->priceofbusinessclassticket,(a + i)->numberofremainingeconomyclasstickets,(a + i)->priceofeconomyclassticket);
	}
	
}

void editInformationAboutTicketSelling(struct ticketselling *a, int *size)
{
	int n, m=0, n1=0, m1=0;
	while (m==0)
 {
	printf("Enter ticket selling number(0-Exit): ");
	scanf("d", &n1);
	m1=0;
	if ((n1<0) || (n1>*size))
	{
		printf("\nYou entered an invalid number, try again.");
	}
	else if (n1==0)
	{
	m=1;
	}
	else while(m1==0)
	{
		printf("\n1 - Edit Number of flight\n2 - Edit Airplane type\n3 - Edit Destination\n4 - Edit Departure date\n5 - Edit Departure time\n6 - Edit Arrival time\n7- Edit Airplane capacity");	
		printf("\n8 - Edit Number of remaining business class tickets\n9 - Edit Price of business class ticket\n10 - Edit Number of remaining economy class ticker\n11 - Edit Price of econpmy class ticket\n0 - Exit\n");
		scanf("%d", &n);
		switch(n)
	{
		case 1:
			printf("\nEnter new Number of flight: ");
			scanf("%2d", &(a+n1-1)->numberofflight);
			break;
		case 2:
		    printf("\nEnter new Airplane type: ");
		    scanf("%2s", &(a+n1-1)->airplanetype);
		    break;
		case 3:
		    printf("\nEnter new Destination: ");
		    scanf("%2s", &(a+n1-1)->destination);
		    break;
		case 4:
			printf("\Enter new Departure date: ");
			scanf("%2d %2d %2d", &(a+n1-1)->departuredate);
			break;
		case 5:
		    printf("\nEnter new Departure time: ");
		    scanf("%2d %2d", &(a+n1-1)->departuretime);
		    break;
		case 6:
		    printf("\nEnter new Arrival time: ");
		    scanf("%2d %2d", &(a+n1-1)->arrivaltime);
		    break;
		case 7:
		    printf("\nEnter new Airplane capacity: ");
		    scanf("%3d", &(a+n1-1)->airplanecapacity);
		    break;
		case 8:
		    printf("\nEnter new Number of remaining business class tickets: ");
		    scanf("%3d", &(a+n1-1)->numberofremainingbusinessclasstickets);
		    break;
		case 9:
		    printf("\nEnter new Price of business class ticket: ");
		    scanf("%2d", &(a+n1-1)->priceofbusinessclassticket);
		    break;
		case 10:
		    printf("\nEnter new Number of remaining economy class tickets: ");
		    scanf("3d", &(a+n1-1)->numberofremainingeconomyclasstickets);
		    break;
		case 11:
		    printf("\nEnter new Price of economy class ticket: ");
		    scanf("2d", &(a+n1-1)->priceofeconomyclassticket);
		    break;
		case 0:
		    m1=1;
			break;
		default:
		    printf("\n You entered an envalid number. Try again.");
			break;    
	}	
	}
}
void addNewTicketSelling(struct ticketselling *a, int *size)
{
	printf("Enter Number of flight: ");
	scanf("%2d", &(a+ *size)->numberofflight);
	printf("Enter Airplane type: ");
	scanf("%2s ", &(a+ *size)->airplanetype);
	printf("Enter Destination: ");
	scanf("%2s ", &(a+*size)->destination);
	printf("Enter Departure date: ");
	scanf("%2d %2d %2d", &(a+ *size)->departuredate);
	printf("Enter Departure time: ");
	scanf("%2d %2d", &(a+*size)->departuretime);
	printf("Enter Arrival time: ");
	scanf("%2d %2d", &(a+*size)->arrivaltime);
	printf("Enter Airplane capacity: ");
	scanf("%3d", &(a+*size)->airplanecapacity);
	printf("Enter Number of remaining business class tickets: ");
	scanf("%3d", &(a+*size)->numberofremainingbusinessclasstickets);
	printf("Enter Price of business class ticket: ");
	scanf("%2d", &(a+*size)->priceofbusinessclassticket);
	printf("Enter Number of remaining economy class tickets: ");
	scanf("%3d", &(a+*size)->numberofremainingeconomyclasstickets);
	printf("Enter Price of economy class ticket: ");
	scanf("%2d", &(a+*size)->priceofeconomyclassticket);
	printf("New ticket selling was added\n");
	system("pause");
}

void outputUsers(struct users *a1, int *size)
{
	for(int i=0; i<*size;i++)
	{
		printf("%d.Login: %s Password: %s Role: %d\n", i+1, (a1+1)->login, (a1+1)->password, (a1+i)->role);
	}
	system("pause");
}

void addNewUser(struct users *a1, int *size)
{
	printf("\n Enter Login of new user: ");
	scanf("%s", &((a1+*size)->login));
	printf("\n Enter Password of new user: ");
	scanf("%s", &((a1+*size)->password));
	printf("\n Enter Role(0 or 1): ");
	scanf("%d", &((a1+*size)->role));
	printf("\n New user was added successfully\n");
	system("pause");
}

int main()
{
	int k=0, size1=2, n, size2=1, m=0;
	struct users a1[5]={"admin", "admin", 1, "user", "user", 0};
	struct ticketselling a[11]={28, "Passenger" , "USA", 161222, 1800, 800, 500, 10, 250, 5, 100};
	password(&k, a1, &size1);
	if(k==3)
	{
		m=0;
		while(m==0)
		{
			printf("1 - Display Information About Ticket Selling\n2 - Exit\n");
			scanf("%d", &n);
			switch(n)
			{
				case 1:
					outputInformationAboutTicketSelling(a, &size2);
					system("pause");
					break;
				case 2:
				    m=-1;
				    break;
				default:
					printf("\nYou entered an invalid number. Try again.\n");
					break;
			}
		}
	}
if(k==2)
{
	m=0;
	while(m==0)
	{
	printf("1 - Display ticket selling\n2 - Edit ticket selling\n3 - Add new ticket selling\n4 - Display all new users\n5 - Add new users\n0 - Exit\n");
	scanf("%d", &n);
	switch(n)
	{
	    case 1:
			outputInformationAboutTicketSelling(a, &size2);
			system("pause");
			break;
		case 2:
			outputInformationAboutTicketSelling(a, &size2);
			editInformationAboutTicketSelling(a, &size2);
			break;
		case 3:
			addNewTicketSelling(a, &size2);
			size2++;
			break;
		case 4:
			outputUsers(a1, &size1);
			break;
		case 5:
			addNewUser(a1, &size1);
			size1++;
			break;
		case 0:
			m=1;
			break;
		default:
		    printf("\n You entered an envalid number. Try again.\n");
		    break;
    }
    }
}
system("pause");
return 0;
}
}