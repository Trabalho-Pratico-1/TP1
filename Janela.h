/*
 * Janela.h
 *
 *  Created on: 14 de ago. de 2024
 *      Author: davia
 */

#ifndef JANELA_H_
#define JANELA_H_

#include <SFML/Graphics.hpp>

class Janela {
protected:
    int parteJogo;
    sf::RenderWindow window;
public:
    Janela() : window(sf::VideoMode(1080, 720), "Jogo", sf::Style::Close), parteJogo(0) {}
};

#endif
