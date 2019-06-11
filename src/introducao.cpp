#include <iostream>
#include <string>
#include <vector>
#include "../include/introducao.h"

//Squirtle aguin = Squirtle("aguin",15,10,10,50,5);
//Charmander foguin = Charmander("foguin",15,10,10,50,5);
//Bulbasauro verdin = Bulbasauro("verdin",15,10,10,50,5);

std::string apelida_jogador() {
    std::string nome;
    std::cout << "Bem-vindo ao mundo Pokemon!\nQual o seu nome? ";
    std::getline(std::cin, nome);
    return nome;
}

void introducao(Treinador *jogador) {
    std::string escolha;

    std::cout << "Voce ganhou seus Pokemons iniciais! Bulbasauro, Charmander e Squirtle." << std::endl;
    std::cout << "Deseja apelida-los? ";
    std::getline(std::cin, escolha);
    if (escolha[0] == 'S' || escolha[0] == 's') {
        std::string bulbasaur, charm, squir;

        std::cout << "Apelido para Bulbasauro: ";
        std::getline(std::cin, bulbasaur);
        std::cout << "Apelido para Charmander: ";
        std::getline(std::cin, charm);
        std::cout << "Apelido para Squirtle: ";
        std::getline(std::cin, squir);

        Bulbasauro *bulba = new Bulbasauro(bulbasaur);
        Charmander *charmander = new Charmander(charm);
        Squirtle *squirtle = new Squirtle(squir);
        
        jogador->add_pokemon(bulba);
        jogador->add_pokemon(charmander);
        jogador->add_pokemon(squirtle);
    }
    else {
        Bulbasauro *bulba = new Bulbasauro("Bulbasauro");
        Charmander *charmander = new Charmander("Charmander");
        Squirtle *squirtle = new Squirtle("Squirtle");

        jogador->add_pokemon(bulba);
        jogador->add_pokemon(charmander);
        jogador->add_pokemon(squirtle);
    }

    /*while (escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3') {
        try {
            std::cin >> escolha;
            verifica_entrada(escolha);
        } catch (Excpt_Entrada_Inicial &e) {
                std::cout << e.what();
        } catch (std::invalid_argument &e) {
                std::cout << "Entrada invalida! Digite 1, 2 ou 3!" << std::endl;
        }
    }

    switch(p) {
        case 1: {
            Bulbasauro *bulba = new Bulbasauro("Bulbasauro");
            jogador->add_pokemon(bulba);
            break;
        }
        case 2: {
            Charmander *charmander = new Charmander("Charmander");
            jogador->add_pokemon(charmander);
            break;
        }
        case 3: {
            Squirtle *squirtle = new Squirtle("Squirtle");
            jogador->add_pokemon(squirtle);
            break;
        }
    }*/
}

void verifica_entrada(std::string p) {
    if ((p[0] != '1') || (p[0] != '2') || (p[0] != '3')) {
        Excpt_Entrada_Inicial x;
        throw x;
    }
}

/*void escolher_modo(Treinador jogador, Pokemon *meu_poke, int dificuldade) {
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
}*/
