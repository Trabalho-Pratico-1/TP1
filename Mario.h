<<<<<<< Updated upstream
/*
 * Mario.h
 *
 *  Created on: 30 de ago. de 2024
 *      Author: davia
 */

#ifndef MARIO_H_
#define MARIO_H_

#include <SFML/Graphics.hpp>
class Mario{
private:
	sf::Texture texturePersongem;
	sf::Sprite imagemPersonagem;
	//int x, y, velocidadex, velocidadey;

public:
	Mario(){
		texturePersongem.loadFromFile("personagem.png");
		imagemPersonagem.setTexture(texturePersongem);
		imagemPersonagem.setPosition(200, 550);
		imagemPersonagem.scale(0.15, 0.15);
	}

	void desenharMario(sf::RenderWindow &window){
		 window.draw(imagemPersonagem);
	}
};



#endif /* MARIO_H_ */
=======
/*
 * Mario.h
 *
 *  Created on: 3 de set. de 2024
 *      Author: davia
 */

#ifndef MARIO_H_
#define MARIO_H_
#include "SFML/Graphics.hpp"
#include "gravidade.h"

class Mario {
protected:
    sf::Texture textureMario;
    sf::Sprite imagemMario;
    float x;
    float y;
    float velocidadeX;
    float velocidadeY;
    float velocidadePulo; // Velocidade inicial do pulo
    bool estaPulando;     // Estado de pulo
    sf::Clock relogio;
    float tempoPassado;

public:
    Mario() {
        x = 200;
        y = 450;
        velocidadeX = 0.0f;   // Inicializa sem movimento horizontal
        velocidadeY = 0.f;
        velocidadePulo = -981.0f; // Velocidade de pulo (negativa para subir)
        estaPulando = false;
        tempoPassado = 0.f;
        textureMario.loadFromFile("Super-Mario-Bros.png");
        imagemMario.setTexture(textureMario);
        imagemMario.setPosition(x, y);
        imagemMario.scale(0.15, 0.15);
        relogio.restart();
    }

    void gravidade() {
        tempoPassado = relogio.restart().asSeconds();

        if (!estaNoChao(x, y, imagemMario)) {
            // Aplica gravidade se não estiver no chão
            velocidadeY += 981.0f * tempoPassado; // Ajuste para pixels por segundo ao quadrado
            y += velocidadeY * tempoPassado;
            imagemMario.setPosition(x, y);
        } else {
            // Se estiver no chão, resetar a velocidadeY e o estado de pulo
            if (estaPulando) {
                velocidadeY = 0;
                estaPulando = false;
            }

            // Corrige a posição para o nível do chão
            if (y + imagemMario.getGlobalBounds().height > 450) {
                y = 450 - imagemMario.getGlobalBounds().height;
            } else if (y + imagemMario.getGlobalBounds().height == 350 && (x < 285 || x > 672)) {
                y = 350 - imagemMario.getGlobalBounds().height;
            }

            imagemMario.setPosition(x, y);
        }
    }

    void pular() {
        if (!estaPulando && estaNoChao(x, y, imagemMario)) {
            estaPulando = true;
            velocidadeY = velocidadePulo; // Inicia o pulo com a velocidade inicial negativa
        }
    }

    void movimentarEsquerda() {
        velocidadeX = -10.f; // Velocidade para a esquerda
        x += velocidadeX;
        imagemMario.setPosition(x, y);
    }

    void movimentarDireita() {
        velocidadeX = 10.f; // Velocidade para a direita
        x += velocidadeX;
        imagemMario.setPosition(x, y);
    }

    void atualizarMovimento() {
        // Atualiza o movimento horizontal e aplica gravidade
        gravidade();

        if (x + imagemMario.getGlobalBounds().width > 957) {
            x = 0;
        }
        if (x < 0) {
            x = 957 - imagemMario.getGlobalBounds().width;
        }

        imagemMario.setPosition(x, y);
    }

    void desenharMario(sf::RenderWindow &window) {
        window.draw(imagemMario);
    }
};

#endif /* MARIO_H_ */
>>>>>>> Stashed changes
