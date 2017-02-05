  #include <stdio.h>

int isPalindrome(int[]);
int areAdjacent(int[],int,int);
#define SIZE 5
int main(void){
	int t[SIZE];
	int i,num1,num2,istrue=0;

do{
		printf("Enter the array elements\n");
		for (i = 0; i < SIZE; i++) {
			scanf("%d", &t[i]); printf("\n");
		}

		printf("Enter x and y\n");
		scanf("%d", &num1); printf("\n");
		scanf("%d", &num2); printf("\n");

		printf("The two integers are%s adjacent\n",areAdjacent(t,num1,num2)==1?"":" not");

}while(1);

	return 0;
}

int isPalindrome(int *a){
	int *start, *end;
	start =a;
	end =a+SIZE-1;
	while(start!=end){
		if(*start!=*end)
		return 0;
		start++;
		end--;
	}
	return 1;
}

int areAjecent(int a[], int b,int c){
	//assuming SIZE is always five
	int i;
	for (i = 0; i < SIZE; i++)
		if (i < 4 && i>0){
			if (a[i] == b)
				if (a[i-1] == c ||a[i+1]==c)
					return 1;
		}
		if ((a[0]==b && a[4]==c)||(a[0]==c && a[4]==b))
			return 1;
	return 0;
}
