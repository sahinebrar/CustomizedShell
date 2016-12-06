#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//girilen arrayin uzunlugunu buluyor.
int size(char *w[]){
	int size=0;
	int i = 0;
	while(w[i] != '\0'){
		size++;
		i++;
	}
	return size;
}

//ekrandan alınan line eger & iceriyorsa bunu bize soyluyor.
int ampersan(char *w[]){
    	int i=0;
    	int bool=1;
  	int size2= size(w);
	if(size2==2 || size2==3 || strcmp(w[0],"cat")==0){
		bool=1;
	}
	else if(size2>3){
		bool=0;
	}
    return bool;
}
int main(int argc, char *argv[], char ** envp){
    int k=1;
    //dongunun icinde kaldırıyoruz cunku her seferinde bizim komutlarımıza hazır olsun diye
    while(k==1){
	//exit girilinceye kadar myshell gozukucek.
        printf("myshell>>");
	//ekrandan giriceleck girdiyi atacagimiz arrayi tanımladık.
        char **newargv= malloc(32 * sizeof(char*));	
        char *input = NULL;
        ssize_t bufsize = 32;
        getline(&input, &bufsize, stdin);
        const char *bosluk=" ";
        char * word;
        int x=0;
        word= strtok(input,bosluk);
	//girdiyi bosluklara ayırıyoruz.
        while(word != NULL){
            newargv[x]= word;
            x++;
            word= strtok(NULL,bosluk);
            if (x >= bufsize) {
                  bufsize += 32;
                  newargv = realloc(newargv, bufsize * sizeof(char*));
            }
        }
	//ampersanda yapılacak bir kontrol için 
	newargv[size(newargv)]="bitti";
        int bool= ampersan(newargv);
	//eger bir donerse & yok vve bu ifin içine gir.
        if(bool==1){
            int i;
            int f;
		//exit yazıldıysa prrogramdan çık.
            	if(strncmp(newargv[0],"exit",2) ==0){
            		break;
		}
		//forkla..
            	f= fork();
                if(f==0){
		    //plustwo ise if in içine gir.
                    if(strcmp(newargv[0],"plustwo") ==0){
			//alt programı cagir. argümanları yolla.
                        i= execve("plustwo",newargv,envp);
                        free(input);
                    }
		    //minustwo ise else if in içine gir.
                    else if(strcmp(newargv[0],"minustwo") ==0){
			//alt programı cagir. argümanları yolla.
                        i=execve("minustwo",newargv,envp);
                        free(input);
                    }
	            //factorial ise else if in içine gir.
                    else if(strcmp(newargv[0],"factorial") ==0){
			//alt programı cagir. argümanları yolla.
                        i=execve("factorial",newargv,envp);
                        free(input);
                    }
                    else if(strncmp(newargv[0],"clear",3) ==0){
			//ekranı temizle.
			system("clear");
                    }
		    //cat ise else if in içine gir.
                    else if(strcmp(newargv[0],"cat") ==0){
			//cat in yanında yazılanları ekrana bas.
                        i=execve("cat",newargv,envp);
                        free(input);
                    }
		    //komut tanımlanamadı.
                    else{
                        printf("Yanlis bir komut girdiniz.\n");
                    }
                }
                else{
                    wait(&i);
                }
        }
	//bool==0 ise & var.
        else{
            int i=0;
            //ampersana kadar olanları tutacak diziyi tanımladık.
            char **word2= malloc(4 * sizeof(char*));
            int j=0;
	    //dongunun sonlanma şartı.
            while(newargv[i] != "bitti"){
		//ampersana eşit değiise diziye at.		
                if(strcmp(newargv[i],"&")!=0){
                    word2[j]= newargv[i];
                    j++;
		    word2[3]= "\0";
                }
		//ampersana eşitse veya bittii ye eşitse içeri gir ve forkla.
                if(strcmp(newargv[i],"&")==0 || strcmp(newargv[i+1],"bitti")==0){
                    int m=0;
                    int f;
	            if(strncmp(newargv[0],"exit",4) ==0){
            	    	break;
		    }
                    f= fork();
                    if(f==0){
                        if(strcmp(word2[0],"plustwo") ==0){                            
                            m= execve(word2[0],word2,envp);
                            free(input);
                        }
                        else if(strcmp(word2[0],"minustwo") ==0){
                            m=execve("minustwo",word2,envp);
                            free(input);
                        }
                        else if(strcmp(word2[0],"factorial") ==0){
                            m=execve("factorial",word2,envp);
                            free(input);
                        }
                        else if(strncmp(word2[0],"clear",3) ==0){
			   system("clear");
                        }
                        else if(strcmp(word2[0],"cat") ==0){
                            m=execve("cat",word2,envp);
                            free(input);
                        }
                        else{
                            printf("Yanlis bir komut girdiniz.\n");
                        }
                    }
                    else{
                        wait(&m);
                    }
                    j=0;
                }
                i++;
            }
        }

    }
	return EXIT_SUCCESS;
}

