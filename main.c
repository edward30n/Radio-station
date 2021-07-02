#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0
/** ------------------------------- Made in Colombia, by: Edward Nicolas Duarte Valencia, Juliana Toro Camelo--------------------------------------------
* Este programa busca la estaci�n de radio "Melod�a Javeriana".\n
* En donde se quiere crear un sistema de reproducci�n y clasificaci�n musical
* Para ello se requieren las siguientes interfaces:
* 1) Actualizar matriz de reproducci�n: el administrador por medio de su acceso con contrase�a puede cambiar el g�nero musical y el n�mero de reproducciones de las canciones.
* 2) N�mero total de reproducciones
* 3) Canci�n menos escuchada por g�nero
* 4) Canci�n m�s escuchada por g�nero
* 5) Canci�n global m�s escuchada
* 6) Reproducir una canci�n
-----------------------------------------------------------------------------------------------------------------------------------------------------------**/
int x,y,reproducciones[7][7] = {{1,3,0,9,8,7,6},{15,14,7,1,17,16,4},{0,50,30,25,18,20,13},{6,5,4,3,2,1,10},{0,24,2,0,2,9,15},{8,6,2,0,5,1,1},{2,8,0,7,2,1,8}};
/*Matriz que define el n�mero de reproducciones de cada canci�n, las filas son los g�neros musicales*/
char generos [7][40] = {{"POP"},{"ROCK"},{"CLASICA"},{"RAP"},{"ELECTRONICA"},{"JAZZ"},{"FRANCESA"}};
/*Matriz que define el nombre de cada g�nero musical por fila*/
int main()
{
 system("color 02"); /*Modificaci�n color impresi�n*/

 printf("Bienvenido\n");
 sleep(2);
 printf(". ");
 sleep(1);
 printf(". ")
 ;sleep(1);
 printf(". \n");
 system("cls");
 // condicional para hacer el codigo en bucle.
 while (TRUE)
 {
 char generos2 [7][40]; /*Matriz que almacenar� la modificaci�n de los g�neros musicales*/
 int suma = 0; /*Variable que representa la suma de reproducciones de las canciones*/
 int fila = 0;
 int menu;/*Variable que almacena la opci�n seleccionada por el usuario*/
 printf("Ingrese el n%cmero de la interfaz a la que desea acceder:\n\n",163); /*Se pregunta al usuario qu� opci�n desea*/
 printf("__________________________________________________\n"); /*A continuaci�n se presentan al usuario las opciones disponibles*/
 printf("| N%cMERO |               INTERFAZ                 |\n",163);
 printf("|________|________________________________________|\n");
 printf("|   1    |  Actualizar Reproducciones             |\n");
 printf("|--------|----------------------------------------|\n");
 printf("|   2    |  N%cmero de reproducciones              |\n",163);
 printf("|--------|----------------------------------------|\n");
 printf("|   3    |  Canci%cn menos escuchada por g%cnero    |\n",162,130);
 printf("|--------|----------------------------------------|\n");
 printf("|   4    |  Canci%cn m%cs escuchada por g%cnero      |\n",162,131,130);
 printf("|--------|----------------------------------------|\n");
 printf("|   5    |  Canci%cn global mas escuchada          |\n",162);
 printf("|--------|----------------------------------------|\n");
 printf("|   6    |  Reproducir una canci%cn                |\n",162);
 printf("|--------|----------------------------------------|\n");
 printf("|   7    |  Salir                                 |\n",162);
 printf("|________|________________________________________|\n");
 scanf("%d", &menu); /*Se lee la elecci�n del usuario*/

 void interfazGenero() /*Esta funci�n imprime los g�neros representados en la matriz*/
 {
     for(x = 0 ;x < 7 ;x ++)
     {
        puts(generos[x]);
        printf("---------------\n");
        printf("|       ");
        printf("%d", x + 1);
        printf("     |\n");
        printf("---------------  \n");
     }
 }
 void actualizarReproducciones() /*Funci�n para modificar el n�mero de reproducciones*/
 {
    int generoModificar; /*Variable que define el g�nero que el administrador desee modificar*/
    int tipoModificacion;/*Variable que deine el tipo de modificaci�n que se desea hacer al g�nero definido en la variable anterior*/
    interfazGenero(); /*Llamado a la funci�n que presenta los g�neros*/
    printf("\nPor favor seleccione el g%cnero que desea modificar:\n",130); /*Se pregunta al administrador qu� g�nero desea modificar*/
    scanf("%d", &generoModificar); /*Se escanea la respuesta del usuario*/
    printf("Usted ha seleccionado el g%cnero: ",130); /*Se indica el g�nero seleccionado*/
    puts(generos[generoModificar - 1]); /*Al iniciar la matriz en la posici�n 0 se resta una unidad al g�nero de la respusta del usuario para que la posici�n coincida*/
    printf("\n Digite el tipo de modificaci%cn que desea realizar:\n",162); /*Se pregunta qu� modificaci�n se desea hacer*/
    printf(" ______________________    __________________________    ___________\n");
    printf("|   Nombre del g%cnero  |  |   Canciones del g%cnero   |  |   Salir   |\n",130,130);
    printf("|          1           |  |             2            |  |     3     |\n");
    printf("|______________________|  |__________________________|  |___________|\n");
    scanf("%d", &tipoModificacion);
    if(tipoModificacion == 1)
    /*Si el usuario desea modificar el nombre del g�nero se le pregunta cu�l debe ser el nuevo nombre y este se guarda en la matriz dispuesta para la modificaci�n*/
    {
        printf("Digite el nuevo nombre del g%cnero\n",130);
        char ed[40];
        scanf("%c", &ed[40]);
        gets(ed);
        for(x = 0 ;x < 40 ;x ++)
        {
            generos2[generoModificar-1][x] = ed[x];
        }
        for(x = 0;x < 40;x ++)
        {
            generos[generoModificar-1][x] = generos2[generoModificar-1][x]; /*Ahora la matriz de generos es la matriz modificada*/
        }
        interfazGenero(); /*Llamado a la funci�n que presenta los g�neros*/
        printf("\nNombre de g%cnero actualizado.\n",130);
    }
    else if(tipoModificacion == 2)
   /*Si el usuario desea modificar el n�mero de reproducciones por canci�n se preguntan las nuevas reproducciones y este n�mero se guarda en la matriz dispuesta para la modificaci�n*/
    {
        printf("Digite los nuevos n%cmeros de reproducci%cn de cada canci%cn. Cada vez que digite un n%cmero oprima enter.\n",163,162,162,163);
        for(x=0;x<7;x++)
        {
            int numeroCancion = 1; /*Variable que define en n�mero de la canci�n*/
            numeroCancion += x; /*El n�mero de la canci�n hace referencia a cada columna en la fila g�nero*/
            printf("Canci%cn %d\n",162,numeroCancion);
            int nuevoValorReproducciones = 0; /*Variable que guarda la modificaci�n ingresada del n�mero de reproducciones*/
            scanf("%d", &nuevoValorReproducciones);
            reproducciones[generoModificar-1][x] = nuevoValorReproducciones; /*Ahora la matriz reproducciones es la matriz modificada*/
        }
        printf("Actualemente se encuentran los siguientes g%cneros musicales:\n\n",130);
        /*A continuaci�n se imprimen las canciones por g�nero y sus respectivas reproducciones*/
        for(x=0;x<7;x++)
        {
            puts(generos[x]);
            printf("|--------------------------------------------------------------------------------------------------------|\n");
            printf("|                                      N%cmero de reproducciones                                          |\n",163);
            printf("|--------------------------------------------------------------------------------------------------------|\n");
            printf("|      C1      |      C2      |      C3      |      C4      |      C5      |      C6      |      C7      |\n");
            printf("|--------------------------------------------------------------------------------------------------------|\n  ");
            printf("%d ",reproducciones[x][0]);
            printf("            ");
            printf("%d ",reproducciones[x][1]);
            printf("              ");
            printf("%d ",reproducciones[x][2]);
            printf("            ");
            printf("%d ",reproducciones[x][3]);
            printf("             ");
            printf("%d ",reproducciones[x][4]);
            printf("              ");
            printf("%d ",reproducciones[x][5]);
            printf("              ");
            printf("%d ",reproducciones[x][6]);
            printf("\n");
        }
    }
 }
 int numeroReproducciones() /*Funci�n para establecer el n�mero total de reproducciones, recorre la matriz y suma cada valor*/
 {
    for(x = 0 ;x < 7 ;x ++)
    {
        for(y = 0 ;y < 7;y ++)
        {
            suma += reproducciones[x][y];
        }
    }
printf("El numero de reproducciones totales es de: ");
printf("%d\n",suma); /*Se imprime el resultado*/
 }
 int menosEschuchadaGenero(int fila) /*Funci�n para establecer qu� canci�n es la menos escuchada por g�nero, se pone como par�metro la variable filas que representa los g�neros*/
 {
    int numeroMenosEscuchado  = 9999999999; /*Variable que define el menor n�mero de reproducciones de una fila, se inicializa con un n�mero muy grande por lo que todas las canciones tendr�n
                                              un valor de reproducciones menor a dicho valor y asi sean evaluadas en el condicional*/
    int cancionMenosEscuchada; /*Variable que define la canci�n con menor n�mero de reproducciones en una fila*/

    /*A continuaci�n se recorre la fila del g�nero correspondiente en matriz reproducciones y se va evaluando qu� n�mero es menor*/
    for(x = 0 ;x < 7 ;x ++)
    {
        if(numeroMenosEscuchado >= reproducciones[fila-1][x]) /*Condicional que eval�a si el n�mero de reproducciones en cada posici�n es menor*/
        {
            cancionMenosEscuchada = x + 1; /*Se suma una unidad a la posici�n para que concuerde con la canci�n impresa*/
            numeroMenosEscuchado  = reproducciones[fila-1][x]; /*La variable numeroMenosEscuchado es equivalente la posici�n en cada fila de la canci�n con menor reproducciones*/
        }
    }
 printf("La canci%cn menos escuchada del g%cnero seleccionado es la n%cmero: ",162,130,163);
 printf("%d\n",cancionMenosEscuchada); /*Se imprime la canc�on con menos reproducciones*/
 printf("Con un total de reproducciones de: ");
 printf("%d\n", numeroMenosEscuchado); /*Se imprime el n�mero de reproducciones dicha canci�n*/
 }
 int masEschuchadaGenero(int fila) /*Variable que define la canci�n con mayor n�mero de reproducciones*/
 {
     int numeroMasEscuchado  = -1; /*Variable que define el mayor n�mero de reproducciones de una fila, se inicializa con un n�mero negativo por lo que todas las canciones tendr�n siempre un valor de reproducciones mayor a dicho n�mero y asi entren a ser evaluadas en el condicional*/
     int cancionMasEscuchada;/*Variable que define la canci�n con m�s reproducciones en una fila*/
     for(x = 0 ;x < 7 ;x ++) /*A continuaci�n se recorre la fila del g�nero correspondiente en la matriz reproducciones y se va evaluando qu� n�mero es mayor*/
    {
        if(numeroMasEscuchado <= reproducciones[fila-1][x]) /*Condicional que eval�a si el n�mero de reproducciones en cada posici�n es mayor*/
        {
            cancionMasEscuchada = x + 1; /*Se suma una unidad a la posici�n para que concuerde con la canci�n impresa*/
            numeroMasEscuchado  = reproducciones[fila-1][x]; /*La variable numeroMasEscuchado equivale al n�mero que se encuentre en la posici�n de la canci�n con m�s reproducciones */
        }
    }
 printf("La canci%cn m%cs escuchada del g%cnero seleccionado es la n%cmero: ",162,160,130,163);
 printf("%d\n",cancionMasEscuchada); /*Se imprime la canci�n con mayor n�mero de reproducciones*/
 printf("Con un total de reproducciones de: ");
 printf("%d\n", numeroMasEscuchado); /*Se imprime el n�mero de reproducciones de dicha canci�n*/
 }
 void masEschuchadaGlobal() /*Funci�n para definir la canci�n con m�s reproducciones teniendo en centa todos los g�neros*/
 {
    int numeroMasEscuchado  = -1; /*Variable que define el mayor n�mero de reproducciones, se inicializa con un n�mero negativo por lo que todas las canciones tendr�n
                                    siempre un valor de reproducciones mayor a dicho n�mero y asi entren a ser evaluadas en el condicional*/
    int mostrarCancionMasEscuchada=0; /*Variable que define la caci�n con m�s reproducciones en toda la Matriz reproducciones*/
    int generoMasEscuchada=0; /*Variable que define a que g�nero pertenece dicha canci�n*/

    /*Se eval�a de igual manera que en la funci�n anterior pero esta vez recorriendo todas las filas de la matriz*/
    for(x = 0 ;x < 7 ;x ++)
    {
        for(y = 0 ;y < 7 ;y ++)
        {
            if(numeroMasEscuchado <= reproducciones[x][y])
                {
                    mostrarCancionMasEscuchada = y + 1;
                    generoMasEscuchada = x; /*La variable generoMasEscuchada es la fila (x) en la matriz generos*/
                    numeroMasEscuchado  = reproducciones[x][y]; /*La variable numeroMasEscuchado equivale al n�mero que se encuentre en la posici�n de la canci�n con m�s reproducciones */
                }
        }
    }
 printf("El g%cnero de la canci%cn m%cs escuchada es: ",130,162,160);
 puts(generos[generoMasEscuchada]); /*Se imprime el nombre del g�nero que se encuentre en la posici�n que defina la variable generoMasEscuchada*/
 printf("La canci%cn m%cs escuchada es la n%cmero: ",163,160,163);
 printf("%d\n",mostrarCancionMasEscuchada); /*Se imprime la canci�n que cuente con mayor n�mero de reproducciones*/
 printf("Con un total de reproducciones de: ");
 printf("%d\n\n", numeroMasEscuchado); /*Se mprim el n�mero de reproducciones de dicha canci�n*/
 }
 int reproducirCancion() /*Funci�n para reproducir una canci�n y aumentar su n�mero de reproducciones */
 {
     interfazGenero(); /*funci�n para definir a qu� genero pertenece la canci�n que se desea reproducir*/
     printf("Escriba el n%cmero del g%cnero de la canci%cn\n", 163,130,162);
     int generoCancion; /*Variable que define la fila, es decir el d�nero correspondiente, de la canci�n*/
     scanf("%d", &generoCancion);
     generoCancion-=1; /*Se resta una unidad a la posici�n del g�nero para que concuerde con el g�nero mostrado al usuario*/
     printf("Escriba el n%cmero de la canci%cn. La primera es la 1 y la %cltima la 7\n",163,162,163);
     int cancion; /*Variable que define la canci�n seleccionada a reproducir*/
     scanf("%d", &cancion);
     reproducciones[generoCancion][cancion-1]+=1; /*Se suma una unidad al valor que haya en la posici�n de la canci�n*/
     puts(generos[generoCancion]); /*Se imprimen los valores de la matriz de reproducciones para mostrar los n�meros de reproducciones de cada canci�n*/
     printf("|--------------------------------------------------------------------------------------------------------|\n");
     printf("|                                      N%cmero de reproducciones                                          |\n",163);
     printf("|--------------------------------------------------------------------------------------------------------|\n");
     printf("|      C1      |      C2      |      C3      |      C4      |      C5      |      C6      |      C7      |\n");
     printf("|--------------------------------------------------------------------------------------------------------|\n  ");
     printf("%d ",reproducciones[generoCancion][0]);
     printf("            ");
     printf("%d ",reproducciones[generoCancion][1]);
     printf("              ");
     printf("%d ",reproducciones[generoCancion][2]);
     printf("            ");
     printf("%d ",reproducciones[generoCancion][3]);
     printf("             ");
     printf("%d ",reproducciones[generoCancion][4]);
     printf("              ");
     printf("%d ",reproducciones[generoCancion][5]);
     printf("              ");
     printf("%d ",reproducciones[generoCancion][6]);
     printf("\n\n\n\n");
 }
 switch (menu) /*Selecci�n opciones por parte del usuario*/
 {
    int varCaso1;
    int varCaso3;
    case (1): /*Men� para administrador*/
    {
        int contrasenia; /*Variable que define la contrase�a del administrador*/

        printf("Ingrese la contrase%ca:\n",164); /*Mensaje para ingresar la contrase�a de adminstrdor*/
        scanf("%d", &contrasenia); /*Se lee la contrase�a ingresada*/

        if(contrasenia == 123) /*Condicional que eval�a la contrase�a ingresada*/
        {

            printf("Bienvenido\n");
            actualizarReproducciones(varCaso1); /*Llamado a la funci�n que modifica el n�mero de preproducciones*/
        }
        /*Si la contrase�a no coincide se inica que es incorreca, finaliza el men� administrador*/
        else
        {
            printf("Contrase%ca incorrecta\n",164);
        }

        break;
    }
    case (2): /*Opci�n para ver el total de reproducciones*/
    {
        numeroReproducciones(); /*Se llama a la funci�n que realiza la suma*/
        break;
    }
    case (3): /*Opci�n para ver la canci�n menos escuchada por g�nero*/
    {
        interfazGenero(); /*Se accede a la interfaz que define la fila donde se ubica la canci�n*/
        printf("\nPor favor seleccione el g%cnero:\n",130);
        scanf("%d", &fila);
        menosEschuchadaGenero(fila); /*Se llama a la funci�n que determina a la canci�n menos escuchada por g�nero*/
        break;
    }
    case (4): /*Opci�n para ver la canci�n m�s escuchada por g�nero*/
    {
        interfazGenero(); /*Se accede a la interfaz que define la fila donde se ubica la canci�n*/
        printf("\nPor favor seleccione el g%cnero:\n",130);
        scanf("%d", &fila);
        masEschuchadaGenero(fila); /*Se llama a la funci�n que determina a la canci�n m�s escuchada por g�nero*/
        break;
    }
    case (5): /*Opci�n para ver la canci�n global m�s escuchada*/
    {
        masEschuchadaGlobal(); /*Se lama a la funci�n que determina la canci�n m�s escuchada*/
        break;
    }
    case (6): /*Opci�n para reproducir una canci�n*/
    {
        reproducirCancion(); /*Se llama a la funci�n que reproduce y aumenta el n�mero de reproducciones de las canciones*/
        break;
    }
    case (7): /*Salida*/
    {
        return(0);
    }
 }
}
}
