/*
 * GameOver.h
 *
 *  Created on: 7 de out. de 2024
 *      Author: magal
 */

#ifndef GAMEOVER_H_
#define GAMEOVER_H_


#include <SFML/Graphics.hpp>

class GameOver {
protected:
	sf::Texture textureGameOver;
	sf::Sprite imagemGameOver;

public:
	GameOver() {
		textureGameOver.loadFromFile("marioGameOver.jpg");
		imagemGameOver.setTexture(textureGameOver);
		imagemGameOver.scale(1, 1);
	}

	void desenharGameOver(sf::RenderWindow &window) {
		window.draw(imagemGameOver);
	}
};


#endif /* GAMEOVER_H_ */
