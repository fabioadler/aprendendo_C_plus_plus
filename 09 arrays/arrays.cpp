#include <iostream>
#include <stdlib.h>
#include <locale>
#include <string>

using namespace std;

int main(){

    int lista[] = {1,4,6,2,3,10}; // Lista default <tipo da lista> <nome da variavel>[] = {<itens da lista>}
    string lista2[] = {"teste","marcha","clone"};
    int lista3[4]; // Variavel em que colocamos os valores depois <tipo lista> <nome da variavel>[<quantos itens vão ter na lista>]
    lista3[0] = 1; // Adicionamos o primeiro valor na lista, lembrando que todas as posições de uma lista começam contando do 0, ou seja a primeira posição e 0, a segunda e 1, a terceira 2 e etc...
    lista3[1] = 10;
    lista3[2] = 100;
    lista3[3] = 1000;

    cout << "Printando um item de cada lista" << endl << "--> " << lista[0] << endl << "--> " << lista2[2] << endl << "--> " << lista3[1] << endl;
    cout << "Printando a primeira lista" << endl;
    for(int n: lista){
        cout << "]===> " << n << endl;
    }
    cout << "Printando a segunda lista" << endl;
    for(string v: lista2){
        cout << "]---> " << v << endl;
    }
    cout << "Printando uma terceira lista" << endl;
    cout << "[";
    for (int n: lista3){
        cout << n << ", ";
    }
    cout << "]" << endl;
    return 0;

}