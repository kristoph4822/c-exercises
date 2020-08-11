//Symulacja automatu skończonego PINF 29.11.2018
//Pierwszym argumentem jest nazwa pliku do odczytu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DANYCH_WEJ 15//limit danych wejściowych

void diagram(FILE *in, char *stan);

int main(int argc, char **argv){
	
	if (argc < 2){
		fprintf(stderr, "Nie podano nazwy pliku z danymi\n");
                return 1;}
			
	FILE *in = fopen (argv[1], "r");
	if (in == NULL){
		fprintf(stderr, "Nie mozna otworzyc pliku\n");
		return 2;}


	char stan[] = "q0";
	printf("\nStan poczatkowy: %s\n", stan);

	diagram(in, stan);
	
	if (stan[1] != '3'){
	       	printf("\nCiag nie zostal zaakceptowany - zla wartosc koncowa\n");
		return 3;}

	else printf("\nCiag zostal zaakceptowany\n");
	
	return 0;
}
					  
void diagram(FILE *in, char *stan){//funkcja wypisująca diagram przejść

	char *q0 = "-> q0 "; char *q1 = "-> q1 "; char *q2 = "-> q2 "; char *q3 = "-> q3 ";
	char wiersz[MAX_DANYCH_WEJ*6+4] = "q0 ";/*łańcuch wiersz, w którym przechowujemy diagram przejść
						6 to dł. łańcuchów q0, q1.., 4 to dł. początkowa łańcucha wiersz */
	int c, cnt = 0;//cnt - licznik odczytanych symboli wejściowych
        while ((c = getc(in)) != EOF){
		
                if (c == '0'){
                        switch (stan[1]) {
                                case '0': stan[1] = '1';
                                          strcat(wiersz, q1);
					  printf("Wczytano %c: %s\n", c, wiersz);
                                          break;
                                case '1': stan[1] = '3';
                                          strcat(wiersz, q3);
					  printf("Wczytano %c: %s\n", c, wiersz);
                                          break;
                                case '2': stan[1] = '0';
                                          strcat(wiersz, q0);
					  printf("Wczytano %c: %s\n", c, wiersz);
                                          break;
                                case '3': stan[1] = '1';
                                          strcat(wiersz, q1);
					  printf("Wczytano %c: %s\n", c, wiersz);
                                          break;}
			cnt++;	
			if (cnt == MAX_DANYCH_WEJ) break;}

		else if (c == '1'){
                        switch (stan[1]) {
                                case '0': stan[1] = '2';
                                          strcat(wiersz, q2);
					  printf("Wczytano %c: %s\n", c, wiersz);
                                          break;
                                case '1': stan[1] = '0';
                                          strcat(wiersz, q0);
					  printf("Wczytano %c: %s\n", c, wiersz);
                                          break;
                                case '2': stan[1] = '3';
                                          strcat(wiersz, q3);
					  printf("Wczytano %c: %s\n", c, wiersz);
                                          break;
                                case '3': stan[1] = '2';
                                          strcat(wiersz, q2);
					  printf("Wczytano %c: %s\n", c, wiersz);
                                          break;}
			cnt++;
			if (cnt == MAX_DANYCH_WEJ) break;}

		else if (c == '\n'||c == '\t'||c == ' ');//pomijamy znaki biale

                else {
			printf("Wczytano %c: ERROR\n\nZle dane wejsciowe\n", c);
			exit(0);
		}}}
