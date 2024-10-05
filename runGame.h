/*
 * runGame.h
 *
 *  Created on: 21 de set. de 2024
 *      Author: magal
 */
#ifndef RUNGAME_H_
#define RUNGAME_H_
#include "Player.h"				//Inclui o arquivo que guarda os atributos e métodos do jogador
#include "Inimigos.h"			//Inclui o arquivo que guarda os atributos e métodos dos inimigos
#include "Plataformas.h"		//Inclui o arquivo que guarda os atributos e métodos das plataformas
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

//Funções que recebem o jogador e o inimigo e verifica se há colisão entre eles
bool colisaoInimigoTartarugaPlayer(Player player, Tartaruga tartaruga) {
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

bool colisaoInimigoCaranguejoPlayer(Player player, Caranguejo caranguejo) {
	bool colisao = false;

	if (player.posicao.x + player.width > caranguejo.posicao.x
			and caranguejo.posicao.x + caranguejo.width > player.posicao.x
			and caranguejo.posicao.y + caranguejo.height > player.posicao.y
			and player.posicao.y + player.height > caranguejo.posicao.y) {
		colisao = true;
	} else {
		colisao = false;
	}
	return colisao;
}

bool colisaoInimigoVagalumePlayer(Player player, Vagalume vagalume) {
	bool colisao = false;

	if (player.posicao.x + player.width > vagalume.posicao.x
			and vagalume.posicao.x + vagalume.width > player.posicao.x
			and vagalume.posicao.y + vagalume.height > player.posicao.y
			and player.posicao.y + player.height > vagalume.posicao.y) {
		colisao = true;
	} else {
		colisao = false;
	}
	return colisao;
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

	Plataformas plataformas;
// Criar os personagens
	Player player; // Cria o jogador
	player.carregarTexture();
	player.windowSize = sf::Vector2f(window.getSize()); // Define o tamanho da janela para o jogador

	Fogo fogo;
	Tartaruga tartaruga; //Cria o inimigo tartaruga
	Vagalume vagalume;
	Caranguejo caranguejo;
	sf::Clock clock;  // Relógio para medir o tempo delta
	//float duracao;

// Loop principal do jogo
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close(); // Fecha a janela se o evento de fechamento for recebido
		}

		// Calcular o tempo delta (tempo desde o último frame)
		float deltaTime = clock.restart().asSeconds();
		//sf::Time time = clock.restart();

		// Atualizar os personagens
		player.update(deltaTime, collisionMap, cellWidth, cellHeight);
		fogo.update(deltaTime, collisionMap, cellWidth, cellHeight);
		tartaruga.update(deltaTime, collisionMap, cellWidth, cellHeight);
		vagalume.pular();
		vagalume.update(deltaTime, collisionMap, cellWidth, cellHeight);
		caranguejo.update(deltaTime, collisionMap, cellWidth, cellHeight);

		window.clear(); // Limpa a janela

		// Desenhar o mapa
		window.draw(mapSprite);

		// Desenhar o personagem
		window.draw(player.getSprite());

		//fogo.desenharFogo(window);
		//Desenhar inimigos
//Analisa a colisão entre a tartaruga e o player


		if (colisaoInimigoTartarugaPlayer(player, tartaruga) == true) {
			if (tartaruga.vivo == true) {
				player.getSprite().setPosition(0.0f, 480.0f);
				player.vidas--;
			}
			if (tartaruga.vivo == false) {
				player.pontos = player.pontos + 100;
				std::cout << "Pontos: " << player.pontos << std::endl;
				tartaruga.morrerDefinitivamente();
				tartaruga.renascer();
			}
		}
<<<<<<< Updated upstream
=======
<<<<<<< HEAD

			       // std::cout << duracao << std::endl;

=======
>>>>>>> 761bc71690a730f776124527c552b287ee4702f4
>>>>>>> Stashed changes
		if (tartaruga.vivo == true) {
			if (plataformas.colisaoPlayerPlataformaTartaruga(player, tartaruga,
					collisionMap, cellWidth, cellHeight) == true) {
				tartaruga.morrer();
			}
		}
<<<<<<< Updated upstream
//		tartaruga.desenharTartaruga(window);
=======
<<<<<<< HEAD

		tartaruga.desenharTartaruga(window);

=======
//		tartaruga.desenharTartaruga(window);
>>>>>>> 761bc71690a730f776124527c552b287ee4702f4
>>>>>>> Stashed changes
//Analisa a colisão entre vagalume e o player
		if (colisaoInimigoVagalumePlayer(player, vagalume) == true) {
			if (vagalume.vivo == true) {
				player.getSprite().setPosition(0.0f, 480.0f);
				player.vidas--;
			}
			if (vagalume.vivo == false) {
				player.pontos = player.pontos + 100;
				std::cout << "Pontos: " << player.pontos << std::endl;
				vagalume.morrerDefinitivamente();
				vagalume.renascer();
			}
		}

		if (vagalume.vivo == true) {
			if (plataformas.colisaoPlayerPlataformaVagalume(player, vagalume,
					collisionMap, cellWidth, cellHeight) == true) {
				vagalume.morrer();
			}
		}

		//vagalume.desenharVagalume(window);

//Analisa a colisão entre caranguejo e o player
		if (colisaoInimigoCaranguejoPlayer(player, caranguejo) == true) {
			if (caranguejo.vivo == true) {
				player.getSprite().setPosition(0.0f, 480.0f);
				player.vidas--;
			}
			if (caranguejo.vivo == false) {
				caranguejo.morrerDefinitivamente();
				caranguejo.renascer();
				player.pontos = player.pontos + 100;
				std::cout << "Pontos: " << player.pontos << std::endl;
			}
		}

		if (caranguejo.vivo == true) {
			if (plataformas.colisaoPlayerPlataformaCaranguejo(player,
					caranguejo, collisionMap, cellWidth, cellHeight) == true) {
				caranguejo.morrer();
			}
		}

		caranguejo.desenharCaranguejo(window);

		if (player.vidas == 0) {
			window.clear(sf::Color::Blue);
		}

		window.display(); // Exibe o conteúdo renderizado na janela
	}
}

#endif /* RUNGAME_H_ */
