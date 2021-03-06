#ifndef POKEBOLA_H
#define POKEBOLA_H

#define POKEBOLA_INVALIDO 0
#define POKEBALL_CHANCE 25
#define GREATBALL_CHANCE 50
#define MASTERBALL_CHANCE 100

#include "pokemon.h"
#include "treinador.h"
#include "interface.h"
#include "pokemon_include/charmander.h"
#include "pokemon_include/bulbasauro.h"
#include "pokemon_include/squirtle.h"

//função responsável por pokebolas recompensadas na batalha
void recompensar_treinador(Pokemon *meu_poke, Treinador &jogador, int dificuldade);

//funções complementares da capturar_pokemon (nao utilizar na batalha)
void pokemon_capturado(Treinador jogador, Pokemon *inimigo, int tipo_chance);
void utilizar_pokebola(Treinador jogador, Pokemon *inimigo, int tipo_chance);

void capturar_pokemon(Treinador jogador, Pokemon *inimigo); // <-- utilizar essa função para capturar pokemon
// Função para capturar pokemon utilizando as pokebolas implementadas no treinador
// Recebe um treinador como parametro e o pokemon inimigo ativo na batalha.

#endif
