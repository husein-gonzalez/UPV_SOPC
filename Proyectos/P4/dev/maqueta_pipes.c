// maqueta_pipes.c
// Prueba de pipes (fifos sin nombre).
/////////////////////////////////////////////////////////////////

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define error(a) {perror(a); exit(-1);}

main(int argc, char *argv[])
{
   int pfd[2],pfd1[2];
   int id;

   if (pipe(pfd) == -1) error("pipe");
   if (pipe(pfd1) == -1) error("pipe1");
   

   switch(fork()) {
      case -1:  error("fork");
      case 0:
         if (close(1) == -1) error("close0");
         if (dup(pfd[1]) != 1) error("dup");
         if (close(pfd[0])==-1 || close(pfd[1])==-1) error("close1");
         execlp("./sim_CO2", "./sim_CO2", NULL);
         error("execlp");
   }

   switch(fork()) {
      case -1:  error("fork");
      case 0:
         if (close(1) == -1) error("close2");
         if (dup(pfd[1]) != 1) error("dup");
         if (close(pfd[0])==-1 || close(pfd[1])==-1) error("close3");
         execlp("./sim_H2O", "./sim_H2O", NULL);
         error("execlp");
   }

   switch(fork()) {
      case -1:  error("fork");
      case 0:
         if (close(1) == -1) error("close4");
         if (dup(pfd[1]) != 1) error("dup");
         if (close(pfd[0])==-1 || close(pfd[1])==-1) error("close5");
         execlp("./sim_pos", "./sim_pos", NULL);
         error("execlp");
   }

   switch(fork()) {
      case -1:  error("fork");
      case 0:
         if (close(0) == -1) error("close6");
         if (close(1) == -1) error("close7");
         if (dup(pfd[0]) != 0) error("dup");
         if (dup(pfd1[1]) != 1) error("dup");
         if (close(pfd[0])==-1 || close(pfd[1])==-1) error("close8");
         if (close(pfd1[0])==-1 || close(pfd1[1])==-1) error("close9");
         execlp("./encriptador", "./encriptador", "cifrado", NULL);
         error("execlp");
   }

   switch (fork()) {
      case -1:  error("fork");
      case 0:
         if (close(0) == -1) error("close10");
         if (dup(pfd1[0]) != 0) error("dup");
         if (close(pfd1[0])==-1 || close(pfd1[1])==-1) error("close11");
         execlp("./vida", "./vida", NULL);
         error("execlp");
        }

   if (close(pfd[0])==-1 || close(pfd[1])==-1) error("close12");

   while ((id=wait(NULL)) != -1) ;
}
