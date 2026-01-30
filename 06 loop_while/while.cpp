#include <iostream>
#include <stdlib.h>
#include <locale>

using namespace std;

int main() {

    int num = 0;
    cout << "Contando de 0 a 100" << endl;
    while(num<=100){ //O while só precisa de uma condição para funcionar, enquanto for verdadeiro ele continua o loop
        cout << "]==> " << num << endl;
        num ++;
    }
    cout << "Terminamos de contar" << endl;
    // O while pode ser feito assim também
    int num2 = 0;
    cout << "Contando de 0 a 10" << endl;
    do{
        cout << "]---> " << num2 << endl;
        num2 ++;
    }while(num2 <= 10);
    cout << "Terminamos de contar" << endl;
    return 0;

}