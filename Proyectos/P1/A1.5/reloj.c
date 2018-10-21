//reloj.c


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char* argv[])
{
	struct timeval start, end;
	int i,x=0;

	gettimeofday(&start,NULL);
        
        if (argc == 1)
                x = 1;
        else
                x = atoi(argv[1]);

        for(i=1;i<=10;i++){
                sleep(x);
                printf("%d\n", i);
        }

	gettimeofday(&end,NULL); 
	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds*1000000) + end.tv_usec) - (start.tv_usec);
	printf("%ld\n",micros);
        return 0;
}
