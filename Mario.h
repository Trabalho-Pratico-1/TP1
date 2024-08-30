/*
 * Mario.h
 *
 *  Created on: 30 de ago. de 2024
 *      Author: davia
 */

#ifndef MARIO_H_
#define MARIO_H_

#include <SFML/Graphics.hpp>
class Mario{
private:
	sf::Texture texturePersongem;
	sf::Sprite imagemPersonagem;
	//int x, y, velocidadex, velocidadey;

public:
	Mario(){
		texturePersongem.loadFromFile("personagem.png");
		imagemPersonagem.setTexture(texturePersongem);
		imagemPersonagem.setPosition(200, 550);
		imagemPersonagem.scale(0.15, 0.15);
	}

	void desenharMario(sf::RenderWindow &window){
		 window.draw(imagemPersonagem);
	}
};



#endif /* MARIO_H_ */
