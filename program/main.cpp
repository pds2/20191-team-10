// #include "../include/pokemon.h"

#include "../include/introducao.h"
#include "../include/treinador.h"
#include "../include/excecoes.h"
#include "../include/batalha.h"
#include "../include/interface.h"
#include "../include/pokebola.h"
#include "../include/pokedex.h"

#include <iostream>
#include <string>
#include <ctime>

#define DIFICULDADE_FACIL 1
#define DIFICULDADE_MEDIO 2
#define DIFICULDADE_DIFICIL 3

int main() {

    srand (time(NULL));
/*
    Squirtle aguin = Squirtle("Tartaruga");
    Wartotle aguin2 = Wartotle("War Turtle");
    Blastoise aguin3 = Blastoise("Blast");

	Charmander foguin = Charmander("Chama");
	Charmeleon foguin2 = Charmeleon("Lagartixa de Fogo");
	Charizard foguin3  = Charizard("Dragão");

	Bulbasauro verdin = Bulbasauro("Alpiste");
	Ivysaur verdin2 = Ivysaur("Trepadeira");
	Venosauro verdin3 = Venosauro("Peçonhento");
*/
	print_ascii_art("intro");
    print_ascii_art("blastoise+charizard");

	Treinador uno = Treinador(apelida_jogador(),4);
/*
	uno.add_pokemon(&aguin); // add_pokemon(x) adiciona o pokemon x ao vetor de Pokemons presente na classe Jogador
    uno.add_pokemon(&aguin2);
	uno.add_pokemon(&aguin3);
    uno.add_pokemon(&foguin);
	uno.add_pokemon(&foguin2);
	uno.add_pokemon(&foguin3);
	uno.add_pokemon(&verdin);
    uno.add_pokemon(&verdin2);
	uno.add_pokemon(&verdin3);
*/
	introducao(&uno);
	treinador_info(uno);
	int escolha = escolher_pokemon(uno);
	batalha_x1(uno, (uno._lista_de_pokemon.at(escolha)), DIFICULDADE_FACIL);

	return 0;
}
