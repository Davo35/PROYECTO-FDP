#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void agregar_words(void);

int main()
{
    // agregar_words();

    char palabra[8];
    int longitud;

    printf("PALABRA: ");
    scanf("%s", &palabra);

    longitud = strlen(palabra);

    printf("\n\nLA PALABRA ES %s Y SU LONGITUD ES %d", palabra, longitud);

    return 0;
}