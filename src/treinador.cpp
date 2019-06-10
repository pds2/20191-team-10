#include "../include/treinador.h"
#include "../include/pokemon.h"
#include "../include/pokemon_agua.h"
#include "../include/excecoes.h"
#include "../include/interface.h"

#include <iostream>
#include <string>
#include <vector>

Treinador::Treinador(std::string nome, int lideranca):
	_treinador(nome), _lideranca(lideranca)
	{
	    set_pokeball(5);set_greatball(0);set_masterball(0);set_capturas_efetivas(0);set_capturas_totais(0);

	    try{
            verificar_lideranca_valida(lideranca);
        }
        catch(Excpt_Lideranca_Invalida &e){
            std::cout<<e.what();
            lideranca = tratamento_lideranca_invalida();
            set_lideranca(lideranca);
        }

    };

std::string Treinador::get_treinador(){
	return _treinador;
}
int Treinador::get_lideranca(){
	return _lideranca;
}
void Treinador::set_lideranca(int x){
	_lideranca=x;
}
int Treinador::get_pokeball(){
	return _pokeball;
}
void Treinador::set_pokeball(int quantidade){
	this->_pokeball = quantidade;
}
int Treinador::get_greatball(){
	return _greatball;
}
void Treinador::set_greatball(int quantidade){
	this->_greatball = quantidade;
}
int Treinador::get_masterball(){
	return _masterball;
}
void Treinador::set_masterball(int quantidade){
	this->_masterball = quantidade;
}
int Treinador::get_capturas_efetivas(){
	return _capturas_efetivas;
}
void Treinador::set_capturas_efetivas(int capturas){
	this->_capturas_efetivas = capturas;
}
int Treinador::get_capturas_totais(){
	return _capturas_totais;
}
void Treinador::set_capturas_totais(int capturas){
	this->_capturas_totais = capturas;
}
int Treinador::get_taxa_sucesso(){
	return (_capturas_efetivas/_capturas_totais);
}
void Treinador::add_pokemon(Pokemon *novo_pokemon){
	_lista_de_pokemon.push_back(novo_pokemon);
}

void Treinador::print_lista_pokemon(){
	for(unsigned i=0; i < this->_lista_de_pokemon.size(); i++){
		std::cout << "\t" << i+1 << " - " <<"Tipo: "<< _lista_de_pokemon.at(i)->get_nome()<<" - Apelidado : "<< _lista_de_pokemon.at(i)->get_apelido()<<"\n";
	}
}
