#ifndef GONDOLA_H
#define GONDOLA_H
#include "producto.h"
#include <string>

/*
Precondiciones:
.Ninguna.
Postcondiciones:
.Se inicializan todos los atributos de la góndola.
.gondola_productos es inicializado como un vector dinamico el cual es un puntero a los objetos de la clase producto.
.capacidad_en_gondola es inicializado como 5.
.cantidad_en_gondola es inicializado como 0.
*/

class Gondola {
    private:
        Producto* gondola_productos; 
        int capacidad_en_gondola;
        int cantidad_en_gondola; 
    
    public:
        /* Gondola() - Constructor
        Precondiciones:
        .Ninguna.
        Postcondiciones:
        .Se inicializan todos los atributos de la góndola.
        .gondola_productos es inicializado como un puntero nulo.
        .capacidad_en_gondola es inicializado como 0.
        .cantidad_en_gondola es inicializado como 0.
        */
        Gondola();

        /* ~Gondola() - Destructor
        Precondiciones:
        .Ninguna.
        Postcondiciones:
        .Libera la memoria asignada dinámicamente para gondola_productos.
        .Los demás atributos son eliminados adecuadamente.
        */
        ~Gondola();
        
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

        /* disminuirCapacidad() - Método
        Precondiciones:
        .Ninguna.
        Postcondiciones:
        .Disminuye la capacidad de la góndola a la mitad.
        .Se copian los productos de la góndola actual al nuevo arreglo de productos.
        .Se libera la memoria asignada dinámicamente para el arreglo de productos actual.
        .Se actualiza la capacidad de la góndola.
        */
        void disminuirCapacidad();

        /* leerProductos() - Método
        Precondiciones:
        .El usuario proporciona los datos de los productos.
        .Los productos no se repiten en la góndola.
        .Los productos se almacenan en productos.txt.
        .El nombre del producto se escribe en minusculas en el txt.
        Postcondiciones:
        .Los productos se leen y almacenan en la góndola.
        */
        void leerProductos();

        /* buscarProducto() - Método
        Precondiciones:
        .Ninguna.
        Postcondiciones:
        .Devuelve la posición del producto con el nombre proporcionado en la góndola.
        .Si el producto no existe en la góndola, devuelve -1.
        .No modifica el estado de la góndola.
        */
        int buscarProducto(const std::string& nombre_producto) const;

        /* mostrarProductos() - Método
        Precondiciones:
        .Ninguna.
        Postcondiciones:
        .Muestra los productos en la góndola.
        .Muestra el precio de cada producto.
        .Muestra el stock de cada producto.
        .Muestra si el producto esta en oferta.
        .No modifica el estado de la góndola.
        */
        void mostrarProductos();


        /* modificarStock() - Método
        Precondiciones:
        .Que la posición proporcionada sea válida.
        Postcondiciones:
        .Modifica el stock del producto en la posición proporcionada en la góndola.
        .Si la cantidad a comprar es mayor que el stock disponible, devuelve -1.
        .Si la cantidad a comprar es menor o igual que el stock disponible, devuelve 0.
        .Modifica el estado de la góndola.
        */
        int modificarStock(int posicion, int cantidad_a_comprar);

        /* buscarPrecio() - Método
        Precondiciones:
        .Que la posición proporcionada sea válida.
        Postcondiciones:
        .Devuelve el precio del producto en la posición proporcionada en la góndola.
        .No modifica el estado de la góndola.
        */
        double buscarPrecio(int posicion) const;

        /* buscarOferta() - Método
        Precondiciones:
        .Que la posición proporcionada sea válida.
        Postcondiciones:
        .Devuelve verdadero si el producto en la posición proporcionada en la góndola está en oferta; de lo contrario, devuelve falso.
        .No modifica el estado de la góndola.
        */
        bool buscarOferta(int posicion) const;

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

        /* actualizarGondola() - Método
        Precondiciones:
        .Ninguna.
        Postcondiciones:
        .Actualiza el archivo de texto con los productos de la góndola.
        .Si el archivo de texto no existe, muestra un mensaje de error y termina la ejecución del programa.
        */
        void actualizarGondola();
};

#endif // GONDOLA_H