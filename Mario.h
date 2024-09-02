/*
 * Mario.h
 *
 *  Created on: 30 de ago. de 2024
 *      Author: davia
 */

#ifndef MARIO_H_
#define MARIO_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Mario{
private:
	sf::Texture texturePersongem;
	sf::Sprite imagemPersonagem;
	int x, y;
	float velocidadeX, velocidadeY;
	sf::Clock relogio;
	float cronometro = 0.0f;

public:
	Mario(){
		x = 200;
		y = 450;
		velocidadeX = 0;
		velocidadeY = 0;
		texturePersongem.loadFromFile("personagem.png");
		imagemPersonagem.setTexture(texturePersongem);
		imagemPersonagem.setPosition(x, y);
		imagemPersonagem.scale(0.15, 0.15);
	}

	bool estaNoChao(){
		if (y + imagemPersonagem.getGlobalBounds().height >= 450){
			return true;
		}
		else{
			return false;
		}
	}

	void gravidade(){
		y-=velocidadeY * cronometro + 5* cronometro * cronometro;
		imagemPersonagem.setPosition(x, y);
		if (estaNoChao()){
			cronometro = 0.0f;
			relogio.restart();
		}
		else{
			cronometro = relogio.getElapsedTime().asSeconds();
		}
	}

	void moverDireita(){
		x+=10;
		imagemPersonagem.setPosition(x, y);
	}

	void moverEsquerda(){
		x-=10;
		imagemPersonagem.setPosition(x, y);
	}

	void desenharMario(sf::RenderWindow &window){
		 window.draw(imagemPersonagem);
	}
};



#endif /* MARIO_H_ */
