#include <iostream>
#include <locale>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

using namespace std;

int main(){

    locale::global(locale(""));
    sf::RenderWindow window(sf::VideoMode(800,500),"Movimento e imagem");
    sf::Font font1, font2;
    font1.loadFromFile("./fonts/basictitlefont.ttf");
    font2.loadFromFile("./fonts/Wrexham Script.ttf");
    sf::Texture textura_bola,textura_campo;//criamos as nossas 2 variaveis/texturas
    textura_campo.loadFromFile("./img/campo.png");//Caregamos a textura do campo e importante está na mesma dimensão da janela em px
    textura_bola.loadFromFile("./img/bolta_storm.png");//Carregamos a textura da bola, já tem que tar do tamanho em que sera usado no jogo em px
    textura_bola.setSmooth(true);//Seria algo semelhante a o anti aliasing, no caso suavisa o serrilhamento
    sf::Text texto_bola("0, 0",font2,32);
    sf::Sprite bola(textura_bola),campo(textura_campo);//Criamos as variaveis/sprite no caso a bola e o campo
    sf::Vector2u tamanho_bola = textura_bola.getSize();//Salvamos o tamanho da bola em relação a textura
    sf::Vector2f velocidade(0.1f,0.1f);//Definimos a velocidade em que a bola vai se mover
    sf::Vector2f velocidade_texto(0.f,-50.f);//E como se fosse a distantica do texto em relação a bola
    while(window.isOpen()){
        sf::Event evento;
        window.pollEvent(evento);
        if(evento.type == 0){
            break;
        }
        else {
            cout << "[Evento] ]---> " << evento.type << endl;
        }

        if(((bola.getPosition().x + tamanho_bola.x) > window.getSize().x) && (velocidade.x > 0) || (bola.getPosition().x < 0 && velocidade.x < 0)){// Verificamos se a bola não vai sair da tela e se a velocidade e maior ou menos que 0 no eixo x
            velocidade.x = -velocidade.x;//Alteramos a velocidade sempre que a bola for sair no eixo x
        }
        else if(((bola.getPosition().y + tamanho_bola.y) > window.getSize().y) && (velocidade.y > 0) || (bola.getPosition().y < 0 && velocidade.y < 0)){ // Verificamos se a bola não vai sair da tela e se a velocidade e maior ou menos que 0 no eixo y
            velocidade.y = -velocidade.y;//Alteramos a velocidade sempre que a bola for sair no eixo y
        }

        bola.setPosition(bola.getPosition() + velocidade);//Aqui adicionamos a posição da bola a velocidade, assim fazendo ela se mover
        texto_bola.setPosition(bola.getPosition() + velocidade + velocidade_texto);//Fazemos o mesmo com o texto só que adicionamos a outra velocidade que fizemos para o texto, para que ele sempre fique acima da bola
        texto_bola.setString("x: " + to_string(u_int(bola.getPosition().x)) + ", y: " + to_string(u_int(bola.getPosition().y)));//Escrevemos a posição da bola no texto, lembrando que o texto e opicional para fazer debug da posição da bola

        window.clear();
        window.draw(campo);
        window.draw(bola);
        window.draw(texto_bola);
        window.display();
    }
    return 0;

}