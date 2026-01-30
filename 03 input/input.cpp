#include <iostream>
#include <stdlib.h>
#include <locale>
#include <string>

using namespace std;

int main() {

    locale::global(locale(""));
    cout << "Digit o seu nome: ";
    char* nome = new char[100];
    cin >> nome;
    cout << "Seu nome e " << nome << endl;
    return 0;

}