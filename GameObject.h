/*
 * GameObject.h
 *
 *  Created on: 20 de set. de 2024
 *      Author: magal
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SFML/Graphics.hpp>    // Inclui a biblioteca SFML para gráficos
#include <SFML/Window.hpp>      // Inclui a biblioteca SFML para gerenciamento de janelas
#include <SFML/System.hpp>      // Inclui a biblioteca SFML para funcionalidades do sistema
#include <iostream>             // Inclui a biblioteca para operações de entrada e saída
#include <fstream>              // Inclui a biblioteca para operações de arquivo
#include <sstream>              // Inclui a biblioteca para operações de fluxo de string
#include <vector>               // Inclui a biblioteca para uso de vetores
#include <string>               // Inclui a biblioteca para operações com strings
#include <stdexcept>            // Inclui a biblioteca para manipulação de exceções padrão
// Classe base para objetos do jogo
class GameObject {
public:
	// Método virtual puro que deve ser implementado por classes derivadas
	virtual void update(float deltaTime,
			const std::vector<std::vector<int>> &collisionMap, float cellWidth,
			float cellHeight) = 0;

};


#endif /* GAMEOBJECT_H_ */
