#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "producto.h"
#include "gondola.h"
#include "chango.h"


int main() {
    Gondola gondola;
    Chango chango;

    std::cout << std::setw(60) << "/  Bienvenido al supermercado  /" << std::endl;
    std::cout << std::setw(50) << "/  Menu  /" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Ingrese el numero de la accion que quiera ejecutar" << std::endl;
    std::cout << "En caso de querer salir ingrese '0'" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << std::setw(2) << "1. Leer productos disponibles en la gondola" << std::endl;
    std::cout << std::setw(2) << "2. Leer productos del chango" << std::endl;
    std::cout << std::setw(2) << "3. Realizar la compra" << std::endl;
    std::cout << std::setw(2) << "0. Salir" << std::endl;

    gondola.leerProductos();
    chango.leerChango(); 

    int opcion_elegida;
    std::cin >> opcion_elegida;

    if (std::cin.fail()) { 
        std::cin.clear(); 
        opcion_elegida = 5; // Se asigna un valor invalido para que el programa no continue
    }

    switch (opcion_elegida) {
        case 1:
            std::cout << "----------------------------------- Estos son los productos disponibles ---------------------------------" << std::endl;
            std::cout << std::setw(3) << "|";
            std::cout << std::setw(15) << std::left << "Producto";
            std::cout << std::setw(20) << std::left << "| Precio_Unitario";
            std::cout << std::setw(15) << std::left << "| Stock";
            std::cout << std::setw(15) << std::left << "| Oferta (S/N)" << "|" << std::endl;
            gondola.mostrarProductos();
            std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
            break;
        case 2:
            std::cout << "----------------------------------- Estos son los productos del chango ---------------------------------" << std::endl;
            std::cout << std::setw(3) << "|";
            std::cout << std::setw(15) << std::left << "Producto";
            std::cout << std::setw(15) << std::left << "| Cantidad" << "|" << std::endl;
            chango.mostrarChango();
            std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
            break;
        case 3:
            std::cout << std::setw(57) << "-  Realizando la compra  -" << std::endl;    
            chango.realizarCompra(gondola);
            std::cout << std::setw(62) << "- La compra se finalizo con exito  -" << std::endl;

            std::cout << std::setw(50) << "/  Menu  /" << std::endl;
            std::cout << "-----------------------------------------------" << std::endl;
            std::cout << "Ingrese el numero de la accion que quiera ejecutar" << std::endl;
            std::cout << "En caso de querer salir ingrese '0'" << std::endl;
            std::cout << "-----------------------------------------------" << std::endl;
            std::cout << std::setw(2) << "1. Mostrar resumen de la compra y guardar los cambios" << std::endl;
            std::cout << std::setw(2) << "2. Salir y guardar los cambios" << std::endl;
            std::cout << std::setw(2) << "0. Salir sin guardar los cambios" << std::endl;
            int opcion_elegida_2;
            std::cin >> opcion_elegida_2;
        
            switch (opcion_elegida_2) {
                case 1:
                    chango.mostrarChangoFinal();
                    gondola.actualizarGondola();
                    std::cout << std::setw(62) << "-Los cambios se guardaron correctamente -" << std::endl;
                    break;
                case 2:
                    gondola.actualizarGondola();
                    std::cout << std::setw(62) << "-Los cambios se guardaron correctamente -" << std::endl;
                    break;
                case 0:
                    std::cout << std::setw(62) << "- Saliendo sin guardar los cambios -" << std::endl;
                    break;
                default:
                    std::cout << "Opcion invalida" << std::endl;
                    break;
            }
            break;
        case 0: 
            std::cout << std::setw(62) << "- Saliendo sin guardar los cambios -" << std::endl;
            break;
        default:
            std::cout << "Opcion invalida, vuelva a intentarlo" << std::endl;
            break;
    }
    return 0;
}