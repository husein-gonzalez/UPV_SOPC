// fifos.c
// Prueba de fifos con nombre.
/////////////////////////////////////////////////////////////////

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define error(a) {perror(a); exit(-1);}

main(int argc, char *argv[])
{
   int id;

   if (mkfifo("mififo", 0666) == -1) error("mkfifo");

   switch (id=fork()) {
      case -1: error("fork");
      case 0:
         if (close(1) == -1) error("close");
         if (open("mififo", O_WRONLY) != 1) error("open");
         execlp("./sim_pos", "./sim_pos", "L", NULL);
         error("execlp");
   }

   switch (id=fork()) {
      case -1: error("fork");
      case 0:
         if (close(1) == -1) error("close");
         if (open("mififo", O_WRONLY) != 1) error("open");
         execlp("./sim_CO2", "./sim_CO2", NULL);
         error("execlp");
   }

   switch (id=fork()) {
      case -1: error("fork");
      case 0:
         if (close(1) == -1) error("close");
         if (open("mififo", O_WRONLY) != 1) error("open");
         execlp("./sim_H2O", "./sim_H2O", NULL);
         error("execlp");
   }

   switch (id=fork()) {
      case -1: error("fork");
      case 0:
         if (close(0) == -1) error("close");
         if (open("mififo", O_RDONLY)!=0) error("open");
         execlp("./vida", "./vida", NULL);
         error("execlp");
   }

   while ((id=wait(NULL)) != -1) ;
   unlink("mififo") ;
}
