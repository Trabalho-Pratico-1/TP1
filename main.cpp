#include "runGame.h"

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

