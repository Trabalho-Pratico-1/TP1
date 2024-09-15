#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

class GameObject {
public:
    GameObject(const sf::Vector2f& size, const sf::Color& color, const sf::Vector2f& position)
        : shape(size) {
        shape.setFillColor(color);
        shape.setPosition(position);
    }

    virtual void update(float deltaTime, const std::vector<std::vector<int>>& collisionMap, float cellWidth, float cellHeight) = 0;

    sf::RectangleShape shape;
};

class Player : public GameObject {
public:
    Player(const sf::Vector2f& size, const sf::Color& color, const sf::Vector2f& position)
        : GameObject(size, color, position), velocity(0.0f, 0.0f), isJumping(false) {
        gravity = 0.5f;
        jumpForce = -12.5f;
        speed = 300.0f;
    }

    void update(float deltaTime, const std::vector<std::vector<int>>& collisionMap, float cellWidth, float cellHeight) override {
        velocity.x = 0.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity.x = -speed * deltaTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocity.x = speed * deltaTime;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isJumping) {
            velocity.y = jumpForce;
            isJumping = true;
        }

        velocity.y += gravity;

        shape.move(velocity);

        sf::Vector2f pos = shape.getPosition();
        float width = shape.getSize().x;
        float height = shape.getSize().y;

        int cellXLeft = static_cast<int>(pos.x / cellWidth);
        int cellXRight = static_cast<int>((pos.x + width) / cellWidth);
        int cellYTop = static_cast<int>(pos.y / cellHeight);
        int cellYBottom = static_cast<int>((pos.y + height) / cellHeight);

        bool onGround = false;

        if (collisionMap[cellYBottom][cellXLeft] != -1 ||
            collisionMap[cellYBottom][cellXRight] != -1) {
            shape.setPosition(pos.x, cellYBottom * cellHeight - height);
            velocity.y = 0;
            isJumping = false;
            onGround = true;
        }

        if (!onGround) {
            if (collisionMap[cellYTop][cellXLeft] != -1 ||
                collisionMap[cellYTop][cellXRight] != -1) {
                shape.setPosition(pos.x, (cellYTop + 1) * cellHeight);
                velocity.y = 0;
                isJumping = false;
            }
        }

        // Transporte pelas bordas da janela
        if (pos.x < 0) {
            shape.setPosition(windowSize.x - width, pos.y);
        } else if (pos.x > windowSize.x) {
            shape.setPosition(0, pos.y);
        }

        if (pos.y < 0) {
            shape.setPosition(pos.x, windowSize.y - height);
            velocity.y = 0;
        } else if (pos.y > windowSize.y) {
            shape.setPosition(pos.x, 0);
        }
    }

    sf::Vector2f windowSize;
    sf::Vector2f velocity;
    bool isJumping;
    float gravity;
    float jumpForce;
    float speed;
};



std::vector<std::vector<int>> loadCollisionsFromCSV(const std::string& filename) {
    std::vector<std::vector<int>> collisionMap;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo CSV");
    }

    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(std::stoi(cell));  // Converte string para int e adiciona à linha
        }
        collisionMap.push_back(row);  // Adiciona a linha ao mapa
    }

    return collisionMap;
}

void runGame(const std::string& csvFile, const std::string& mapImageFile) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jogo com Colisões");
    window.setFramerateLimit(60); // Limitar FPS para evitar sobrecarga

    // Carregar o mapa de colisão a partir do CSV
    std::vector<std::vector<int>> collisionMap = loadCollisionsFromCSV(csvFile);
    int mapWidth = collisionMap[0].size();
    int mapHeight = collisionMap.size();

    // Calcula o tamanho de cada célula do mapa de colisão com base no tamanho da janela
    float cellWidth = static_cast<float>(window.getSize().x) / mapWidth;
    float cellHeight = static_cast<float>(window.getSize().y) / mapHeight;

    // Carregar textura do mapa
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile(mapImageFile)) {
        throw std::runtime_error("Erro ao carregar a imagem do mapa");
    }
    sf::Sprite mapSprite(mapTexture);
    mapSprite.setScale(
        window.getSize().x / static_cast<float>(mapTexture.getSize().x),
        window.getSize().y / static_cast<float>(mapTexture.getSize().y)
    );

    // Criar o personagem
    Player player(sf::Vector2f(50.0f, 50.0f), sf::Color::Green, sf::Vector2f(100.0f, 520.0f));
    player.windowSize = sf::Vector2f(window.getSize());

    sf::Clock clock;  // Relógio para medir o tempo delta

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Calcular o tempo delta (tempo desde o último frame)
        float deltaTime = clock.restart().asSeconds();

        // Atualizar o personagem
        player.update(deltaTime, collisionMap, cellWidth, cellHeight);



        window.clear();

        // Desenhar o mapa
        window.draw(mapSprite);

        // Desenhar o personagem
        window.draw(player.shape);

        window.display();
    }
}

int main() {
    try {
        // Caminho do arquivo CSV e imagem do mapa
        std::string csvFile = "mapa_Colisao.csv";
        std::string mapImageFile = "map.png";

        // Executa o jogo
        runGame(csvFile, mapImageFile);
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
