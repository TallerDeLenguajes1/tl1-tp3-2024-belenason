#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 12

void cargarMatriz1(int *pMatriz, int filas, int columnas);
void cargarMatriz2(int matriz[N][M]);
void mostrarMatriz(int matriz[N][M]);
void promedioGananciaAnual(int matriz[N][M]);
void valorMinYMax(int matriz[N][M]);

int main (){
    srand(time(NULL));
    int produc[N][M];
    cargarMatriz2(produc);
    mostrarMatriz(produc);
    promedioGananciaAnual(produc);
    valorMinYMax(produc);
    
    return 0;
}

void cargarMatriz1(int *pMatriz, int filas, int columnas){
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(pMatriz + (i*columnas + j)) = 10000+rand()%(50000 - 10000 + 1);
        }
    }
}

void cargarMatriz2(int matriz[N][M]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matriz[i][j] = 10000+rand()%(50000 - 10000 + 1);
        }
        
    }
    
}

void mostrarMatriz(int matriz[N][M]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d   ", matriz[i][j]);
        }
        printf("\n");
    }
}

void promedioGananciaAnual(int matriz[N][M]){
    float suma, promedio;
    for (int i = 0; i < N; i++)
    {
        suma = 0;
        for (int j = 0; j < M; j++)
        {
            suma = suma + matriz[i][j];
        }
        promedio = suma/12;
        printf("\nPromedio del ano %d: %.2f", i+1, promedio);
    }
}

void valorMinYMax(int matriz[N][M]){
    int min, max, anoMin, mesMin, anoMax, mesMax;
    min = 50002;
    max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matriz[i][j]>=max)
            {
                max = matriz[i][j];
                anoMax = i+1;
                mesMax = j+1;
            }
            if (matriz[i][j]<=min)
            {
                min = matriz[i][j];
                anoMin = i+1;
                mesMin = j+1;
            }
        }
    }
    printf("\nEl valor maximo obtenido fue %d y tuvo lugar el ano %d en mes %d", max, anoMax, mesMax);
    printf("\nEl valor minimo obtenido fue %d y tuvo lugar el ano %d en mes %d", min, anoMin, mesMin);

}