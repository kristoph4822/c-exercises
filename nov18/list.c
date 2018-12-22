//program tworzacy chronologiczną listę liczb 
//pierwszy argument jest liczbą, którą chcemy dodać do listy
//LIM okresla jak dluga liste chcemy wygenerowac

#include <stdio.h>
#include <stdlib.h>
#define LIM 10
#include <time.h>
 
 typedef struct element {//tworzy skrótową nazwę dla struktury element
   struct element *next;
   int val;
 } el_listy;//skrótowa nazwa
 
 el_listy *first;//tworzymy wskaźnik na obiekt typu struct element

 void dodajw_liste (el_listy *lista, int x){//funkcja dodaje liczbę x w odpowiednie miejsce listy liczbowej
	 el_listy *wsk;
	 wsk=lista;
	 if(wsk->val > x){//jeżeli podamy l. mniejsza od pierwzego el. listy
		 el_listy *nowy=malloc(sizeof(el_listy));
		 nowy->val=wsk->val;
		 nowy->next=wsk->next;
		 wsk->val=x;
		 wsk->next=nowy;
		 }
	 else {
		while((wsk->next->val <= x) && (wsk->next->next != NULL)){
		 wsk=wsk->next;}
 	el_listy *nowy=malloc(sizeof(el_listy));
	nowy->val=x;
	nowy->next=wsk->next;
	wsk->next=nowy;
	 if (nowy->next->val < x){ //jeżeli podamy l. wieksza od ostatniego el. listy
	int temp = nowy->next->val;
	 nowy->next->val=x;
	 nowy->val=temp;}}}

 void dodaj_do_listy (el_listy *lista, int liczba)//dodaje elementy na koniec listy
 {
   el_listy *wsk, *nowy;
   wsk = lista;
   while (wsk->next != NULL)//zatrzymujemy sie na ostatnim wskazniku
     { 
     wsk = wsk->next; /* przesuwamy wsk aż znajdziemy ostatni element */
     }
   nowy =(el_listy*) malloc (sizeof(el_listy));
   nowy->val = liczba;
   nowy->next = NULL;
   wsk->next = nowy; /* podczepiamy nowy element do ostatniego z listy */
 }
 
 void wypisz_liste(el_listy *lista)
 {
   el_listy *wsk=lista;
   while( wsk != NULL )//lecimy przez wszystkie wskazniki
     {
     printf ("%2d  ", wsk->val);
     wsk = wsk->next;
     }
   puts("\n");
 }
 
 int main (int argc, char **argv)
 {
   int d=atoi(argv[1]);
   first =(el_listy*) malloc (sizeof(el_listy));
   first->val = 5;
   first->next = NULL;
   for (int i=0;i<LIM-1;i++) {
       dodaj_do_listy (first, i*5+10);
       }
   wypisz_liste(first);
   dodajw_liste(first, d);
   wypisz_liste(first);
   return 0;
 }
