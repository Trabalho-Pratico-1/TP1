/*
 * Botoes.h
 *
 *  Created on: 14 de ago. de 2024
 *      Author: davia
 */

#ifndef BOTOES_H_
#define BOTOES_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Botoes {
public:
	sf::RectangleShape botao;
	sf::Text texto;

    void configurarCor(const sf::Color& cor) {
        botao.setFillColor(cor);
    }

    bool mousePassar(const sf::RenderWindow& window) {
        sf::Vector2i posicaoMouse = sf::Mouse::getPosition(window);
        sf::FloatRect limite = botao.getGlobalBounds();
        return limite.contains(static_cast<sf::Vector2f>(posicaoMouse));
    }
    void desenhar (sf::RenderWindow& window){
        window.draw(botao);
        window.draw(texto);
    }
    void posicaoTexto() {
        texto.setPosition(botao.getPosition());
    }
    void trocarCorBotao(sf::RenderWindow& window){
        if (mousePassar(window)) {
            configurarCor(sf::Color(255, 0, 0));
        } else {
            configurarCor(sf::Color(0, 0, 0));
        }
    }
};


#endif /* BOTOES_H_ */
