#include "gauss.h"
#define ZERO 0.00000000001 
#include <stdio.h>
#include <math.h>// do fabsa
/**
 *  * Zwraca 0 - elimnacja zakonczona sukcesem
 *   * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 *    */
int eliminate(Matrix *mat, Matrix *b){
	    /**
	     *      Wyzerowanie dolnej połowy macierzy
	     *      od kolejnych wierszy odejmujemy pierwszy wiersz
	     *      przemnożony przez taki współczynnik m aby pierwszy wyraz 
	     *      kazdego wiersza sie zerował, nastepnie odejmujemy drugi wiersz 
	     *      tak aby drugi wyraz kazdego wiersza sie zerowal itd...
	     *         */
	double m;
	for(int i=0;i< (mat->r)-1;i++){//kolejne wiersze ktore odejmujemy, od 1. do przedostatniego
		for (int j=i+1;j<(mat->r);j++){//kolejne wiersze od ktorych odejmujemy, od drugiego do ostatniego
			if(fabs(mat->data[i][i])< ZERO){
				fprintf(stderr,"Macierz osobliwa!\n");
				return 1;}
			m=(mat->data[j][i])/(mat->data[i][i]);//wspolczynnik
			for(int k=i;k<mat->c;k++){//kolejne kolumny 
				(mat->data[j][k])-=m*(mat->data[i][k]);}
		(b->data[j][0])-=(b->data[i][0])*m;
		}}


	    return 0;
}
