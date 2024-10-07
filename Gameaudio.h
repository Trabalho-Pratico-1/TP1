#ifndef GAMEAUDIO_H_
#define GAMEAUDIO_H_

#include <SFML/Audio.hpp>
#include <iostream>

class GameAudio {
private:
    sf::Music backgroundMusic;  // Objeto para a música de fundo
    std::string musicFile = "8bit_action_title_bpm150.wav";

public:
    // Função para carregar e iniciar a música
    bool loadMusic() {
        if (!backgroundMusic.openFromFile(musicFile)) {
            std::cerr << "Erro ao carregar o arquivo de música: " << musicFile << std::endl;
            return false;
        }
        backgroundMusic.setLoop(true);  // Configura para tocar em loop
        backgroundMusic.play();         // Inicia a reprodução da música
        return true;
    }

    // Função para parar a música (caso necessário)
    void stopMusic() {
        backgroundMusic.stop();
    }
};

#endif /* GAMEAUDIO_H_ */

