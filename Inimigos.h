/*
 * Inimigos.h
 *
 *  Created on: 1 de set. de 2024
 *      Author: davia
 */

#ifndef INIMIGOS_H_
#define INIMIGOS_H_
#include "SFML/Graphics.hpp"
#include "gravidade.h"

class Inimigos {
protected:
    sf::Texture textureInimigos;
    sf::Sprite imagemInimigos;
    float x;
    float y;
    float velocidadeX;
    float velocidadeY;
    sf::Clock relogio;
    float tempoPassado;

public:
    Inimigos(float posicaoX, float posicaoY) {
        x = posicaoX;
        y = posicaoY;
        velocidadeX = 0.1f;
        velocidadeY = 0.f;
        tempoPassado = 0.f;
        textureInimigos.loadFromFile("Inimigos-TestandoPNG.png");
        imagemInimigos.setTexture(textureInimigos);
        imagemInimigos.setPosition(x, y);
        relogio.restart(); // Inicializa o relógio
    }

    void gravidade() {
        // Atualizar tempoPassado com o tempo desde o último frame
        tempoPassado = relogio.restart().asSeconds();

        // Aplicar gravidade se não estiver no chão
        if (!estaNoChao(x, y, imagemInimigos)) {
            velocidadeY += 9.81f * tempoPassado; // Acelerando devido à gravidade
            velocidadeGravidade(x, &y, imagemInimigos, velocidadeY, tempoPassado);
        } else {
            // Se estiver no chão, definir posição correta e zerar velocidadeY
            if (y + imagemInimigos.getGlobalBounds().height > 450) {
                y = 450 - imagemInimigos.getGlobalBounds().height;
            } else if (y + imagemInimigos.getGlobalBounds().height == 350 && (x < 285 || x > 672)) {
                y = 350 - imagemInimigos.getGlobalBounds().height;
            }
            velocidadeY = 0;
            imagemInimigos.setPosition(x, y);
        }
    }

    void movimentar() {
        x += velocidadeX;

        gravidade();

        if (x + imagemInimigos.getGlobalBounds().width > 957) {
            x = 0;
        }
        if (x < 0) {
            x = 957 - imagemInimigos.getGlobalBounds().width;
        }

        imagemInimigos.setPosition(x, y);
    }
};

class Tartaruga : public Inimigos {
public:
    Tartaruga() : Inimigos(100, 350) {
        imagemInimigos.setTextureRect(sf::IntRect(0, 1, 20, 15));
        imagemInimigos.scale(5, 5);
        imagemInimigos.setPosition(x, y);
    }

    void desenharTartaruga(sf::RenderWindow &window) {
        window.draw(imagemInimigos);
    }
};

class Carangueijo : public Inimigos {
public:
    Carangueijo() : Inimigos(200, 100) {
        imagemInimigos.setTextureRect(sf::IntRect(0, 20, 20, 16));
        imagemInimigos.scale(5, 5);
        imagemInimigos.setPosition(x, y);
    }

    void desenharCarangueijo(sf::RenderWindow &window) {
        window.draw(imagemInimigos);
    }
};

class Vagalume : public Inimigos {
public:
    Vagalume() : Inimigos(700, 70) {
        imagemInimigos.setTextureRect(sf::IntRect(0, 76, 20, 15));
        imagemInimigos.scale(5, 5);
        imagemInimigos.setPosition(x, y);
    }

    void desenharVagalume(sf::RenderWindow &window) {
        window.draw(imagemInimigos);
    }
};

#endif /* INIMIGOS_H_ */
