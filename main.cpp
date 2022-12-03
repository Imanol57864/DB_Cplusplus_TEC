#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#define N 50
#define P 3 // No. Pymes Maximas de la base de datos
#define W 3 // No. Workers Maximos de la base de datos
using namespace std;

// Alfonso Imanol Macias Marañon

// Prototype Setup
void dibujarCuadro(int x1,int y1,int x2,int y2);
void gotoxy(int x,int y);
void limpia();
void menu();
int CONSULTARPYME();

// Object Setup
string search;
int search_break;
#include "PYME.cpp"
PYME pyme_arr[P];
#include "Trabajador.cpp"
Trabajador trabajador_arr[W];
int contador_PYME = -1;
int contador_workers = -1;

// Main Setup
int main(){
	system("mode con: cols=80 lines=25"); //Ajusta la pantalla a nuestro programa
	dibujarCuadro(0,0,78,24);
	dibujarCuadro(1,1,77,3);
	gotoxy(16,2); cout << "           B A S E  D E  D A T O S";
	menu();
	getch();
	return 0;
}

// Process SETUP
void menu(){
	char op;
	do{
		limpia();
		gotoxy(3,6); cout << "  MENU PRINCIPAL";
		gotoxy(3,9); cout << "  (1) Agregar una PYME";
		gotoxy(3,11); cout << "  (2) Agregar un Trabajador";
		gotoxy(3,13); cout << "  (3) Consultar PYME";
		gotoxy(3,15); cout << "  (4) Consultar Trabajador";
		gotoxy(3,17); cout << "  (5) Cerrar";
		gotoxy(3,19); cout << "  Ingrese opcion: ";
		cin >> op;
		
		if(op!='1' && op!='2' && op!='3' && op!='4' && op!='5'){
			gotoxy(3,21); cout << "  Error al ingresar valores. Presione una tecla para volver a ingresar.";
			getch();
			gotoxy(3,22); cout << "                                                                       ";
			gotoxy(3,17); cout << "                                                                       ";
		}
			
	}while(op!='1' && op!='2' && op!='3' && op!='4' && op!='5');
	
	
	if (op=='1'){
		limpia(); 
		gotoxy(3,6);
		if (contador_PYME < P-1){
			contador_PYME += 1;
			pyme_arr[contador_PYME].construir_pyme();

		}
		else {
			cout << "  Se ha superado la cantidad maxima de PYMEs para guardar.";
			gotoxy(3,8); cout << "  Presiona una tecla para continuar.";
		}
		getch();
		menu();
	}
	

	if (op=='2'){
		limpia();
		gotoxy(3,6);
		if (contador_PYME >= 0 && contador_workers < W-1){
	    contador_workers += 1;
 		trabajador_arr[contador_workers].construir_worker();
		}
		else if (contador_PYME <= 0){
			cout << "  No se pueden anadir trabajadores aun. Crea una PYME para empezar.";
			gotoxy(3,8); cout << "  Presiona una tecla para continuar.";
		}
		else if (contador_workers >= W-1){
			cout << "  Se ha superado la cantidad maxima de trabajadores para guardar.";
			gotoxy(3,8); cout << "  Presiona una tecla para continuar.";
		}
		else {
			cout << "\n||  No ha sucedido nada. Como llegaste aquí?";
		}
		getch();  
		menu(); 
	}
	
	if (op=='3'){
		limpia();
		gotoxy(3,6); std::cout << "\n||   Introduzca el nombre de la PYME que desea consultar: ";
		std::cin >> search;
		int i = CONSULTARPYME();
		if (i >= 0){
			limpia();
			gotoxy(3,6);
			pyme_arr[i].imprimir_pyme();
			cout << "\n||";
			cout << "\n||   Presiona una tecla para continuar.";
			getch(); 
		}
		else {
			limpia();
			gotoxy(3,6); 
			cout << "\n||   Pyme no encontrada en los registros.";
			cout << "\n||";
			cout << "\n||   Presiona una tecla para continuar.";
			getch();  
		}
		menu();
	}

	if (op=='4'){
		search_break = 0;
		limpia();
		gotoxy(3,6); std::cout << "\n||   Introduzca el nombre del trabajador que desea consultar: ";
    	std::cin >> search;
    	for (int i = 0; i < P; i++) {
			if (trabajador_arr[i].name_Trabajador == search){
				search_break = 1;
				limpia();
				gotoxy(3,6);
				trabajador_arr[i].imprimir_worker();
				cout << "\n||";
				cout << "\n||   Presiona una tecla para continuar.";
				getch();  
			}
    	}
		if (search_break == 0){
				limpia();
				gotoxy(3,6); cout << "\n||   Trabajador no encontrado en los registros.";
				cout << "\n||";
				cout << "\n||   Presiona una tecla para continuar.";
				getch();  
		}
		menu(); 
	}
	
	if (op=='5')
		exit(0);
	
}

//Funcion Extra 1
int CONSULTARPYME(){
	int i;
    for (i = 0; i < P; i++) {
		if (pyme_arr[i].name_PYME == search){
			return i;
		}
    }
	return -1;
}

//GUI Setup
void limpia(){
	int i,j;
	for(i=5;i<=23;i++){
		for(j=3;j<=76;j++){
			gotoxy(j,i); printf(" ");}}
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}
void dibujarCuadro(int x1,int y1,int x2,int y2){
    int i;
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "-";
		gotoxy(i,y2); cout << "-";
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout << "||";
		gotoxy(x2,i); cout << "||";
    }
    
    gotoxy(x1,y1); cout << "||";
    gotoxy(x1,y2); cout << "||";
    gotoxy(x2,y1); cout << "||";
    gotoxy(x2,y2); cout << "||";
}