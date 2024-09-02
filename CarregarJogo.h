
#ifndef CARREGARJOGO_H_
#define CARREGARJOGO_H_

#include "ElementosTelaInicio.h"
#include "Botoes.h"
#include "Mario.h"
#include "Background.h"
#include "Inimigos.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

enum class Fase { MENU_INICIAL, FASE1};

class CarregarJogo : public ElementosTelaInicio {
protected:
    Botoes botaoJogar;
    Botoes botaoFechar;
    sf::Sprite background;
    float escalaX;
    float escalaY;
    Fase faseAtual;

public:
    CarregarJogo() : ElementosTelaInicio("Johnny B. Goode.wav", "MarioBrosMenu.jpg", "SuperMarioBros.2.ttf"),
                           background(textura),
                           escalaX(static_cast<float>(window.getSize().x) / background.getLocalBounds().width),
                           escalaY(static_cast<float>(window.getSize().y) / background.getLocalBounds().height),
                           faseAtual(Fase::MENU_INICIAL) {

        background.setScale(escalaX, escalaY);
    }

    void telaInicio() {
        botaoJogar.botao.setSize(sf::Vector2f(200.f, 80.f));
        botaoFechar.botao.setSize(sf::Vector2f(200.f, 80.f));
        botaoJogar.botao.setPosition((window.getSize().x / 4), window.getSize().y - ((window.getSize().y / 3)));
        botaoFechar.botao.setPosition((window.getSize().x / 4) * 2, window.getSize().y - window.getSize().y / 3);
        botaoJogar.texto.setFont(fonte);
        botaoFechar.texto.setFont(fonte);
        botaoJogar.texto.setString("Jogar");
        botaoFechar.texto.setString("Fechar");
        botaoJogar.texto.setCharacterSize(30);
        botaoFechar.texto.setCharacterSize(30);
        botaoJogar.posicaoTexto();
        botaoFechar.posicaoTexto();

        while (window.isOpen()) {
            if (faseAtual != Fase::MENU_INICIAL) {
                break;
            }

            botaoJogar.trocarCorBotao(window);
            botaoFechar.trocarCorBotao(window);

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (botaoJogar.mousePassar(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    faseAtual = Fase::FASE1;
                    som.stop();
                }
                if (botaoFechar.mousePassar(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    window.close();
                }
            }

            window.clear();
            if (faseAtual == Fase::MENU_INICIAL) {
                window.draw(background);
                botaoJogar.desenhar(window);
                botaoFechar.desenhar(window);
            }
            window.display();
        }
    }

    void executarJogo() {
        while (window.isOpen()) {
            switch (faseAtual) {
                case Fase::MENU_INICIAL:
                    telaInicio();
                    break;
                case Fase::FASE1:
                    desenharFase1();
                    break;
                default:
                    window.close();
                    break;
            }
        }
    }

    void desenharFase1() {
    	Background background;
    	Mario mario;
    	Tartaruga tartaruga;
    	Carangueijo carangueijo;
    	Vagalume vagalume;
    	sf::Clock relogio;
    	float cronometro = 0.0f;
    	bool menu;

    	while (window.isOpen()){
    		sf::Event event;

    		while (window.pollEvent(event)){
    			if (event.type == sf::Event::Closed){
    				window.close();
    			}
    			if (event.key.code == sf::Keyboard::Escape){
    				menu = true;
    				break;
    			}
    			if (event.key.code == sf::Keyboard::Right){
    				cronometro = relogio.getElapsedTime().asSeconds();
    				if (cronometro >= 0.05f){
    					mario.moverDireita();
    					relogio.restart();
    				}
    			}
    			if (event.key.code == sf::Keyboard::Left){
    				cronometro = relogio.getElapsedTime().asSeconds();
    			    if (cronometro >= 0.05f){
    			    	mario.moverEsquerda();
    			    	relogio.restart();
    			    }
    			}
    		}

			if(menu == true){
				faseAtual = Fase::MENU_INICIAL;
				window.clear();
				break;
			}

			mario.gravidade();

			background.desenharBackground(window);
			mario.desenharMario(window);
			tartaruga.desenharTartaruga(window);
			carangueijo.desenharCarangueijo(window);
			vagalume.desenharVagalume(window);
			window.display();
		}
   }
};

void carregarJogo() {
    CarregarJogo jogo;
    jogo.executarJogo();
}

#endif /* CARREGARJOGO_H_ */
