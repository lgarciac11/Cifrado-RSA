#ifndef RSA_H
#define RSA_H
#include <string>
#include <vector>

using namespace std;
//cambiar todo a long long int?
class RSA
{
private:
    long int prim1;//(p)
    long int prim2;//(q)
    long int mult; //de prim1 y prim2 (n)
    long int Euler; //(phi)
    long int c_pub; //exponente clave pública
    long int c_priv; //exponente clave privada

    long long int encriptar_valor(double message);  // encriptar valor simple
    long long int desencriptar_valor(long long int encrpyted_text); // desencriptar valor simple
public:
    RSA();
    long int mcd(long int n1,long int n2); //Calculamos el máximo común múltiplo
    bool isPrime(long int n); //Calcular número primo
    void calcularClaves(); //Cálculos claves
    vector<long long int> cifrar(const string& t); //Cifrar mensaje
    string descifrar(const vector<long long int>& e); //Descifrar mensaje
};

#endif // RSA_H
