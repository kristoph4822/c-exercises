#include "mat_io.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Zwraca <> NULL - udalo sie wczytac
 * Zwraca == NULL - podczas wczytywania wystapil blad
 */
Matrix * readFromFile(char * fname) {//argument to nazwa pliku
        int r,c;
        int ir, ic;//i of rows and i of columns
        FILE * fin =  fopen(fname,"r");
        Matrix * mat = NULL;//struktura Matrix zdefiniowana jest w mat_io.h

        if (fin != NULL) {
          fscanf(fin,"%d %d",&r,&c);
          mat = createMatrix(r,c);
          if (mat != NULL) {
            for (ir = 0; ir < r; ir++)
              for (ic = 0; ic < c; ic++)
                fscanf(fin, "%lf",&(mat->data[ir][ic]));
          } else {
                fprintf(stderr,"Wystąpił problem podczas tworzenia macierzy o rozmiarach %d x %d dla danych z pliku: %s\n", r, c, fname);
          }

          fclose(fin);
        } else {
                fprintf(stderr,"Nie mogę otworzyć pliku o nazwie: %s\n", fname);
        }

        return mat;
}

void printToScreen(Matrix *mat) {
  int i,j;
  printf("[ \n");
  for (i = 0; i<mat->r; i++) {
    printf("  ");
    for (j = 0; j < mat->c; j++) {
      printf("%12f ", mat->data[i][j]);
    }
    printf("; \n");
  }
  printf("]\n");
}

Matrix * createMatrix(int r, int c) {//alokowanie pamięci macierzy
    int i;
    Matrix * mat = (Matrix*) malloc(sizeof(Matrix));//tworzymy macierz
    if (mat != NULL) {
      mat->r = r;
      mat->c = c;
      mat->data = (double**) malloc(sizeof(double*) * r);
      /* teraz ustalamy ile dokładnie miejsca na dane macierzy chcemy zarezerwować
       * każdemu wskaźnikowi musimy przypisać pamięć osobno
       * tutaj double** to wiersze zaś double* to kolumny*/
      for (i=0; i < r; i++) {
          mat->data[i] = (double*) malloc(sizeof(double) * c);
      }
    }

    return mat;
}

void freeMatrix(Matrix * mat) {
  int i;
  for (i=0;i < mat->r; i++)
    free(mat->data[i]);//pamięć zwalniamy wspak
  free(mat->data);
  free(mat);
}
