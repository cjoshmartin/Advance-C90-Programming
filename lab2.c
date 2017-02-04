#include<stdio.h>

int main(void) {
	/*
	Lab Name: Lab 2
	Name: Josh Martin
	Description: Interest rate
	*/
	// main function
	const char *names[2];
	names[0] = "Paula Gander";
	names[1] = "Lyle Bowers";
	 int net_loan[2], duration[2];
	float interest_rate[2], loan_face[2], monthly[2];
	int j, i;
	for (j = 0;j < 2;j++) {
		//gets user input
		printf("Enter the loan net amount, interest rest percent and the duration of the loan for %s \n", names[j]);
		scanf("%d %f %d", &net_loan[j], &interest_rate[j], &duration[j]);
		loan_face[j] = net_loan[j] / (1-interest_rate[j]*duration[j] / 12);

		monthly[j] = loan_face[j] / duration[j];



	}//end of first for loop

	printf("Name\t \t|Loan Net\t\t|Interest rate\t|Loan Duration in Months|\tLoan Face Value|\tMonthly Payment\n");
	for (i = 0; i < 2;i++) {
		printf("%s \t%d \t\t\t\t%.2f \t\t%d \t\t\t\t%.2f \t%.2f \n", names[i], net_loan[i], interest_rate[i], duration[i], loan_face[i] , monthly[i]);
	}//end of second for loop
	getchar();
	return 0;
}//end of function
