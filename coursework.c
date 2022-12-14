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
void outputInformationAboutHospitalEmployees(struct hospitalEmployee *a, int *size)
{
    for (int i=0; i<*size; i++)
    {
        printf("%d.|FIO: %2s %2s %2s | Year: %2d | Month: %2d | Number of days: %2d | Payment in one day: %2.3f|\n", i+1, (a+i)->surname, (a+i)->name, (a+i)->patronymic, (a+i)->years, (a+i)->months, (a+i)->days, (a+i)->paymentinOneDay);
    }
}
void editInformationAboutHospitalEmployees(struct hospitalEmployee *a, int *size)
{
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
                    printf("\nEnter new surname: ");
                    scanf("%s", &(a+n1-1)->surname);
                    break;
                case 2:
                    printf("\nEnter new name: ");
                    scanf("%s", &(a+n1-1)->name);
                    break;
                case 3:
                    printf("\nEnter new patronymic: ");
                    scanf("%s", &(a+n1-1)->patronymic);
                    break;
                case 4:
                    printf("\nEnter new number of years of absence due to illness: ");
                    scanf("%d", &(a+n1-1)->years);
                    break;
                case 5:
                    printf("\nEnter new number of months of absence due to illness: ");
                    scanf("%d", &(a+n1-1)->months);
                    break;
                case 6:
                    printf("\nEnter new number of days of absence due to illness: ");
                    scanf("%d", &(a+n1-1)->days);
                    break;
                case 7:
                    printf("\nEnter new payment in one day: ");
                    scanf("%f", &(a+n1-1)->paymentinOneDay);
                    break;
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
void addNewHospitalEmployee(struct hospitalEmployee *a, int *size)
{
    printf("Enter FIO: ");
    scanf("%s %s %s", &(a+*size)->surname, &(a+*size)->name, &(a+*size)->patronymic);
    printf("Enter number of years of absence due to illness: ");
    scanf("%d", &((a+*size)->years));
    printf("Enter number of months of absence due to illness: ");
    scanf("%d", &((a+*size)->months));
    printf("Enter number of days of absence due to illness: ");
    scanf("%d", &((a+*size)->days));
    printf("Enter payment in one day: ");
    scanf("%f", &((a+*size)->paymentinOneDay));
    printf("New hospital employee was added\n");
    system("pause");
}
void usercapabilities(struct hospitalEmployee *a, int *sizeEmployee)
{
    int stop=0, n;
    while (stop==0)
    {
        printf("1 - Display information about hospital employees\n0 - Exit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                outputInformationAboutHospitalEmployees(a, sizeEmployee);
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
void admincapabilities(struct hospitalEmployee *a, struct users *a1, int *sizeEmployee, int *sizeUsers)
{
    int stop=0, n;
    while (stop==0)
    {
        printf("1 - Display information about hospital employees\n2 - Edit information about hospital employees\n3 - Add new user\n4 - Display all users\n5 - Add new hospital employee\n0 - Exit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                outputInformationAboutHospitalEmployees(a, sizeEmployee);
                system("pause");
                break;
            case 2:
                outputInformationAboutHospitalEmployees(a, sizeEmployee);
                editInformationAboutHospitalEmployees(a, sizeEmployee);
                break;
            case 3:
                addNewUser(a1, sizeUsers);
                (*sizeUsers)++;
                break;
            case 4:
                outputUsers(a1, sizeUsers);
                break;
            case 5:
                addNewHospitalEmployee(a, sizeEmployee);
                (*sizeEmployee)++;
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
    int k, sizeUsers=2, n, sizeEmployee=1, stop1, n1, stopmain=0;
    char *filename ="users.dat";
    char *filename1 ="employee.dat";
    struct users a1[5]={"admin", "admin", 1, "user", "user", 0};
    struct hospitalEmployee a[10]={"Kostroma", "Matvey", "Olegovich", 2018, 11, 5, 8.54};
    load(filename, &sizeUsers);
    while (stopmain==0)
    {
        pass(&k, a1, &sizeUsers, &stopmain);
        if (k==2) usercapabilities(a, &sizeEmployee);
        if (k==1) admincapabilities(a, a1, &sizeEmployee, &sizeUsers);
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

