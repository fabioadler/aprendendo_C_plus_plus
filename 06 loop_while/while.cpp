#include <iostream>
#include <stdlib.h>
#include <locale>

using namespace std;

int main() {

    int num = 0;
    cout << "Contando de 0 a 100" << endl;
    while(num<=100){
        cout << "]==> " << num << endl;
        num ++;
    }
    cout << "Terminamos de contar" << endl;
    return 0;

}