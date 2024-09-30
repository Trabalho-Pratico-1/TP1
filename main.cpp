#include <SFML/Graphics.hpp>    // Inclui a biblioteca SFML para gráficos
#include <SFML/Window.hpp>      // Inclui a biblioteca SFML para gerenciamento de janelas
#include <SFML/System.hpp>      // Inclui a biblioteca SFML para funcionalidades do sistema
#include <iostream>             // Inclui a biblioteca para operações de entrada e saída
#include <fstream>              // Inclui a biblioteca para operações de arquivo
#include <sstream>              // Inclui a biblioteca para operações de fluxo de string
#include <vector>               // Inclui a biblioteca para uso de vetores
#include <string>               // Inclui a biblioteca para operações com strings
#include <stdexcept>            // Inclui a biblioteca para manipulação de exceções padrão
#include "runGame.h"
/*
 *
 *Este código usa como base o código comitado no github no dia 18/09
 * -> A forma como eles morrem - isso envolve a colisão deles com o Mário e com a plataforma
 * -> Os básicos que temos que fazer são: a tartaruga, o caranguejo e o vagalume
 * -> Também tem uma bola de fogo que se movimenta na diagonal
 * Tem um botão que faz com que os inimigos caiam, mas tem um limite de vezes que ele pode ser acionado
 * Também falta a contagem de pontos e de tempo
 *
 */

// Função principal do programa
int main() {
	try {
		// Caminho do arquivo CSV e imagem do mapa
		std::string csvFile = "mapa_Colisao.csv";
		std::string mapImageFile = "map.png";

		// Executa o jogo
		runGame(csvFile, mapImageFile);
	} catch (const std::exception &e) {
		std::cout << "Erro: " << e.what() << std::endl; // Exibe a mensagem de erro se uma exceção for lançada
		return EXIT_FAILURE; // Retorna falha na execução
	}

	return EXIT_SUCCESS; // Retorna sucesso na execução
}
