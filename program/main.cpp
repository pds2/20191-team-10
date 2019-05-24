#include "../include/pokemon.h"
#include "../include/pokemon_agua.h"
#include "../include/pokemon_include/charmander.h"
#include "../include/pokemon_include/bulbasauro.h"
#include "../include/pokemon_include/squirtle.h"
#include "../include/treinador.h"

#include <iostream>
#include <string>

int main() {
	Squirtle aguin = Squirtle("aguin",15,10,10,50,5);
	// Charmander foguin = Charmander("foguin",15,10,10,50,5);
	// Bulbasauro verdin = Bulbasauro("verdin",15,10,10,50,5);

	Treinador uno = Treinador("Leandro",4);
	//
	// uno.add_pokemon(&aguin); // add_pokemon(x) adiciona o pokemon x ao vetor de Pokemons presente na classe Jogador
	// uno.add_pokemon(&foguin);
	// uno.add_pokemon(&verdin);
	//
	// //Abaixo temos um exemplo de como acessar elementos específicos dos pokemons pertencentes a um treinador
	//
	// std::cout<<"Segue a lista dos pokemons desse treinador:\n";
	// for(int i=0; i < uno._lista_de_pokemons.size() ; i++){
	// 	std::cout<<uno._lista_de_pokemons.at(i)->get_nome()<<"\n"; // Imprima o nome do pokemon na posição 'i' da _lista_de_pokemon do treinador uno
	// }
	//
	// std::cout<<"O treinador : "<<uno.get_jogador()<<", possui o pokemon : "<<uno._lista_de_pokemons.at(1)->get_nome()<<"\n";
	// std::cout<<"Atributos :\n";
	// std::cout<<"Ataque : = "<<uno._lista_de_pokemons.at(1)->get_ataque()<<"\n";
	// std::cout<<"Defesa : = "<<uno._lista_de_pokemons.at(1)->get_defesa()<<"\n";
	// std::cout<<"Agilidade : = "<<uno._lista_de_pokemons.at(1)->get_agilidade()<<"\n";

	return 0;
}
