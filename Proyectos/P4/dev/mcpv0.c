// mcpv0.c: Tres threads leyendo sensores y compartiendo la salida estándar.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define SENSORES 3

char *sensor[SENSORES];
char POS[]= "dev/pos";
char CO2[]= "dev/CO2";
char H2O[]= "dev/H2O";

pthread_t tp[SENSORES];  //crea array con los estruct de los threads

int cnt= 0;

void* productor(char* f) {

  char input[2];
  int fd, n;

  if ((fd= open(f, O_RDONLY)) < 0) {  //abre el fichero del sensor que le han pasado
      fprintf(stderr, "Error al abrir para lectura: %s\n", f);
      exit(3);
  }
  while ((n= read(fd, input, 1)) > 0) { //mientras haya datos en el fichero los va sacando por pantalla y aumenta el contador
      write(1, input, 1);
      cnt++;
  };
  close(fd);
  pthread_exit(NULL);
}


int main(int argc, char* argv[])
{
  int i, k, max_prods= SENSORES;

  if (argc != 1) {
      fprintf(stderr, "Uso: %s \n", argv[0]);
      exit(1);
  }

  sensor[0]= POS;
  sensor[1]= CO2;
  sensor[2]= H2O;

  for (i=0; i<max_prods; i++) {  //crea los threads, sin atributo, con la rutina de comienzo "productor" y el argumento de la funcion "sensoor [i]
      if (pthread_create(&tp[i], NULL, (void *)productor, (void *)sensor[i]) != 0) {
          fprintf(stderr, "Error al crear thread para el sensor %s\n", sensor[i]);
          exit(2);
      };
  }
  for (i=0; i<max_prods; i++) {
     pthread_join(tp[i], NULL);
  }
  // fprintf(stderr, "\n----Datos leidos: %d\n", cnt);
  exit(0);
}
