#include <iostream>
#include <stdlib.h>
#include <locale>

using namespace std;

int main() {

    cout << "Contagem regreciva" << endl;
    for(int c = 10; c >= 0; c --){ //O for no C++ e em outras linguaguens precisa de uma variavel de referencia, uma condição e uma incrementação
        cout << "Contando: " << c << endl;
    }
    return 0;

}