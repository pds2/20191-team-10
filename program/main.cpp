#include "../include/pokemon.h"
#include "../include/treinador.h"
#include "../include/batalha.h"
#include "../include/pokedex.h"

#include <vector>
#include <string>
#include <iostream>

int main(){

	Treinador uno = Treinador("Leandro",4); // Criamos o treinador "uno" cujo nome é Leandro e o nível de lideranca é Mestre
											// via o construtor Treinador(nome,liderança)

	uno.add_pokemon(Bulbasauro); // add_pokemon(x) adiciona o pokemon x ao vetor de Pokemons presente na classe Jogador
	uno.add_pokemon(Charmander); // Importante : Os pokemons devem ser criados dentro do Header Pokedex via
	uno.add_pokemon(Squirtle);   // o construtor Pokemon(nome,crit,HP,ataque,defesa,agilidade)

	//Abaixo temos um exemplo de como acessar elementos específicos dos pokemons pertencentes a um treinador

	std::cout<<"Segue a lista de todos os pokemons :\n";
	for(int i=0;i<uno._lista_de_pokemons.size();i++){
		std::cout<<uno._lista_de_pokemons.at(i).get_nome()<<"\n"; // Imprima o nome do pokemon na posição 'i' da _lista_de_pokemon do treinador uno
	}

	std::cout<<"\n";

	std::cout<<"O treinador : "<<uno.get_jogador()<<" possui o pokemon : "<<uno._lista_de_pokemons.at(1).get_nome()<<"\n";
	std::cout<<"Atributos :\n";
	std::cout<<"Ataque : "<<uno._lista_de_pokemons.at(1)._ataque<<" = "<<uno._lista_de_pokemons.at(1).get_ataque()<<"\n";
	std::cout<<"Defesa : "<<uno._lista_de_pokemons.at(1)._defesa<<" = "<<uno._lista_de_pokemons.at(1).get_defesa()<<"\n";
	std::cout<<"Agilidade : "<<uno._lista_de_pokemons.at(1)._agilidade<<" = "<<uno._lista_de_pokemons.at(1).get_agilidade()<<"\n";

	return 0;
}
