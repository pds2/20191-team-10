#ifndef INTRODUCAO_H
#define INTRODUCAO_H
#include "../include/introducao.h"
#include "../include/treinador.h"
#include "../include/pokemon_include/squirtle.h"
#include "../include/pokemon_agua.h"
#include "../include/pokemon_include/charmander.h"
#include "../include/pokemon_include/bulbasauro.h"
#include "../include/pokemon_fogo.h"
#include "../include/pokemon_grama.h"
#include "../include/batalha.h"
#include <stdexcept>

class Excpt_Entrada_Inicial : public std::exception {
public:
    const char *what() {
        return "Entrada invalida! Digite 1, 2 ou 3!\n";
    }
};

std::string apelida_jogador();
void introducao(Treinador *jogador); // Texto introdutório do jogo
void verifica_entrada(int p);
//void escolher_modo(Treinador jogador, Pokemon *meu_poke, int dificuldade); // Escolher modo batalha 1X1, 3X3 ou torneio

#endif // INTRODUCAO_H
