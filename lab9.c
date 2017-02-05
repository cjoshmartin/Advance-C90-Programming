/*
* Josh Martin
* Lab 9
* Note to self: program works because arrays are techinal pointers. The array can be passed in a function call and has it value in main changed
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillarray(int a[][3]);

void disparray(int a[][3]);

void avgarray(int a[][3], float b[]);

int main() {
	srand(time(NULL));

	int team1[3][3],team2[3][3], i, yellow1=0,yellow2=0;
	
	float teamavg1[3], teamavg2[3], avg1=0, avg2=0, temp;
	fillarray(team1);
	disparray(team1);
	printf("\n");
	avgarray(team1, teamavg1);
	fillarray(team2);
	disparray(team2);
	avgarray(team2, teamavg2);

	for (i = 0; i < 3; i++) {
		printf("Team1 goals per game for player %d is %f \n", i + 1, teamavg1[i]);
		avg1 += teamavg1[i];
		yellow1 += team1[2][i];
	}
	temp = avg1 / i;
	avg1 = temp;

	printf("\n\n");
	for (i = 0; i < 3; i++) {
		printf("Team2 goals per game for player %d is %f \n", i + 1, teamavg2[i]);
		avg2 += teamavg2[i];
		yellow2 += team2[2][i];
	}
	printf("\n");

	if (avg1 > (avg2 / i))
		printf("Team 1 is better %lf %lf \n", avg1, avg2 / i);
	else if (avg1 < (avg2 / i)) {
		printf("Team 2 is better %lf %lf \n", avg2/i, avg1);
	}
	if (yellow1 >yellow2)
		printf("Team 1 is more disciplined %d %d \n", yellow1, yellow2);
	else if (yellow1 < yellow2) {
		printf("Team 1 is more disciplined %d %d \n", yellow2, yellow1);

	}

	return 0;
}

void fillarray(int a[][3]) {
	int i;
	for (i = 0; i < 3; i++)
	{
		a[i][0] = (rand() % 10) + 1;
		a[i][1] = (rand() % 6) + 1;
		a[i][2] = (rand() % 4) + 1;
	}
}


void avgarray(int a[][3], float b[]) {
	int i;
	for (i = 0; i < 3; i++)
		b[i] = (float)a[i][1] / a[i][0];
}
void disparray(int a[][3]) {
	int i, j;
	printf("Player Matches Goals YC\n");
	for (i = 0; i < 3; i++) {
		printf("%2d ", i + 1);
		for (j = 0; j < 3; j++)
		{
			printf("%6d ", a[i][j]);
		}
		printf("\n");
	}// end of for loop
}//end of disparray

