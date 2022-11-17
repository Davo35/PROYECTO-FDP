// MODULO AGREGAR PALABRAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void agregar_words(void);     // FUNCION PARA AGREGAR PALABRAS
void mostrarPalabras(char *); // FUNCION PARA MOSTRAR LAS PALABRAS

int main()
{
    agregar_words();

    return 0;
}

//-----------------------------------------------------
void adminPalabras(int longitud, char palabra[30]) // TODO: duda con esta funcion
{
    char ruta[30], tipo[30]; //

    if (longitud >= 8 && longitud < 15)
    {
        strcpy(ruta, "facil.txt");
        strcpy(tipo, "facil");
    }
    else if (longitud >= 15 && longitud < 20)
    {
        strcpy(ruta, "medio.txt");
        strcpy(tipo, "medio");
    }
    else if (longitud >= 20)
    {
        strcpy(ruta, "dificil.txt");
        strcpy(tipo, "dificil");
    }

    // TODO: duda control + F
    FILE *fp = fopen(ruta, "a"); // ABRIENDO ARCH EN MODO ADJUNTAR
    fprintf(fp, "%s\n", palabra);
    fclose(fp);

    printf("Las palabras para el modo %s son: \n", tipo);
    mostrarPalabras(ruta);
}

//--------------------------------------------------------
void mostrarPalabras(char *file)
{
    char c;
    FILE *fp = fopen(file, "r"); // ABRIENDO ARCH MODO LECTURA
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }
}

int election()
{
    int eleccion;
    printf("\n\n");
    printf("QUIERE GUARDAR MAS PALABRAS?\n\n "); // Menu agregar otra vez
    printf("(1)SI | (2)NO : ");

    scanf("%d", &eleccion); // GUARDARA LA RESPUESTA DEL USUARIO
    system("cls");
    if (eleccion == 1 || eleccion == 2)
        return eleccion;
    else
        return 0;
}

//-----------------------------------------------------------
void agregar_words(void)
{
    char palabra[32]; // palabra ingresada
    int longitud;     // Longitud de palabra

    int eleccion = 1; // variable para eleccion del usuario

    while (eleccion == 1) // ELECCION DEBE SER 1
    {
        fflush(stdin); // LIMPIA BUFFER
        printf("\nINGRESE LA PALABRA: ");
        scanf("%s", &palabra);
        system("cls");

        longitud = strlen(palabra);

        if (longitud < 8 || longitud > 30)
        {
            printf("\nIngrese una palabra mayor de 8 letras e inferior a 30\n");
            continue; /* Detiene el proceso actual sin
                          detener el bucle */
        }

        adminPalabras(longitud, palabra);

        // MENU SI QUIERE VOLVER A GUARDAR facil
        eleccion = election();
        while (eleccion == 0)
            eleccion = election();
        if (eleccion == 0 || eleccion > 2)
        {
            printf("\nESCRIBA YA SEA 1 O 2");
        }
    }

    printf("\nSALIENDO...");
}
