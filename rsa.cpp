#include "rsa.h"
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

RSA::RSA(){
    prim1 =0;
    prim2= 0;
    mult = 0;
    Euler= 0;
    c_pub = 0;
    c_priv = 0;
}
//Para calcular el maximo comúm divisor (Necesario para  calcular las claves)
long int RSA:: mcd(long int n1,long  int n2){
    long int min;
    if(n1<n2) min = n1;
    else min = n2;
    while(n2%min !=0 || n1%min != 0) min--;
    return min;
}

bool RSA::isPrime(long int n){
    if(n <2) return false;
    for(int i{2}; i<=n/2; i++){
        if(n % i== 0){
            return false;
        }
    }
    return true;
}

//Cálculo de las claves y demás variables
void RSA:: calcularClaves(){
    //Comenzamos dándole valor a los números primos
    while(!isPrime(prim1) || !isPrime(prim2) || prim1 == prim2){
        prim1 = 1000 + rand() %(5001-1000);
        prim2 = 1000 + rand() %(5001-1000);
    }
    mult = prim1*prim2; //Calculamos n.
    //Ya teniendo n, podemos calcular los valores de las claves
    //Calculamos phi:
    Euler = (prim1 - 1)*(prim2 - 1); //p
    // c_pub será un num entre 1 y euler y que además sea coprimo de este
    // Porque tiene que ser mayor que 1
    for(c_pub =2; c_pub<Euler; c_pub++){
        if(mcd(c_pub,Euler) == 1) break;
    }

    //Una vez tenemos el valor del exponente la clave pública, calculamos el exponente de la clave privada
    for(c_priv =2; c_priv<Euler; c_priv++){
        if((c_pub * c_priv )% Euler == 1) break;
    }
    //ya tenemos c_pub y c_priv
}

long long int RSA::encriptar_valor(double message)
{
    int e = c_pub;
    long long int encrpyted_text = 1;
    //encrpyted_text = static_cast<long long int>(pow(message,c_pub))%mult;
    while (e--) {
        encrpyted_text *= message;
        encrpyted_text %= mult;
    }
    return encrpyted_text;
}

long long int RSA::desencriptar_valor(long long int encrpyted_text)
{
    int d = c_priv;
    long long int decrypted = 1;
    //decrypted = static_cast<long long int>(pow(encrpyted_text,c_priv))%mult;
    //Protección contra desbordamientos
    while (d--) {
        decrypted *= encrpyted_text;
        decrypted %= mult;
    }
    return decrypted;
}

//Recibimos un mensaje de texto y devolvemos un vector con todos los valores que han sido cifrados en encritpar_valor
vector<long long int> RSA::cifrar(const string& t){
    vector<long long int> data;
    //Llamada a la función de encriptar_valor
    for (auto& m : t)
        data.push_back(encriptar_valor((int)m));
    return data;
}

//Recibimos un vector con la cadena encriptada y devolvemos el mensaje original
string RSA::descifrar(const vector<long long int>& e){
    string s;
    ///Llamada a la función de encriptar_valor
    for (auto& v : e) {
        long long int valor = desencriptar_valor(v);
        s += valor;
    }
    return s;
}



