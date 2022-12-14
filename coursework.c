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
}
