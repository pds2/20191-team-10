#ifndef BATALHA_H
#define BATALHA_H

#include "pokemon.h"
#include "treinador.h"
#include "interface.h"
#include "pokebola.h"

#include "pokemon_include/charmander.h"
#include "pokemon_include/charmeleon.h"
#include "pokemon_include/charizard.h"
#include "pokemon_include/bulbasauro.h"
#include "pokemon_include/ivysaur.h"
#include "pokemon_include/venosauro.h"
#include "pokemon_include/squirtle.h"
#include "pokemon_include/wartotle.h"
#include "pokemon_include/blastoise.h"

int rola_dados(int);
// Gera um número aleatório entre 1 e int. Utilizado para calcular a chance de crit, por exemplo.

void reset_current_hp(Pokemon *);
// Função que reseta a vida dos pokemons dados como parâmetro

void escolher_pos_batalha(Pokemon *meu_poke, Pokemon *inimigo, Treinador jogador);
// Função para escolher o que fazer depois da batalha

Pokemon *gera_oponente_facil();
Pokemon *gera_oponente_medio();
Pokemon *gera_oponente_dificil();
// Funções que gera um adversário para batalhar dependendo do nivel de dificuldade.

void encerrar_batalha(Pokemon *, Pokemon *, Treinador jogador, int Dificuldade);
// Encerra a batalha e reseta o HP dos pokemons envolvidos (meu_poke,inimigo).
// Sempre delete o inimigo após o uso dessa função caso ele não tiver mais serventia.

void batalha_x1(Treinador, Pokemon *, int);
// Função que faz dois Pokémon lutarem.
// Recebe como parâmetro o jogador, seu Pokémon escolhido e a dificuldade ( representada como inteiro).

#endif // BATALHA_H
