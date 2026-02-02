#include <iostream>
#include <stdlib.h>
#include <locale>
#include <cmath>

using namespace std;

int main(){

    double peso;
    double altura;
    cout << "A sua altura em metros: ";
    cin >> altura;
    cout << "O seu peso em Kg: ";
    cin >> peso;
    double rnum = peso/(pow(altura,2));
    //Operador ternario [variavel] = ([condição]) ? [se a condição for verdadeira sera esse valor] : [se não sera esse valor]
    string result = (rnum > 18.5 && rnum < 24.9) ? "O seu peso está dentro do ideal!" : "O Seu peso está alterado";
    cout << endl << result << endl << endl;
    return 0;

}