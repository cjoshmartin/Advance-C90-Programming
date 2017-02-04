#include <stdio.h>

/*
Program Name: Lab 1
Author's name: Josh Martin
Class Date: 8/26/2016
Descripton: cost of grass carpeting
*/
int main(void) {
	float pool, fountain, garage, mudroom, total_area, sq_cost, total_cost, width, height;

	printf("Input the cost of carpeting per square foot: ");
	scanf("%f", &sq_cost);
	printf("Enter the width: ");
	scanf("%f", &width);
	printf("Enter the Height: ");
	scanf("%f", &height);
	total_area = width*height;
	float doubl_f = (3.14 * (5 / 2)) * 4;
	float doubl_d = (25 * 25);
	fountain = doubl_f + doubl_d;
	mudroom = ((30 * 20) - ((6 * 13) / 2));
	pool = (70 * 35 - (5 * 7 * 2));
	garage = (30 * 35);

	printf("Pool area in square feet is %f \n", pool);
	printf("Fountain area in square feet is: %f \n", fountain);
	printf("Garage area in square feet is: %f \n", garage);
	printf("mudroom area in square feet is: %f \n", mudroom);
	printf("Total area in square feet is: %f \n", total_area);
	printf("the cost of carpeting per square foot: %f \n", sq_cost);


	printf("total grass carpeting cost in US$ is %f\n", (total_area - (garage + fountain + pool + mudroom))*sq_cost);

	return 0;
}




