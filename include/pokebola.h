#ifndef POKEBOLA_H
#define POKEBOLA_H

#define POKEBOLA_INVALIDO 0
#define POKEBALL_CHANCE 25
#define GREATBALL_CHANCE 50
#define MASTERBALL_CHANCE 100

#include "pokemon.h"
#include "treinador.h"
#include "interface.h"
#include "../include/pokemon_include/charmander.h"
#include "../include/pokemon_include/bulbasauro.h"
#include "../include/pokemon_include/squirtle.h"

//funções complementares da capturar_pokemon (nao utilizar na batalha)
void pokemon_capturado(Treinador jogador, Pokemon *inimigo);
void utilizar_pokebola(Treinador jogador, Pokemon *inimigo);

void capturar_pokemon(Treinador jogador, Pokemon *inimigo); // <-- utilizar essa função para capturar pokemon
// Função para capturar pokemon utilizando as pokebolas implementadas no treinador
// Recebe um treinador como parametro e o pokemon inimigo ativo na batalha.

#endif
