#include <stdio.h>
#include <stdlib.h>

char *tasm_wej(int m, int n){//generowanie taśmy wejściowej

	int dlug = m + n + 2; //dodatkowe 2 miejsca dla 1 i B
        char *tasma = malloc (dlug * sizeof(char*));
	int i=0;

	while (i != m){//przedtawiamy pierwszą liczbę na taśmie w postaci zer
		tasma[i] = '0';
		i++;
	}

	tasma[i] = '1';//rozdzielamy liczby jedynką
	i++;

	while (i != m + n + 1){//druga liczba w postaci zer
		tasma[i] = '0';
		i++;
	}
	
	tasma[i] = 'B';//symbol pusty na koniec
	
	return tasma;
}

int policz_zera(char *tasma){//zliczanie zer na taśmie

       	int i=0, j=0;

	while (tasma[i] != '\0'){

		if (tasma[i] == '0') j++;
		i++;
	}

	return j;
}

int main(){
	
	//funkcje przejść zapisujemy jako tablicę dwuwymiarową
	int stany[7][3] = { {1, 5, -1} , {1, 2, -1} , {3, 2, 4} , {3, 3, 0} , {4, 4, 6} , {5, 5, 6} , {-1, -1, -1} };
	char symbol[7][3] = { {'B', 'B', '-'} , {'0', '1', '-'} , {'1', '1', 'B'} , {'0', '1', 'B'} , {'0', 'B', '0'} , {'B', 'B', 'B'} , {'-', '-', '-' } };
	char przejscie[7][3] = { {'P', 'P', '-'} , {'P', 'P', '-'} , {'L', 'P', 'L'} , {'L', 'L', 'P'} , {'L', 'L', 'P'} , {'P', 'P', 'P'} , {'-', '-', '-' } };

	//opis MT
	printf("*******************************************************************************\n");
	printf("*                                                                             *\n");
	printf("*                Emulator MT obliczający rożnicę właściwą                     *\n");
	printf("*                                                                             *\n");
	printf("*     M = ({q0, q1, q2, q3, q4, q5, q6}, {0, 1}, {0, 1, B}, δ, q0, B, 0)      *\n");
	printf("*                                                                             *\n");
	printf("*                Dostepne opcje:                                              *\n");
	printf("*                1) Odczytaj z pliku, zapisz do pliku                         *\n");
	printf("*                2) Odczytaj z pliku, wyświetl na ekran                       *\n");
	printf("*                3) Odczytaj z ekranu, zapisz do pliku                        *\n");
	printf("*                4) Odczytaj z ekranu, wyświetl na ekran                      *\n");
	printf("*                                                                             *\n");
    	printf("*******************************************************************************\n");

	int m, n, wybor, tmp;
	FILE *input, *output;
	char plik[15], nvm;
	
	printf("Wybierz opcje: ");//przyjmujemy wybór użytkownika
	scanf("%d", &wybor);

	if (wybor < 1 || wybor > 4){
		fprintf(stderr,"\nPodano niewlasciwa wartosc!\n");
		return 1;
	}
	
	if (wybor == 1 || wybor == 2){//wybranie odczytu z pliku

		printf("\nPodaj nazwę pliku do odczytu: ");
		scanf("%s", plik);
		input = fopen (plik, "r");

		if (!input){
                        fprintf(stderr, "\nNie można otworzyć tego pliku\n");
                        return 2;
                }
	
		if (fscanf(input,"%d %d %c", &m, &n, &nvm) != 2){//kontrola błędów odczytu z pliku
		  	fprintf(stderr,"\nBłędne dane w pliku\nPlik powinien zawierać jedynie dwie liczby całkowite\n");
			return 3;
		}		
	}	

	if (wybor == 3 || wybor == 4){//wybranie odczytu z stdin

		printf("\nPodaj pierwszą liczbę całkowitą: ");
                if (scanf("%d", &m) == 0 || m < 0){
			fprintf(stderr, "\nNie podano dodatniej liczby całkowitej\n");       
			return 4;
		}
                printf("\nPodaj drugą liczbę calkowitą: ");
		if (scanf("%d", &n) == 0 || n < 0){
                	fprintf(stderr, "\nNie podano dodatniej liczby całkowitej\n");
		      	return 4;
	       	}
	}

 	if (wybor == 2 || wybor == 4) output = stdout;//wybranie wyswietlenia na stdout
	
	if (wybor == 1 || wybor == 3){//wybranie zapisu do pliku

                printf("\nPodaj nazwę pliku do zapisu: ");
                scanf("%s", plik);
                output = fopen (plik, "w");

                if(!output){
                        fprintf(stderr, "\nNie można otworzyć tego pliku\n");
                        return 4;
                }
        }

	if (m < n) {
        	printf("\nPierwsza liczba jest mniejsza od drugiej liczby\n");
		printf("Wynik = 0\n");
        	return 0;
    	}
	
        char *tasma = tasm_wej (m, n);//generujemy tasme wejsciowa
	
	int stan = 0, glowica = 0, err = 0;

	fprintf(output, "\nWczytano %d i %d\n", m, n);
	fprintf(output, "%s         Pozycja głowicy: %d   Stan: %d\n", tasma, glowica, stan);//stan początkowy
	
	while (err != 1){
		
		switch (tasma[glowica]){//zależnie od przeczytanego znaku

			case '0': if (stany[stan][0] == -1){
					  err = 1; 
					  break;
				  }
				  tasma[glowica] = symbol[stan][0];//zmieniamy znak na tasmie
				  if(przejscie[stan][0]=='P') glowica += 1;
  				  else glowica -= 1;//przesuwamy głowice
  				  tmp = stany[stan][0];
  				  stan = tmp;//zmieniamy stan
				  break;
		           	
		  			
			case '1': if (stany[stan][1] == -1){
					  err = 1; 
					  break;
				  }
				  tasma[glowica] = symbol[stan][1];
      				  if(przejscie[stan][1]=='P') glowica += 1;
				  else glowica -= 1;
				  tmp = stany[stan][1];
				  stan = tmp;
				  break;
					
			case 'B': if (stany[stan][2] == -1){ 
					 err = 1;
				  	 break;
				  }
				  tasma[glowica] = symbol[stan][2];
				  if(przejscie[stan][2]=='P') glowica += 1;
				  else glowica -= 1;
				  tmp = stany[stan][2];
				  stan = tmp;
				  break;
		}
		
		if (err != 1){	//wypisujemy aktualny stan rzeczy
		fprintf(output, "%s         Pozycja głowicy: %d   Stan: %d\n", tasma, glowica, stan);
	}}

	//liczymy zera i wyświetlamy różnicę
	fprintf(output,"Różnica wynosi %d\n", policz_zera(tasma));

	return 0;
}
