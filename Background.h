/*
 * Background.h
 *
 *  Created on: 30 de ago. de 2024
 *      Author: davia
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <SFML/Graphics.hpp>

class Background{
protected:
	sf::Texture textureBackground;
	sf::Sprite imagemBackground;

public:
	Background(){
		textureBackground.loadFromFile("backgroundAtari.png");
		imagemBackground.setTexture(textureBackground);
		imagemBackground.setTextureRect(sf::IntRect(1,1,318,224));
		imagemBackground.scale(3, 2.8);
	}

	void desenharBackground(sf::RenderWindow &window){
		window.draw(imagemBackground);
	}
};

class Plataformas : Background{
protected:
	int a, l, x, y;
public:
	Plataformas(){
		a = l = x = y = 0;
		}

	void definirPlataforma(){
		imagemBackground.setTextureRect(sf::IntRect(a,l,x,y));
	}

	void desenharPlataforma(sf::RenderWindow &window){
			//moverTartaruga();
			window.draw(imagemBackground);
		}

};

Plataformas plataforma1, plataforma2, plataforma3, plataforma4, plataforma5, plataforma6, plataforma7;



#endif /* BACKGROUND_H_ */
