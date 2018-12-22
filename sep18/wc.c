//program liczacy slowa

#include <stdio.h>

int main(){

	int c, d;
	int b=0;

	while ((c=getchar()) != EOF){
		if (c==' ' || c=='\t' || c=='\n')
			;
		else {for(d=getchar(); d!=' '&&d!='\t'&&d!='\n'; d=getchar());
			
			b++;}}
	       	      
		
	printf("liczba slow: %d\n", b);
	return 0;
}
