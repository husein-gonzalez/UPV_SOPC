// controlador2.c
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

	if (argc != 3) //error si no se han introducido todos los parametros
	{
		fprintf(stderr, "Uso: %s tiempo nombre_programa  \n", argv[0]);
           	exit(1);
	}


	int id_sleep, id_programa, id_muerto,muerte;
	int EstadoHijo;
	int pid = 15; //SIGTERM

        id_programa=fork(); //crear el proceso que ejcuta el programa
	//printf("id programa: %d\n",id_programa);
	switch (id_programa)
	{
		case -1: //no se ha creado el proceso
			printf("error fork 1\n");
			exit(1);
               		break;
            	case 0:	//hijo1:ejecuta programa
		        if (execlp(argv[2], argv[2], NULL) == -1)
			{
           	        fprintf(stderr, "El programa %s no se ha podido ejecutar\n", argv[1]);
			exit(2);
			}
               		 break;
		default: //padre
	        	id_sleep=fork(); //crear el proceso que controla el tiempo
			//printf("id sleep: %d\n",id_sleep);
			switch (id_sleep)
			{
				case -1: //no se ha creado el proceso
					printf("error fork 2\n");
					exit(3);
			       		break;
			    	case 0:	//hijo2:controla el tiempo
					
					sleep(atoi(argv[1]));
					
			       		 break;
				default:
					
					id_muerto=wait(&EstadoHijo);
					//printf("id: %d\n",id_muerto);
					if (id_muerto==id_sleep)
						muerte=kill(id_programa,pid);
					else if (id_muerto==id_programa)
						muerte=kill(id_sleep,pid);
					else
						printf("error wait\n");
					//printf("exito, %d \n", muerte);
					exit(4);
			}
	}

exit (0);

}
