/*
 * Background.h
 *
 *  Created on: 30 de ago. de 2024
 *      Author: davia
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <SFML/Graphics.hpp>

class Background {
private:
	sf::Texture textureBackground;
	sf::Sprite imagemBackground;

public:
	void BackgroundGameOver() {
		textureBackground.loadFromFile("marioGameOver.jpg");
		imagemBackground.setTexture(textureBackground);
		imagemBackground.scale(0.6, 0.6);
	}

	void BackgroundMenu() {
		textureBackground.loadFromFile("marioMenu.jpg");
		imagemBackground.setTexture(textureBackground);
		imagemBackground.scale(0.4, 0.4);
	}

	void desenharBackground(sf::RenderWindow &window) {
		window.draw(imagemBackground);
	}
};

#endif /* BACKGROUND_H_ */
