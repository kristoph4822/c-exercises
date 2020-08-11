//Gramatyka Bezkontekstowa PINF 15.12.2018
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct lista {//nasz wyraz zapiszemy jako listę kolejnych znaków
	char litera;
	struct lista *next;
} symbol;

symbol *search_nt(symbol *lista){
	/*szuka na liście pierwszego elementu z symbolem nieterminalnym (A/B/S)
	 *zwraca ten element lub ostatni, jeżeli nie znajdzie wcześniej takiego symbolu*/
	symbol *wsk = lista;
	while (wsk->litera!='A'&&wsk->litera!='B'&&wsk->litera!='S'&&wsk->next!=NULL)
		wsk=wsk->next;
	return wsk;
}	

void add1(symbol *wsk, char znak1){//funkcje add służą do zamiany/dodania elementów listy
	wsk->litera=znak1;
}

void add2(symbol *wsk, char znak1, char znak2){
        symbol *nowy2=malloc(sizeof(symbol));
        nowy2->next=wsk->next;
        nowy2->litera=znak2;
	wsk->next=nowy2;
	wsk->litera=znak1;
}

void add3(symbol *wsk, char znak1, char znak2, char znak3){
        symbol *nowy2=malloc(sizeof(symbol));
        symbol *nowy3=malloc(sizeof(symbol));
        nowy3->next=wsk->next;
        nowy3->litera=znak3;
	nowy2->next=nowy3;
	nowy2->litera=znak2;
	wsk->litera=znak1;
	wsk->next=nowy2;
}

void wyswietl(symbol *lista){//wyswietlanie listy, czyli naszego wyrazu
	symbol *wsk=lista;
	printf(" -> ");
	while(wsk!=NULL){
		printf("%c", wsk->litera);
		wsk=wsk->next;}
}

void zwolnij (symbol *lista){//zwalnianie pamieci po wypisaniu listy
	symbol *wsk=lista;
	symbol *temp;
	while(wsk->next!=NULL){
		temp=wsk;
		wsk=wsk->next;
		free(temp);}
	free(wsk);
}

void generuj(int limit){//generator wyrazu, argument określa nam limit, co pozwala kontrolować długość wyrazu

	symbol *first=malloc(sizeof(symbol));
	first->litera='S';
	first->next=NULL;
	printf("%c", first->litera);

	int cnt=2;
	/*cnt określa ile znaków będzie miał wyraz, jeżeli chcielibyśmy go zakończyć w najkrótszy możliwy sposób
	 *jeżeli cnt jest mniejsze od limitu, wydłużamy wyraz
	 *jezeli cnt przekroczy limit, kończymy wyraz w najkrótszy możliwy sposób*/
	
	symbol *wsk;
	while ((wsk=search_nt(first))!=NULL){//dopóki znajdujemy znak A,B lub S, wykonuj pętle

		if(wsk->litera!='S'&&wsk->litera!='B'&&wsk->litera!='A') break;//jeżeli
		/*search, jezeli nie znajdzie zadnego A,B lub S wczesniej, zatrzymuje się na ostatnim elemencie
	 	* jezeli element ten nie jest A,B lub S to znaczy ze wygenerowalismy wyraz*/
	
		if(cnt>=limit){//kończenie łańcucha w najkrótszy możliwy sposób

			if(wsk->litera=='S'){
                		int a=rand()%2;
               			switch (a) {
                        		case 0: add2(wsk, 'a', 'B'); break;
                        		case 1:	add2(wsk, 'b', 'A'); break;}
				wyswietl(first);}

			else if(wsk->litera=='A'){
		       		add1(wsk, 'a');
		    		wyswietl(first);}	
 
			else if(wsk->litera=='B'){ 
				add1(wsk, 'b');
				wyswietl(first);}}
	

		else if(wsk->litera=='S'){
			int a=rand()%2;//przekształcenia są przeprowadzane losowo
			switch (a) {
				case 0: add2(wsk, 'a', 'B'); break;
				case 1: add2(wsk, 'b', 'A'); break;}
			wyswietl(first);}

		else if(wsk->litera=='A'){
            		int a=rand()%2;
                	switch (a) {
                        	case 0: add2(wsk, 'A', 's'); cnt+=1; break;
				case 1: add3(wsk, 'b', 'A', 'A'); cnt+=2; break;}
			wyswietl(first);}

		else if(wsk->litera=='B'){
                	int a=rand()%2;
                	switch (a) {
                        	case 0: add2(wsk, 'b', 'S'); cnt+=2; break;
				case 1: add3(wsk, 'a', 'B', 'B'); cnt+=2; break;}
			wyswietl(first);}

		wsk=search_nt(first);//rozpoczynamy poszukiwanie symbolu nieterm. od początku
	}
	zwolnij(first);//zwalniamy pamięć(niszczymy listę) po wypisaniu wyrazu
	puts("\n");
}

int main(int n, char **argv){

	if (n<2){
		fprintf(stderr,"Nie podano argumentu\n");
		return 1;}
	if (n>2){
		fprintf(stderr,"Podaj jeden argument!\n");
		return 2;}
	for(int i=0;i<(strlen(argv[1]));i++){
		int z=argv[1][i];
		if (z<48||z>57){//wartosci 48-57 odpowiadają cyfrom 0-9
			fprintf(stderr,"Zły argument\n");
			return 3;}}

	int ile = atoi(argv[1]);
	printf("Opis gramatyki bezkontekstowej: S->aB|bA  A->a|As|bAA  B->b|bS|aBB\n\n");
	srand(time(NULL));
	for (int i=1; i<=ile; i++)
		generuj(i*2);

	return 0;
}



