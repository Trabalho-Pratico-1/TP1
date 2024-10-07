#ifndef CARREGARJOGO_H_
#define CARREGARJOGO_H_

#include "ElementosTelaInicio.h"
#include "Botoes.h"
#include "Background.h"
#include "Inimigos.h"
#include "runGame.h"
#include <iostream>

enum class Fase {
	MENU_INICIAL, FASE1
};

class CarregarJogo: public ElementosTelaInicio {
protected:
	Botoes botaoJogar;
	sf::Sprite background;
	float escalaX;
	float escalaY;
	Fase faseAtual;

public:
	CarregarJogo() :
			ElementosTelaInicio("marioMenu.jpg", "SuperMarioBros.2.ttf"), background(
					textura), escalaX(
					static_cast<float>(janela.getSize().x)
							/ background.getLocalBounds().width), escalaY(
					static_cast<float>(janela.getSize().y)
							/ background.getLocalBounds().height), faseAtual(
					Fase::MENU_INICIAL) {

		background.setScale(escalaX, escalaY);
	}

	void telaInicio() {
		botaoJogar.botao.setSize(sf::Vector2f(200.f, 80.f));
		botaoJogar.botao.setPosition((janela.getSize().x / 2.5),
				janela.getSize().y - janela.getSize().y / 2);
		botaoJogar.texto.setFont(fonte);
		botaoJogar.texto.setString("Jogar");
		botaoJogar.texto.setCharacterSize(25);
		botaoJogar.posicaoTexto();

		while (janela.isOpen()) {
			if (faseAtual != Fase::MENU_INICIAL) {
				break;
			}

			botaoJogar.trocarCorBotao(janela);

			sf::Event event;
			while (janela.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					janela.close();
				}

				if (botaoJogar.mousePassar(janela)
						&& sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					faseAtual = Fase::FASE1;
					break;
				}
			}

			janela.clear();
			if (faseAtual == Fase::MENU_INICIAL) {
				janela.draw(background);
				botaoJogar.desenhar(janela);
			}
			janela.display();
		}
	}

	void executarJogo() {
		while (janela.isOpen()) {
			switch (faseAtual) {
			case Fase::MENU_INICIAL:
				telaInicio();
				break;
			case Fase::FASE1:
				janela.close();
				desenharFase1();
				break;
			default:
				janela.close();
				break;
			}
		}
	}

	int desenharFase1() {
		try {
			// Caminho do arquivo CSV e imagem do mapa
			std::string csvFile = "mapa_Colisao.csv";
			std::string mapImageFile = "map.png";

			// Executa o jogo
			runGame(csvFile, mapImageFile);
		} catch (const std::exception &e) {
			std::cout << "Erro: " << e.what() << std::endl; // Exibe a mensagem de erro se uma exceção for lançada
			return EXIT_FAILURE;// Retorna falha na execução
		}

		return EXIT_SUCCESS; // Retorna sucesso na execução

}

};

void carregarJogo() {
	CarregarJogo jogo;
	jogo.executarJogo();
}

#endif /* CARREGARJOGO_H_ */
