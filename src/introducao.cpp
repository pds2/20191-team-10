#include <iostream>
#include <string>
#include <vector>
#include "../include/introducao.h"
#include "../include/pokemon.h"
#include "../include/treinador.h"

void introducao() {
    int p;
    Treinador uno;
    std::string nome;

    std::cout << "Bem-vindo ao mundo Pokemon!" << std::endl;
    std::cout << "Qual será o seu nome de treinador?" << std::endl;

    std::getline(std::cin, nome);
    uno = Treinador(nome, 1);

    std::cout << "Pokemons para escolher: Bulbasauro, Squirtle e Charmander." << std::endl;
    std::cout << "Digite 1 para Bulbasauro, 2 para Squirtle e 3 para Charmander." << std::endl;
    std::cin >> p;
    switch(p) {
        case 1:
            uno.add_pokemon(&verdin);
            break;
        case 2:
            uno.add_pokemon(&aguin);
            break;
        case 3:
            uno.add_pokemon(&foguin);
            break;
    }
}

void escolher_modo() {
    int p;
    if (uno._lista_de_pokemons.size() < 3) {
        std::cout << "Digite 1 para modo 1X1. (Os outros modos são liberados ao ter 3 pokémons na equipe)" << std::endl;
        std::cin >> p;
        if (p == 1) {
            batalha_x1();
        }
    }
    else {
        std::cout << "Digite 1 para modo 1X1, 2 para modo 3X3 e 3 para modo Torneio" << std::endl;
        std::cin >> p;
        switch(p) {
            case 1:
                batalha_x1(Treinador jogador, Pokemon meu_poke);
                break;
            case 2:
                batalha_x3(Treinador jogador, Pokemon meu_poke);
                break;
            case 3:
                torneio(Treinador jogador, Pokemon meu_poke);
                break;
        }
    }
}
