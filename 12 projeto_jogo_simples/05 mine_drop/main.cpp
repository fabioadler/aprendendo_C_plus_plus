#include <iostream> //lib de escrita e leitura do terminal
#include <string> //lib para o uso de strings
#include <locale> //lib para corrigir os erros de uso de acentos
#include <ctime> //lib para leitura e manipulação de data e hora
#include <experimental/random> //lib para fazer random (fazer sorteios aleatorios)
#include <stdlib.h> //lib com funções padrões
#include <SFML/Graphics.hpp> //lib que estamos usando para fazer jogos ela automaticamente incluem as seguintes SFML/Window e SFML/System

using namespace std; //Comando usado para não ter que ficar escrevendo std:: toda vez que for usar um comando

int main(){

    locale::global(locale(""));//Correção de acentos
    srand(time(nullptr));//Inicio da função necessaria para sortear usando random
    sf::RenderWindow window(sf::VideoMode(800,500),"Mine_drop");//Cria uma janela com a dimensão 800x500 com o titulo "Mine_drop"
    window.setFramerateLimit(60);//Determina que a quantidade maxima de FPS como 60
    sf::Texture textura;//Criamos uma variavel/objeto do tipo de textura
    textura.loadFromFile("./img/sr2e4357b9812e5.png");//Caregamos a textura
    vector<sf::Sprite> objs;//Uma lista de objetos do tipo Sprite (Nesse caso os blocos dentro do jogo)
    size_t max_objs = 5;// Quantidade maxima de objetos, se não tivessemos usado size_t o compilador reclamaria, ou teriamos que ter determinado a quantidade de objetos maxima do array
    sf::Vector2i pos_mouse_tela;//Variavel onde vamos salvar com as posições x e y do mousde dentro da tela
    sf::Vector2f pos_mouse_coord;//Seriam as coordenadas x e y do mouse dentro da janela
    float ponto_sprite_init = 20.f;//A altura de onde os blocos começam a aparecer
    int score = 0;//Valor dos pontos do jogo
    sf::Font font1;//Cria uma variavel/objeto do tipo fonte
    font1.loadFromFile("./fonts/basictitlefont.ttf");//Carrega o arquivo da fonte
    sf::Text texto("Socre: " + to_string(score),font1,32);//Criamos variaver/objeto do tipo texto, o texto dos pontos do jogo
    texto.setPosition(sf::Vector2f(0.f,0.f));//Determinamos a posição do texto
    while(window.isOpen()){//O loop while vai continua enquanto a janela esteja aberta
        sf::Event evento;//Criamos uma variavel/objeto do tipo do evento
        while(window.pollEvent(evento)){//aqui o loop while vai continuar enquanto tiver eventos para serem processados e salva o evento atual no nossa variavel/objeto evento
            if(evento.type == 0){//Caso feche a tela executar
                break;//para o loop
            }
            else if(evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape){//Caso uma tecla do teclado for precionado e se essa tela for o ESC, executar
                window.close();//fechar a janela
            }
            else{//executar se nenhuma outra condição for valida
                cout << "[log evento] ]---> " << evento.type << endl;//Escreve no console o log dos eventos
            }
            texto.setString("Socre: " + to_string(score));//Alteramos o texto dos pontos
        }
        pos_mouse_tela = sf::Mouse::getPosition(window);//pegamos a posição do mouse dentro da tela
        pos_mouse_coord = window.mapPixelToCoords(pos_mouse_tela);//coordenadas do mouse na janela

        if(objs.size() < max_objs){//Verifica se a todos os objetos possiveis determinados já existam
            sf::Sprite bloco(textura);//cria uma variavel/objeto do tipo sprite
            float x = static_cast<float>(experimental::randint(10,(int)(window.getSize().x - textura.getSize().x)));//sorteamos ums valor para o eixo x aleatoriamente
            bloco.setPosition(sf::Vector2f(x,ponto_sprite_init));//determina a posição do bloco com o valor x aleatorio, o y e o valor que já determinamos
            objs.push_back(bloco);//adicione o nosso sprite na lista
        } else{}

        window.clear();//limpa a janela
        window.draw(texto);//desenha o texto na janela
        for(auto &obj: objs){//o loop roda em relação ao intens da lista
            float x = static_cast<float>(experimental::randint(10,(int)(window.getSize().x - textura.getSize().x)));//sorteamos o valor x de forma aleatoria de novo
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && (obj.getGlobalBounds().contains(pos_mouse_coord))){//verifica se o botão escerdo do mouse está precionado e se a posição do mouse está dentro da posição dos nossos sprites
                obj.setPosition(sf::Vector2f(x,ponto_sprite_init));//Mudamos a posição do sprite para o inicio e com o x aleatorio
                cout << "Acertou o bloco" << endl;//escreve o log no console
                score ++;//adiciona um ponto
            }
            else if(obj.getPosition().y > window.getSize().y){//verifica se o sprite saiu da janela
                obj.setPosition(sf::Vector2f(x,ponto_sprite_init));//Muda a posição para o inicio com o x aleatorio
                if(score > 0){//se os pontos for maior que 0 executar
                    score --;//diminui um ponto
                } else {}
            } else {
                obj.move(0.f,2.f);//adiciona movimento ao sprite
            }
            window.draw(obj);//escreve o objeto
        }
        window.display();//mostra tudo na janela
    }
    return 0;

}