//program usuwajacy puste wiersze z stdin

#include <stdio.h>

int main(){
	
	char line[1000];
	int c, d, i=0;
	while ((c=getchar())!=EOF){
		line[i]=c;
		if(c=='\n'){
			while((d=getchar())=='\n');//jezeli napotkamy znak nowej linii, uruchamiamy petle ktora zignoruje wszystkie znaki nowej linii po nim
			i++;
			line[i]=d;}
		i++;
	}
	line[i]='\0';//dodajemy na koncu znak konca ciagu, dzieki czemu nasza tablica jest traktowana jak zwykly wyraz
	printf("%s", line);

	return 0;
}
