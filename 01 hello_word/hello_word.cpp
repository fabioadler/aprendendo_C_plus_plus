//inclui uma biblioteca
#include <iostream> //bilioteca que vai nós permitir interagir com o console
#include <stdlib.h> //biblioteca padrão 

//usar o namespace (caminho para o diretorio) para poder usar arquivos em outros diretorios e std siginifica padrão. Usamos por exemplo para não presiar digitar std::cout e digitar só cout
using namespace std;

//cria função main (principal)
int main() {

    //cout siginifica console output, em resumo escrevemos no terminal, o endl indica o fim da linha
    cout << "hello word!" << endl;
    //retorna 0 para o sistema saber que não ouve erro
    return 0;

}