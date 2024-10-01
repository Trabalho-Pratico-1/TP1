/*
 * runGame.h
 *
 *  Created on: 21 de set. de 2024
 *      Author: magal
 */

#ifndef RUNGAME_H_
#define RUNGAME_H_
#include <SFML/Graphics.hpp>    // Inclui a biblioteca SFML para gráficos
#include <SFML/Window.hpp>      // Inclui a biblioteca SFML para gerenciamento de janelas
#include <SFML/System.hpp>      // Inclui a biblioteca SFML para funcionalidades do sistema
#include <iostream>             // Inclui a biblioteca para operações de entrada e saída
#include <fstream>              // Inclui a biblioteca para operações de arquivo
#include <sstream>              // Inclui a biblioteca para operações de fluxo de string
#include <vector>               // Inclui a biblioteca para uso de vetores
#include <string>               // Inclui a biblioteca para operações com strings
#include <stdexcept>            // Inclui a biblioteca para manipulação de exceções padrão
#include "Player.h"				//Inclui o arquivo que guarda os atributos e métodos do jogador
#include "Inimigos.h"			//Inclui o arquivo que guarda os atributos e métodos dos inimigos
// Função para carregar o mapa de colisão a partir de um arquivo CSV
std::vector<std::vector<int>> loadCollisionsFromCSV(
		const std::string &filename) {
	std::vector<std::vector<int>> collisionMap; // Mapa de colisão
	std::ifstream file(filename); // Abre o arquivo CSV
	std::string line; // Linha lida do arquivo

	if (!file.is_open()) {
		throw std::runtime_error("Erro ao abrir o arquivo CSV"); // Lança uma exceção se o arquivo não puder ser aberto
	}

	while (std::getline(file, line)) { // Lê o arquivo linha por linha
		std::vector<int> row; // Linha do mapa de colisão
		std::stringstream ss(line); // Cria um fluxo de string para processar a linha
		std::string cell; // Célula da linha

		while (std::getline(ss, cell, ',')) { // Lê cada célula separada por vírgula
			row.push_back(std::stoi(cell)); // Converte string para int e adiciona à linha
		}
		collisionMap.push_back(row);  // Adiciona a linha ao mapa
	}

	return collisionMap; // Retorna o mapa de colisão
}

//Função que recebe o jogador e o inimigo e verifica se há colisão entre eles
bool colisaoInimigoPlayer(Player player, Inimigos tartaruga) {
	bool colisao = false;

	if (player.posicao.x + player.width > tartaruga.posicao.x
			and tartaruga.posicao.x + tartaruga.width > player.posicao.x
			and tartaruga.posicao.y + tartaruga.height > player.posicao.y
			and player.posicao.y + player.height > tartaruga.posicao.y) {
		colisao = true;
	} else {
		colisao = false;
	}
	return colisao;
}

bool colisaoPlayerPlataformaInimigo(Player player, Inimigos tartaruga) {
	bool aconteceuColisao;
	if (player.pulo == true) {
		if (tartaruga.onGround == true) {
			if (tartaruga.posicao.x >= player.posicao.x
					and player.posicao.x <= tartaruga.posicao.x) {
				aconteceuColisao = true;
				std::cout << "Player colidiu com Inimigo" << std::endl;
			}
		}
	} else {
		aconteceuColisao = false;
	}
	return aconteceuColisao;
}

// Função principal para executar o jogo
void runGame(const std::string &csvFile, const std::string &mapImageFile) {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Jogo com Colisões"); // Cria a janela do jogo
	window.setFramerateLimit(60); // Limita os FPS para evitar sobrecarga

// Carregar o mapa de colisão a partir do CSV
	std::vector<std::vector<int>> collisionMap = loadCollisionsFromCSV(csvFile); // Carrega o mapa de colisão
	int mapWidth = collisionMap[0].size(); // Largura do mapa
	int mapHeight = collisionMap.size(); // Altura do mapa

// Calcula o tamanho de cada célula do mapa de colisão com base no tamanho da janela
	float cellWidth = static_cast<float>(window.getSize().x) / mapWidth;
	float cellHeight = static_cast<float>(window.getSize().y) / mapHeight;

// Carregar textura do mapa
	sf::Texture mapTexture;
	if (!mapTexture.loadFromFile(mapImageFile)) {
		throw std::runtime_error("Erro ao carregar a imagem do mapa"); // Lança uma exceção se a imagem não puder ser carregada
	}
	sf::Sprite mapSprite(mapTexture); // Cria um sprite para o mapa
	mapSprite.setScale(
			window.getSize().x / static_cast<float>(mapTexture.getSize().x),
			window.getSize().y / static_cast<float>(mapTexture.getSize().y)); // Ajusta a escala do sprite para preencher a janela

// Criar o personagem
	Player player; // Cria o jogador
	player.carregarTexture();
	player.windowSize = sf::Vector2f(window.getSize()); // Define o tamanho da janela para o jogador

	//Tartaruga tartaruga; //Cria o inimigo tartaruga
	Vagalume vagalume;

	sf::Clock clock;  // Relógio para medir o tempo delta

// Loop principal do jogo
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close(); // Fecha a janela se o evento de fechamento for recebido
		}

		// Calcular o tempo delta (tempo desde o último frame)
		float deltaTime = clock.restart().asSeconds();

		// Atualizar o personagem
		player.update(deltaTime, collisionMap, cellWidth, cellHeight);
		//Aturalizar inimigos
		//tartaruga.update(deltaTime, collisionMap, cellWidth, cellHeight);
		vagalume.pular();
		vagalume.update(deltaTime, collisionMap, cellWidth, cellHeight);

		window.clear(); // Limpa a janela

		// Desenhar o mapa
		window.draw(mapSprite);

		// Desenhar o personagem
		window.draw(player.getSprite());
		//Desenhar inimigos
		//tartaruga.desenharTartaruga(window);
		vagalume.desenharVagalume(window);
		/*for (int i = 4; i >= 0; i--) {
		 player.vidas[i] = i;
		 }
		 if (colisaoInimigoPlayer(player, tartaruga) == true) {
		 player.vidas--;
		 }
		 std::cout<<"Vidas:"<<player.vidas<<std::endl;
		 if (player.vidas == 0) {
		 std::cout << "GAME OVER" << std::endl;
		 window.close(); // Fecha a janela se o evento de fechamento for recebido
		 }
		 */
		//colisaoPlayerPlataformaInimigo(player, tartaruga);
		//std::cout<<"Pulo: "<<player.pulo<<std::endl;
		window.display(); // Exibe o conteúdo renderizado na janela
	}
}

#endif /* RUNGAME_H_ */
