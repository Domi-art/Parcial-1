
/*Encontrar el mensaje cifrado, se tiene 2 vectores:
* vector char mensajeCifrado: contiene todas las letras del abecedario, minusculas como mayusculas
* vector int decodifcador: en la cual contiene las posiciones claves de las letras del mensaje a 
* decodificar, tienen un tamano de 19 numeros enteros
* se requiere por medio de apuntadores recorrer en el mensajeCifrado segun el numero del decodificador
* e imprimir el mensaje cifrado, preferible que lo haga con funciones.
* Valor 3 puntos, si utiliza funciones y da con el mensaje cifrado
* Valor 2 puntos, si no utiliza funciones y da con el mensaje
* Valor 0, si no da con el mensaje aunque use funciones
*/
#include<iostream>
#include<conio.h>
using namespace std;


void revelarmensaje(char* ptrmensaje, int* ptrdecodificador, int tamano){
    int posicion = 0;

    cout<<"el mensaje secreto e: ";

    for(int i = 0; i < tamano; i++){
        posicion += *(ptrdecodificador + i);
        cout<<*(ptrmensaje + posicion);
    }
    
    cout<<endl;
}

int main() {

    char mensajecifrado[] = {
        ' ','A','E','I','O','U','a','e','i','o','u',
        'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z',
        'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'
    };
    
    int decodificador[] = { 2,17,-19,2,48,-44,35,-34,35,-42,2,44,1,-41,-6,2,4,40,5};
    
   
    int tamanodecodificador=sizeof(decodificador)/sizeof(decodificador[0]);

    revelarmensaje(mensajecifrado, decodificador, tamanodecodificador);

	return 0;
}
