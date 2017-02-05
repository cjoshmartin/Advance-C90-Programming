#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLENTHNAME 20
#define MAXLENTHORDER 30

typedef struct name{
	char names[MAXLENTHNAME];
	int size;
} name;

typedef struct order{
	char orders[MAXLENTHORDER];
	int size;
} order;

void creates(name a[], order b[], int index, int index2, char ans[90]);
void findreplace(char*, char*, char*);

int main(void) {
	name nam[MAXLENTHNAME];
	order ord[MAXLENTHORDER];
	int i = 0, n = 1;
	char stringss[90];

  printf("%s\n","please type something:" );
	while (n==1){
		scanf("%s", nam[i++].names);
		if (getchar() == '\n')
			n = 0;
	}
	nam[0].size = i;

	i = 0;
	while (n==1){
		scanf("%s", ord[i++].orders);
		if (getchar() == '\n')
			n = 0;
	}

		ord[0].size = i;
		creates(nam, ord, 0, 2, stringss);

    printf("%s\n",stringss);
		return 0;

}

void creates(name a[], order b[], int index, int index2, char ans[90]){
		strcpy(ans, a[index].names);
		strcpy(ans, " Loves ");
		strcpy(ans, b[index2].orders);
}

void findreplace(char *search, char *find, char *replace){
  char *temp, temparray[500]="";
  int ind =0;
  do{
    strcat(temparray,temp);
  }while(temp!=NULL);
  strcpy(toSearch,temparray);
  if(occurances==0)
  printf("String not found\n");
}
