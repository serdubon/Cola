
#include "stdafx.h"
#include <iostream>
using namespace std;


/*                Estructura de los nodos de la cola
------------------------------------------------------------------------*/
struct nodo
{
	int numero;
	struct nodo *siguiente;
};


/*                      Estructura de la cola
------------------------------------------------------------------------*/
struct cola
{
	nodo *delante;
	nodo *atras;
};


/*                        Encolar elemento
------------------------------------------------------------------------*/
void encolar(struct cola &NodoActual, int valor)
{
	struct nodo *auxiliar = new(struct nodo);

	auxiliar->numero = valor;
	auxiliar->siguiente = NULL;

	if (NodoActual.delante == NULL)
		NodoActual.delante = auxiliar;   // encola el primero elemento
	else
		(NodoActual.atras)->siguiente = auxiliar;

	NodoActual.atras = auxiliar;        // puntero NodoActualue siempre apunta al ultimo elemento

}

/*                        Desencolar elemento
------------------------------------------------------------------------*/
int desencolar(struct cola &NodoActual)
{
	int num;
	struct nodo *auxiliar;

	auxiliar = NodoActual.delante;      // auxiliar apunta al inicio de la cola
	num = auxiliar->numero;
	NodoActual.delante = (NodoActual.delante)->siguiente;
	delete(auxiliar);          // libera memoria a donde apuntaba auxiliar

	return num;
}

/*                        Mostrar Cola
------------------------------------------------------------------------*/
void mostrarCola(struct cola NodoActual)
{
	struct nodo *auxiliar;

	auxiliar = NodoActual.delante;

	while (auxiliar != NULL)
	{
		cout << "   " << auxiliar->numero;
		auxiliar = auxiliar->siguiente;
	}
}

/*              Eliminar todos los elementos de la Cola
------------------------------------------------------------------------*/
void vaciarCola(struct cola &NodoActual)
{
	struct nodo *auxiliar;

	while (NodoActual.delante != NULL)
	{
		auxiliar = NodoActual.delante;
		NodoActual.delante = auxiliar->siguiente;
		delete(auxiliar);
	}
	NodoActual.delante = NULL;
	NodoActual.atras = NULL;

}

/*                        Menu de opccionciones
------------------------------------------------------------------------*/
void menu()
{
	cout << "\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
	cout << " 1. ENCOLAR                               " << endl;
	cout << " 2. DESENCOLAR                            " << endl;
	cout << " 3. MOSTRAR COLA                          " << endl;
	cout << " 4. VACIAR COLA                           " << endl;
	cout << " 5. SALIR                                 " << endl;

	cout << "\n INGRESE opccionCION: ";
}

/*                        Funcion Principal
------------------------------------------------------------------------*/
int main()
{
	struct cola NodoActual;

	NodoActual.delante = NULL;
	NodoActual.atras = NULL;


	int dato;  // numero a encolar
	int opccion;    // opccioncion del menu
	int x;    // numero NodoActualue devuelve la funcon popccion

	system("color 0b");

	do
	{
		menu(); 
		cin >> opccion;

		switch (opccion)
		{
		case 1:

			cout << "\n NUMERO A ENCOLAR: "; cin >> dato;
			encolar(NodoActual, dato);
			cout << "\n\n\t\tNumero " << dato << " encolado...\n\n";
			break;


		case 2:

			x = desencolar(NodoActual);
			cout << "\n\n\t\tNumero " << x << " desencolado...\n\n";
			break;


		case 3:

			cout << "\n\n MOSTRANDO COLA\n\n";
			if (NodoActual.delante != NULL) mostrarCola(NodoActual);
			else   cout << "\n\n\tCola vacia...!" << endl;
			break;


		case 4:

			vaciarCola(NodoActual);
			cout << "\n\n\t\tHecho...\n\n";
			break;

		}

		cout << endl << endl;
		system("pause");  system("cls");

	} while (opccion != 5);


	return 0;
}
