//program liczacy wiersze, slowa i litery
//teoretycznie program pownien przyjac liczbe wierszy = 1 jako wartosc domyslna
#include <stdio.h>

int main(){

	int w=0, s=0, l=0;
	int c, d;
	while ((c=getchar()) != EOF){
		if(c=='\t'||c==' ');
		if(c=='\n') w++;
		if(c!=' '&&c!='\t'&&c!='\n'){
			s++; l++;//zwiekszamy litery o 1 gdyz d=getchar() zacznie czytac od nastepnej
			while((d=getchar())!=' '&&d!='\t'&&d!='\n') l++;
			if (d=='\n') w++;}//musimy uwzglednic wariant ze d bedzie znakiem nowego wiersza
	}
	       	      
		
	printf("w: %d\ns: %d\nl: %d\n", w, s, l);
	return 0;
}
