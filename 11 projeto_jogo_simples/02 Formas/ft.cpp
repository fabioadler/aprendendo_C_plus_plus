#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <locale>

using namespace std;

int main(){

    locale::global(locale(""));
    sf::RenderWindow window(sf::VideoMode(800,500),"Formas e telas");
    sf::RectangleShape retangulo(sf::Vector2f(100.f,100.f));//criamos um retangulo e usamos a função Vector2f para definir a largura e altura
    retangulo.setFillColor(sf::Color::Green);//Definimos uma cor para o retangulo
    retangulo.setPosition(//usamos o setPosition para determinar a posição do retangulo no eixo x e y
        (window.getSize().x / 2) - (retangulo.getSize().x / 2),//Fizemos o calculo para descobrir o centro do eixo x/2 menos o tamanho no eixo x/2 do retangulo, para ele ficar no centro
        (window.getSize().y / 2) - (retangulo.getSize().y / 2)//Fizemos o calculo para descobrir o centro do eixo y/2 menos o tamanho no eixo y/2 do retangulo, para ele ficar no centro
    );
    while(window.isOpen()){
        sf::Event evento;
        window.pollEvent(evento);
        if(evento.type == 0){
            break;
        }
        else{
            cout << "[Evento] ]===> " << evento.type << endl;
        }
        auto posicao_mouse = sf::Mouse::getPosition(window);//Pega a posição do mouse
        if(posicao_mouse.x < (window.getSize().x - retangulo.getSize().x) && posicao_mouse.y < (window.getSize().y - retangulo.getSize().y)){//Verifica se o mouse está dentro da tela
            retangulo.setPosition(posicao_mouse.x,posicao_mouse.y);//Seta a posição do retangulo
        }
        else{}
        window.clear();
        window.draw(retangulo);
        window.display();
    }
    return 0;

}