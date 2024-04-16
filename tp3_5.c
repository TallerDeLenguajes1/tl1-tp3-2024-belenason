#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *buff;
    buff= (char *) malloc(100*sizeof(char));
    int longitud, cant;

    printf("Cuantos nombres va a ingresar?\n");
    scanf("%d", &cant);

    char **nombres = (char**)malloc(cant * sizeof(char*));
    for (int i = 0; i < cant; i++)
    {
        printf("Ingrese el nombre que desea guardar\n");
        fflush(stdin);
        gets(buff);
        longitud = strlen(buff);
        nombres[i] = (char *)malloc(sizeof(char)*(longitud + 1));
        strcpy(nombres[i], buff);
    }
    for (int i = 0; i < cant; i++)
    {
        puts(nombres[i]);
    }
    
    free(buff);
    for (int i = 0; i < cant; i++)
    {
        free(nombres[i]);
    }
    free(nombres);
    return 0;
}