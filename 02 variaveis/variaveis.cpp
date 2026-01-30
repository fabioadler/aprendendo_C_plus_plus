#include <iostream>
#include <stdlib.h>
#include <locale> //lib para corrigir problemas com acentuação

using namespace std;

int main() {

    // Configurar locale para caracteres acentuados
    locale::global(locale(""));
    //definindo variaveis
    const char* nome = "Fábio Adler";
    int idade = 25;
    double peso = 125.500;
    cout << "Meu nome e " << nome << " eu tenho " << idade << " anos e peso " << peso << "Kg" << endl;
    return 0;

}