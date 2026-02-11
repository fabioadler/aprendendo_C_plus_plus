#include <iostream>
#include <string>
#include <locale>
#include <ctime>
#include <experimental/random>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

using namespace std;

int main(){

    locale::global(locale(""));
    srand(time(nullptr));
    sf::RenderWindow window(sf::VideoMode(800,500),"Mine_drop");
    window.setFramerateLimit(60);
    sf::Texture textura;
    textura.loadFromFile("./img/sr2e4357b9812e5.png");
    vector<sf::Sprite> objs;
    size_t max_objs = 5;
    sf::Vector2i pos_mouse_tela;
    sf::Vector2f pos_mouse_coord;
    float ponto_sprite_init = 20.f;
    int score = 0;
    sf::Font font1;
    font1.loadFromFile("./fonts/basictitlefont.ttf");
    sf::Text texto("Socre: " + to_string(score),font1,32);
    texto.setPosition(sf::Vector2f(0.f,0.f));
    while(window.isOpen()){
        sf::Event evento;
        while(window.pollEvent(evento)){
            if(evento.type == 0){
                break;
            }
            else if(evento.type == sf::Event::KeyPressed){
                if(evento.key.code == sf::Keyboard::Escape){
                    window.close();
                } else{}
            }
            else{
                cout << "[log evento] ]---> " << evento.type << endl;
            }
            texto.setString("Socre: " + to_string(score));
        }
        pos_mouse_tela = sf::Mouse::getPosition(window);
        pos_mouse_coord = window.mapPixelToCoords(pos_mouse_tela);

        if(objs.size() < max_objs){
            sf::Sprite bloco(textura);
            float x = static_cast<float>(experimental::randint(10,(int)(window.getSize().x - textura.getSize().x)));
            bloco.setPosition(sf::Vector2f(x,ponto_sprite_init));
            objs.push_back(bloco);
        } else{}

        window.clear();
        window.draw(texto);
        for(auto &obj: objs){
            float x = static_cast<float>(experimental::randint(10,(int)(window.getSize().x - textura.getSize().x)));
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && (obj.getGlobalBounds().contains(pos_mouse_coord))){
                obj.setPosition(sf::Vector2f(x,ponto_sprite_init));
                cout << "Acertou o bloco" << endl;
                score ++;
            }
            else if(obj.getPosition().y > window.getSize().y){
                obj.setPosition(sf::Vector2f(x,ponto_sprite_init));
                if(score > 0){
                    score --;
                } else {}
            } else {
                obj.move(0.f,2.f);
            }
            window.draw(obj);
        }
        window.display();
    }
    return 0;

}