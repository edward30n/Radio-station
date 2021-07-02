#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0
/** ------------------------------- Made in Colombia, by: Edward Nicolas Duarte Valencia, Juliana Toro Camelo--------------------------------------------
* Este programa busca la estación de radio "Melodía Javeriana".\n
* En donde se quiere crear un sistema de reproducción y clasificación musical
* Para ello se requieren las siguientes interfaces:
* 1) Actualizar matriz de reproducción: el administrador por medio de su acceso con contraseña puede cambiar el género musical y el número de reproducciones de las canciones.
* 2) Número total de reproducciones
* 3) Canción menos escuchada por género
* 4) Canción más escuchada por género
* 5) Canción global más escuchada
* 6) Reproducir una canción
-----------------------------------------------------------------------------------------------------------------------------------------------------------**/
int x,y,reproducciones[7][7] = {{1,3,0,9,8,7,6},{15,14,7,1,17,16,4},{0,50,30,25,18,20,13},{6,5,4,3,2,1,10},{0,24,2,0,2,9,15},{8,6,2,0,5,1,1},{2,8,0,7,2,1,8}};
/*Matriz que define el número de reproducciones de cada canción, las filas son los géneros musicales*/
char generos [7][40] = {{"POP"},{"ROCK"},{"CLASICA"},{"RAP"},{"ELECTRONICA"},{"JAZZ"},{"FRANCESA"}};
/*Matriz que define el nombre de cada género musical por fila*/
int main()
{
 system("color 02"); /*Modificación color impresión*/

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
 char generos2 [7][40]; /*Matriz que almacenará la modificación de los géneros musicales*/
 int suma = 0; /*Variable que representa la suma de reproducciones de las canciones*/
 int fila = 0;
 int menu;/*Variable que almacena la opción seleccionada por el usuario*/
 printf("Ingrese el n%cmero de la interfaz a la que desea acceder:\n\n",163); /*Se pregunta al usuario qué opción desea*/
 printf("__________________________________________________\n"); /*A continuación se presentan al usuario las opciones disponibles*/
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
 scanf("%d", &menu); /*Se lee la elección del usuario*/

 void interfazGenero() /*Esta función imprime los géneros representados en la matriz*/
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
 void actualizarReproducciones() /*Función para modificar el número de reproducciones*/
 {
    int generoModificar; /*Variable que define el género que el administrador desee modificar*/
    int tipoModificacion;/*Variable que deine el tipo de modificación que se desea hacer al género definido en la variable anterior*/
    interfazGenero(); /*Llamado a la función que presenta los géneros*/
    printf("\nPor favor seleccione el g%cnero que desea modificar:\n",130); /*Se pregunta al administrador qué género desea modificar*/
    scanf("%d", &generoModificar); /*Se escanea la respuesta del usuario*/
    printf("Usted ha seleccionado el g%cnero: ",130); /*Se indica el género seleccionado*/
    puts(generos[generoModificar - 1]); /*Al iniciar la matriz en la posición 0 se resta una unidad al género de la respusta del usuario para que la posición coincida*/
    printf("\n Digite el tipo de modificaci%cn que desea realizar:\n",162); /*Se pregunta qué modificación se desea hacer*/
    printf(" ______________________    __________________________    ___________\n");
    printf("|   Nombre del g%cnero  |  |   Canciones del g%cnero   |  |   Salir   |\n",130,130);
    printf("|          1           |  |             2            |  |     3     |\n");
    printf("|______________________|  |__________________________|  |___________|\n");
    scanf("%d", &tipoModificacion);
    if(tipoModificacion == 1)
    /*Si el usuario desea modificar el nombre del género se le pregunta cuál debe ser el nuevo nombre y este se guarda en la matriz dispuesta para la modificación*/
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
        interfazGenero(); /*Llamado a la función que presenta los géneros*/
        printf("\nNombre de g%cnero actualizado.\n",130);
    }
    else if(tipoModificacion == 2)
   /*Si el usuario desea modificar el número de reproducciones por canción se preguntan las nuevas reproducciones y este número se guarda en la matriz dispuesta para la modificación*/
    {
        printf("Digite los nuevos n%cmeros de reproducci%cn de cada canci%cn. Cada vez que digite un n%cmero oprima enter.\n",163,162,162,163);
        for(x=0;x<7;x++)
        {
            int numeroCancion = 1; /*Variable que define en número de la canción*/
            numeroCancion += x; /*El número de la canción hace referencia a cada columna en la fila género*/
            printf("Canci%cn %d\n",162,numeroCancion);
            int nuevoValorReproducciones = 0; /*Variable que guarda la modificación ingresada del número de reproducciones*/
            scanf("%d", &nuevoValorReproducciones);
            reproducciones[generoModificar-1][x] = nuevoValorReproducciones; /*Ahora la matriz reproducciones es la matriz modificada*/
        }
        printf("Actualemente se encuentran los siguientes g%cneros musicales:\n\n",130);
        /*A continuación se imprimen las canciones por género y sus respectivas reproducciones*/
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
 int numeroReproducciones() /*Función para establecer el número total de reproducciones, recorre la matriz y suma cada valor*/
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
 int menosEschuchadaGenero(int fila) /*Función para establecer qué canción es la menos escuchada por género, se pone como parámetro la variable filas que representa los géneros*/
 {
    int numeroMenosEscuchado  = 9999999999; /*Variable que define el menor número de reproducciones de una fila, se inicializa con un número muy grande por lo que todas las canciones tendrán
                                              un valor de reproducciones menor a dicho valor y asi sean evaluadas en el condicional*/
    int cancionMenosEscuchada; /*Variable que define la canción con menor número de reproducciones en una fila*/

    /*A continuación se recorre la fila del género correspondiente en matriz reproducciones y se va evaluando qué número es menor*/
    for(x = 0 ;x < 7 ;x ++)
    {
        if(numeroMenosEscuchado >= reproducciones[fila-1][x]) /*Condicional que evalúa si el número de reproducciones en cada posición es menor*/
        {
            cancionMenosEscuchada = x + 1; /*Se suma una unidad a la posición para que concuerde con la canción impresa*/
            numeroMenosEscuchado  = reproducciones[fila-1][x]; /*La variable numeroMenosEscuchado es equivalente la posición en cada fila de la canción con menor reproducciones*/
        }
    }
 printf("La canci%cn menos escuchada del g%cnero seleccionado es la n%cmero: ",162,130,163);
 printf("%d\n",cancionMenosEscuchada); /*Se imprime la cancíon con menos reproducciones*/
 printf("Con un total de reproducciones de: ");
 printf("%d\n", numeroMenosEscuchado); /*Se imprime el número de reproducciones dicha canción*/
 }
 int masEschuchadaGenero(int fila) /*Variable que define la canción con mayor número de reproducciones*/
 {
     int numeroMasEscuchado  = -1; /*Variable que define el mayor número de reproducciones de una fila, se inicializa con un número negativo por lo que todas las canciones tendrán siempre un valor de reproducciones mayor a dicho número y asi entren a ser evaluadas en el condicional*/
     int cancionMasEscuchada;/*Variable que define la canción con más reproducciones en una fila*/
     for(x = 0 ;x < 7 ;x ++) /*A continuación se recorre la fila del género correspondiente en la matriz reproducciones y se va evaluando qué número es mayor*/
    {
        if(numeroMasEscuchado <= reproducciones[fila-1][x]) /*Condicional que evalúa si el número de reproducciones en cada posición es mayor*/
        {
            cancionMasEscuchada = x + 1; /*Se suma una unidad a la posición para que concuerde con la canción impresa*/
            numeroMasEscuchado  = reproducciones[fila-1][x]; /*La variable numeroMasEscuchado equivale al número que se encuentre en la posición de la canción con más reproducciones */
        }
    }
 printf("La canci%cn m%cs escuchada del g%cnero seleccionado es la n%cmero: ",162,160,130,163);
 printf("%d\n",cancionMasEscuchada); /*Se imprime la canción con mayor número de reproducciones*/
 printf("Con un total de reproducciones de: ");
 printf("%d\n", numeroMasEscuchado); /*Se imprime el número de reproducciones de dicha canción*/
 }
 void masEschuchadaGlobal() /*Función para definir la canción con más reproducciones teniendo en centa todos los géneros*/
 {
    int numeroMasEscuchado  = -1; /*Variable que define el mayor número de reproducciones, se inicializa con un número negativo por lo que todas las canciones tendrán
                                    siempre un valor de reproducciones mayor a dicho número y asi entren a ser evaluadas en el condicional*/
    int mostrarCancionMasEscuchada=0; /*Variable que define la cación con más reproducciones en toda la Matriz reproducciones*/
    int generoMasEscuchada=0; /*Variable que define a que género pertenece dicha canción*/

    /*Se evalúa de igual manera que en la función anterior pero esta vez recorriendo todas las filas de la matriz*/
    for(x = 0 ;x < 7 ;x ++)
    {
        for(y = 0 ;y < 7 ;y ++)
        {
            if(numeroMasEscuchado <= reproducciones[x][y])
                {
                    mostrarCancionMasEscuchada = y + 1;
                    generoMasEscuchada = x; /*La variable generoMasEscuchada es la fila (x) en la matriz generos*/
                    numeroMasEscuchado  = reproducciones[x][y]; /*La variable numeroMasEscuchado equivale al número que se encuentre en la posición de la canción con más reproducciones */
                }
        }
    }
 printf("El g%cnero de la canci%cn m%cs escuchada es: ",130,162,160);
 puts(generos[generoMasEscuchada]); /*Se imprime el nombre del género que se encuentre en la posición que defina la variable generoMasEscuchada*/
 printf("La canci%cn m%cs escuchada es la n%cmero: ",163,160,163);
 printf("%d\n",mostrarCancionMasEscuchada); /*Se imprime la canción que cuente con mayor número de reproducciones*/
 printf("Con un total de reproducciones de: ");
 printf("%d\n\n", numeroMasEscuchado); /*Se mprim el número de reproducciones de dicha canción*/
 }
 int reproducirCancion() /*Función para reproducir una canción y aumentar su número de reproducciones */
 {
     interfazGenero(); /*función para definir a qué genero pertenece la canción que se desea reproducir*/
     printf("Escriba el n%cmero del g%cnero de la canci%cn\n", 163,130,162);
     int generoCancion; /*Variable que define la fila, es decir el dénero correspondiente, de la canción*/
     scanf("%d", &generoCancion);
     generoCancion-=1; /*Se resta una unidad a la posición del género para que concuerde con el género mostrado al usuario*/
     printf("Escriba el n%cmero de la canci%cn. La primera es la 1 y la %cltima la 7\n",163,162,163);
     int cancion; /*Variable que define la canción seleccionada a reproducir*/
     scanf("%d", &cancion);
     reproducciones[generoCancion][cancion-1]+=1; /*Se suma una unidad al valor que haya en la posición de la canción*/
     puts(generos[generoCancion]); /*Se imprimen los valores de la matriz de reproducciones para mostrar los números de reproducciones de cada canción*/
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
 switch (menu) /*Selección opciones por parte del usuario*/
 {
    int varCaso1;
    int varCaso3;
    case (1): /*Menú para administrador*/
    {
        int contrasenia; /*Variable que define la contraseña del administrador*/

        printf("Ingrese la contrase%ca:\n",164); /*Mensaje para ingresar la contraseña de adminstrdor*/
        scanf("%d", &contrasenia); /*Se lee la contraseña ingresada*/

        if(contrasenia == 123) /*Condicional que evalúa la contraseña ingresada*/
        {

            printf("Bienvenido\n");
            actualizarReproducciones(varCaso1); /*Llamado a la función que modifica el número de preproducciones*/
        }
        /*Si la contraseña no coincide se inica que es incorreca, finaliza el menú administrador*/
        else
        {
            printf("Contrase%ca incorrecta\n",164);
        }

        break;
    }
    case (2): /*Opción para ver el total de reproducciones*/
    {
        numeroReproducciones(); /*Se llama a la función que realiza la suma*/
        break;
    }
    case (3): /*Opción para ver la canción menos escuchada por género*/
    {
        interfazGenero(); /*Se accede a la interfaz que define la fila donde se ubica la canción*/
        printf("\nPor favor seleccione el g%cnero:\n",130);
        scanf("%d", &fila);
        menosEschuchadaGenero(fila); /*Se llama a la función que determina a la canción menos escuchada por género*/
        break;
    }
    case (4): /*Opción para ver la canción más escuchada por género*/
    {
        interfazGenero(); /*Se accede a la interfaz que define la fila donde se ubica la canción*/
        printf("\nPor favor seleccione el g%cnero:\n",130);
        scanf("%d", &fila);
        masEschuchadaGenero(fila); /*Se llama a la función que determina a la canción más escuchada por género*/
        break;
    }
    case (5): /*Opción para ver la canción global más escuchada*/
    {
        masEschuchadaGlobal(); /*Se lama a la función que determina la canción más escuchada*/
        break;
    }
    case (6): /*Opción para reproducir una canción*/
    {
        reproducirCancion(); /*Se llama a la función que reproduce y aumenta el número de reproducciones de las canciones*/
        break;
    }
    case (7): /*Salida*/
    {
        return(0);
    }
 }
}
}
