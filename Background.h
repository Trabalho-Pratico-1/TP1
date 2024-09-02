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
private:
	sf::Texture textureBackground;
	sf::Sprite imagemBackground;

public:
	Background(){
		textureBackground.loadFromFile("Atari - Mario Bros Atari 2600 - Backgrounds.png");
		imagemBackground.setTexture(textureBackground);
		imagemBackground.setTextureRect(sf::IntRect(1,1,320,210));
		imagemBackground.scale(3, 3);
	}

	void desenharBackground(sf::RenderWindow &window){
		window.draw(imagemBackground);
	}
};



#endif /* BACKGROUND_H_ */
