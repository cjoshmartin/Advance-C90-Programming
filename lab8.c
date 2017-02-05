/*
*Name: Josh Martin
*Lab 8
*/

#include <stdio.h>
#include <math.h>

//quadratic function
void quad(double a, double b, double c);
//factorial function
void fact(long a);
int pyth(int a, int b, int c);


int main() {
	int i;

	do{
		double a, b, c;
		long afact;
		printf("*******************************************************\nMake a choice \n1. Solve a quadratic eqation\n2. Find factorial of a number\n3. Check whether the number form a pyhagorean triplet\nPress 0 to quit!\n******************************************************* \n");
		scanf("%d", &i);
		if (i == 1){
			printf("Enter A,B, and C\n");
			scanf("%lf", &a); printf("\n");
			scanf("%lf", &b); printf("\n");
			scanf("%lf", &c); printf("\n");
			// printf("%lf %lf %lf\n",a,b,c);
			quad(a, b, c);
		}
		if (i == 2){
			printf("Enter number Factorial\n");
			scanf("%d", &afact); printf("\n");
			if (afact < 0)
				printf("this factoral is undefined\n");
			else
			fact(afact);
		}
		if (i == 3){
			printf("Enter A,B, and C\n");
			//fix this shit
			scanf("%lf", &a); printf("\n");
			scanf("%lf", &b); printf("\n");
			scanf("%lf", &c); printf("\n");
			pyth((int)a, (int)b, (int)c);
			//pyth(a,b,c);
		}
		if (i == 0){
			return 0;
		}
	} while (1);
	return 0;
}

void quad(double a, double b, double c) {
	double square = sqrt(pow(b, 2) - 4 * a*c);
	if (a <= 0) {
		printf("\"a\" can't be less then zero\n");
	}
	else if ((pow(b,2) - 4 * a*c) < 0)
	{
		printf("there is no solution to this quadractic.\n");
	}
	else{
		// maybe get this checked I don't know about this always being negitive
		printf("The roots are at %.2lf and %.2lf . \n", (-b + square) / 2 * a, (-b - square) / 2 * a);
	}

}
void fact(long a){
	long sum=1;

	printf("the facatoral of %d ",a);
	for (a; a > 1; a--)
			sum *= a;
	printf(" is %d\n",sum);
		
}
int pyth(int a, int b, int c){
	if ((pow(a, 2) + pow(b, 2)) == pow(c,2)&& a!=0 && b!=0 && c !=0)
	{
		printf("It is a Pythagorean triplet\n");
		return 0;
	}
	printf("Is not a Pythagorean triplet.\n");
	return 0;
}
