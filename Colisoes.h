/*
 * Colisoes.h
 *
 *  Created on: 7 de out. de 2024
 *      Author: magal
 */

#ifndef COLISOES_H_
#define COLISOES_H_
#include "Player.h"				//Inclui o arquivo que guarda os atributos e métodos do jogador
#include "Inimigos.h"			//Inclui o arquivo que guarda os atributos e métodos dos inimigos
#include "Plataformas.h"		//Inclui o arquivo que guarda os atributos e métodos das plataformas

//Funções que recebem o jogador e o inimigo e verifica se há colisão entre eles
bool colisaoInimigoTartarugaPlayer(Player player, Tartaruga tartaruga) {
	bool colisao = false;

	if (player.posicao.x + player.width > tartaruga.posicao.x
			and tartaruga.posicao.x + tartaruga.width > player.posicao.x
			and tartaruga.posicao.y + tartaruga.height > player.posicao.y
			and player.posicao.y + player.height > tartaruga.posicao.y) {
		colisao = true;
	} else {
		colisao = false;
	}
	return colisao;
}

bool colisaoInimigoCaranguejoPlayer(Player player, Caranguejo caranguejo) {
	bool colisao = false;

	if (player.posicao.x + player.width > caranguejo.posicao.x
			and caranguejo.posicao.x + caranguejo.width > player.posicao.x
			and caranguejo.posicao.y + caranguejo.height > player.posicao.y
			and player.posicao.y + player.height > caranguejo.posicao.y) {
		colisao = true;
	} else {
		colisao = false;
	}
	return colisao;
}

bool colisaoInimigoVagalumePlayer(Player player, Vagalume vagalume) {
	bool colisao = false;

	if (player.posicao.x + player.width > vagalume.posicao.x
			and vagalume.posicao.x + vagalume.width > player.posicao.x
			and vagalume.posicao.y + vagalume.height > player.posicao.y
			and player.posicao.y + player.height > vagalume.posicao.y) {
		colisao = true;
	} else {
		colisao = false;
	}
	return colisao;
}

bool colisaoInimigoFogoPlayer(Player player, Fogo fogo) {
	bool colisao = false;

	if (player.posicao.x + player.width > fogo.getPosicao().x
			and fogo.getPosicao().x + fogo.getWidth() > player.posicao.x
			and fogo.getPosicao().y + fogo.getHeight() > player.posicao.y
			and player.posicao.y + player.height > fogo.getPosicao().y) {
		colisao = true;
	} else {
		colisao = false;
	}
	return colisao;
}
#endif /* COLISOES_H_ */
