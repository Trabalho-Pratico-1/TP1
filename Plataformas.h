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
#include <stdexcept>            // Inclui a biblioteca para manipulação de exceções padrão
using namespace std;
class Plataformas {
public:
	void colisaoPlayerPlataformaInimigo(Player player, Inimigos tartaruga, float deltaTime,
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

		if (collisionMap[cellYBottomTartaruga][cellXLeftTartaruga] == 20) //Inimigos
				//Player
				{
			if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 20) {
				if (player.posicao.x >= tartaruga.posicao.x
						and player.posicao.x
								<= tartaruga.posicao.x + tartaruga.width) {
					aconteceuColisao = true;
					std::cout << "Player colidiu com Inimigo" << std::endl;
				}
			}
		}
		if (collisionMap[cellYBottomTartaruga][cellXLeftTartaruga] == 22) //Inimigos
					//Player
					{
				if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 22) {
					if (player.posicao.x >= tartaruga.posicao.x
							and player.posicao.x
									<= tartaruga.posicao.x + tartaruga.width) {
						aconteceuColisao = true;
						std::cout << "Player colidiu com Inimigo" << std::endl;
					}
				}
			}
		if (collisionMap[cellYBottomTartaruga][cellXLeftTartaruga] == 24) //Inimigos
					//Player
					{
				if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 24) {
					if (player.posicao.x >= tartaruga.posicao.x
							and player.posicao.x
									<= tartaruga.posicao.x + tartaruga.width) {
						aconteceuColisao = true;
						std::cout << "Player colidiu com Inimigo" << std::endl;
					}
				}
			}
		if (collisionMap[cellYBottomTartaruga][cellXLeftTartaruga] == 25) //Inimigos
					//Player
					{
				if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 25) {
					if (player.posicao.x >= tartaruga.posicao.x
							and player.posicao.x
									<= tartaruga.posicao.x + tartaruga.width) {
						aconteceuColisao = true;
						std::cout << "Player colidiu com Inimigo" << std::endl;
					}
				}
			}
		if (collisionMap[cellYBottomTartaruga][cellXLeftTartaruga] == 26) //Inimigos
					//Player
					{
				if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 26) {
					if (player.posicao.x >= tartaruga.posicao.x
							and player.posicao.x
									<= tartaruga.posicao.x + tartaruga.width) {
						aconteceuColisao = true;
						std::cout << "Player colidiu com Inimigo" << std::endl;
					}
				}
			}
		if (collisionMap[cellYBottomTartaruga][cellXLeftTartaruga] == 41) //Inimigos
					//Player
					{
				if (collisionMap[cellYTopPlayer][cellXLeftPlayer] == 41) {
					if (player.posicao.x >= tartaruga.posicao.x
							and player.posicao.x
									<= tartaruga.posicao.x + tartaruga.width) {
						aconteceuColisao = true;
						std::cout << "Player colidiu com Inimigo" << std::endl;
					}
				}
			}
	}
};

#endif /* PLATAFORMAS_H_ */
