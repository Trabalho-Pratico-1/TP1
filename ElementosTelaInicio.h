/*
 * TelaInicio.h
 *
 *  Created on: 14 de ago. de 2024
 *      Author: davia
 */

#ifndef ELEMENTOSTELAINICIO_H_
#define ELEMENTOSTELAINICIO_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "Janela.h"

class ElementosTelaInicio : public Janela {
protected:
    sf::Sound som;
    sf::SoundBuffer buffer;
    sf::Texture textura;
    sf::Font fonte;

public:
    ElementosTelaInicio(const std::string& entradaMusica, const std::string& entradaFundo, const std::string& entradaFonte): Janela() {
        if (!buffer.loadFromFile(entradaMusica)) {
            std::cerr << "Erro ao carregar arquivo de áudio." << std::endl;
        } else {
            som.setBuffer(buffer);
            som.play();
        }

        if (!textura.loadFromFile(entradaFundo)) {
            std::cerr << "Erro ao carregar arquivo de imagem." << std::endl;
        }

        if (!fonte.loadFromFile(entradaFonte)) {
            std::cerr << "Erro ao carregar arquivo de fonte." << std::endl;
        }
    }
};

#endif /* ELEMENTOSTELAINICIO_H_ */
