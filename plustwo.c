#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	int num1,num2;
	int i;
	num1= atoi(argv[1]);
	num2= atoi(argv[2]);
	int j;
	int sonuc= num1 + num2;
	printf("%d + %d = %d\n",num1,num2,sonuc);
	return(0);
}
