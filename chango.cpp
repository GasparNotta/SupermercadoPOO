#include "chango.h"
#include "gondola.h"
#include "producto.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

Chango::Chango() {
        capacidad_en_chango = 5; 
        cantidad_en_chango = 0; 
        chango_productos = new Producto[capacidad_en_chango]; 
    }

    Chango::~Chango() {
        delete[] chango_productos; 
        chango_productos = nullptr; 
        capacidad_en_chango = 0; 
        cantidad_en_chango = 0; 
    }

    bool Chango::estaLlena() const{
        if (cantidad_en_chango == capacidad_en_chango) {
            return true;
        } else {
            return false;
        }
    }

    void Chango::aumentarCapacidad() {
        capacidad_en_chango = capacidad_en_chango * 2;
        Producto* nuevo_array = new Producto[capacidad_en_chango];

        for (int i = 0; i < cantidad_en_chango; i++) {
            nuevo_array[i] = chango_productos[i];
        }

        delete[] chango_productos;
        chango_productos = nuevo_array;
    }

    void Chango::leerChango() {
        std::ifstream archivo;
        archivo.open("compra.txt", std::ios::in);

        if(!archivo.is_open()){
        std::cerr << "No se pudo abrir el archivo compra.txt" << std::endl;
        delete[] chango_productos;
        exit(EXIT_FAILURE);
        } else if( archivo.peek() == std::ifstream::traits_type::eof() ) {
        std::cerr << "El archivo compra.txt esta vacio" << std::endl;
        delete[] chango_productos;
        exit(EXIT_FAILURE);
        } else {
            std::string nombre;
            int cantidad_a_comprar;
            while (archivo >> nombre >> cantidad_a_comprar){
                if (estaLlena() == true) {
                    aumentarCapacidad();
                }
            chango_productos[cantidad_en_chango] = Producto(nombre, 0, false, 0 , cantidad_a_comprar, 0);
            cantidad_en_chango++;
        }
        archivo.close();
        }
    }


    void Chango::eliminarProducto(int posicion) {
        if (posicion < 0 || posicion >= cantidad_en_chango) {
            // Verificar si la posición es válida
            std::cerr << "Error: La posición especificada está fuera de los límites del chango." << std::endl;
            return;
        }

        // Mover los productos una posición hacia la izquierda, comenzando desde la posición dada
        for (int i = posicion; i < cantidad_en_chango - 1; i++) {
            chango_productos[i] = chango_productos[i + 1];
        }

        // Reducir la cantidad total de productos en el chango
        cantidad_en_chango--;
    }

    void Chango::mostrarChango() const{
        for (int i = 0; i < cantidad_en_chango; i++) {
            std::cout << std::setw(3) << i + 1 << ": ";
            std::cout << std::setw(15) << std::left << chango_productos[i].obtenerNombre();
            std::cout << std::setw(15) << std::left << chango_productos[i].obtenerCantidadAComprar() << std::endl;
        }
    }

    void Chango::realizarCompra(Gondola& gondola){
        //Recorremos el chango
        for (int i = 0; i < cantidad_en_chango; ) {
            //Buscamos el producto en la gondola
            int indice = gondola.buscarProducto(chango_productos[i].obtenerNombre());
            //Si el producto no se encuentra en la gondola se elimina del chango
            if (indice == -1) {
                std::cout << "Aviso: No hay stock del producto \"" << chango_productos[i].obtenerNombre() << "\" Se continua la compra." << std::endl;
                eliminarProducto(i);
            //Si el producto se encuentra en la gondola se intenta modificar el stock
            } else {
                int valor = gondola.modificarStock(indice, chango_productos[i].obtenerCantidadAComprar());
                //Si no hay suficiente stock del producto en la gondola se elimina del chango y se continua con la compra
                if (valor == -1) {
                    eliminarProducto(i);
                }else{
                    //Si hay suficiente stock del producto se calcula el precio total a pagar por la cantidad de productos
                    double precio = gondola.buscarPrecio(indice);
                    int oferta = gondola.buscarOferta(indice);
                    double precio_total_a_pagar_por_producto = precio * chango_productos[i].obtenerCantidadAComprar();

                    if (oferta == true) {
                        precio_total_a_pagar_por_producto = precio_total_a_pagar_por_producto * 0.9;
                    }
                    //Se actualiza el producto en el chango para que tenga la informarcion necesaria para mostrar el detalle de la compra
                    chango_productos[i] = Producto(chango_productos[i].obtenerNombre(), precio, oferta, 0 , chango_productos[i].obtenerCantidadAComprar(), precio_total_a_pagar_por_producto);
                    i++;
                }
            }
        }
    }
    


    void Chango::mostrarChangoFinal() const {
    std::cout << "----------------------------------- Este es el detalle de la compra ---------------------------------" << std::endl;
    std::cout << std::setw(3) << "|";
    std::cout << std::setw(15) << std::left << "Producto";
    std::cout << std::setw(20) << std::left << "| Precio_Unitario";
    std::cout << std::setw(15) << std::left << "| Cantidad";
    std::cout << std::setw(15) << std::left << "| Oferta (S/N)";
    std::cout << std::setw(15) << std::left << "| Precio_Item" << "|" << std::endl;

    double cantidad_total_a_pagar = 0.0;

    for (int i = 0; i < cantidad_en_chango; i++) {
        std::cout << std::setw(3) << i + 1 << ": ";
        std::cout << std::setw(15) << std::left << chango_productos[i].obtenerNombre();
        std::cout << std::setw(20) << std::left << chango_productos[i].obtenerPrecio();
        std::cout << std::setw(15) << std::left << chango_productos[i].obtenerCantidadAComprar();
        std::cout << std::setw(15) << std::left << (chango_productos[i].obtenerOferta() ? "Si" : "No");
        std::cout << std::setw(15) << std::left << chango_productos[i].obtenerCantidadAPagarPorProducto() << std::endl;

        cantidad_total_a_pagar += chango_productos[i].obtenerCantidadAPagarPorProducto();
    }
    std::cout << "------------------------------------------ Total a pagar: $" << cantidad_total_a_pagar << " ---------------------------------------"<< std::endl;
}






