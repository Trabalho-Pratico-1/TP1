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
    sf::RenderWindow janela;
public:
    Janela() : janela(sf::VideoMode(800, 600), "Jogo"), parteJogo(0) {}
};

#endif
