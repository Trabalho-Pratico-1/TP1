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
    // Construtor da classe que inicializa o tamanho, cor e posição do objeto
    GameObject(const sf::Vector2f& size, const sf::Color& color, const sf::Vector2f& position)
        : shape(size) {
        shape.setFillColor(color);       // Define a cor de preenchimento da forma
        shape.setPosition(position);     // Define a posição da forma
    }

    // Método virtual puro que deve ser implementado por classes derivadas
    virtual void update(float deltaTime, const std::vector<std::vector<int>>& collisionMap, float cellWidth, float cellHeight) = 0;

    sf::RectangleShape shape;  // Forma retangular usada para representar o objeto
};

// Classe derivada para o jogador
class Player : public GameObject {
public:
    // Construtor da classe que inicializa o jogador com tamanho, cor e posição, além de propriedades de movimento
    Player(const sf::Vector2f& size, const sf::Color& color, const sf::Vector2f& position)
        : GameObject(size, color, position), velocity(0.0f, 0.0f), isJumping(false) {
        gravity = 0.5f;          // Define a gravidade
        jumpForce = -12.5f;     // Define a força do salto
        speed = 300.0f;         // Define a velocidade de movimento
    }

    // Implementação do método update para atualizar o estado do jogador
    void update(float deltaTime, const std::vector<std::vector<int>>& collisionMap, float cellWidth, float cellHeight) override {
        velocity.x = 0.0f; // Inicializa a velocidade horizontal

        // Atualiza a velocidade horizontal com base nas teclas pressionadas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity.x = -speed * deltaTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocity.x = speed * deltaTime;
        }

        // Atualiza a velocidade vertical se a tecla de salto for pressionada e o jogador não estiver pulando
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isJumping) {
            velocity.y = jumpForce;
            isJumping = true;
        }

        // Aplica a gravidade
        velocity.y += gravity;

        // Move a forma do jogador com base na velocidade
        shape.move(velocity);

        sf::Vector2f pos = shape.getPosition(); // Obtém a posição atual do jogador
        float width = shape.getSize().x;        // Obtém a largura do jogador
        float height = shape.getSize().y;       // Obtém a altura do jogador

        // Calcula as células da matriz de colisão que o jogador ocupa
        int cellXLeft = static_cast<int>(pos.x / cellWidth);
        int cellXRight = static_cast<int>((pos.x + width) / cellWidth);
        int cellYTop = static_cast<int>(pos.y / cellHeight);
        int cellYBottom = static_cast<int>((pos.y + height) / cellHeight);

        bool onGround = false; // Flag para verificar se o jogador está no chão

        // Verifica colisões na parte inferior do jogador
        if (collisionMap[cellYBottom][cellXLeft] != -1 ||
            collisionMap[cellYBottom][cellXRight] != -1) {
            shape.setPosition(pos.x, cellYBottom * cellHeight - height); // Ajusta a posição do jogador para o chão
            velocity.y = 0; // Reseta a velocidade vertical
            isJumping = false; // Permite que o jogador pule novamente
            onGround = true;
        }

        // Verifica se o jogador está em colisão com o teto se não estiver no chão
        if (!onGround) {
            if (collisionMap[cellYTop][cellXLeft] != -1 ||
                collisionMap[cellYTop][cellXRight] != -1) {
                shape.setPosition(pos.x, (cellYTop + 1) * cellHeight); // Ajusta a posição do jogador para o teto
                velocity.y = 0; // Reseta a velocidade vertical
                isJumping = false; // Permite que o jogador pule novamente
            }
        }

        // Transporte pelas bordas da janela
        if (pos.x < 0) {
            shape.setPosition(windowSize.x - width, pos.y); // Teletransporta para a borda direita se sair pela esquerda
        } else if (pos.x > windowSize.x) {
            shape.setPosition(0, pos.y); // Teletransporta para a borda esquerda se sair pela direita
        }

        if (pos.y < 0) {
            shape.setPosition(pos.x, windowSize.y - height); // Teletransporta para a borda inferior se sair pela superior
            velocity.y = 0; // Reseta a velocidade vertical
        } else if (pos.y > windowSize.y) {
            shape.setPosition(pos.x, 0); // Teletransporta para a borda superior se sair pela inferior
        }
    }

    sf::Vector2f windowSize; // Tamanho da janela para transporte
    sf::Vector2f velocity;   // Velocidade do jogador
    bool isJumping;          // Flag para verificar se o jogador está pulando
    float gravity;           // Gravidade aplicada ao jogador
    float jumpForce;        // Força do salto
    float speed;            // Velocidade de movimento do jogador
};

// Função para carregar o mapa de colisão a partir de um arquivo CSV
std::vector<std::vector<int>> loadCollisionsFromCSV(const std::string& filename) {
    std::vector<std::vector<int>> collisionMap; // Mapa de colisão
    std::ifstream file(filename); // Abre o arquivo CSV
    std::string line; // Linha lida do arquivo

    if (!file.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo CSV"); // Lança uma exceção se o arquivo não puder ser aberto
    }

    while (std::getline(file, line)) { // Lê o arquivo linha por linha
        std::vector<int> row; // Linha do mapa de colisão
        std::stringstream ss(line); // Cria um fluxo de string para processar a linha
        std::string cell; // Célula da linha

        while (std::getline(ss, cell, ',')) { // Lê cada célula separada por vírgula
            row.push_back(std::stoi(cell));  // Converte string para int e adiciona à linha
        }
        collisionMap.push_back(row);  // Adiciona a linha ao mapa
    }

    return collisionMap; // Retorna o mapa de colisão
}

// Função principal para executar o jogo
void runGame(const std::string& csvFile, const std::string& mapImageFile) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jogo com Colisões"); // Cria a janela do jogo
    window.setFramerateLimit(60); // Limita os FPS para evitar sobrecarga

    // Carregar o mapa de colisão a partir do CSV
    std::vector<std::vector<int>> collisionMap = loadCollisionsFromCSV(csvFile); // Carrega o mapa de colisão
    int mapWidth = collisionMap[0].size(); // Largura do mapa
    int mapHeight = collisionMap.size(); // Altura do mapa

    // Calcula o tamanho de cada célula do mapa de colisão com base no tamanho da janela
    float cellWidth = static_cast<float>(window.getSize().x) / mapWidth;
    float cellHeight = static_cast<float>(window.getSize().y) / mapHeight;

    // Carregar textura do mapa
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile(mapImageFile)) {
        throw std::runtime_error("Erro ao carregar a imagem do mapa"); // Lança uma exceção se a imagem não puder ser carregada
    }
    sf::Sprite mapSprite(mapTexture); // Cria um sprite para o mapa
    mapSprite.setScale(
        window.getSize().x / static_cast<float>(mapTexture.getSize().x),
        window.getSize().y / static_cast<float>(mapTexture.getSize().y)
    ); // Ajusta a escala do sprite para preencher a janela

    // Criar o personagem
    Player player(sf::Vector2f(50.0f, 50.0f), sf::Color::Green, sf::Vector2f(100.0f, 520.0f)); // Cria o jogador
    player.windowSize = sf::Vector2f(window.getSize()); // Define o tamanho da janela para o jogador

    sf::Clock clock;  // Relógio para medir o tempo delta

    // Loop principal do jogo
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Fecha a janela se o evento de fechamento for recebido
        }

        // Calcular o tempo delta (tempo desde o último frame)
        float deltaTime = clock.restart().asSeconds();

        // Atualizar o personagem
        player.update(deltaTime, collisionMap, cellWidth, cellHeight);

        window.clear(); // Limpa a janela

        // Desenhar o mapa
        window.draw(mapSprite);

        // Desenhar o personagem
        window.draw(player.shape);

        window.display(); // Exibe o conteúdo renderizado na janela
    }
}

// Função principal do programa
int main() {
    try {
        // Caminho do arquivo CSV e imagem do mapa
        std::string csvFile = "mapa_Colisao.csv";
        std::string mapImageFile = "map.png";

        // Executa o jogo
        runGame(csvFile, mapImageFile);
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl; // Exibe a mensagem de erro se uma exceção for lançada
        return EXIT_FAILURE; // Retorna falha na execução
    }

    return EXIT_SUCCESS; // Retorna sucesso na execução
}
