#ifndef BATALHA_H
#define BATALHA_H

#include "pokemon.h"
#include "treinador.h"
#include "../include/pokemon_include/charmander.h"
#include "../include/pokemon_include/bulbasauro.h"
#include "../include/pokemon_include/squirtle.h"

int rola_dados();
// Gera um número aleatório entre 1 e 10. Utilizado para calcular a chance de crit, por exemplo.

void encerrar_batalha(Pokemon *, Pokemon *); 
// Encerra. Deve inclusive resetar o current_hp para o valor original.

void set_current_hp(Pokemon *); //Função que seta a vida na hora da batalha

void gera_oponente_facil(Pokemon *); //Função que gera um treinador inicial para batalhar.

int escolher_pokemon(Treinador); //Função que recebe um treinador e a partir desse treinado, escolhe um Pokémon.

void batalha_x1(Treinador, Pokemon *, int); 
// Função que faz dois Pokémon lutarem.
//Recebe como parâmetro o jogador, seu Pokémon escolhido e a dificuldade.

#endif // BATALHA_H
