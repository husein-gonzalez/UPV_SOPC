// ejecuta.c
// Ejecuta el programa cuyo nombre se especifica como argumento
/////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if (argc != 2) {
       fprintf(stderr, "Uso: %s nombre_programa\n", argv[0]);
           exit(1);
   }

    if (execlp(argv[1], argv[1], NULL) == -1)
       fprintf(stderr, "El programa %s no se ha podido ejecutar\n", argv[1]);
    else
       fprintf(stderr, "El programa %s se ha ejecutado\n", argv[1]);
}
