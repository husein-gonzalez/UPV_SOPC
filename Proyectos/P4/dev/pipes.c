// pipes.c
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
   int pfd[2];
   int id;

   if (pipe(pfd) == -1) error("pipe");
   switch(fork()) {
      case -1:  error("fork");
      case 0:
         if (close(1) == -1) error("close");
         if (dup(pfd[1]) != 1) error("dup");
         if (close(pfd[0])==-1 || close(pfd[1])==-1) error("close");
         execlp("./encriptador", "./encriptador", "cifrado", NULL);
         error("execlp");
   }

   switch (fork()) {
      case -1:  error("fork");
      case 0:
         if (close(0) == -1) error("close");
         if (dup(pfd[0]) != 0) error("dup");
         if (close(pfd[0])==-1 || close(pfd[1])==-1) error("close");
         execlp("./vida", "./vida", NULL);
         error("execlp");
        }

   if (close(pfd[0])==-1 || close(pfd[1])==-1) error("close");

   while ((id=wait(NULL)) != -1) ;
}
