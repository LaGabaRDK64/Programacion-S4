#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "watch_miku.h"
#include "search_process.h"

void strTolower(char string[], char new_str[]) {

    int i = 0;

    while (string[i]) {

        new_str[i] = tolower((unsigned char)string[i]);
        i++;
    }

    new_str[i] = '\0';
}

void duckinvestigation(float buscprecios[2][10], char buscname[10][20], int x, float total[10]){

    char find[20];
    char findminuscula[20];
    char nombreminuscula[20];

    int opc2 = 0;
    int simi = 0;

    do
    {
        printf("--- Ingrese que producto desea buscar >>>>>");
        SILETRAS(find,20);

        strTolower(find, findminuscula);

        for (int i = 0; i < x; i++)
        {
            strTolower(buscname[i],nombreminuscula);

            if (strstr(nombreminuscula, findminuscula) != NULL)
            {
                printf("------(.)Informacion del producto(.)------\n");
                printf("Nombre del producto >>>> %s \n", buscname[i]);
                printf("Precio Unitario >>>> %.2f \n", buscprecios[0][i]);
                printf("Precio Stock >>>> %.1f \n", buscprecios[1][i]);
                printf("Valor total >>>> %.2f\n", total[i]);

                simi = 1;

            }
            
        }

        if (!simi)
            {
                printf("------(.)No se encontre ningun resultado acorde a la busqueda(.)------\n");
            }

        printf("\n-----(Presione Enter para continuar...)-----\n");
        getchar();

        printf("------(.)Desea seguir buscando( 1 = Si ||| 2 = No )(.)------\n");
        printf(".-------.Ingrese su opcion aqui >>>>>> ");

        opc2 = mikuscanneroption(opc2,1,2);

    } while (opc2 != 2);
    
}