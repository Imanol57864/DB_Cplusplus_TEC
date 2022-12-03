#include <iostream>

class PYME{
    private:
        string director;
        int numWorkers;
        float yearIncome;

    public:
        // Importanes para el trabajador
        string name_PYME;
        string socialReason_PYME;
        string address_PYME;
        construir_pyme(); // [!!!] SI TIENEN EL MISMO NOMBRE, SE AUTOCONSTRUIRAN.
        imprimir_pyme();

};

// PYME Setup
PYME::construir_pyme(){
    std::cout << "\n||   Introduzca el nombre de esta PYME: ";
    std::cin >> name_PYME; 

    std::cout << "\n||   Introduzca la razon social de esta PYME: ";
    std::cin >> socialReason_PYME; 

    std::cout << "\n||   Introduzca la direccion de esta PYME: ";
    std::cin >> address_PYME; 

    std::cout << "\n||   Introduzca el nombre del director de esta PYME: ";
    std::cin >> director; 

    std::cout << "\n||   Introduzca el numero de trabajadores que tiene esta PYME: ";
    std::cin >> numWorkers; 

    std::cout << "\n||   Introduzca el ingreso anual de esta PYME: ";
    std::cin >> yearIncome;    

    cout << "\n||   PYME anadida con exito! Presiona una tecla para continuar.";
}

PYME::imprimir_pyme(){
    cout << "\n||   Nombre de la PYME: " << name_PYME; 
    cout << "\n||";
    cout << "\n||   Razon social: " << socialReason_PYME;
    cout << "\n||";
    cout << "\n||   Direccion: " << address_PYME; 
    cout << "\n||";
    cout << "\n||   Director: " << director; 
    cout << "\n||";
    cout << "\n||   Numero de trabajadores: " << numWorkers; 
    cout << "\n||";
    cout << "\n||   Ingreso anual: " << yearIncome;    
}