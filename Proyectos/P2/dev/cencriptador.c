//cencriptador.c



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define PASSWORD 0x08

int main(int argc, char* argv[])
{
    FILE* fd;
    int c;

    if ((argc != 2)) {
        fprintf(stderr, "Uso: %s fichero_salida\n", argv[0]);
        exit(1);
    }

    if ((fd= fopen(argv[1], "w")) == NULL) {
        fprintf(stderr, "No se puede abrir para escritura en %s\n", argv[1]);
        exit(2);
    }
    while ((c=getc(stdin)) != EOF) 
	{

        putc(c, stdout);

	if(c>32) //Nos aseguramos de no cifrar caracteres de control
        	             
                c = c ^ PASSWORD;
                                
	putc(c, fd);
	}
	fclose(fd);
	exit(0);
	
}
