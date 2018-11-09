// vida.c
//
// Filtro para el robot explorador. Calcula probabilidad de presencia de vida
//
/////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

main (int argc, char* argv[])
{
    int s= 0, r= 0;
    int ns= 0, nr= 0;
    int c, p;

    if (argc != 1) {
        fprintf(stderr, "Uso: %s < fuente > destino\n", argv[0]);
        exit(1);
    }

    do if ((p=getchar())==EOF) exit(0);
    while ((p<'A') || (p>'Z'));

    while ((c=getchar()) != EOF) {
       if ((c>='A') && (c<='Z')) {
          if ((ns==0) || (nr==0)) printf("%c-%c: nd\n", p, c);
          else printf("%c-%c: %1.2f\n", p, c, (float)(((float)s/ns)/5.0)*(((float)r/nr)/5.0));
          p= c;
          s=r= 0;
          ns=nr= 0;
       }
       else if ((c>='0') && (c<='5')) {
          ns++;
          s= s + (c-'0');
       }
       else if ((c>='a') && (c<='f')) {
          nr++;
          r= r + (c-'a');
       }
       else continue;
   }
}
