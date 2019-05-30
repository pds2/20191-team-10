#include "../include/treinador.h"
#include "../include/pokemon.h"
#include "../include/pokemon_agua.h"

#include <iostream>
#include <string>
#include <vector>

Treinador::Treinador(std::string nome, int lideranca):
	_treinador(nome), _lideranca(lideranca){};

std::string Treinador::get_treinador(){
	return _treinador;
}
int Treinador::get_lideranca(){
	return _lideranca;
}
void Treinador::set_lideranca(int x){
	_lideranca=x;
}
void Treinador::add_pokemon(Pokemon *novo_pokemon){
	_lista_de_pokemon.push_back(novo_pokemon);
}

void Treinador::print_lista_pokemon(){
	for(int i=0; i < this->_lista_de_pokemon.size(); i++){
		//std::cout<<uno._lista_de_pokemons.at(i)->get_nome()<<"\n"; // Imprima o nome do pokemon na posição 'i' da _lista_de_pokemon do treinador uno
		//std::cout << "\tO treinador "<<this->_jogador<<" possui o pokemon : ";
		std::cout << "\t" << i+1 << " - " <<"Tipo: "<< _lista_de_pokemon.at(i)->get_nome()<<" - "<< _lista_de_pokemon.at(i)->get_apelido()<<"\n";
	}
}
