#include <SFML/Graphics.hpp>//Lib adiciona os recursos para criação de janela e uso dos recursos do sistema
#include <iostream>
#include <stdlib.h>
#include <locale>
#include <string>

using namespace std;
using namespace sf;

int main() {

    locale::global(locale(""));
    RenderWindow window;//cria a nossa variavel de janela
    VideoMode dimension(1280,720);//cria nossa variavel de dimensão
    window.create(dimension,"Fundamentos Inicias");//cria a janela
    CircleShape circulo(100.0f);//criamos uma varivel que e um criculo de 100px
    while (window.isOpen()){//Criamos um while por que se não simplesmente o sistema abriria e fecharia rapidamente, no caso usamo uma função que enquanto a tela estiver aberta continua
        Event event;//Estaciamos a variavel event, que sera responsavel por receber os eventos
        window.pollEvent(event);//Fazemos a captura do evento e salvamos na nossa variavel event
        if(event.type == 0){//Se o evento for 0 que seria close (fechar a janela) pare o loop
            break;
        }
        else {
            cout << event.type << endl;//Escreve para agente no console o tipo do evento que está ocorrendo
        }
        window.clear();//limpar tela
        window.draw(circulo);//Desenha circulo
        window.display();//mostrar na janela
    }
    return EXIT_SUCCESS;

}