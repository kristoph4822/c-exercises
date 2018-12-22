//jezeli wypiszemy klika spacji z rzedu, program zamieni je na jedną spację

#include <stdio.h>

int main(){

	int c, b;

	while((c=getchar()) != EOF){
		if (c == ' '){ //jeżeli chcemy by wgl nie bylo spacji napiszemy if (c== ' ');
                        while((b=getchar())==' ')
                                ; //wykonujemy petle, czyli odczytujemy kolejne znaki (ale nic z nimi nie robimy), poki są one równe spacji, mozna rowniez zrobic z petla for
                       	putchar(c); //wypisujemy c czyli spacje
                        putchar(b);} //wypisujemy b czyli pierwszy znak po spacjach

		else putchar(c);}
	return 0;
}
