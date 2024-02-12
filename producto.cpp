#include "producto.h"
#include <string>

    Producto::Producto(std::string _nombre, double _precio, bool _oferta, int _stock, int _cantidad_a_comprar, double _cantidad_a_pagar_por_producto){
        nombre = _nombre;
        precio = _precio;
        oferta = _oferta;
        stock = _stock;
        cantidad_a_comprar = _cantidad_a_comprar;
        cantidad_a_pagar_por_producto = _cantidad_a_pagar_por_producto;
    }

    // Constructor por defecto
    Producto::Producto() {
        nombre = "";
        precio = 0.0;
        oferta = false;
        stock = 0;
        cantidad_a_comprar = 0;
        cantidad_a_pagar_por_producto = 0;
    }

    std::string Producto::obtenerNombre() const {return nombre;}
    double Producto::obtenerPrecio() const {return precio;}
    bool Producto::obtenerOferta() const {return oferta;}
    int Producto::obtenerStock() const {return stock;}
    int Producto::obtenerCantidadAComprar() const {return cantidad_a_comprar;}
    double Producto::obtenerCantidadAPagarPorProducto() const {return cantidad_a_pagar_por_producto;}

    
