// descifrador.c
//
// Lee un fichero cifrado con encriptador y lo descifra con una clave
//////////////////////////////////////////////////////////////////////

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>



int cambia_eco ()    // Commuta el modo eco / no eco del terminal

{
        int r;
        struct termios tm;

        tcgetattr(0, &tm);
        if (tm.c_lflag & ECHO) {
                r= 1;
                tm.c_lflag &= ~ECHO;
        }
        else {
                r= 0;
                tm.c_lflag |= ECHO;
        }
        tcsetattr(0, TCSANOW, &tm);
        return (r);
}



#define MASK 0x0f

main (int argc, char* argv[])
{
    int c, i, k;
    char clave;
    FILE *fp1, *fp2;
    struct termios tm;

    if (argc != 3) {
        fprintf(stderr, "Uso: %s fichero-cifrado fichero-descifrado\n", argv[0]);
        exit(1);
    }

        while (!cambia_eco()) ;    // Por si ya estuviera en modo no eco
        i= getchar();
        cambia_eco();
        clave= ((char)i) & MASK;
        if ((clave<1)||(clave>15)) {
                fprintf(stderr, "La clave debe estar entre 1 y 15\n");
                cambia_eco();
                exit(1);
        }

    if ((fp1= fopen(argv[1], "r")) == NULL) {
       fprintf(stderr, "No se puede leer de %s\n", argv[1]);
       exit(1);
    }
    if ((fp2= fopen(argv[2], "w")) == NULL) {
       fprintf(stderr, "No se puede escribir en %s\n", argv[2]);
       exit(1);
    }

    while ((c=getc(fp1)) != EOF) {
        if (c=='\n') putc(c, fp2);
        else putc(c^clave, fp2);
                putchar(c);
    }
}

