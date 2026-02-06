#include <iostream>
#include <locale>
#include <stdlib.h>
#include <string>

using namespace std;

class Pessoa{ //inicio da classe
    private: //parte privada da classe que pode ter variaveis e funções, que só podem ser usadas dentro da class
        string cpf;
        string profissao;

    public://parte publica da classe que podem ser acessadas no codigo, desde funções e variaveis
        string nome;
        int idade;

        Pessoa(string nome_pessoa,string cpf_pessoa){ //metodo construtor
            nome = nome_pessoa;
            cpf = cpf_pessoa;
            profissao = "Sem profissão";
            idade = 0;
            cout << "Hoje e um dia muito feliz! Hoje nasceu: " << nome << endl;
        }
        ~Pessoa(){//metodo destrutor
            cout << "Faleceu: " << nome << " com " << idade << " anos" << endl;
        }
        void aniversario(){
            idade ++;
            cout << nome << " fez " << idade << " anos" << endl; 
        }
        void exib_infos(){
            cout << "Meu nome e " << nome << " tenho " << idade << " anos e o meu CPF e " << cpf << " minha profissão e " << profissao << endl;
        }
        void set_idade(int anos){
           idade = anos; 
        }
        void set_profissao(string prof){
            profissao = prof;
            cout << "[" << nome << "] ]--> Mudou de profissão" << endl;
        }
};

int main() {

    locale::global(locale(""));
    Pessoa player1("Tron","000.000.000-00");
    player1.set_idade(18);
    cout << "Eu sou " << player1.nome << " e eu tenho " << player1.idade << "anos" << endl; //as variaveis da parte publicas podem ser acessadas no codigo
    player1.set_profissao("pedreiro");
    player1.aniversario();
    player1.exib_infos();
    return 0;
    //Ao fim do metodo main ele automaticamente chama o metodo destuctor 

}