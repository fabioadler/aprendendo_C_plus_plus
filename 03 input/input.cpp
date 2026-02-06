#include <iostream>
#include <stdlib.h>
#include <locale>
#include <string>

using namespace std;

int main() {

    locale::global(locale(""));
    string idade;
    string nome;
    cout << "Digite a sua idade: ";
    getline(cin,idade); //O getline(cin,[variavel]) cerve para pegar todo conteudo da linha, por que o cin só pega até o primeiro espaço
    cout << "Digite o seu nome: ";
    getline(cin,nome);
    cout << "Seu nome e " << nome << " e você tem " << idade << " anos" << endl;
    return 0;

}