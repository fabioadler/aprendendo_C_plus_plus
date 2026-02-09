#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){

    locale::global(locale(""));
    sf::RenderWindow window(sf::VideoMode(800,600),"Fonts");
    sf::Font font1, font2;//Criamos duas variaveis do tipo fonte
    if(!font1.loadFromFile("./fonts/basictitlefont.ttf") || !font2.loadFromFile("./fonts/Wrexham Script.ttf")){//Carregamos e verificamos se todas as fontes foram carregadas corretamente
        cout << "Falha ao carregar as fonts" << endl;
        return EXIT_FAILURE;
    } else{}
    int score = 0;
    sf::Text texto1("My game",font2, 32);//Criamos um texto com a fonst2 e o tamanho 32
    sf::Text texto2("Score: " + to_string(score),font1, 32);
    texto1.setPosition(sf::Vector2(2.f,0.f));
    texto2.setPosition(sf::Vector2(window.getSize().x - 200.f,0.f));
    bool press_left_button = false;//Criamos um botão para verificar se o mouse está precionado ou não, para não clicar infinitamente
    while(window.isOpen()){
        sf::Event evento;
        window.pollEvent(evento);
        if(evento.type == 0){
            cout << "[Evento] ]===> " << evento.type << endl;
            break;
        }
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && press_left_button != true){//Verificamos se o botão esquerdo do mouse está precionado
            score ++;
            cout << "Clicou" << endl;
            texto2.setString("Score: " + to_string(score));
            press_left_button = true;
        }
        else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && press_left_button == true){//Verificamos se o botão esquerdo do mouse não está precionado
            press_left_button = false;
        }
        else{
            cout << "[Evento] ]===> " << evento.type << endl;
        }
        window.clear();
        window.draw(texto1);
        window.draw(texto2);
        window.display();
    }
    return 0;

}