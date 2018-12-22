#include "backsubst.h"
#include <math.h>
#include <stdio.h>
#define ZERO 0.000001

int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {//podstawianie wsteczne

		if (mat->r != mat->c){//jezeli macierz nie jest kwadratowa - blad
			fprintf(stderr,"Nieprawidlowy wymiar macierzy!\n");       
			return 2;}
		
		for(int i=(mat->r)-1; i>=0;i--){//kolejne wiersze od dolu
			double s=0;
			for(int j=(mat->r)-1;j>i;j--){//do obliczania s
				s+=(x->data[j][0])*(mat->data[i][j]);}
			if(fabs(mat->data[i][i])<ZERO){
				fprintf(stderr,"Dzielenie przez 0\n");       
				return 1;}
			x->data[i][0]=((b->data[i][0])-s)/(mat->data[i][i]);}
			
			        return 0;
}
