/*
 * Background.h
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <SFML/Graphics.hpp>

class Background {
protected:
	sf::Texture textureBackground;
	sf::Sprite imagemBackground;

public:
	Background() {
		textureBackground.loadFromFile("marioMenu.jpg");
		imagemBackground.setTexture(textureBackground);
		imagemBackground.scale(1, 1);
	}

	void desenharBackground(sf::RenderWindow &window) {
		window.draw(imagemBackground);
	}
};
#endif /* BACKGROUND_H_ */
