#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	int i=0;
	while(argv[i] != '\0'){
		if(i==0){
			printf("%s:",argv[i]);
		}
		else if(strcmp(argv[i],"bitti")==0){
			break;
		}
		else{
			printf(" %s",argv[i]);
		}
			
		i++;
	}
	return 0;
}
