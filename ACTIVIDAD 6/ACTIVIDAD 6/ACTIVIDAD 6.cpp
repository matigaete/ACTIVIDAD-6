#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
struct nodo 
{
	string PREGUNTA;
	nodo *SI;
	nodo *NO;
};
int main() 
{
	int cont = 2;
	string resp, preg, animal, aux;
	nodo *RAIZ, *PUNT1, *PUNT2, *punt, *puntero, *pregunta;
	RAIZ = new(nodo);
	RAIZ->PREGUNTA = "¿VIVE EN EL AGUA?";
	RAIZ->SI = NULL;
	RAIZ->NO = NULL;
	PUNT1 = new(nodo);
	PUNT1->PREGUNTA = "RANA";
	PUNT1->SI = NULL;
	PUNT1->NO = NULL;
	PUNT2 = new(nodo);
	PUNT2->PREGUNTA = "RATON";
	PUNT2->SI = NULL;
	PUNT2->NO = NULL;
	RAIZ->SI = PUNT1;
	RAIZ->NO = PUNT2;
	while (resp != "salir")
	{
		punt = RAIZ;
		cout << "Piense en un animal y yo trataré de adivinarlo." << endl;
		cout << "El animal que Ud. pensó, " << endl;
		while (punt->SI != NULL)
		{
			cout << punt->PREGUNTA << endl;
			cin >> resp;
			if (resp == "si")
			{
				punt = punt->SI;
			}
			else
			{
				punt = punt->NO;
			}
		}
		cout << "¿Es un(a) " << punt->PREGUNTA << "?" << endl;
		animal = punt->PREGUNTA;
		cin >> resp;
		if (resp == "no")
		{
			pregunta = new(nodo);
			pregunta->PREGUNTA = "";
			pregunta->SI = NULL;
			pregunta->NO = NULL;
			puntero = new(nodo);
			puntero->PREGUNTA = "";
			puntero->SI = NULL;
			puntero->NO = NULL;
			cout << "Lo felicito, Ud. ganó, pero debe decirme cuál era el animal." << endl;
			cin >> puntero->PREGUNTA;
			cout << "Ahora, debe decirme una pregunta que diferencie Un(a) " << puntero->PREGUNTA << " de un(a) " << animal << endl;
			cin >> pregunta->PREGUNTA;
			cout << "¿Cuál sería la respuesta correcta a esa pregunta para Un(a) " << puntero->PREGUNTA << "?" << endl;
			cin >> resp;
			if (resp == "no")
			{
				punt->NO = puntero;
				punt->SI = pregunta;
				aux = punt->PREGUNTA;
				punt->PREGUNTA = pregunta->PREGUNTA;
				pregunta->PREGUNTA = aux;
			}
			else
			{
				punt->NO = pregunta;
				punt->SI = puntero;
				aux = punt->PREGUNTA;
				punt->PREGUNTA = pregunta->PREGUNTA;
				pregunta->PREGUNTA = aux;
			}
			cont++;
			cout << "Gracias, ahora conozco a " << cont << " animales." << endl;
			cin >> resp;
		}
		else
		{
			cout << "Usted ganó" << endl;
		}
	}
}