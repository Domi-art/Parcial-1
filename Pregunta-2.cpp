/* Cifrar y Descifrar mensajes, segun el desplazamiento de letras
* vector char codificacionDecodificacion: contiene todas las letras del abecedario, minusculas 
* como mayusculas
* metodo cifrarMensaje que debe, segun el desplazamiento, cifrar el mensaje
* metodo descifrarMensaje que debe, segun el desplazamiento, descifrar el mensaje
* Todo debe realizarse por punteros
* Debe imprimir el mensaje cifrado y el mensaje descifrado (Que debe ser igual mensaje original)
* EL MENSAJE NO DEBE TENER ESPACIOS EN BLANCO, cuando se le solicite el mensaje
* Ejemplo: digita "HolaComoEstas" cuando se cifre el mensaje debe imprimir algo como esto
* "LCpoGCqCUwxow", y cuando descifre el mensaje de imprimir igual al mensaje original, es decir
* "HolaComoEstas"
* Valor 2 puntos, si realiza de forma correcta los dos metodos
* Valor 1, si solo funciona un solo metodo
* Valor 0, sino funciona ninguno de los dos
*/

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

char codificacionDecodificacion[] = {
    ' ','A','E','I','O','U','a','e','i','o','u',
    'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z',
    'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'
};

int tamanoAlfabeto = sizeof(codificacionDecodificacion) / sizeof(char);

void cifrarMensaje(char* m, int desplazamiento, char* code) {
    char* pmensaje = m;
    while (*pmensaje != '\0') {
        char* pcode = code;
        for (int i = 0; i < tamanoAlfabeto; i++) {
            if (*pmensaje == *(pcode + i)) {
                int nuevapos = (i + desplazamiento) % tamanoAlfabeto;
                *pmensaje = *(pcode + nuevapos);
                break;
            }
        }
        pmensaje++;
    }
}

void descifrarMensaje(char* m, int desplazamiento, char* code) {
    char* pmensaje = m;
    while (*pmensaje != '\0') {
        char* pcode = code;
        for (int i = 0; i < tamanoAlfabeto; i++) {
            if (*pmensaje == *(pcode + i)) {
                int nuevapos = (i - desplazamiento) % tamanoAlfabeto;
                if (nuevapos < 0) nuevapos += tamanoAlfabeto;
                *pmensaje = *(pcode + nuevapos);
                break;
            }
        }
        pmensaje++;
    }
}

int main() {
    char mensaje[100];
    char mensajeDescifrar[100];
    int des = 0;

    cout << "--- MODO CIFRADO ---" << endl;
    cout << "Digite mensaje a cifrar: ";
    cin >> mensaje;
    cout << "Digite desplazamiento: ";
    cin >> des;

    cifrarMensaje(mensaje, des, codificacionDecodificacion);
    cout << "Resultado cifrado: " << mensaje << endl;

    cout << "\n----------------------------\n" << endl;

    cout << "--- MODO DESCIFRADO ---" << endl;
    cout << "Digite el mensaje que desea descifrar: ";
    cin >> mensajeDescifrar;
    cout << "Digite el desplazamiento original: ";
    cin >> des;

    descifrarMensaje(mensaje, des, codificacionDecodificacion);
    cout << "Resultado descifrado: " << mensaje << endl;

    return 0;
}
