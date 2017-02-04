#include <stdio.h>

int main(void) {
  int h1,h2,h3,i,j,k;
  char plus[50]={""};
  printf("enter the value of h1: ");
  scanf("%d",&h1);

  printf("\n enter the value of h2: ");
  scanf("%d",&h2);

  printf("\nenter the value of h1: ");
  scanf("%d",&h3);

  //I like for loops :)

  //starloop
  for(i=1;i<h1;i++)
  {
    for ( j=h1; i < j;j--) {
      printf(" " );
    }
    for (k=1;k<2*i;k++){
      printf("*");
    }
    printf("\n");
  }//end of outerloop

  // Plus "string"
  for (i = 0; i < h1+5; i++) {
    printf("+");
  }
  //Zero Loop
  printf("\n");
  for(i=0; i < h2;i++)
  {
    for (j= 0; j < h1+4; j++) {
      printf("0");
    }
    printf("0\n");
  }

  for (i = 0; i < h1+5; i++) {
    printf("-");
  }
  printf("\n");


  for(i=0; i<h3;i++)
  {
    for (j= 0; j < h1+5; j++) {
      printf("|");
    }
    printf("\n");
  }

  for (i = 0; i < h1+5; i++) {
    printf("-");
  }
  printf("\n");

  return 0;
}
