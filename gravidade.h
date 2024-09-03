/*
 * gravidade.h
 *
 *  Created on: 2 de set. de 2024
 *      Author: davia
 */

#ifndef GRAVIDADE_H_
#define GRAVIDADE_H_
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

bool estaNoChao(float x, float y, const sf::Sprite& sprite){
    float spriteWidth = sprite.getGlobalBounds().width;
    float spriteHeight = sprite.getGlobalBounds().height;

    if (y + spriteHeight > 450) {
        return true;
    }

    if (y + spriteHeight == 350 && (x < 285 || x > 672)) {
        return true;
    }

    return false;
}

void velocidadeGravidade(float x, float* y, sf::Sprite& sprite, const float velocidadeY, const float tempoPassado){
    *y += velocidadeY * tempoPassado + 5 * tempoPassado * tempoPassado;
    sprite.setPosition(x, *y);
}

#endif /* GRAVIDADE_H_ */
