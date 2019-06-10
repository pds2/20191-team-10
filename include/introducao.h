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

class Excpt_Entrada_Inicial : public std::exception {
public:
    const char *what() {
        return "Entrada invalida! Digite 1, 2 ou 3!\n";
    }
};

std::string apelida_jogador();
void introducao(Treinador *jogador); // Texto introdutório do jogo
void verifica_entrada(std::string p);
//void escolher_modo(Treinador jogador, Pokemon *meu_poke, int dificuldade); // Escolher modo batalha 1X1, 3X3 ou torneio

#endif // INTRODUCAO_H
