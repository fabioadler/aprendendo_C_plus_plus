#include <iostream>
#include <stdlib.h>
#include <locale>

using namespace std;

int main() {

    cout << "Contagem regreciva" << endl;
    for(int c = 10; c >= 0; c -= 1){
        cout << "Contando: " << c << endl;
    }
    return 0;

}