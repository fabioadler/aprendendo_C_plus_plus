#include <iostream>
#include <stdlib.h>
#include <locale>
#include <cmath> //biblioteca para poder realizar algums calculos como a elevalçao e o resto da divisão (em outra linguaguem seria num1 ** num2 e num1 % num2)

using namespace std;

int main() {

    locale::global(locale(""));
    double num1,num2,soma,sub,multi,divi,resto,elev,raiz;
    cout << "Seja bem vindo aos nossos resultados de calculo!" << endl;
    cout << "Digite o primeiro numero: ";
    cin >> num1;
    cout << "Digite o segundo numero:";
    cin >> num2;
    cout << "Os resultados são os seguintes:" << endl;
    soma = num1 + num2;
    sub = num1 - num2;
    multi = num1 * num2;
    divi = num1 / num2;
    resto = fmod(num1,num2);
    elev = pow(num1,num2);
    raiz = pow(num1,1.0/num2);
    cout << "A soma e: " << soma << endl;
    cout << "A subtração e: " << sub << endl;
    cout << "A multiplicação e: " << multi << endl;
    cout << "A divisão e: " << divi << endl;
    cout << "O resto da divisão e: " << resto << endl;
    cout << "A elevação e: " << elev << endl;
    cout << "A Raiz e: " << raiz << endl << endl;
    cout << "Obrigado por usar o nosso sistema!" << endl;
    return 0;

}