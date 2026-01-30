#include <iostream>
#include <stdlib.h>
#include <locale>
#include <cmath>

using namespace std;

int main(){

    locale::global(locale(""));
    int nota;
    cout << "Qual a sua nota (0-10): ";
    cin >> nota;
    if(nota >= 7){ //O if e uma função que verifica se algo e verdadeiro, no caso verifica se a condição e verdadeira, se for executa o codigo dentro do if
        cout << "Você foi aprovado com a nota: " << nota << endl;
    }
    else{ //O else e caso não seja o verdadeiro a condição, como um se não for, executa o codigo dentro de else
        cout << "Você foi reprovado com essa nota: " << nota << endl;
    }
    if(fmod(nota,2) == 0){
        cout << "Sua nota e par" << endl;
    }
    else{
        cout << "Sua nota e impar" << endl;
    }
    switch(nota){ //O switch vai verificar se o valor da variavel e igual a de alguma case (como se fosse uma situação)
        case 10: //Uma das opções, se o valor for 10 ele execulta o codido dentro de case
            cout << "Meus parabéns! Você tirou a maior nota, você tem futuro" << endl;
            break; //O break e necessario dentro do case para para a execução do case, caso não tenha ele segue executando direto
        case 9:
            cout << "Você foi muito bem, tá quase lá, continue se esforçando" << endl;
            break;
        case 8:
            cout << "Você foi bem, mas da para melhorar, não pare" << endl;
            break;
        case 7:
            cout << "Essa foi por pouco, se cuida, você consegue mais" << endl;
            break;
        default: //O defaulta e como se fosse o padrão, se nenhuma dessas situações a cima for verdadeira o default vai ser execultado
            cout << "Eeee... Vacilou, mais não e o fim, você consegue melhorar, vamos lá" << endl;
            break;
    }

}
