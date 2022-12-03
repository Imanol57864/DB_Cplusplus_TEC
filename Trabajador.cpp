#include <iostream>

//Trabajador a heredado todo lo publico de la clase PYME
class Trabajador : public PYME { 
    private:
        int edad;
        string puesto;
        float sueldo;
    public:
        string name_Trabajador;
        construir_worker();
        imprimir_worker();
}; 

// Trabajador Setup
Trabajador::construir_worker(){
    std::cout << "\n||   Introduzca el nombre de este Trabajador: ";
    std::cin >> name_Trabajador; 

    std::cout << "\n||   Introduzca la edad de este Trabajador: ";
    std::cin >> edad; 

    std::cout << "\n||   Introduzca el nombre del puesto de este Trabajador: ";
    std::cin >> puesto; 

    std::cout << "\n||   Introduzca la cantidad del sueldo de este Trabajador: ";
    std::cin >> sueldo; 

    search_break = 0;
    while (search_break == 0) {
        gotoxy(0,17); cout << "||                                                                            ||";
        gotoxy(0,17); std::cout << "||   Introduzca el nombre de la PYME asociada con el trabajador: ";
        std::cin >> search;
        int i = CONSULTARPYME();
        if (i >= 0){
            name_PYME = pyme_arr[i].name_PYME;
            socialReason_PYME = pyme_arr[i].socialReason_PYME;
            address_PYME = pyme_arr[i].address_PYME;
            search_break = 1;
        }
        else {
            gotoxy(0,19);cout << "||   Pyme no encontrada en los registros. Presione una tecla para continuar.";
        }
    }
    gotoxy(0,19); cout << "||                                                                            ||";
    gotoxy(0,19); cout << "||   Trabajador anadido con exito! Presiona una tecla para continuar.";
}

Trabajador::imprimir_worker(){
    cout << "\n||   Nombre del Trabajador: " << name_Trabajador; 
    cout << "\n||";
    cout << "\n||   Edad: " << edad; 
    cout << "\n||";
    cout << "\n||   Puesto: " << puesto; 
    cout << "\n||";
    cout << "\n||   Sueldo: " << sueldo; 
    cout << "\n||";
    cout << "\n||   Nombre de la empresa donde trabaja: " << name_PYME;
    cout << "\n||";
    cout << "\n||   Razon social de la empresa donde trabaja: " << socialReason_PYME;
    cout << "\n||";
    cout << "\n||   Direccion de la empresa donde trabaja: " << address_PYME;
}

