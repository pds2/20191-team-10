#include "../include/pokemon.h"

#include <time.h>
#include <stdlib.h>
#include <string>
#include <iostream>

Pokemon::Pokemon(std::string apelido,int ataque,int defesa,int agilidade ,int hp,int crit):
	_apelido(apelido), _ataque(ataque),_defesa(defesa),_agilidade(agilidade),_hp(hp),_crit(crit),current_hp(hp){
		this->_iv = (rand() % 100) + 1;
	};

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
int Pokemon::get_iv(){
		return this->_iv;
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

void Pokemon::print_atributos(){
    std::cout<<"HP: \t\t"<<this->get_hp()<<"\n";
    std::cout<<"Ataque: \t"<<this->get_ataque()<<"\n";
    std::cout<<"Defesa: \t"<<this->get_defesa()<<"\n";
    std::cout<<"Agilidade: \t"<<this->get_agilidade()<<"\n";
}
