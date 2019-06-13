#ifndef INTRODUCAO_H
#define INTRODUCAO_H
#include "introducao.h"
#include "treinador.h"
#include "pokemon_agua.h"
#include "pokemon_include/squirtle.h"
#include "pokemon_include/charmander.h"
#include "pokemon_include/bulbasauro.h"
#include "pokemon_fogo.h"
#include "pokemon_grama.h"
#include "batalha.h"
#include "pokedex_ascii.h"
#include <stdexcept>

std::string apelida_jogador();
void introducao(Treinador *jogador); // Texto introdutório do jogo

#endif // INTRODUCAO_H
