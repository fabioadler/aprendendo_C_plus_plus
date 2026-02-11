#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale>
#include <string>
#include <ctime>
#include <experimental/random>
#include <stdlib.h>

using namespace std;

int main(){

    locale::global(locale(""));
    srand(time(nullptr));//determina um valor inicial para o random

    sf::RenderWindow window(sf::VideoMode(800,500),"Mine drop");
    window.setFramerateLimit(60); //Determina o tanto de quadros macimos por segundo FPS
    //sf::RectangleShape quadrado;                --> Seria feito assim se fossemos criar usando uma simples variavel, mas vamos fazer com ponteiros
    //quadrado.setSize(sf::Vector2f(50.f,50.f));
    //quadrado.setFillColor(sf::Color::Green);
    //quadrado.setPosition(sf::Vector2f(10.f,10.f));
    sf::RectangleShape* quadrado = new sf::RectangleShape(); //--> Forma de criar um ponteiro classico nos vamos acabar usando esse no projeto
    //auto quadrado = make_shared<sf::RectangleShape>(); --> Criamos um ponteiro inteligente
    quadrado->setSize(sf::Vector2f(50.f,50.f));
    quadrado->setFillColor(sf::Color::Green);
    float x = static_cast<float>(experimental::randint(10,(int)(window.getSize().x - quadrado->getSize().x)));
    quadrado->setPosition(sf::Vector2f(x,10.f));
    sf::Vector2i pos_mouse_win;
    sf::Vector2f coord_mouse;

    while(window.isOpen()){
        sf::Event evento;
        window.pollEvent(evento);
        pos_mouse_win = sf::Mouse::getPosition(window);
        coord_mouse = window.mapPixelToCoords(pos_mouse_win);
        if(evento.type == 0){
            break;
        }
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && quadrado->getGlobalBounds().contains(coord_mouse)){
            x = static_cast<float>(experimental::randint(10,(int)(window.getSize().x - quadrado->getSize().x)));
            quadrado->setPosition(x,10.f);
            cout << "Acertou" << endl;
        }
        else {
            cout << evento.type << endl;
        }

        x = static_cast<float>(experimental::randint(10,(int)(window.getSize().x - quadrado->getSize().x)));
        //quadrado.move(0.f,0.08f); --> como seria usando variavel
        quadrado->move(0.f,5.f);
        if(quadrado->getPosition().y > window.getSize().y){
            quadrado->setPosition(sf::Vector2f(x,10.f));
        }
        window.clear();
        //window.draw(quadrado); --> como seria usando variavel
        window.draw(*quadrado);
        window.display();
    }

}