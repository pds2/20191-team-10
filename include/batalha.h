#ifndef BATALHA_H
#define BATALHA_H

#include "pokemon.h"
#include "treinador.h"
#include "../include/pokemon_include/charmander.h"
#include "../include/pokemon_include/bulbasauro.h"
#include "../include/pokemon_include/squirtle.h"

int rola_dados();
// Gera um número aleatório entre 1 e 10. Utilizado para calcular a chance de crit, por exemplo.

void reset_current_hp(Pokemon *,Pokemon *);
// Função que reseta a vida dos pokemons dados como parâmetro

void gera_oponente_facil(Pokemon *);
// Função que gera um adversário para batalhar.

void encerrar_batalha(Pokemon *, Pokemon *);
// Encerra a batalha e reseta o HP dos pokemons envolvidos (meu_poke,inimigo).
// Sempre delete o inimigo após o uso dessa função caso ele não tiver mais serventia.

void batalha_x1(Treinador, Pokemon *, int);
// Função que faz dois Pokémon lutarem.
// Recebe como parâmetro o jogador, seu Pokémon escolhido e a dificuldade ( representada como inteiro).

#endif // BATALHA_H
