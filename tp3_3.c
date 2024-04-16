#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char **nombres = (char**)malloc(5 * sizeof(char*));
    char *buff;
    buff= (char *) malloc(100*sizeof(char));
    int longitud;
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre que desea guardar\n");
        gets(buff);
        longitud = strlen(buff);
        nombres[i] = (char *)malloc(sizeof(char)*(longitud + 1));
        strcpy(nombres[i], buff);
    }
    for (int i = 0; i < 5; i++)
    {
        puts(nombres[i]);
    }
    
    free(buff);
    for (int i = 0; i < 5; i++)
    {
        free(nombres[i]);
    }
    free(nombres);
    return 0;
}