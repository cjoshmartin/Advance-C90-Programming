#include <stdio.h>

int main(void){
  //declars
  char charactertype;
  int health =100;
  int path1,path2,isredo;
  isredo=1;

  do{
  //propmted for input
  printf("Please enter a letter to choose your character, Mage(m) Priest(p) Warrior(w): " );
  scanf("%c",&charactertype);
//test for wrong characters
  while(charactertype!='m'&& charactertype!='p'&& charactertype!='w'){
    printf("\nPlease enter a valied letter for your character: ");
    scanf("%c",&charactertype);
  }

  //gets the first path from the user
  printf("\n Choose a Path 1-3: ");
  scanf("%d",&path1);

//checks for unvaild numbers
  while (path1 > 3 || path1<1){
    printf("\nPlease enter the a vaild number for the first path: ");
    scanf("%d",&path1);
  }

  //second path
  printf("\n Choose a Second Path 4-6: ");
  scanf("%d",&path2);

  //checks for unvaild numbers
  while (path2 > 6 || path2<4){
    printf("\nPlease enter the a vaild number for the second path: ");
    scanf("%d",&path2);
  }

//Magic
switch (charactertype) {
  case 'm': //mage path
    switch (path1) {
      case 1:
        health += health*.10;
        printf("health changed to %d \n ",health);
        break;
      case 2:
        health -= health*.05;
        printf("health changed to %d \n ",health);
        break;
      case 3:
        health -= health*.10;
        printf("health changed to %d \n ",health);
        break;
    }
    switch (path2) {
      case 4:
        health -= health*.05;
        printf("health changed to %d \n ",health);
        break;
      case 5:
        health += health*.10;
        printf("health changed to %d \n ",health);
        break;
      case 6:
        health -= health*.10;
        printf("health changed to %d \n ",health);
        break;
    }
    break;
  case 'p':
      switch (path1) {
        case 1:
          health -= health*.10;
          printf("health changed to %d \n ",health);
          break;
        case 2:
          health += health*.10;
          printf("health changed to %d \n ",health);
          break;
        case 3:
          health -= health*.05;
          printf("health changed to %d \n ",health);
          break;
      }
      switch (path2) {
        case 4:
          health += health*.1;
          printf("health changed to %d \n ",health);
          break;
        case 5:
          health -= health*.10;
          printf("health changed to %d \n ",health);
          break;
        case 6:
          health -= health*.05;
          printf("health changed to %d \n ",health);
          break;
      }
    break;
  case 'w':
        switch (path1) {
          case 1:
            health -= health*.05;
            printf("health changed to %d \n ",health);
            break;
          case 2:
            health -= health*.10;
            printf("health changed to %d \n ",health);
            break;
          case 3:
            health += health*.10;
            printf("health changed to %d \n ",health);
            break;
        }
        switch (path2) {
          case 4:
            health -= health*.05;
            printf("health changed to %d \n ",health);
            break;
          case 5:
            health -= health*.5;
            printf("health changed to %d \n ",health);
            break;
          case 6:
            health += health*.10;
            printf("health changed to %d \n ",health);
            break;
        }
    break;
}


  if(health>=111){
    printf("################\n");
    printf("##  YOU WIN!  ##\n");
    printf("###############\n");
    isredo=0;
  }
  else{
    printf("You Lose :( ... Go again\n");
  }
}while(isredo);
  return 0;
}//end of main function
