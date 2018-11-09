// lanzador_0.c
// Ejecuta los programas cuyos nombres se especifican como argumento
/////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <wait.h>

int main(int argc, char * argv[])
{
    if (argc < 2) {
       fprintf(stderr, "Uso: %s nombre_programa1 nombre_programa_n  \n", argv[0]);
           exit(1);
   }

	int i,j,id,status;


	i=argc-1;
	

	for(j=i;j>0;j--)
{
		
		id=fork();
		if (id==0){
			    if (execlp(argv[j], argv[j], NULL) == -1)
       				fprintf(stderr, "El programa %s no se ha podido ejecutar\n", argv[1]);
}
		else wait(&status);
		

	

} 

return 0;
}








  


/*


    int id, i;
    char dato= '0';
    char mensaje[80];

    srandom(time(NULL));  // Para mayor aleatoriedad en las ejecuciones.

    sprintf(mensaje, "--Punto 0  >>> %d: dato= %c\n", getpid(), dato);
    write(1, mensaje, strlen(mensaje));
    switch (id= fork()) {
      case -1:
        perror("fork");
        exit(1);
      case 0:
        sleep(random()%5);
        sprintf(mensaje, "--Punto 1  >>> %d: dato= %c\n", getpid(), dato);
        write(1, mensaje, strlen(mensaje));
        dato= 'a';
        for (i=0; i<5; i++) {
           sleep(random()%5);
           sprintf(mensaje, "--Punto 2.%d>>> %d: dato= %c\n", i, getpid(), dato);
           write(1, mensaje, strlen(mensaje));
           dato++;
        }
        break;
      default:
        sleep(random()%5);
        sprintf(mensaje, "--Punto 3  >>> %d: dato= %c\n", getpid(), dato);
        write(1, mensaje, strlen(mensaje));
        dato= 'A';
        for (i=0; i<5; i++) {
           sleep(random()%5);
           sprintf(mensaje, "--Punto 4.%d>>> %d: dato= %c\n", i, getpid(), dato);
           write(1, mensaje, strlen(mensaje));
           dato++;
        }
    }
    sprintf(mensaje, "--Punto 5  >>> %d: dato= %c\n", getpid(), dato);
    write(1, mensaje, strlen(mensaje));
    exit(0);
}

*/
