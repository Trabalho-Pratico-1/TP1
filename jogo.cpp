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
		imagemPersonagem.setPosition(200, 550);
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
		textureBackground.loadFromFile("backgroundAtari.png");
		imagemBackground.setTexture(textureBackground);
		imagemBackground.setTextureRect(sf::IntRect(0,0,1080,720));
		imagemBackground.scale(3, 3);
	}

	void desenharBackground(sf::RenderWindow &window){
		window.draw(imagemBackground);
	}
};

int jogo(int argc, char **argv) {

	Background background;
	Mario mario;

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
	 window.display(); //Mostra na tela
	 }
	return 0;
}
