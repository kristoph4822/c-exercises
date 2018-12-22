//HISTOGRAM CYFR WYSTEPUJACYCH W TEKSCIE NA STDIN
#include <stdio.h>

int main(){

	int t[10];
	int n =10;

        for (int i=0;i<n;i++) t[i]=0;

        int c;

       	while ((c=getchar())!=EOF){
                switch (c){
			case '0': t[0]++; break;
                        case '1': t[1]++; break;
                        case '2': t[2]++; break;
                        case '3': t[3]++; break;
                        case '4': t[4]++; break;
                        case '5': t[5]++; break;
                        case '6': t[6]++; break;
                        case '7': t[7]++; break;
                        case '8': t[8]++; break;
                        case '9': t[9]++; break;
                }}

        int m = t[0]; //ZNAJDUJEMY MAKSYMALNA WARTOSC W WEKTORZE (CZEGO JEST NAJWIECEJ)
        for(int i=0; i<n-1;i++){
                if(m <= t[i+1]) m = t[i+1];}

        printf("\n");

        for (int i=m;i>=1;i--){ //ZACZYNAMY ODLICZANIE W DÓŁ OD MAKSYMALNEJ WARTOSCI W WEKTORZE 
                printf("%d\t", i);
                for(int x=0;x<10;x++){//DLA KOLEJNYCH EL TABLICY SPRAWDZAMY CZY SA >= OD STOPNIOWO ZMIENJSZANEJ WARTOSCI MAKS
 			t[x]>=i ? printf("* ") : printf("  ");}
                printf("\n");}

        printf(" \t0 1 2 3 4 5 6 7 8 9\n");	

	return 0;}

