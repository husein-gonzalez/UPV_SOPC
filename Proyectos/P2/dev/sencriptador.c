//sencriptador.c



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


#define PASSWORD 0x08
#define TAMANO_BUFFER 1

int main(int argc, char* argv[])
{
    int c,fd;
    char buf[TAMANO_BUFFER];
    

    if ((argc != 2)) {
        fprintf(stderr, "Uso: %s fichero_salida\n", argv[0]);
        exit(1);
    }

    if ((fd= open(argv[1], O_WRONLY|O_CREAT, 0660)) < 0) {
        fprintf(stderr, "No se puede abrir para escritura %s\n", argv[1]);
        exit(2);
    }

    while ((c= read(0, buf, TAMANO_BUFFER)) > 0) 
	{

        write(1, buf, 1);

	if(buf[0]>32) //Nos aseguramos de no cifrar caracteres de control
        	             
                buf[0] = buf[0] ^ PASSWORD;
                                
	write(fd, buf, 1);
	}
	
	exit(0);
	
}
