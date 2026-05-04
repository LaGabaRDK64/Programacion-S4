#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "watch_miku.h"

//*definicion de funciones*//

int menu(){

    int opc = 0;

    printf("\n-----.(TIENDA VIRTUAL ||| Seleccione la opcion con la que desea trabajar).-----\n");
    printf("\n----.(1)Ingresar productos. \n----.(2)Consultar precio total y promedio. \n----.(3)Consultar informacion de los productos.\n----.(4)Salir. \n");
    printf("\n--- Ingrese su opcion aqui >>>>>");
    opc = mikuscanneroption(opc, 1, 4);

    return opc;
}

int mikuscanneroption(int x, int min , int max){

    int opc = x;
    int aux = 0;

    while (opc < min || opc > max || aux != 1)
    {
        aux = scanf("%d", &opc);

        if (aux != 1)
        {
            printf("\n-----(.)Opcion invalida. El programa no admite letras\n");

        }else if (opc < min)
        {
            printf("\n-----(.)Opcion invalida. El programa no admite numeros menores a %d\n", min);

        }else if (opc > max)
        {
            printf("\n-----(.)Opcion invalida. El programa no admite numeros mayores a %d\n", max);

        }

        while(getchar() != '\n');
        
        if(opc < min || opc > max || aux != 1){
            printf("--- Ingrese su opcion aqui >>>>>");
        }
    }
    return opc;
}

float mikuscanneroptionALT(float x, int min , int max){
    
    float opc = x;
    int aux = 0;

    while (opc < min || opc > max || aux != 1)
    {
        aux = scanf("%f", &opc);

        if (aux != 1)
        {
            printf("\n-----(.)Opcion invalida. El programa no admite letras\n");

        }else if (opc < min)
        {
            printf("\n-----(.)Opcion invalida. El programa no admite numeros menores a %d\n", min);

        }else if (opc > max)
        {
            printf("\n-----(.)Opcion invalida. El programa no admite numeros mayores a %d\n", max);

        }

        while(getchar() != '\n');
        
        if(opc < min || opc > max || aux != 1){
            printf("--- Ingrese su opcion aqui >>>>>");
        }
    }
    return opc;
}

void opcionselectmiku(int x){

    printf("\n-----(.)Usted ha seleccionado la opcion %d(.)-----\n", x);
    printf("\n-----(Presione Enter para continuar...)-----\n");
    getchar();

}

void SILETRAS(char nom[20], int x){

    int len, aux;

    fgets(nom, x, stdin);

    do
    {
        aux = 1;

        for (int i = 0; nom[i] != '\0'; i++){
            if (isdigit(nom[i]))
            {
                aux = 0;
                break; 

            }
        }
        if (!aux)
        {
            printf("\n-----(.)Opcion invalida. El programa no admite numeros solo letras .\n");
            printf("(.)---Ponga su opcion aqui >>>>> ");
            fgets(nom, x, stdin);
        }
        
    } while (!aux);
     
    len = strlen(nom)-1;
    nom[len] = '\0';
}