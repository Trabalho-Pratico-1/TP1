/*
 * Inimigos.h
 *
 *  Created on: 1 de set. de 2024
 *      Author: davia
 */

#ifndef INIMIGOS_H_
#define INIMIGOS_H_
#include "SFML/Graphics.hpp"

class Inimigos{
protected:
	sf::Texture textureInimigos;
	sf::Sprite imagemInimigos;
public:
	Inimigos(){
		textureInimigos.loadFromFile("Inimigos-TestandoPNG.png");
		imagemInimigos.setTexture(textureInimigos);
	}
};

class Tartaruga : public Inimigos{
public:
	Tartaruga(){
		Inimigos();
		imagemInimigos.setTextureRect(sf::IntRect(0,1,20,15));
		imagemInimigos.scale(5, 5);
		imagemInimigos.setPosition(100, 350);
	}
	void desenharTartaruga(sf::RenderWindow &window){
		window.draw(imagemInimigos);
	}
};

class Carangueijo : public Inimigos{
public:
	Carangueijo(){
		imagemInimigos.setTextureRect(sf::IntRect(0,20,20,16));
		imagemInimigos.scale(5, 5);
		imagemInimigos.setPosition(200, 100);
		}
	void desenharCarangueijo(sf::RenderWindow &window){
			window.draw(imagemInimigos);
		}

};

class Vagalume : public Inimigos{
public:
	Vagalume(){
		imagemInimigos.setTextureRect(sf::IntRect(0,76,20,15));
		imagemInimigos.scale(5, 5);
		imagemInimigos.setPosition(700, 70);
	}
	void desenharVagalume(sf::RenderWindow &window){
			window.draw(imagemInimigos);
		}
};


#endif /* INIMIGOS_H_ */
