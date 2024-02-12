#include "gondola.h"
#include "producto.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

Gondola::Gondola() {
        capacidad_en_gondola = 5; 
        cantidad_en_gondola = 0; 
        gondola_productos = new Producto[capacidad_en_gondola]; 
    }

    Gondola::~Gondola() {
        delete[] gondola_productos; 
        gondola_productos = nullptr; 
        capacidad_en_gondola = 0; 
        cantidad_en_gondola = 0; 
    }

    bool Gondola::estaLlena() const{
        if (cantidad_en_gondola == capacidad_en_gondola) {
            return true;
        } else {
            return false;
        }
    }

    void Gondola::aumentarCapacidad() {
        capacidad_en_gondola = capacidad_en_gondola * 2;
        Producto* nuevo_array = new Producto[capacidad_en_gondola];

        for (int i = 0; i < cantidad_en_gondola; i++) {
            nuevo_array[i] = gondola_productos[i];
        }

        delete[] gondola_productos;
        gondola_productos = nuevo_array;
    }

    void Gondola::disminuirCapacidad() {
        capacidad_en_gondola = capacidad_en_gondola / 2;
        Producto* nuevo_array = new Producto[capacidad_en_gondola];

        for (int i = 0; i < cantidad_en_gondola; i++) {
            nuevo_array[i] = gondola_productos[i];
        }

        delete[] gondola_productos;
        gondola_productos = nuevo_array;
    }

    void Gondola::leerProductos() {
        std::ifstream archivo;
        archivo.open("productos.txt", std::ios::in);

        if(!archivo.is_open()){
            std::cerr << "No se pudo abrir el archivo productos.txt" << std::endl;
            delete[] gondola_productos;
            exit(EXIT_FAILURE);
        } else if( archivo.peek() == std::ifstream::traits_type::eof() ) {
            std::cerr << "El archivo productos.txt esta vacio" << std::endl;
            delete[] gondola_productos;
            exit(EXIT_FAILURE);
        } else {
            std::string nombre;
            double precio;
            int oferta;
            int stock;
            while (archivo >> nombre >> precio >> oferta >> stock){
                if (estaLlena() == true) {
                    aumentarCapacidad();
                }
                gondola_productos[cantidad_en_gondola] = Producto(nombre, precio, oferta, stock, 0, 0);
                cantidad_en_gondola++;
            }
            archivo.close();
            }
    }

    void Gondola::mostrarProductos(){
        for (int i = 0; i < cantidad_en_gondola; i++) {
            std::cout << std::setw(3) << i + 1 << ": ";
            std::cout << std::setw(15) << std::left << gondola_productos[i].obtenerNombre();
            std::cout << std::setw(20) << std::left << gondola_productos[i].obtenerPrecio();
            std::cout << std::setw(15) << std::left << gondola_productos[i].obtenerStock();
            std::cout << std::setw(15) << std::left << (gondola_productos[i].obtenerOferta() ? "Si" : "No") << std::endl;
        }
    }

    int Gondola::buscarProducto(const std::string& nombre_producto) const {
        // Algoritmo de búsqueda lineal retorna el indice
        for (int i = 0; i < cantidad_en_gondola; i++) {
            if (gondola_productos[i].obtenerNombre() == nombre_producto) {
                return i;
            }
        }
        // Si el producto no se encuentra en la góndola y retorna -1
        return -1;
    }


    int Gondola::modificarStock(int posicion, int cantidad_a_comprar) {
        int stock = gondola_productos[posicion].obtenerStock();
        // Si no hay suficiente stock del producto retorna -1
        if (stock < cantidad_a_comprar) {
            std::cout << "Aviso: No hay suficiente stock del producto \"" << gondola_productos[posicion].obtenerNombre() << "\",solo hay "<< stock <<" en la góndola. Se continua la compra" << std::endl;
            return -1;
        // Si el stock es igual a la cantidad a comprar se elimina el producto de la góndola
        }else if (stock == cantidad_a_comprar) {
            eliminarProducto(posicion);
        // Si el stock es mayor a la cantidad a comprar se disminuye el stock
        }else {
            int nuevo_stock = stock - cantidad_a_comprar;
            gondola_productos[posicion] = Producto(gondola_productos[posicion].obtenerNombre(), gondola_productos[posicion].obtenerPrecio(), gondola_productos[posicion].obtenerOferta(), nuevo_stock, 0, 0);
        }    
        return 0;
    }

    double Gondola::buscarPrecio(int posicion) const {
        double precio = gondola_productos[posicion].obtenerPrecio();
        return precio;
    }   

    bool Gondola::buscarOferta(int posicion) const {
        bool oferta = gondola_productos[posicion].obtenerOferta();
        return oferta;
    }

    void Gondola::eliminarProducto(int posicion) {
        for (int i = posicion; i < cantidad_en_gondola - 1; i++) {
            gondola_productos[i] = gondola_productos[i+1];
        }
        cantidad_en_gondola--;
        if (cantidad_en_gondola < capacidad_en_gondola/2) {
            disminuirCapacidad();
        }
    }

    void Gondola::actualizarGondola(){
        std::ofstream archivo;
        archivo.open("productos.txt", std::ios::out);

        for (int i = 0; i < cantidad_en_gondola; i++) {
            archivo << gondola_productos[i].obtenerNombre() << ' ';
            archivo << gondola_productos[i].obtenerPrecio() << ' ';
            archivo << gondola_productos[i].obtenerOferta() << ' ';
            archivo << gondola_productos[i].obtenerStock() << std::endl;
        }
        archivo.close();
    }