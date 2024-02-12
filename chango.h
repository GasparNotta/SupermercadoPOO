#ifndef CHANGO_H
#define CHANGO_H
#include "gondola.h"
#include "producto.h"

/*
Precondiciones:
.Ninguna.
Postcondiciones:
.Se inicializan todos los atributos de la chango.
.chango_productos es inicializado como un vector dinamico el cual es un puntero a los objetos de la clase producto.
.capacidad_en_chango es inicializado como 5.
.cantidad_en_chango es inicializado como 0.
.cantidad_total_a_pagar es inicializado como 0.
*/
class Chango{
    private:
        Producto* chango_productos; 
        int capacidad_en_chango;
        int cantidad_en_chango; 
        double cantidad_total_a_pagar;
    
    public:
        Chango();
        ~Chango();
        
        /* estaLlena() - Método
        Precondiciones:
        .Ninguna.
        Postcondiciones:
        .Devuelve verdadero si la cantidad de productos en la góndola es igual a la capacidad máxima de la góndola; de lo contrario, devuelve falso.
        .No modifica el estado de la góndola.
        */
        bool estaLlena() const;

        /* aumentarCapacidad() - Método
        Precondiciones:
        .Ninguna.
        Postcondiciones:
        .Duplica la capacidad de la góndola.
        .Se copian los productos de la góndola actual al nuevo arreglo de productos con mayor tamano.
        .Se libera la memoria asignada dinámicamente para el arreglo de productos actual.
        .Se actualiza la capacidad de la góndola.
        */
        void aumentarCapacidad();

        /* leerProductos() - Método
        Precondiciones:
        .El usuario proporciona los datos de los productos.
        .Los productos no se repiten en la góndola.
        .Los productos se almacenan en productos.txt.
        .El nombre del producto se escribe en minusculas en el txt.
        Postcondiciones:
        .Los productos se leen y almacenan en la góndola.
        */
        void leerChango();

        /* eliminarProducto() - Método
        Precondiciones:
        .Que la posición proporcionada sea válida.
        Postcondiciones:
        .Elimina el producto en la posición proporcionada en la góndola.
        .Si la posición no es válida, no hace nada.
        .Si el tamaño de la gondola es el doble de la cantidad de productos, disminuye la capacidad de la góndola a la mitad.
        .Modifica el estado de la góndola.
        */
        void eliminarProducto(int posicion);

        /* mostrarChango() - Método
        Precondiciones:
        .Ninguna.
        Postcondiciones:
        .Muestra los productos en el chango.
        .Muestra la cantidad a comprar de cada producto.
        .No modifica el estado del chango.
        */
        void mostrarChango() const;

        /* realizarCompra() - Método
        Precondiciones:
        .La gondola debe estar definida correctamente.
        Postcondiciones:
        .Realiza la compra de los productos del chango en la gondola.
        .Si el producto no existe en la gondola, muestra un mensaje de aviso y borra ese producto del chango.
        .Si el producto existe en la gondola pero su stock es menor a la cantidad a comprar, muestra un mensaje y borra el producto del chango.
        .Si el producto existe en la gondola, modifica el stock del producto en la gondola.
        .Se calcula el precio total a pagar por la cantidad de productos deseado
        .Si los productos no están en oferta, se pagan a el precio regular.
        .Si los productos están en oferta, se pagan a el precio de oferta.
        .Actualiza los datos del producto en el chango para imprimirlos posteriormente en el resumen de compra.
        .Modifica el estado del chango.
        */
        void realizarCompra(Gondola& gondola);

        /* mostrarChangoFinal() - Método
        Precondiciones:
        .Ninguna.
        Postcondiciones:
        .Muestra los productos en el chango.
        .Muestra la cantidad a comprar de cada producto.
        .Muestra la cantidad a pagar por ese producto.
        .Muestra la cantidad total a pagar por la cantidad de productos deseada.
        .Muestra si el producto esta en oferta.
        .Muestra el total a pagar.
        .No modifica el estado del chango.
        */
        void mostrarChangoFinal() const;
};

#endif // CHANGO_H