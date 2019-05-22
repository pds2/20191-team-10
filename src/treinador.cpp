#include "../include/treinador.h"
#include "../include/pokemon.h"

#include <iostream>
#include <string>
#include <vector>

Treinador::Treinador(std::string nome,int lideranca):
	_jogador(nome), _lideranca(lideranca){};

std::string Treinador::get_jogador(){
	return _jogador;
}
int Treinador::get_lideranca(){
	return _lideranca;
}
void Treinador::set_lideranca(int x){
	_lideranca=x;
}
void Treinador::add_pokemon(Pokemon *novo_pokemon){
	_lista_de_pokemons.push_back(novo_pokemon);
}
