//program odwracajacy wiersze 

#include <stdio.h>

int main(){

	int c, d;
	char u[1000];
	char tab[1000];
	int i=0, x=0;

	while((c=getchar())!=EOF){
		
		int i=0;
		tab[i]=c;

		if (c=='\n'){
			u[x]='\n';
			x++;}

		else{	
		       	while ((d=getchar())!='\n'){
			i++;
			tab[i]=d;
			}

		for(i;i>=0;i--){
			u[x]=tab[i];
			x++;}

		u[x]='\n';
		x++;}	
	}

	u[x]='\0';

	printf("%s", u);

	return 0;}
