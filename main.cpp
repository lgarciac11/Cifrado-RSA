//main.cpp
#include <iostream>
#include "rsa.h"
#include <ctime> //Para los núeros primos

using namespace std;

int main()
{
    srand(time(NULL)); //Creamos la semilla en el main
    RSA rsa;
    string MensajeOriginal;

    cout << "Bienvenido usuario! Estaremos utilizando el algoritmo RSA para cifrar y descifrar mensajes" << endl
         << "Introduzca a continuacion el mensaje que desea cifrar: ";
    getline(cin, MensajeOriginal);

    rsa.calcularClaves();
    vector<long long int> MensajeCifrado = rsa.cifrar(MensajeOriginal);
    string MensajeDescifrado = rsa.descifrar(MensajeCifrado);

    cout<< "Mensaje original: "<< MensajeOriginal<< endl;
    cout <<"Mensaje cifrado: ";
    for(auto elem: MensajeCifrado){
        cout<< elem<< " ";
    }
    cout<<endl;
    cout << "Mensaje descifrado: "<< MensajeDescifrado<<endl;

    return 0;
}
