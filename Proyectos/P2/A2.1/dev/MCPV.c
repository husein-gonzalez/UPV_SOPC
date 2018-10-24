//MCPV.c


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char* argv[])
{

	float x=0;
	int y,ch=0;

	        
        if (argc != 1)
        	fprintf(stderr,"Filtro sin argumentos");


	ch=getchar();
	//printf("%d",ch);
	while (ch!= EOF) 
{
	if (ch==EOF || ch=='\n')
		return 1;
	//ch=getchar();
	
	y=ch-'0';
	if (y<=5)
{
		x=y/5.0;
		//putchar(ch);
		printf("%f \n",x);
	
}

	else
		fprintf(stderr,"Entrada invalida: %d\n", y);

	ch=getchar();
}

	return 0;


}



