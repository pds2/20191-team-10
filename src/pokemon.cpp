#include "../include/pokemon.h"

#include <string>
#include <iostream>

Pokemon::Pokemon(std::string apelido,int ataque,int defesa,int agilidade ,int hp,int crit):
	_apelido(apelido), _ataque(ataque),_defesa(defesa),_agilidade(agilidade),_hp(hp),_crit(crit),current_hp(hp){};

int Pokemon::get_ataque(){
    return this->_ataque;
}
int Pokemon::get_defesa(){
    return this->_defesa;
}
int Pokemon::get_agilidade(){
    return this->_agilidade;
}
int Pokemon::get_hp(){
    return this->_hp;
}
int Pokemon::get_crit(){
    return this->_crit;
}

void Pokemon::set_nome(std::string nome){
		this->_nome = nome;
}

std::string Pokemon::get_nome(){
  	return this->_nome;
}

void Pokemon::set_apelido(std::string apelido){
		this->_apelido = apelido;
}

std::string Pokemon::get_apelido(){
		return this->_apelido;
}
