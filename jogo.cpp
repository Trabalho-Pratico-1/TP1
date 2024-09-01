#include <SFML/Graphics.hpp>
class Mario{
private:
	sf::Texture texturePersongem;
	sf::Sprite imagemPersonagem;
	//int x, y, velocidadex, velocidadey;

public:
	Mario(){
		texturePersongem.loadFromFile("personagem.png");
		imagemPersonagem.setTexture(texturePersongem);
		imagemPersonagem.setPosition(200, 535);
		imagemPersonagem.scale(0.15, 0.15);
	}

	void desenharMario(sf::RenderWindow &window){
		 window.draw(imagemPersonagem);
	}
};

class Background{
private:
	sf::Texture textureBackground;
	sf::Sprite imagemBackground;

public:
	Background(){
		textureBackground.loadFromFile("Atari - Mario Bros Atari 2600 - Backgrounds.png");
		imagemBackground.setTexture(textureBackground);
		imagemBackground.setTextureRect(sf::IntRect(0,0,1080,720));
		imagemBackground.scale(3.5, 3.5);
	}

	void desenharBackground(sf::RenderWindow &window){
		window.draw(imagemBackground);
	}
};

class Inimigos{
protected:
	sf::Texture textureInimigos;
	sf::Sprite imagemInimigos;
public:
	Inimigos(){
		textureInimigos.loadFromFile("Inimigos-TestandoPNG.png");
		imagemInimigos.setTexture(textureInimigos);
	}
};

class Tartaruga : public Inimigos{
public:
	Tartaruga(){
		Inimigos();
		imagemInimigos.setTextureRect(sf::IntRect(0,1,20,15));
		imagemInimigos.scale(5, 5);
		imagemInimigos.setPosition(100, 420);
	}
	void desenharTartaruga(sf::RenderWindow &window){
		window.draw(imagemInimigos);
	}
};

class Carangueijo : public Inimigos{
public:
	Carangueijo(){
		imagemInimigos.setTextureRect(sf::IntRect(0,20,20,16));
		imagemInimigos.scale(5, 5);
		imagemInimigos.setPosition(200, 130);
		}
	void desenharCarangueijo(sf::RenderWindow &window){
			window.draw(imagemInimigos);
		}

};

class Vagalume : public Inimigos{
public:
	Vagalume(){
		imagemInimigos.setTextureRect(sf::IntRect(0,76,20,15));
		imagemInimigos.scale(5, 5);
		imagemInimigos.setPosition(700, 90);
	}
	void desenharVagalume(sf::RenderWindow &window){
			window.draw(imagemInimigos);
		}
};

int jogo(int argc, char **argv) {

	Background background;
	Mario mario;
	Tartaruga tartaruga;
	Carangueijo carangueijo;
	Vagalume vagalume;

	sf::RenderWindow window(sf::VideoMode(1080, 720), "Jogo");

	while (window.isOpen()){ //Loop do jogo
	 sf::Event event;
	 while (window.pollEvent(event)){ //Loop de eventos
	 if (event.type == sf::Event::Closed){
		 window.close();
	 }
	 }

	 background.desenharBackground(window);
	 mario.desenharMario(window);
	 tartaruga.desenharTartaruga(window);
	 carangueijo.desenharCarangueijo(window);
	 vagalume.desenharVagalume(window);

	 window.display(); //Mostra na tela
	 }
	return 0;
}
