#ifndef INIMIGOS_H_
#define INIMIGOS_H_
#include "SFML/Graphics.hpp"

class Inimigos{
protected:
	sf::Texture textureInimigos;
	sf::Sprite imagemInimigos;
	float x, y;
public:
	Inimigos(){
		textureInimigos.loadFromFile("Inimigos-TestandoPNG.png");
		imagemInimigos.setTexture(textureInimigos);
		x = y= 0;
	}
};

class Tartaruga : public Inimigos{
public:
	Tartaruga(){
		Inimigos();
		x = 290;
		y = 110;
		imagemInimigos.setTextureRect(sf::IntRect(0,1,20,15));
		imagemInimigos.scale(5, 5);
		imagemInimigos.setPosition(x, y);
	}
	/*void moverTartaruga(){
		x=x+0.5;
		if(x>=200){
			x=-x;
		}
		imagemInimigos.setPosition(x, y);
	}*/

	void desenharTartaruga(sf::RenderWindow &window){
		//moverTartaruga();
		window.draw(imagemInimigos);
	}
};

class Carangueijo : public Inimigos{
public:
	Carangueijo(){
		x = 200;
		y = 100;
		imagemInimigos.setTextureRect(sf::IntRect(0,20,20,16));
		imagemInimigos.scale(5, 5);
		imagemInimigos.setPosition(x, y);
		}
	void desenharCarangueijo(sf::RenderWindow &window){
			window.draw(imagemInimigos);
		}

};

class Vagalume : public Inimigos{
public:
	Vagalume(){
		x = 700;
		y = 70;
		imagemInimigos.setTextureRect(sf::IntRect(0,76,20,15));
		imagemInimigos.scale(5, 5);
		imagemInimigos.setPosition(x, y);
	}
	void desenharVagalume(sf::RenderWindow &window){
			window.draw(imagemInimigos);
		}
};


#endif /* INIMIGOS_H_ */
