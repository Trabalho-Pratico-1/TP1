/*
 * Player.h
 *
 *  Created on: 20 de set. de 2024
 *      Author: magal
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>    // Inclui a biblioteca SFML para gráficos
#include <SFML/Window.hpp>      // Inclui a biblioteca SFML para gerenciamento de janelas
#include <SFML/System.hpp>      // Inclui a biblioteca SFML para funcionalidades do sistema
#include <iostream>             // Inclui a biblioteca para operações de entrada e saída
#include <fstream>              // Inclui a biblioteca para operações de arquivo
#include <sstream>              // Inclui a biblioteca para operações de fluxo de string
#include <vector>               // Inclui a biblioteca para uso de vetores
#include <string>               // Inclui a biblioteca para operações com strings
#include <stdexcept>            // Inclui a biblioteca para manipulação de exceções padrão
#include "GameObject.h"
// Classe derivada de GameObject para o jogador
class Player: public GameObject {
private:
	sf::Texture texturePersongem;
	sf::Sprite sprite;
public:

	// Construtor da classe que inicializa o jogador com propriedades de movimento
	Player() :
			velocity(0.0f, 0.0f), isJumping(false) {
		sf::Vector2f velocity(0.0f, 0.0f); //Define a velocidade
		gravity = 0.5f;          // Define a gravidade
		jumpForce = -12.5f;     // Define a força do salto
		speed = 300.0f;         // Define a velocidade de movimento
	}
	//Implementação do método getSprite para passar o sprite, já que ele está declarado como privado
	sf::Sprite& getSprite() {
		return this->sprite;
	}
	//Implementação do método carregarTexture para carregar a textura e o sprite e a escala da imagem
	void carregarTexture() {
		if (!texturePersongem.loadFromFile("personagem.png")) {
			std::cout << "Erro ao carregar textura." << std::endl;
		} else {
			texturePersongem.loadFromFile("personagem.png");
			sprite.setTexture(texturePersongem);
			sprite.scale(0.15, 0.15);
		}

	}

	// Implementação do método update para atualizar o estado do jogador
	void update(float deltaTime,
			const std::vector<std::vector<int>> &collisionMap, float cellWidth,
			float cellHeight) override {
		velocity.x = 0.0f; // Inicializa a velocidade horizontal
		// Atualiza a velocidade horizontal com base nas teclas pressionadas
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			velocity.x = -speed * deltaTime;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			velocity.x = speed * deltaTime;
		}

		// Atualiza a velocidade vertical se a tecla de salto for pressionada e o jogador não estiver pulando
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isJumping) {
			velocity.y = jumpForce;
			isJumping = true;
		}

		// Aplica a gravidade
		velocity.y += gravity;

		// Move a forma do jogador com base na velocidade
		sprite.move(velocity);

		posicao = sprite.getPosition(); // Obtém a posição atual do jogador
		globalBounds = sprite.getGlobalBounds();
		width = globalBounds.width;        // Obtém a largura do jogador
		height = globalBounds.height;        // Obtém a altura do jogador

		// Calcula as células da matriz de colisão que o jogador ocupa
		int cellXLeft = static_cast<int>(posicao.x / cellWidth);
		int cellXRight = static_cast<int>((posicao.x + width) / cellWidth);
		int cellYTop = static_cast<int>(posicao.y / cellHeight);
		int cellYBottom = static_cast<int>((posicao.y + height) / cellHeight);

		bool onGround = false; // Flag para verificar se o jogador está no chão

		// Verifica colisões na parte inferior do jogador
		if (collisionMap[cellYBottom][cellXLeft] != -1
				|| collisionMap[cellYBottom][cellXRight] != -1) {
			sprite.setPosition(posicao.x, cellYBottom * cellHeight - height); // Ajusta a posição do jogador para o chão
			velocity.y = 0; // Reseta a velocidade vertical
			isJumping = false; // Permite que o jogador pule novamente
			onGround = true;
		}

		// Verifica se o jogador está em colisão com o teto se não estiver no chão
		if (!onGround) {
			if (collisionMap[cellYTop][cellXLeft] != -1
					|| collisionMap[cellYTop][cellXRight] != -1) {
				sprite.setPosition(posicao.x, (cellYTop + 1) * cellHeight); // Ajusta a posição do jogador para o teto
				velocity.y = 0; // Reseta a velocidade vertical
				isJumping = false; // Permite que o jogador pule novamente
			}
		}

		// Transporte pelas bordas da janela
		if (posicao.x < 0) {
			sprite.setPosition(windowSize.x - width, posicao.y); // Teletransporta para a borda direita se sair pela esquerda

		} else if (posicao.x > windowSize.x) {
			sprite.setPosition(0, posicao.y); // Teletransporta para a borda esquerda se sair pela direita

		}

		if (posicao.y < 0) {
			sprite.setPosition(posicao.x, windowSize.y - height); // Teletransporta para a borda inferior se sair pela superior
			velocity.y = 0; // Reseta a velocidade vertical

		} else if (posicao.y > windowSize.y) {
			sprite.setPosition(posicao.x, 0); // Teletransporta para a borda superior se sair pela inferior

		}

	}

	sf::Vector2f windowSize; // Tamanho da janela para transporte
	sf::Vector2f velocity;   // Velocidade do jogador
	bool isJumping;          // Flag para verificar se o jogador está pulando
	float gravity;           // Gravidade aplicada ao jogador
	float jumpForce;        // Força do salto
	float speed;            // Velocidade de movimento do jogador

};

#endif /* PLAYER_H_ */
