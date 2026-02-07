#include <iostream>
#include <stdlib.h>
#include <locale>
#include <string>
#include <variant> //lib para poder colocar valores diversos na lista
#include <vector> // lib para criar a lista com valores diferentes
#include <algorithm> //lib para usar algumas funções que usei para criar a função de remover itens da lista

using namespace std;
using var_l = variant<int,string>;

vector<var_l> remover_item(vector<var_l> lista, var_l item_r){ // Função que eu criei para remover itens das listas especialmente da lista4
    auto item = find_if(lista.begin(),lista.end(),[item_r](const var_l& v) { //Verifica se esse item existe dentro da lista e depois chama uma função lambda
        if (holds_alternative<int>(item_r) && holds_alternative<int>(v)) { //Esse if dentro do lambda, verifica se o item e um int
            return get<int>(v) == get<int>(item_r);// Caso seja inteiro, vai retornar o valor inteiro do item
        } else if (holds_alternative<string>(item_r) && holds_alternative<string>(v)) {// verficia se e string
            return get<string>(v) == get<string>(item_r);
        }
        return false;// caso o formato serja falso retorna um false
    });
    if(item != lista.end()){//verifica se o item está na lista
        lista.erase(item);//se tiver na lista remover
    }
    else {
        cout << "O item não foi encontrado" << endl;
    }
    return lista;//retorna uma lista nova no formato vetor<var_l>;
};

int main(){

    int lista[] = {1,4,6,2,3,10}; // Lista default <tipo da lista> <nome da variavel>[] = {<itens da lista>}
    string lista2[] = {"teste","marcha","clone"};
    int lista3[4]; // Variavel em que colocamos os valores depois <tipo lista> <nome da variavel>[<quantos itens vão ter na lista>]
    lista3[0] = 1; // Adicionamos o primeiro valor na lista, lembrando que todas as posições de uma lista começam contando do 0, ou seja a primeira posição e 0, a segunda e 1, a terceira 2 e etc...
    lista3[1] = 10;
    lista3[2] = 100;
    lista3[3] = 1000;
    vector<var_l> lista4 = {1,"Hello",2,"ola"}; // lista com tipos de valores diferentes
    
    cout << "Printando um item de cada lista" << endl << "--> " << lista[0] << endl << "--> " << lista2[2] << endl << "--> " << lista3[1] << endl;
    cout << "Printando a primeira lista" << endl;
    for(int n: lista){
        cout << "]===> " << n << endl;
    }
    cout << "Printando a segunda lista" << endl;
    for(string v: lista2){
        cout << "]---> " << v << endl;
    }
    cout << "Printando a terceira lista" << endl;
    for(int v: lista3){
        cout << "]---> " << v << endl;
    }
    cout << "Printando uma quarta lista de forma semelhante ao python" << endl;
    cout << "[";
    for (auto item: lista4){ //Aqui no auto, usamos ele para atribuir um tipo de variavel automaticamente
        if(holds_alternative<int>(item)){//Aqui verificamos o se o tipo da variavel e int
            cout << get<int>(item) << ", ";// Aqui pegamos a variavel como int usando a funsão get
        }
        else if(holds_alternative<string>(item)){
            cout << "'" << get<string>(item) << "', ";
        }
    }
    cout << "]" << endl;
    lista4 = remover_item(lista4,"ola");//removendo item da lista
    cout << "Mostrando a lista 4 após a remoção do item" << endl;
    cout << "[";
    for (auto item: lista4){ 
        if(holds_alternative<int>(item)){
            cout << get<int>(item) << ", ";
        }
        else if(holds_alternative<string>(item)){
            cout << "'" << get<string>(item) << "', ";
        }
    }
    cout << "]" << endl;
    return 0;

}