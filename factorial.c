#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	long num1;
	num1= atoi(argv[1]);
	long sonuc=1;
	int i;
	for(i=1; i<=num1; i++){
		sonuc= sonuc* i;
	}
	printf("%li!= %li\n",num1,sonuc);
	return(0);
}
