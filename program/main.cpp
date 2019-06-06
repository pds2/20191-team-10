// #include "../include/pokemon.h"
// #include "../include/introducao.h"
#include "../include/pokemon_include/charmander.h"
#include "../include/pokemon_include/bulbasauro.h"
#include "../include/pokemon_include/squirtle.h"
#include "../include/treinador.h"
#include "../include/excecoes.h"
#include "../include/batalha.h"
#include "../include/interface.h"
#include "../include/pokebola.h"
#include "../include/pokedex.h"

#include <iostream>
#include <string>

int main() {
	Squirtle aguin = Squirtle("aguin");
	Charmander foguin = Charmander("foguin");
	Bulbasauro verdin = Bulbasauro("verdin");

	std::cout << "Resistência: " << aguin.get_resistencia() << std::endl;
	std::cout << "Fraqueza: " << aguin.get_fraqueza() << std::endl;

	Treinador uno = Treinador("Leandro",4);

	uno.add_pokemon(&aguin); // add_pokemon(x) adiciona o pokemon x ao vetor de Pokemons presente na classe Jogador
	uno.add_pokemon(&foguin);
	uno.add_pokemon(&verdin);

	//Abaixo temos um exemplo de como acessar elementos específicos dos pokemons pertencentes a um treinador

	std::cout<<"Segue a lista dos pokemon desse treinador:\n";
	uno.print_lista_pokemon();

	std::cout<<"Atributos :\n";
	std::cout<<"Ataque : = "<<uno._lista_de_pokemon.at(1)->get_ataque()<<"\n";
	std::cout<<"Defesa : = "<<uno._lista_de_pokemon.at(1)->get_defesa()<<"\n";
	std::cout<<"Agilidade : = "<<uno._lista_de_pokemon.at(1)->get_agilidade()<<"\n";

	int escolha = escolher_pokemon(uno);
	batalha_x1(uno, (uno._lista_de_pokemon.at(escolha)), 1);
	treinador_info(uno);

	return 0;
}
