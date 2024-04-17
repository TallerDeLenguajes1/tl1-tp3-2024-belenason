#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto 
{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
} typedef cliente;

void cargarClientes(cliente *clientes, int cantClientes);
float costoTotalxProduc(producto produc);
void mostrar(cliente *clientes, int cantClientes);
float totalAPagarxCliente(producto produc[], int cantidadProd);


int main(){
    srand(time(NULL));
    int cantClientes;
    float total = 0;
    do{
        printf("\nIngrese la cantidad de clientes: ");
        scanf("%d", &cantClientes);
        if (cantClientes<0 || cantClientes>5)
        {
            printf("\nLa cantidad ingresada no es valida");
        }
    }while(cantClientes<0 || cantClientes>5);
    cliente *clientes = (cliente *)malloc(cantClientes * sizeof(cliente));
    cargarClientes(clientes, cantClientes);
    mostrar(clientes, cantClientes);
    for(int i = 0;i<cantClientes;i++)
    {
        for (int j = 0; j < ((clientes + i)->CantidadProductosAPedir); j++)
        {
            free(((clientes + i)->Productos + j)->TipoProducto);
        }
        free((clientes+i)->Productos);
        free((clientes+i)->NombreCliente);
    }
    free(clientes);
    return 0;
}

void cargarClientes (cliente *clientes, int cantClientes){
    char *buff, *puntTipodeProducto;
    buff = (char *)malloc(100 * sizeof(char));
    int longitud = 0;
    for (int i = 0; i < cantClientes; i++)
    {
        (clientes + i)->ClienteID = i;
        printf("\nIngrese el nombre del cliente: ");
        fflush(stdin);
        gets(buff); //Por qué no se pone (*buff)?
        longitud = strlen(buff) + 1;
        (clientes+i)->NombreCliente = (char *)malloc(longitud * sizeof(char));
        strcpy((clientes+i)->NombreCliente, buff);
        (clientes + i)->CantidadProductosAPedir = 1 + rand()%(5 - 1 + 1);
        (clientes + i)->Productos = (producto *)malloc(((clientes + i)->CantidadProductosAPedir) * sizeof(producto));
        for (int j = 0; j < ((clientes + i)->CantidadProductosAPedir); j++)
        {
            ((clientes + i)->Productos + j)->ProductoID = j;
            ((clientes + i)->Productos + j)->Cantidad = 1 + rand()%(10 - 1 + 1);
            ((clientes + i)->Productos + j)->PrecioUnitario = (1000+(rand()%(10000 - 1000 + 1)))*0.01;
            puntTipodeProducto = TiposProductos[0 + rand()%(4 - 0 + 1)];
            ((clientes + i)->Productos + j)->TipoProducto = (char*)malloc(strlen(puntTipodeProducto)*sizeof(char));
            strcpy(((clientes + i)->Productos + j)->TipoProducto, puntTipodeProducto);
        }
        //Otra opcion: 
        //clientes[i].ClienteID = ...
    }
    free(buff);
}

float costoTotalxProduc(producto produc){
    float costo;
    costo = produc.Cantidad * produc.PrecioUnitario;
    return costo;
}

float totalAPagarxCliente(producto produc[], int cantidadProd){
    float total = 0;
    for (int i = 0; i < cantidadProd; i++)
    {
        total = total + costoTotalxProduc(produc[i]);
    }
    
}

void mostrar(cliente *clientes, int cantClientes){
    
    for(int i = 0;i<cantClientes;i++)
    {
        printf("\n\n--------Cliente %d--------\n", i+1);
        printf("\nId del cliente: %d", (clientes + i)->ClienteID);
        printf("\nNombre del cliente: %s", (clientes + i)->NombreCliente);  
        printf("\nCantidad de productos pedidos: %d", (clientes + i)->CantidadProductosAPedir);
        for (int j = 0; j < (clientes + i)->CantidadProductosAPedir; j++)
        {
            printf("\n\n--------Producto %d--------\n", j+1);
            printf("\nId del producto: %d", ((clientes + i)->Productos + j)->ProductoID);
            printf("\nCantidad: %d", ((clientes + i)->Productos + j)->Cantidad);  
            printf("\nTipo de producto: %s", ((clientes + i)->Productos + j)->TipoProducto);
            printf("\nPrecio unitario: %.2f", ((clientes + i)->Productos + j)->PrecioUnitario);
        }
    printf("\n\nEl total a pagar por el cliente es: %.2f", totalAPagarxCliente((clientes+i)->Productos, ((clientes + i)->CantidadProductosAPedir)));
    }
}