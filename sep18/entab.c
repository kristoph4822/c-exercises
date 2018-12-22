#include <stdio.h>

int main(){

	int c, d;
	int x=0;

	while ((c=getchar()) != EOF){
		
		if (c==' '){
			x++;
			while((d=getchar())==' ')
				x++;
			if (x%4==0)
				for(int i=0;i<(x/4);i++)
					printf("t...");
			else {
				for (int i=0;i<((x-(x%4))/4);i++)
					printf("t...");
				
				for(int i=0;i<(x%4);i++)
					printf("s");
			putchar(d);
			x=0;
			}
		}

		else putchar(c);
	}

	return 0;
}


