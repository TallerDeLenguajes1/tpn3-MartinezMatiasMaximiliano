#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    int ProductoID;                     //Numerado en ciclo iterativo
    int Cantidad;                       // entre 1 y 10        
    char *TipoProducto;                 // Algún valor del arreglo TiposProductos            
    float PrecioUnitario;               // entre 10 - 100
}Producto;



typedef struct{
    int ClienteID;                      // Numerado en el ciclo iterativo 
    char *NombreCliente;                // Ingresado por usuario
    int CantidadProductosAPedir;        // (alteatorio entre 1 y 5)
    Producto *Productos;                //El tamaño de este arreglo depende de la variable CantidadProductosAPedir 
}Cliente;

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
void CargarClientes(Cliente *auxCargar,int cantClientes);
void CargarProductos(Producto *auxProductos,int cantProductos);
void MostrarVenta(Cliente *auxVenta,int cantClientes);

int main(){
    srand(time(NULL));
    int cantClientes = 0;
    //pedir cantidad de clientes
    while (cantClientes == 0 || cantClientes > 5 )
    {
        printf("Ingrese la cantidad de clientes que visita (MENOR A 5):");
        scanf("%d",&cantClientes);
    }

    Cliente *visitas = (Cliente*)malloc(sizeof(Cliente)*cantClientes);//visitas apunta a la dir de primer cliente
    CargarClientes(visitas,cantClientes);
    MostrarVenta(visitas,cantClientes);
    getchar();
    return 0;
}

void CargarClientes(Cliente *auxCliente,int cantClientes)
{
    Cliente aux;
    for (int i = 0; i < cantClientes; i++)
    {
        //ID
        aux.ClienteID = i+1;
        //NOMBRE
        printf("Ingrese el nombre del cliente #%d: ",i+1);
            fflush(stdin);
            char nombre[500];
            int a;
            gets(nombre);
            a = strlen(nombre);
            aux.NombreCliente =(char*)malloc(sizeof(char)*a);
            strcpy(aux.NombreCliente,nombre);
            
        //PRODUCTOS
        aux.CantidadProductosAPedir = rand()%10+1;

        aux.Productos = (Producto*)malloc(sizeof(Producto)*aux.CantidadProductosAPedir);
        CargarProductos(aux.Productos,aux.CantidadProductosAPedir);

        *auxCliente = aux;
        auxCliente++;
    }
}

void CargarProductos(Producto *auxProductos,int cantProductos)
{
    Producto aux;
    for (int j = 0; j < cantProductos; j++)
    {
        aux.ProductoID = j+1;
        aux.Cantidad = rand()%10 +1;
        aux.TipoProducto = *(TiposProductos + rand()%5);
        aux.PrecioUnitario = rand()% 91 +10;

        *auxProductos = aux;
        auxProductos++;
    }
}

void MostrarVenta(Cliente *auxVenta,int cantClientes){
    Cliente mostrarCliente;
    Producto mostrarProducto;
    printf("\n\n==========================LISTA DE VENTAS==========================\n");
    for (int k = 0; k < cantClientes; k++)
    {
        mostrarCliente = *auxVenta;
        printf("==========================\n\n");
        printf("Cliente #%d: [",mostrarCliente.ClienteID);
        printf("%s]\n",mostrarCliente.NombreCliente);
        printf("Cantidad de productos pedidos:%d\n",mostrarCliente.CantidadProductosAPedir);
        
        for (int l = 0; l < mostrarCliente.CantidadProductosAPedir; l++)
        {
            mostrarProducto = mostrarCliente.Productos[l];
            //printf("Producto #%d",l+1);
            printf("ID producto:%d\n",mostrarProducto.ProductoID);
            printf("Tipo de producto:[%s]\n",mostrarProducto.TipoProducto);
            printf("Cantidades pedidas:%d\n",mostrarProducto.Cantidad);
            printf("Precio unitario: $%d\n\n",mostrarProducto.PrecioUnitario);
            
        }
            //printf("total a pagar:%d",total);
            

        auxVenta++;
    }   
    
}
