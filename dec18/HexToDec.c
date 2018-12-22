//zamiana z szesnastkowego na dziesietny z wykorzystaniem schematu Hornera

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv){

	//...kontrola błędów....

	int wynik = argv[1][0];
	wynik -= isdigit(wynik) ? '0' : ('A'-10);

	for(int i=1; i < strlen(argv[1]); i++){
		
		int wsk=argv[1][i];
		wsk -= isdigit(wsk) ? '0' : ('A'-10); //dopasowujemy wartość ASCII do wartości sys. szesnastkowego

		wynik = wynik*16 + wsk;//schemat Hornera

	}

	printf("%d\n", wynik);

	return 0;
}


		

