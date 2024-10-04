/*
 * Plataformas.h
 *
 *  Created on: 2 de out. de 2024
 *      Author: magal
 */

#ifndef PLATAFORMAS_H_
#define PLATAFORMAS_H_
#include <SFML/Graphics.hpp>    // Inclui a biblioteca SFML para gráficos
#include <SFML/Window.hpp>      // Inclui a biblioteca SFML para gerenciamento de janelas
#include <SFML/System.hpp>      // Inclui a biblioteca SFML para funcionalidades do sistema
#include <iostream>             // Inclui a biblioteca para operações de entrada e saída
#include <fstream>              // Inclui a biblioteca para operações de arquivo
#include <sstream>              // Inclui a biblioteca para operações de fluxo de string
#include <vector>               // Inclui a biblioteca para uso de vetores
#include <string>               // Inclui a biblioteca para operações com strings
using namespace std;
class Plataformas {
public:
	bool colisaoPlayerPlataformaTartaruga(Player player, Tartaruga tartaruga,
			const std::vector<std::vector<int>> &collisionMap, float cellWidth,
			float cellHeight) {
		bool aconteceuColisao = false;
		//Calcula as células da matriz de colisão que o jogador ocupa
		int cellXLeftPlayer = static_cast<int>(player.posicao.x / cellWidth);
		int cellYTopPlayer = static_cast<int>(player.posicao.y / cellHeight);

		//Calcula as células da matriz de colisão que a tartaruga ocupa
		int cellXLeftTartaruga = static_cast<int>(tartaruga.posicao.x
				/ cellWidth);
		int cellYBottomTartaruga = static_cast<int>((tartaruga.posicao.y
				+ player.height) / cellHeight);

		//Verifica colisão com a tartaruga
		if (collisionMap[cellYBottomTartaruga][cellXLeftTartaruga] == 20) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 20) {
				if (player.posicao.x >= tartaruga.posicao.x
						and player.posicao.x
								<= tartaruga.posicao.x + tartaruga.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomTartaruga][cellXLeftTartaruga] == 22) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 22) {
				if (player.posicao.x >= tartaruga.posicao.x
						and player.posicao.x
								<= tartaruga.posicao.x + tartaruga.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomTartaruga][cellXLeftTartaruga] == 24) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 24) {
				if (player.posicao.x >= tartaruga.posicao.x
						and player.posicao.x
								<= tartaruga.posicao.x + tartaruga.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomTartaruga][cellXLeftTartaruga] == 25) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 25) {
				if (player.posicao.x >= tartaruga.posicao.x
						and player.posicao.x
								<= tartaruga.posicao.x + tartaruga.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomTartaruga][cellXLeftTartaruga] == 26) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 26) {
				if (player.posicao.x >= tartaruga.posicao.x
						and player.posicao.x
								<= tartaruga.posicao.x + tartaruga.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomTartaruga][cellXLeftTartaruga] == 41) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 41) {
				if (player.posicao.x >= tartaruga.posicao.x
						and player.posicao.x
								<= tartaruga.posicao.x + tartaruga.width) {
					aconteceuColisao = true;
				}
			}
		}

		return aconteceuColisao;
	}

	bool colisaoPlayerPlataformaVagalume(Player player, Vagalume vagalume,
			const std::vector<std::vector<int>> &collisionMap, float cellWidth,
			float cellHeight) {
		bool aconteceuColisao = false;
		//Calcula as células da matriz de colisão que o jogador ocupa
		int cellXLeftPlayer = static_cast<int>(player.posicao.x / cellWidth);
		int cellYTopPlayer = static_cast<int>(player.posicao.y / cellHeight);
		//Calcula as células da matriz de colisão que o vagalume ocupa
		int cellXLeftVagalume = static_cast<int>(vagalume.posicao.x / cellWidth);
		int cellYBottomVagalume = static_cast<int>((vagalume.posicao.y
				+ player.height) / cellHeight);
		//Verifica colisão com o vagalume
		if (collisionMap[cellYBottomVagalume][cellXLeftVagalume] == 20) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 20) {
				if (player.posicao.x >= vagalume.posicao.x
						and player.posicao.x
								<= vagalume.posicao.x + vagalume.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomVagalume][cellXLeftVagalume] == 22) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 22) {
				if (player.posicao.x >= vagalume.posicao.x
						and player.posicao.x
								<= vagalume.posicao.x + vagalume.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomVagalume][cellXLeftVagalume] == 24) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 24) {
				if (player.posicao.x >= vagalume.posicao.x
						and player.posicao.x
								<= vagalume.posicao.x + vagalume.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomVagalume][cellXLeftVagalume] == 25) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 25) {
				if (player.posicao.x >= vagalume.posicao.x
						and player.posicao.x
								<= vagalume.posicao.x + vagalume.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomVagalume][cellXLeftVagalume] == 26) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 26) {
				if (player.posicao.x >= vagalume.posicao.x
						and player.posicao.x
								<= vagalume.posicao.x + vagalume.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomVagalume][cellXLeftVagalume] == 41) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 41) {
				if (player.posicao.x >= vagalume.posicao.x
						and player.posicao.x
								<= vagalume.posicao.x + vagalume.width) {
					aconteceuColisao = true;
				}
			}
		}

		return aconteceuColisao;

	}

	bool colisaoPlayerPlataformaCaranguejo(Player player, Caranguejo caranguejo,
			const std::vector<std::vector<int>> &collisionMap, float cellWidth,
			float cellHeight) {
		bool aconteceuColisao = false;
		//Calcula as células da matriz de colisão que o caranguejo ocupa
		int cellXLeftCaranguejo = static_cast<int>(caranguejo.posicao.x
				/ cellWidth);
		int cellYBottomCaranguejo = static_cast<int>((caranguejo.posicao.y
				+ player.height) / cellHeight);

		//Calcula as células da matriz de colisão que o jogador ocupa
		int cellXLeftPlayer = static_cast<int>(player.posicao.x / cellWidth);
		int cellYTopPlayer = static_cast<int>(player.posicao.y / cellHeight);

		//Verifica colisão com o caranguejo
		if (collisionMap[cellYBottomCaranguejo][cellXLeftCaranguejo] == 20) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 20) {
				if (player.posicao.x >= caranguejo.posicao.x
						and player.posicao.x
								<= caranguejo.posicao.x + caranguejo.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomCaranguejo][cellXLeftCaranguejo] == 22) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 22) {
				if (player.posicao.x >= caranguejo.posicao.x
						and player.posicao.x
								<= caranguejo.posicao.x + caranguejo.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomCaranguejo][cellXLeftCaranguejo] == 24) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 24) {
				if (player.posicao.x >= caranguejo.posicao.x
						and player.posicao.x
								<= caranguejo.posicao.x + caranguejo.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomCaranguejo][cellXLeftCaranguejo] == 25) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 25) {
				if (player.posicao.x >= caranguejo.posicao.x
						and player.posicao.x
								<= caranguejo.posicao.x + caranguejo.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomCaranguejo][cellXLeftCaranguejo] == 26) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 26) {
				if (player.posicao.x >= caranguejo.posicao.x
						and player.posicao.x
								<= caranguejo.posicao.x + caranguejo.width) {
					aconteceuColisao = true;
				}
			}
		}
		if (collisionMap[cellYBottomCaranguejo][cellXLeftCaranguejo] == 41) {
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 41) {
				if (player.posicao.x >= caranguejo.posicao.x
						and player.posicao.x
								<= caranguejo.posicao.x + caranguejo.width) {
					aconteceuColisao = true;
				}
			}
		}
		return aconteceuColisao;

	}
};

#endif /* PLATAFORMAS_H_ */
