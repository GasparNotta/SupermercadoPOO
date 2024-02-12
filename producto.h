#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

/*
Precondiciones:
.Nombre no nulo: El nombre del producto (_nombre) proporcionado al constructor no debe ser una cadena nula o vacía.
.Precio válido: El precio del producto (_precio) proporcionado al constructor debe ser un valor numérico válido y no negativo.
.Stock no negativo: El stock del producto (_stock) proporcionado al constructor debe ser un número entero no negativo.
.Cantidad a comprar no negativa: La cantidad a comprar (_cantidad_a_comprar) proporcionada al constructor debe ser un número entero no negativo.
.Cantidad a pagar por producto positiva: La cantidad a pagar por producto (_cantidad_a_pagar_por_producto) proporcionada al constructor debe ser un valor numérico válido y no negativo.
.Relación entre stock y cantidad a comprar: La cantidad a comprar (_cantidad_a_comprar) no puede ser mayor que el stock disponible (_stock) del producto.
.Precio positivo para producto en oferta: Si el producto está en oferta (_oferta es verdadero), su precio (_precio) debe ser menor que el precio regular.
Postcondiciones:
.Objeto inicializado: Después de llamar al constructor Producto, se crea un objeto Producto correctamente inicializado con los valores proporcionados.
.Métodos de obtención correctos: Los métodos obtenerNombre(), obtenerPrecio(), obtenerOferta(), obtenerStock(), obtenerCantidadAComprar() y obtenerCantidadAPagarPorProducto() devuelven los valores correspondientes del objeto Producto creado.
.Actualización de atributos: Los métodos de obtención devuelven los valores actualizados de los atributos después de cualquier modificación realizada en ellos.
.Consistencia en estado de oferta: El estado de oferta (_oferta) del producto permanece consistente y no se altera después de la creación del objeto.
*/

class Producto{
    private:
        std::string nombre;
        double precio;
        bool oferta;
        int stock;
        // Atrinutos para productos del chango
        int cantidad_a_comprar;
        double cantidad_a_pagar_por_producto;

    public:
        Producto(std::string _nombre, double _precio, bool _oferta, int _stock, int _cantidad_a_comprar, double _cantidad_a_pagar_por_producto);
        Producto();
        
        std::string obtenerNombre() const;
        double obtenerPrecio() const;
        bool obtenerOferta() const;
        int obtenerStock() const;
        int obtenerCantidadAComprar() const;
        double obtenerCantidadAPagarPorProducto() const;
        
};




#endif // PRODUCTO_H