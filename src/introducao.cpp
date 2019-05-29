#include <iostream>
#include <string>
#include <vector>
#include "../include/introducao.h"
#include "../include/treinador.h"
#include "../include/pokemon_include/squirtle.h"
#include "../include/pokemon_agua.h"
#include "../include/pokemon_include/charmander.h"
#include "../include/pokemon_include/bulbasauro.h"
#include "../include/pokemon_fogo.h"
#include "../include/pokemon_grama.h"
#include "../include/batalha.h"

Squirtle aguin = Squirtle("aguin",15,10,10,50,5);
Charmander foguin = Charmander("foguin",15,10,10,50,5);
Bulbasauro verdin = Bulbasauro("verdin",15,10,10,50,5);

void introducao(Treinador jogador) {
    int p;
    std::string nome;

    std::cout << "Bem-vindo ao mundo Pokemon!" << std::endl;
    std::cout << "Qual será o seu nome de treinador?" << std::endl;

    std::getline(std::cin, nome);
    jogador = Treinador(nome, 1);

    std::cout << "Pokemons para escolher: Bulbasauro, Squirtle e Charmander." << std::endl;
    std::cout << "Digite 1 para Bulbasauro, 2 para Squirtle e 3 para Charmander." << std::endl;
    std::cin >> p;
    switch(p) {
        case 1:
            jogador.add_pokemon(&verdin);
            break;
        case 2:
            jogador.add_pokemon(&aguin);
            break;
        case 3:
            jogador.add_pokemon(&foguin);
            break;
    }
}

void escolher_modo(Treinador jogador, Pokemon *meu_poke, int dificuldade) {
    int p;
    if (jogador._lista_de_pokemons.size() < 3) {
        std::cout << "Digite 1 para modo 1X1. (Os outros modos são liberados ao ter 3 pokémons na equipe)" << std::endl;
        std::cin >> p;
        if (p == 1) {
            batalha_x1(jogador, meu_poke, dificuldade);
        }
    }
    else {
        std::cout << "Digite 1 para modo 1X1, 2 para modo 3X3 e 3 para modo Torneio" << std::endl;
        std::cin >> p;
        switch(p) {
            case 1:
                batalha_x1(jogador, meu_poke, dificuldade);
                break;
            case 2:
                //batalha_x3(Treinador jogador, Pokemon meu_poke);
                break;
            case 3:
                //torneio(Treinador jogador, Pokemon meu_poke);
                break;
        }
    }
}
