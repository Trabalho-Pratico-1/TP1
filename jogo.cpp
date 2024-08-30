#include <SFML/Graphics.hpp>
//Personagem aparece na tela sem classes
int jogo(int argc, char **argv) {
	sf::Texture texturePersongem;
	sf::Sprite imagemPersonagem;

	sf::Texture textureBackground;
	sf::Sprite imagemBackground;
	//int x, y, velocidadex, velocidadey;

	textureBackground.loadFromFile("backgroundAtari.png");
	imagemBackground.setTexture(textureBackground);
	imagemBackground.setTextureRect(sf::IntRect(0,0,1080,720));
	imagemBackground.scale(3, 3);

	texturePersongem.loadFromFile("personagem.png");
	imagemPersonagem.setTexture(texturePersongem);
	imagemPersonagem.setPosition(200, 550);
	imagemPersonagem.scale(0.15, 0.15);

	sf::RenderWindow window(sf::VideoMode(1080, 720), "Jogo");

	while (window.isOpen()){ //Loop do jogo
	 sf::Event event;
	 while (window.pollEvent(event)){ //Loop de eventos
	 if (event.type == sf::Event::Closed){
		 window.close();
	 }
	 }

	 window.draw(imagemBackground);
	 window.draw(imagemPersonagem);
	 window.display(); //Mostra na tela
	 }
	return 0;
}

