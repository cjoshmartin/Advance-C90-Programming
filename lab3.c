/*
Program Name: Lab3
Author's name: Josh Martin
Class Date: 9/9/2016

*/
#include <stdio.h>
#include <math.h>

#define PI 3.14159265
int main(void) {
	double x, ret, val, Ix, xRad, cosX, errorCos, Cx, Sx, A, fError;
	int n = 0;
	printf("Part 1! \n");

	printf("enter the (double) value for x: ");
	scanf("%lf", &x);
	for (int i = 1; i <= 4;i++)
	{
		if (i == 1)
		{
			Ix = x;
		}
		else {
			Ix = Ix + (pow(-1, i)*pow(x, i) / i);
		}

	}//end of loop

	ret = log(fabs(Ix));
	printf("the value of the ln(1+x -Ix)= %lf  and the abs(1/(1+x)- Ix) = %lf \n",ret,fabs(Ix));
	



	printf("Part 2! \n");
	printf("enter the (double) value for x: ");
	scanf("%lf", &xRad);
	for (int i = 0;i < 3;i++)
	{
		printf("check");
		if (i == 0)
		{
			Cx = 1;
		}
		else {
			
			Cx = Cx + (pow(-1, i)*pow(xRad, n) / factorial(n));
			n += 2;
		}//end of else
	}// end of for loop
	
	cosX = cos(xRad);
	errorCos = fabs(cosX - Cx);
	printf("xRad = %lf . cos(xRad) = %lf . errorCos =%lf . Cx = %lf ", xRad, cosX, errorCos, Cx);





	printf("\nPart 3! \n");
	printf("enter the (double) value for x: ");
	scanf("%lf", &xRad);
	n = 1;
	for (int i = 1;i <3 ;i++)
	{
		if (i == 1)
		{
			Sx = xRad;
		}
		else {
			Sx = Sx + (pow(-1, i)*pow(xRad, n) / factorial(n));
			n += 2;
		}//end of else
	}// end of for loop

	cosX = sin(xRad);
	errorCos = fabs(cosX - Sx);
	printf("xRad = %lf . sin(xRad) = %lf . errorSin =%lf . Sx= %lf\n ", xRad, cosX, errorCos,Sx);






	printf("Part 4! \n");
	printf("enter the (double) value for A: ");
	scanf("%lf", &A);
	xRad = A * 5;
	n = 0;
	for (int i = 0;i < 3;i++)
	{
		if (i == 0)
		{
			Cx = xRad;
		}
		else {

			Cx = Cx + (pow(-1,i)*pow(xRad, n) / factorial(n));
			n += 2;
		}//end of else
	}// end of for loop
	n += 2;
	for (int i = 0;i < 3;i++ )
	{
		if (i == 1)
		{
			Sx = xRad;
		}
		else {

			Sx = Sx + (pow(-1, i)*pow(xRad, n) / factorial(n));
			n += 2;
		}//end of else
	}// end of for loop

	fError = fabs((sin(xRad) - cos(xRad)) - (Cx - Sx));
	printf("\n Sx = %lf Cx = %lf total = %lf \n", Sx,Cx,fError);
		return 0;
}//end of main

int factorial(int n) {
	if (n > 1)
	{
		return n*factorial(n - 1);
	}
	else
		return 1;
}
