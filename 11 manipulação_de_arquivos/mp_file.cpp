#include <stdlib.h>
#include <iostream>
#include <fstream> //Lib para manipular arquivos
#include <string>
#include <locale>
#include <ctime> //Lib de data e hora

using namespace std;

int main(){

    locale::global(locale(""));

    ifstream arquivo_de_leitura("./aq1.txt", ios::in);//Abrir o arquivo apenas como leitura
    if(!arquivo_de_leitura.is_open()){//Executar se não abrir
        cout << "Erro ao ler o arquivo aq1.txt" << endl;
        return 1;
    }
    else{
        string conteudo;
        while(getline(arquivo_de_leitura, conteudo)){//Ler enquanto tiver linhas para ler
            cout << conteudo << endl;
        }
        arquivo_de_leitura.close();//Fechar arquivo
    }

    ofstream arquivo_de_escrita("./aq2.txt", ios::out);//Abrir o arquivo como escrita
    time_t agora = time(0);//O tempo agora
    tm* tempoLocal = localtime(&agora);//Converte para a hora local
    char buffer[80];                                                //
    strftime(buffer,sizeof(buffer),"%d/%m/%Y %H:%M:%S",tempoLocal); //Formatação completa em strtime (string de data e hora)
    string data = buffer;                                           //
    if(arquivo_de_escrita.is_open()){//Se o arquivo estiver aberto executar
        arquivo_de_escrita << "O arquivo foi escrito nesse momento [*] ]---> " << data << endl;//Escrevendo arquivo
        arquivo_de_escrita.flush();//Garantir que a escrita foi realizada
        arquivo_de_escrita.close();
    }
    else{
        cout << "Erro ao abrir o arquivo aq2.txt" << endl;
        return 1;
    }

    fstream arquivo1("./aq2.txt", ios::in | ios::out | ios::app);//abrir o arquivo como leitura, escrita e append
    if(arquivo1.is_open()){
        string conteudo;
        string cont;
        while(getline(arquivo1, cont)){
            conteudo += cont;
            cout << cont << endl;
        }
        arquivo1.clear();//limpar todos os erros de arquivo, por que no loop while depois da ultima linha ele tenta ler mais uma e da erro, e esse comando limpa esse erro
        arquivo1 << conteudo << endl;                                                   //
        arquivo1 << "Deu certo ler e escrever de novo" << endl;                         //Escreve no arquivo
        arquivo1 << "O arquivo foi escrito nesse momento [*] ]---> " << data << endl;   //
        arquivo1.flush();
        arquivo1.close();
    }
    else{
        cout << "Erro ao abrir o arquivo como leitura e escrita" << endl;
        return 1;
    }

    ofstream arquivo2("./aq1.txt", ios::app);//Abre o arquivo como append
    if(arquivo2.is_open()){
        arquivo2 << endl << "[*] ]---> " << data;
        arquivo2.flush();
        arquivo2.close();
    }
    else{
        cout << "Erro ao abrir o arquivo como append" << endl;
        return 1;
    }
    return 0;

}