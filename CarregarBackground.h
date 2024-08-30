/*
 * CarregarBackground.h
 *
 *  Created on: 14 de ago. de 2024
 *      Author: davia
 */

#ifndef CARREGARBACKGROUND_H_
#define CARREGARBACKGROUND_H_

#include "ElementosTelaInicio.h"
#include "Botoes.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class CarregarBackground : public ElementosTelaInicio{
protected:
	Botoes botaoJogar;
	Botoes botaoFechar;
    sf::Sprite background;
    float escalaX;
    float escalaY;

public:
    CarregarBackground() : ElementosTelaInicio("Johnny B. Goode.wav", "MarioBrosMenu.jpg","SuperMarioBros.2.ttf"),
          background(textura),
          escalaX(static_cast<float>(window.getSize().x) / background.getLocalBounds().width),
          escalaY(static_cast<float>(window.getSize().y) / background.getLocalBounds().height) {

        background.setScale(escalaX, escalaY);
    }
    void telaInicio(){

    	botaoJogar.botao.setSize(sf::Vector2f(200.f, 80.f));
    	botaoFechar.botao.setSize(sf::Vector2f(200.f, 80.f));
    	botaoJogar.botao.setPosition((window.getSize().x / 4) , window.getSize().y - ((window.getSize().y / 3)));
    	botaoFechar.botao.setPosition((window.getSize().x / 4) * 2 , window.getSize().y - window.getSize().y / 3);
    	botaoJogar.texto.setFont(fonte);
    	botaoFechar.texto.setFont(fonte);
    	botaoJogar.texto.setString("Jogar");
    	botaoFechar.texto.setString("Fechar");
    	botaoJogar.texto.setCharacterSize(30);
    	botaoFechar.texto.setCharacterSize(30);
    	botaoJogar.posicaoTexto();
    	botaoFechar.posicaoTexto();

    	while (window.isOpen())
    	    {
    	    	if (parteJogo != 0){
    	    		break;
    	    	}

    	    	botaoJogar.trocarCorBotao(window);
    	    	botaoFechar.trocarCorBotao(window);

    	        sf::Event event;
    	        while (window.pollEvent(event))
    	        {
    	            if (event.type == sf::Event::Closed){
    	                window.close();
    	        	}

    	        	if(botaoJogar.mousePassar(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    	        		parteJogo = 1;
    	        		som.stop();
    	        	}
    	        	if(botaoFechar.mousePassar(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    	        		window.close();
    	        	}

    	        	window.clear();
    	        	if(parteJogo == 0){
    	        		window.draw(background);
    	        		botaoJogar.desenhar(window);
    	        		botaoFechar.desenhar(window);
    	        	}
    	        }
    	        window.display();
    	    }
    }
};

void carregarBackground(){
	CarregarBackground background;
	background.telaInicio();
}

#endif /* CARREGARBACKGROUND_H_ */
