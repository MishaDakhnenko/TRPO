#include <stdio.h>
#include <math.h>
int main()
{
	double x,y;
	printf("Enter x: ");
	scanf("%lf",&x);
	if (x>1.5) y=(2.5)*(pow(x,3))+(6)*(pow(x,2))-30;
	if ((x>=0) && (x<=1.5)) y=x+1;
        if(x<0) y=x;
	printf("y: %0.6lf\n", y);
	system("pause");
	return 0;
} 
