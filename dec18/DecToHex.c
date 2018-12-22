//zamiana z sys. dziesiątkowego na szesnastkowy
//pierszy argument to liczba w sys. dziesietnym

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char **argv){
	
	//...kontrola błędów...
	
	int dec = atoi(argv[1]);
	
	int reszta[10], i=-1;

	while (dec >= 1){
		i++;
		reszta[i] = dec % 16;
		dec-=reszta[i];
		dec/=16;
	}

	int j = 0;

	for (i; i>=0 ; i--){
		reszta[i] += (reszta[i]<10) ? '0' : ('A'-10);	
		printf("%c", reszta[i]);
		j++;}
	
	printf("\n");
	
	return 0;
}	
