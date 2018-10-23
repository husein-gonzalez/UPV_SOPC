//MCPV.c


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char* argv[])
{

	float y,x=0;
	int ch=0;

	 /*       
        if (argc == 1)
                x = 1;
*/
	ch=getchar();
	//printf("%d",ch);
	while (ch!= EOF) 
{
	if (ch==EOF || ch=='\n')
		return 1;
	//ch=getchar();
	
	ch=ch-'0';
	x=ch/5;
	//putchar(ch);
	printf("%f \n",x);
	ch=getchar();
}

	return 0;


}
