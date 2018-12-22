//program generujacy losowy wektor i sortujacy go malejaco przy pomocy qsort
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> // do srand(time(NULL))
#define MAX 12

void los(int *tab, int dlugosc);

void wypisz(int *tab, int dlugosc);

int uporzMal (const void *a, const void *b);//prototypy funkcji


int main(int argc, char **argv){ //char **argv to to samo co char *argv[]
	
	int n = argc>1 ? atoi(argv[1]) : MAX;//dlugosc wektora podajemy jako pierwszy argument
	
	int *tab = malloc(n*sizeof(*tab));
	
	los (tab, n);
	printf("Wygenerowany wektor: "); wypisz (tab, n);

	qsort(tab, n, sizeof(tab[0]), uporzMal);
	printf("Posortowany wektor: "); wypisz (tab, n);

	free (tab); //zwalniamy pamiec	

	return 0;}

	
void los(int *tab, int dlugosc){ //wypelnia wektor losowymi liczbami (1-100)
        srand(time(NULL));
        for (int i=0; i<dlugosc; i++)
                tab[i]=(rand()%100)+1;
}

void wypisz(int *tab, int dlugosc){ //ladnie wypisuje wektor
        printf("[ ");
        int i=0;
        for (i; i<dlugosc-1; i++)
                printf("%d, ", tab[i]);
        printf("%d ]\n", tab[i]);}

int uporzMal (const void *a, const void *b){ //funkcja porównująca do qsort
    return ((*(int*)a) - (*(int*)b))*(-1);}	

	


