//program zliczajacy liczbe spacji, tabulatorów oraz wierszy na stdin
//po wywolaniu ./a.out bedziemy mogli pisac ile chcemy i aby zakonczyc ten tryb trzeba wcisnąć ctrl+d i wtedy wyswietla nam sie zliczone dane dot. tego co wypisalismy

#include <stdio.h>

int main(){

        int c;//nie mozna uzywac char dla EOF
        int t=0, s=0, n=0;

        while ((c=getchar()) != EOF){
                if (c == ' ') s++; //kazdy znak, nawet spacja, jest stałą znakową i ma wartóść liczbową
                if (c == '\t') t++;
                if (c == '\n') n++;
        }

        printf("\nspacje: %d\ntabulatory: %d\nwiersze: %d\n",s, t, n);

        return 0;
}
