#ifndef INIMIGOS_H_
#define INIMIGOS_H_
#include "GameObject.h"
#include "Player.h"
// Classe derivada de GameObject para os inimigos
class Inimigos: public GameObject {
protected:
	sf::Texture textureInimigos;
	sf::Sprite imagemInimigos;
	sf::Vector2f posicaoInimigos;
	sf::Vector2f deslocamento;
	float gravity;
	float speed;
public:
	bool onGround;
	bool vivo;

	Inimigos() :
			deslocamento(0.0f, 0.0f), posicaoInimigos(0.0f, 0.0f), onGround(
					false), vivo(true) {
		gravity = 0.5f;
		speed = 50.0f;
	}

	void carregarTexture() {
		textureInimigos.loadFromFile("sprites.png");
		imagemInimigos.setTexture(textureInimigos);
	}
	void morrer() {
		speed = 0.0f;
		vivo = false;
	}

	void renascer() {
		speed = 60.0f;
		vivo = true;
	}

	bool morrerDefinitivamente() {
		imagemInimigos.setPosition(0.0f, 0.0f);
		return true;
	}

	void update(float deltaTime,
			const std::vector<std::vector<int>> &collisionMap, float cellWidth,
			float cellHeight) override {
		deslocamento.x = 0.0f; // Inicializa a velocidade horizontal
		// Atualiza a velocidade horizontal com base no tempo
		deslocamento.x = speed * deltaTime;
		// Aplica a gravidade
		deslocamento.y += gravity;
		// Move a forma do inimigo com base na velocidade
		imagemInimigos.move(deslocamento);

		posicao = imagemInimigos.getPosition(); // Obtém a posição atual do jogador
		globalBounds = imagemInimigos.getGlobalBounds();
		width = globalBounds.width;        // Obtém a largura dos inimigos
		height = globalBounds.height;        // Obtém a altura dos inimigos

		// Calcula as células da matriz de colisão que os inimigos ocupam
		int cellXLeft = static_cast<int>(posicao.x / cellWidth);
		int cellXRight = static_cast<int>((posicao.x + width) / cellWidth);
		int cellYBottom = static_cast<int>((posicao.y + height) / cellHeight);

		// Verifica colisões na parte inferior do inimigo
		if (collisionMap[cellYBottom][cellXLeft] != -1
				|| collisionMap[cellYBottom][cellXRight] != -1) {
			imagemInimigos.setPosition(posicao.x,
					cellYBottom * cellHeight - height); // Ajusta a posição do inimigo para o chão
			deslocamento.y = 0; // Reseta a velocidade vertical
			onGround = true;
		}
		// Transporte pelas bordas da janela
		if (posicao.x < 0) {
			imagemInimigos.setPosition(windowSize.x - width, posicao.y); // Teletransporta para a borda direita se sair pela esquerda

		} else if (posicao.x > 800) {
			imagemInimigos.setPosition(0, posicao.y); // Teletransporta para a borda esquerda se sair pela direita
		}

		if (posicao.y < 0) {
			imagemInimigos.setPosition(posicao.x, windowSize.y - height); // Teletransporta para a borda inferior se sair pela superior
		} else if (posicao.y > 400 and posicao.x > 800) {
			imagemInimigos.setPosition(posicao.x, 2.0f); // Teletransporta para a borda superior se sair pela inferior
		}
	}

	sf::Vector2f windowSize; // Tamanho da janela para transporte

};

class Tartaruga: public Inimigos {
private:
	sf::Clock clock;
	sf::Time time;
public:
	Tartaruga() {
		Inimigos();
		imagemInimigos.setTextureRect(sf::IntRect(7, 331, 15, 15));
		imagemInimigos.scale(2, 2);
	}

	void desenharTartaruga(sf::RenderWindow &window) {
		//moverTartaruga();
		carregarTexture();
		window.draw(imagemInimigos);
	}

	void morrer() {
		Inimigos::morrer();
		clock.restart();
		imagemInimigos.setTextureRect(sf::IntRect(270, 336, 25, 15));
	}
	void renascer() {
		Inimigos::renascer();
		imagemInimigos.setTextureRect(sf::IntRect(7, 331, 15, 15));
	}

	void update(float deltaTime,
			const std::vector<std::vector<int>> &collisionMap, float cellWidth,
			float cellHeight) override {
		if (vivo == false) {
			if (clock.getElapsedTime() > sf::seconds(5.0f)) {
				renascer();
				clock.restart();
			}
		} else {
			Inimigos::update(deltaTime, collisionMap, cellWidth, cellHeight);
		}

	}
}
;

class Caranguejo: public Inimigos {
private:
	sf::Clock clock;
	sf::Time time;
public:
	Caranguejo() {
		Inimigos();
		imagemInimigos.setTextureRect(sf::IntRect(6, 422, 16, 13));
		imagemInimigos.scale(2.5, 2.5);
	}
	void desenharCaranguejo(sf::RenderWindow &window) {
		carregarTexture();
		window.draw(imagemInimigos);
	}
	void morrer() {
		Inimigos::morrer();
		clock.restart();
		imagemInimigos.setTextureRect(sf::IntRect(132, 418, 16, 16));
	}
	void renascer() {
		if (clock.getElapsedTime() > sf::seconds(5.0f)) {
			Inimigos::renascer();
			clock.restart();
		}
		imagemInimigos.setTextureRect(sf::IntRect(6, 422, 16, 13));
	}

	void update(float deltaTime,
			const std::vector<std::vector<int>> &collisionMap, float cellWidth,
			float cellHeight) override {
		if (vivo == false) {
			if (clock.getElapsedTime() > sf::seconds(5.0f)) {
				renascer();
				clock.restart();
			}
		} else {
			Inimigos::update(deltaTime, collisionMap, cellWidth, cellHeight);
		}

	}
};

class Vagalume: public Inimigos {
private:
	sf::Clock clock;
	sf::Time time;
public:
	Vagalume() {
		Inimigos();
		imagemInimigos.setTextureRect(sf::IntRect(6, 509, 15, 12));
		imagemInimigos.scale(2, 2);
	}
	void desenharVagalume(sf::RenderWindow &window) {
		carregarTexture();
		window.draw(imagemInimigos);
	}
	void pular() {
		if (onGround == true and posicao.x < 720) {
			deslocamento.y = -3.0f;
			onGround = false;
		}
	}
	void morrer() {
		Inimigos::morrer();
		clock.restart();
		imagemInimigos.setTextureRect(sf::IntRect(154, 507, 18, 16));
	}
	void renascer() {
		if (clock.getElapsedTime() > sf::seconds(5.0f)) {
			Inimigos::renascer();
			clock.restart();
		}
		imagemInimigos.setTextureRect(sf::IntRect(6, 509, 15, 12));
	}

	void update(float deltaTime,
			const std::vector<std::vector<int>> &collisionMap, float cellWidth,
			float cellHeight) override {
		if (vivo == false) {
			if (clock.getElapsedTime() > sf::seconds(5.0f)) {
				renascer();
				clock.restart();
			}
		} else {
			Inimigos::update(deltaTime, collisionMap, cellWidth, cellHeight);
		}

	}

};

class Fogo: GameObject {
protected:
	sf::Texture textureInimigos;
	sf::Sprite imagemInimigos;
	sf::Vector2f posicaoFogo;
	sf::Vector2f velocity;
	float gravity;
	float speed;
public:
	int vx, vy;
	Fogo() :
			posicaoFogo(0.0f, 0.0f), velocity(0.0f, 0.0f) {
		textureInimigos.loadFromFile("sprites.png");
		imagemInimigos.setTexture(textureInimigos);
		imagemInimigos.setTextureRect(sf::IntRect(10, 216, 16, 16));
		imagemInimigos.scale(3, 3);
		imagemInimigos.setPosition(posicaoFogo);
		gravity = 0.5f;
		speed = 150.0f;
		vx = vy = 0;
	}
	void desenharFogo(sf::RenderWindow &window) {
		window.draw(imagemInimigos);
	}

	void update(float deltaTime,
			const std::vector<std::vector<int>> &collisionMap, float cellWidth,
			float cellHeight) override {
		velocity.x = 0.0f; // Inicializa a velocidade horizontal
		// Atualiza a velocidade horizontal com base no tempo
		velocity.x = deltaTime * speed;
		// Aplica a gravidade
		velocity.y += 0;
		// Move a forma do inimigo com base na velocidade
		posicao = imagemInimigos.getPosition(); // Obtém a posição atual do jogador
		globalBounds = imagemInimigos.getGlobalBounds();
		width = globalBounds.width;        // Obtém a largura
		height = globalBounds.height;        // Obtém a altura
//Coordena a movimentação na horizontal
		if (posicao.x + width < 0) {
			velocity.x = 0;
			speed = 150.0f;
			velocity.x = speed * deltaTime;
		} else if (posicao.x > 800 - width) {
			velocity.x = 0;
			speed = -150.0f;
			velocity.x = speed * deltaTime;
		}
//Coordena a movimentação na vertical
		if (posicao.x <= 1 and speed == -150.0f) {
			if (posicao.y == 0) {
				imagemInimigos.setPosition(0, 170);
			}

		} else if (posicao.x <= 5 and speed == -150.0f and posicao.y == 170) {
			imagemInimigos.setPosition(0, 275);
		} else if (posicao.x <= 5 and speed == -150.0f and posicao.y == 275) {
			imagemInimigos.setPosition(0, 430);
		} else if (posicao.x <= 5 and speed == -150.0f and posicao.y == 430) {
			imagemInimigos.setPosition(0, 0);
		}

		imagemInimigos.move(velocity);

	}

};

#endif /* INIMIGOS_H_ */
