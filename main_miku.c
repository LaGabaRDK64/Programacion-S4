#include <stdio.h>
#include <string.h>
#include <ctype.h>

//*encabezados*//

#include "watch_miku.h" /*Este encabezado son las restricciones que el programa tiene y mensajes visuales*/
#include "search_process.h"/*Este encabezado es el proceso para hacer busquedas*/

//* funcion principal (main) *//

int main(){

    /*Declaracion de variables principales*/
    
    int opcmain;
    char nombre[10][20];
    float precios[2][10] = {0};
    float preciosfinalconstock[10] = {0};
    int numproducts = 0;
    float sumprecios = 0, sumuniprecios = 0, promprecios = 0, promuniprecios = 0;

    /*Declaracion de variables para el caso 1*/

    int numbucle = 0;


    printf("-----(.)BIENVENIDO USUARIO, soy su asistente virtual(.)-----\n");
    do
    {
        opcmain = menu();
        switch (opcmain)
        {
        case 1:

            /*proceso del caso 1*/

            opcionselectmiku(opcmain);

            printf(".--------.Ingrese el numero de productos que desea ingresar >>>> ");
            numbucle = mikuscanneroption(numbucle, 1, 10);
            for (int i = 0; i < numbucle; i++)
            {
                printf(".----.(Ingrese el nombre del producto %d) >>>> ", i + 1);
                SILETRAS(nombre[i], 20);
                printf(".----.(Ingrese el precio de %s) >>>> ", nombre[i]);
                precios[0][i] = mikuscanneroptionALT(precios[0][i],0, 100000);
                printf(".----.(Ingrese el stock de %s) >>>> ", nombre[i]);
                precios[1][i] = mikuscanneroptionALT(precios[1][i],0, 100000);

                getchar();
                numproducts++;
            }

            for (int i = 0; i < numproducts; i++)
            {
                preciosfinalconstock[i] = precios[0][i] * precios[1][i];
            }
        
            break;

        case 2:

            sumprecios = 0;
            sumuniprecios = 0;

            /*restriccion*/
            if (numproducts == 0)
            {
                printf(".----.(No ahi productos registrados)\n");
                printf("\n-----(Presione espacio para continuar...)-----\n");
                getchar();
                break;
            }
            
            /*proceso del caso 2*/
            for (int i = 0; i < numproducts ; i++) {

                sumprecios += preciosfinalconstock[i];

            }
        
            for (int i = 0; i < numproducts ; i++) {

                sumuniprecios += precios[0][i];

            }

            promprecios = sumprecios / numproducts;
            promuniprecios = sumuniprecios / numproducts;

            /*Impresion del caso 2*/

            printf(".----.(La suma del valor unitario (precio de una unidad) de todos los productos es >>>>>>> %.2f .)\n", sumuniprecios);
            printf(".----.(La suma del valor total(valor unitario * stock) de todos los productos es >>>>>>> %.2f .)\n", sumprecios);
            printf(".----.(El promedio de todos los precios unitarios sumados del inventario es >>>>>>> %.2f .)\n", promuniprecios);
            printf(".----.(El promedio del valor total del precio(valor unitario * stock) sumados del inventario es >>>>>>> %.2f .)\n", promprecios);
            printf("\n-----(Presione espacio para continuar...)-----\n");
            getchar();

            break;

        case 3:

            int opc3 = 0;

            opcionselectmiku(opcmain);
            
            /*restriccion*/
            if (numproducts == 0)
            {
                printf(".----.(No ahi productos registrados)\n");
                printf("\n-----(Presione espacio para continuar...)-----\n");
                getchar();
                break;
            }
        
            printf("-----(.)¿Que desea buscar?(.)-----\n----.(1)Producto por nombre.\n----.(2)Mayor y menor.\n----.(3)Mostrar inventario.\n----.(4)Salir");
            opc3 = mikuscanneroption(opc3, 1, 4);

            switch (opc3)
            {
                case 1:

                duckinvestigation(precios, nombre,numproducts, preciosfinalconstock);

                break;

                case 2:

                float mayor = precios[0][0] ,menor = precios[0][0];

                char nommayor[20];
                char nommenor[20];

                strcpy(nommayor, nombre[0]);
                strcpy(nommenor, nombre[0]);

                for (int i = 1; i < numproducts; i++){
                    if(precios[0][i] < menor)
                    {
                        menor = precios[0][i];
                        strcpy(nommenor, nombre[i]);

                    }else if(precios[0][i] > mayor){

                        mayor = precios[0][i];
                        strcpy(nommayor, nombre[i]);

                    }    
                }

                printf(".----.(El producto %s es el mayor >>>>>>> %.2f .)\n", nommayor , mayor);
                printf(".----.(El producto %s es el menor >>>>>>> %.2f .)\n", nommenor , menor);
                printf("\n-----(Presione espacio para continuar...)-----\n");
                getchar();

                break;
            case 3:

                printf("\n-----(Informacion del inventario)-----\n");
                printf("|| Producto || Precio Unitario || Stock || \n");

                for (int i = 0; i < numproducts; i++)
                {
                    printf("|| %s || %.2f || %.0f ||\n", nombre[i], precios[0][i], precios[1][i] );
                }
                printf("\n-----(Presione espacio para continuar...)-----\n");
                getchar();
                
                break;
            default:
                break;
            }

            break;
        case 4:

            opcionselectmiku(opcmain);    
            printf("-----(.)Gracias por usar el programa(.)-----\n");
            break;

        default:
            break;
        }

    
    } while (opcmain != 4);

    return 0;
  
}
