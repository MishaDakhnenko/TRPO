#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ticketselling
{
	int flightnumber;
	char airplanetype;
	char destination;
	int departuredate;
	int departuretime;
	int arrivaldate;
	int airplanecapacity;
	int numberofremainingbusinessclasstickets;
	int coastofbusinessclasstickets;
	int numberofremainingeconomyclasstickets;
	int coastofeconomyclasstickets;
};
 struct users
 {
 	int role;
 	char login;
 	char password;
 };
	
void array_nulling(char *array, int *size)
{
    for (int i=0; i<*size; i++)
    {
        *(array+i)=0;
    }
}
void pass(int *k, struct users *a1, int *size, int *stopmain)
{
    int n, stop, maxNumofLetters=30;
    char login[maxNumofLetters], password[maxNumofLetters];
    *k=0;
    while (*k==0)
    {
        stop=0;
        array_nulling(login, &maxNumofLetters);
        array_nulling(password, &maxNumofLetters);
        printf("Login: ");
        scanf("%s", &login);
        printf("Password: ");
        scanf("%s", &password);
        for (int i=0; i<*size; i++)
        {
            if (memcmp((a1+i)->login, login, maxNumofLetters)==0 && memcmp((a1+i)->password, password, maxNumofLetters)==0)
            {
                if ((a1+i)->role==1)
                {
                    *k=1;
                    printf("Enter succesful! You have entered as an admin\n");
                    break;
                }
                else *k=2;
                printf("Enter succesful! You have entered as a user\n");
                break;
            }
        }
        if (*k==0) printf("\nWrong login or password\n");
        while ((*k==0) && stop!=1)
        {
            printf("1 - Try log in again\n2 - Close program\n");
            scanf("%d", &n);
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
    if (*k!=-1) system("pause");
};
void outputInformationAboutTicketSelling(struct ticketselling *a, int *size)
{
	for (int i=0; i<*size; i++)
    {
    printf("&d.|FlightNumber: %2d | AirplaneType: %2s | Destination: %2s | Departuredate: %2d %2d %2d |departuretime: %2d %2d |arrivaldate: %2d %2d %d |airplanecapacity: %2d");	
	}
} 
void editInformationAboutTicketSelling(struct ticketselling *a, int *size)
 int n, stop=0, n1, stop1=0;
    while (stop==0)
    {
        printf("Enter the employee's number(0-Exit): ");
        scanf("%d", &n1);
        stop1=0;
        if ((n1<0) || (n1>*size))
        {
            printf("\nWrong number, please try again\n");
        }
        else if (n1==0)
        {
                stop=1;     
        }
        else while (stop1==0)
        {
            printf("\n1 - Edit surname\n2 - Edit name\n3 - Edit patronymic\n4 - Edit Number of years of absence due to illness");
            printf("\n5 - Edit number of month of absence due to illness\n6 - Edit number of days of absence due to illness\n7 - Edit payment in one day\n0 - Exit\n");
            scanf("%d", &n);
            switch (n)
            {
                case 1:
                    printf("\nEnter new flightnumber: ");
                    scanf("%s", &(a+n1-1)->surname);
                    break;
                case 2:
                    printf("\nEnter new number of years of absence due to illness: ");
                    scanf("%d", &(a+n1-1)->years);
                    break;
               case 3;
			   printf("Enter flightnumber: ");
                scanf("%2d", &(a+n1-1)->flightnumber);
            break;
            case 4;
			printf("Enter airplanetype: ");
            scanf("%2s", &((a+n1-1)->airplanetype));
            break;
			case 5;
			printf("Enter destination: ");
            scanf("%2s", &((a+n1-1)->destination));
            break;
			case 6;
			printf("Enter departuredate: ");
            scanf("%2d %2d %2d", &((a+n1-1)->departuredate));
            break;
            case 7;
			printf("Enter departuretime: ");
            scanf("%2d %2d", &((a+n1-1)->departuretime));
            break;
            case 8;
			printf("Enter arrivaldate:");
            scanf("%2d %2d %2d", &((a+n1-1)->arrivaldate));
	        break;
	        case 9;
			printf("Enter airplanecapacity:");
            scanf("%2d", &((a+n1-1)->airplanecapacity));
            break;
            case 10;
			printf("Enter numberofremainingbusinessclasstickets:");
	        scanf("%2d", &((a+n1-1)->numberofremainingbusinessclasstickets));
	       break;
	       case 11;
		   printf("Enter coastofbusinessclasstickets:");
	        scanf("%2d", &((a+n1-1)->coastofbusinessclasstickets));
	        break;
	        case 12;
			printf("Enter numberofremainingeconomyclasstickets:");
	        scanf("%2d", &((a+n1-1)->numberofremainingeconomyclasstickets));
            break;
			printf("Enter coastofeconomyclasstickets:");	
	        scanf("%2d", &((a+n1-1)->coastofeconomyclasstickets));
                case 0:
                    stop1=1;
                    break;
                default:
                    printf("\nWrong number, please try again\n");
                    break;
            }
        }
    }
}
void addNewUser(struct users *a1, int *size)
{
    printf("Enter Login: ");
    scanf("%s", &((a1+*size)->login));
    printf("Enter Password: ");
    scanf("%s", &((a1+*size)->password));
    printf("Enter Role(1 or 0): ");
    scanf("%d", &((a1+*size)->role));
    printf("New user was added\n");
    system("pause");
}
void outputUsers(struct users *a1, int *size)
{
    for (int i=0; i<*size; i++)
    {
        printf("%d.Login: %s  Password: %s  Role: %d\n", i+1, (a1+i)->login, (a1+i)->password, (a1+i)->role);
    }
    system("pause");
}
void addNewTicketSelling(struct ticketselling *a, int *size)
{
    printf("Enter flightnumber: ");
    scanf("%2d", &(a+*size)->flightnumber);
    printf("Enter airplanetype: ");
    scanf("%2s", &((a+*size)->airplanetype));
    printf("Enter destination: ");
    scanf("%2s", &((a+*size)->destination));
    printf("Enter departuredate: ");
    scanf("%2d %2d %2d", &((a+*size)->departuredate));
    printf("Enter departuretime: ");
    scanf("%2d %2d", &((a+*size)->departuretime));
    printf("Enter arrivaldate:");
    scanf("%2d %2d %2d", &((a+*size)->arrivaldate));
	 printf("Enter airplanecapacity:");
 scanf("%2d", &((a+*size)->airplanecapacity));
printf("Enter numberofremainingbusinessclasstickets:");
	 scanf("%2d", &((a+*size)->numberofremainingbusinessclasstickets));
	 printf("Enter coastofbusinessclasstickets:");
	 scanf("%2d", &((a+*size)->coastofbusinessclasstickets));
	 printf("Enter numberofremainingeconomyclasstickets:");
	scanf("%2d", &((a+*size)->numberofremainingeconomyclasstickets));
printf("Enter coastofeconomyclasstickets:");	
	scanf("%2d", &((a+*size)->coastofeconomyclasstickets));
printf("New ticket selling was added\n");
    system("pause");
}
void usercapabilities(struct hospitalEmployee *a, int *sizeSelling)
{
    int stop=0, n;
    while (stop==0)
    {
        printf("1 - Display information about ticket selling\n0 - Exit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                outputInformationAboutTicketSelling(a, sizeSelling);
                system("pause");
                break;
            case 0:
                stop=1;
                break;
            default:
                printf("Wrong number, please try again\n");
                break;
        }
    }     
}
void admincapabilities(struct TicketSelling *a, struct users *a1, int *sizeSelling, int *sizeUsers)
{
    int stop=0, n;
    while (stop==0)
    {
        printf("1 - Display information about ticket selling\n2 - Edit information about ticket selling\n3 - Add new user\n4 - Display all users\n5 - Add new ticket selling\n0 - Exit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                outputInformationAboutTicketSelling(a, sizeSelling);
                system("pause");
                break;
            case 2:
                outputInformationAboutTicketSelling(a, sizeSelling);
                editInformationAboutTicketSelling(a, sizeSelling);
                break;
            case 3:
                addNewUser(a1, sizeUsers);
                (*sizeUsers)++;
                break;
            case 4:
                outputUsers(a1, sizeUsers);
                break;
            case 5:
                addNewTicketSelling(a, sizeSelling);
                (*sizeSelling)++;
                break;
            case 0:
                stop=1;
                break;
            default:
                printf("\nWrong number, please try again\n");
                break;
        }
    }
}
int save(char *filename, struct users *a, int *sizeUsers)
{
    FILE *fp;
    char *c;
    int size=sizeof(struct users);
    if ((fp = fopen(filename, "wb"))==NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    c=(char*)sizeUsers;
    for (int i=0; i<sizeof(int); i++)
    {
        putc((*c)++, fp);
    }
    c=(char *)a;
    for (int i=0; i<size; i++)
    {
        putc(*c, fp);
        c++;
    }
    fclose(fp);
    return 0;
}
int load(char *filename, int *size)
{
    FILE *fp;
    char *c;
    int  i;
    int m=sizeof(int);
    int *pti=(int*)malloc(m);
    if ((fp = fopen(filename, "r"))==NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    c=(char*)pti;
    while (m>0)
    {
        i=getc(fp);
        if (i==EOF) break;
        *c=i;
        c++;
        m--;
    }
    *size=*pti;
    struct users *ptr=(struct users*) malloc(*size*sizeof(struct users));
    c=(char*)ptr;
    while ((i=getc(fp))!=EOF)
    {
        *c=i;
        c++;
    }
    free(pti);
    free(ptr);
    fclose(fp);
    return 0;
}
int main()
{
    int k, sizeUsers=2, n, sizeSelling=1, stop1, n1, stopmain=0;
    char *filename ="users.dat";
    char *filename1 ="selling.dat";
    struct users a1[5]={"admin", "admin", 1, "user", "user", 0};
    struct ticketselling a[11]={16, "Passenger", "USA", 21.12.2022, 18.00, 22.12.2022, 500, 250, 50, 250, 25};
    load(filename, &sizeUsers);
    while (stopmain==0)
    {
        pass(&k, a1, &sizeUsers, &stopmain);
        if (k==2) usercapabilities(a, &sizeSelling);
        if (k==1) admincapabilities(a, a1, &sizeSelling, &sizeUsers);
        stop1=0;
        while(k!=-1)
        {
            printf("1 - Log in\n0 - Close programm\n");
            scanf("%d", &n1);
            switch (n1)
            {
            case 1:
                k=-1;
                break;
            case 0:
                k=-1;
                stopmain=1;
                break;
            default:
                printf("\nWrong number, please try again\n");
                break;
            }
        }
    }
    save(filename, a1, &sizeUsers);
    return 0;
}
