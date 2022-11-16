// MODULO AGREGAR PALABRAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void agregar_words(void);     // FUNCION PARA AGREGAR PALABRAS
void mostrarPalabras(char *); // FUNCION PARA MOSTRAR LAS PALABRAS

int main()
{

    agregar_words();

    // TODO: duda funcion de abajo

    //mostrarPalabras(char *file);

    return 0;
}

//-----------------------------------------------------
void adminPalabras() //TODO: duda con esta funcion
{
    // Menu de administración           //PREGUNTA

    char *nameEasy = "facil.txt";       // ARCHIVO FACIL
    char nameMedio[] = "medio.txt";     // ARCHIVO medio
    char nameDificil[] = "dificil.txt"; // ARCHIVO dificil

    mostrarPalabras(nameEasy);
    // agregar_words(nameDificil);
    agregar_words();
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

//-----------------------------------------------------------
void agregar_words(void)
{
    char palabra[30]; // palabra ingresada
    int longitud;     // Longitud de palabra

    int eleccion = 1; // variable para eleccion del usuario

    while (eleccion == 1) // ELECCION DEBE SER 1
    {
        fflush(stdin); // LIMPIA BUFFER
        printf("\nINGRESE LA PALABRA: ");
        scanf("%s", &palabra);

        longitud = strlen(palabra);

        if (longitud < 8)
        {
            printf("\nIngrese una palabra mayor de 8 letras\n");
            continue; /* Detiene el proceso actual sin
                          detener el bucle */
        }

        char ruta[30]; //

        if (longitud >= 8 && longitud < 15)
        {
            strcpy(ruta, "facil.txt");
            printf("Las palabras para el modo facil son: \n");
            mostrarPalabras(ruta);
        }
            
        else if (longitud >= 15 && longitud < 20)
        {
            strcpy(ruta, "medio.txt");
            printf("Las palabras para el modo medio son: \n");
            mostrarPalabras("medio.txt");
        }

        else if (longitud >= 20)
        {
            strcpy(ruta, "dificil.txt");
            printf("Las palabras para el modo dificil son: \n");
            mostrarPalabras("dificil.txt");
        }

        // TODO: duda control + F
        FILE *fp = fopen(ruta, "a"); // ABRIENDO ARCH EN MODO ADJUNTAR
        fprintf(fp, "%s\n", palabra);
        fclose(fp);

        // mostrarPalabras("facil.txt");

        // MENU SI QUIERE VOLVER A GUARDAR facil
        printf("\n\n");
        printf("QUIERE GUARDAR MAS PALABRAS?\n\n "); // Menu agregar otra vez
        printf("(1)SI | (2)NO : ");
        scanf("%d", &eleccion); // GUARDARA LA RESPUESTA DEL USUARIO
        system("cls");

        while (eleccion == 0 || eleccion > 2)
        {
            printf("\nESCRIBA YA SEA 1 O 2"); // si el usuario escribe otra cosa
            continue;
            //TODO: duda con esto
        }

        // fclose(fp);
    }

    printf("\nSALIENDO...");
}