//lanzador_vigilante.c
// Ejecuta los programas cuyos nombres se especifican como argumento y los mata si no han acabado
// en el tiempo definido
/////////////////////////////////////////////////////////////////


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char * argv[])

{

	if (argc < 3) //error si no se han introducido todos los parametros
	{
		fprintf(stderr, "Uso: %s T programa1 [programa2, ..., programaN]  \n", argv[0]);
           	exit(1);
	}


	int i,id_programa,EstadoHijo;
	
	

	for(i=argc-1;i>1;i--)//argv[1] es T
	{

		id_programa=fork(); //crear el proceso que ejcuta el programa
		//printf("id programa: %d\n",id_programa);
		switch (id_programa)
		{
			case -1: //no se ha creado el proceso
				printf("error fork %d\n", i);
				exit(2);
		       		break;
		    	case 0:	//ejecuta programa
				if (execlp("./controlador", "./controlador",argv[1],argv[i], NULL) == -1)
				{
		   	        fprintf(stderr, "El programa %s no se ha podido ejecutar\n", argv[1]);
				exit(3);
				}
				
		       		 break;
			//default: //padre
				//printf("padre %d\n", i);
				
		}
	}

exit (0);

}
