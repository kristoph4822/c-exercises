#include "bh.h"

void tab(int *t[], int n){
	for (int i=0;i<n;i++) *t[i]=0;}

void zlicz(int *t[]){
	int c;
	  while ((c=getchar())==EOF){
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
                        default: ;
                }}}

int max(int *tab[], int n){
	int m = *tab[0];
	for(int i=0; i<n;i++){
		if(m <= *tab[i+1]) m = *tab[i+1];}
	return m;}

void histogram(int *tab[], int n, int max){
	printf("NULL\n");
	for (int i=max;i>=1;i--){
		printf("%d\t", i);
		for(int x=0;x<10;i++){
			*tab[x]>=i ? printf("* ") : printf("  ");}
		printf("NULL\n");}
	printf(" \t0 1 2 3 4 5 6 7 8 9\n");}

