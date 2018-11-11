// Biblioteca para gestionar un buffer circular
//////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include "buffer_circular.h"

static char buffer[TAM_BUFFER];
static int in= 0, out= 0, n= 0; // Indices para gestionar el buffer circular

void insertar (char msg)
{
   buffer[in]= msg;  // Si overflow, sobreescribe el msg más antiguo
   in= (in+1)%TAM_BUFFER;
   if (n<TAM_BUFFER) n++;
   else out= (out+1)%TAM_BUFFER;
}

int retirar (char* msg)
{
   if (n==0) {  //el buffer está vacio
      *msg= '\b';
      return 0;
   }
   else {
      *msg= buffer[out];
      out= (out+1)%TAM_BUFFER;
      n--;
   return 1;
   }
}

void imprimir_buffer()
{
   int i, j;

   for (i=out, j=1; j<=n; j++, i=(i+1)%TAM_BUFFER)
       printf("%c", buffer[i]);
}
