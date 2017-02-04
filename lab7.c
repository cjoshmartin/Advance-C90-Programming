/*
*Name: Josh Martin
*Lab 7
*/


#include <stdio.h>
#include <stdlib.h> //fixes problems with srand and rand
#include <ctype.h>
#include <time.h>
//variables for checking chars
char checkLetter;
int checknum;

void getPosition();

int main(void) {

	/*
	code from worksheet
	*/
	int wloc, num;
	srand(time(NULL));
	wloc = rand() % (7) + 65;
	num = rand() % (7) + 1;
	char location = (char)wloc;
	//printf("\n%c%d\n\n", location, num); // debug line

	/*
	main code
	*/
	printf("Guess the position\n");
	while(1){
		getPosition();

		if (checkLetter == location && checknum == num){
			printf("\nYou found the wumpus!\n");
			break;
		}
		else
			printf("\nTry again\n");
	}
	return 0;
}

void getPosition(){
char cha;
/*
reads what the use has entered
*/
while ((cha = getchar()) != '\n'){
	if (isalpha(cha))
		checkLetter = cha;
	else if (isalnum(cha))
		//the '0' case the cha to int
		checknum = cha - '0';
}//end while

/*
error handing
*/

if ((int)checkLetter < 65 || (int)checkLetter > 71){
	//error handing for unvaild letters
	while (1){ // loop goes until if statement is true
		printf("Sorry input was unvaild\nPlease enter a letter that is capitalized and between A-G :  ");
		scanf("%c", &checkLetter);
		if ((int)checkLetter >= 65 && (int)checkLetter <= 71){
			printf("\n%c%d", checkLetter, checknum);
			break;
		}
	}
}
// check if number is in number set
if (checknum > 7 || checknum < 0){
	while (1)
	{
		printf("Sorry input was unvaild\nPlease enter a number between 1-7 :  ");
		scanf("%d", &checknum);
		if (checknum <= 7 && checknum > 0){
			printf("\n%c%d", checkLetter, checknum);
			break;

		}
	}
}

}//end of function
