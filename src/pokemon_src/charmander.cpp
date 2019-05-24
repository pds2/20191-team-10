#include "../include/pokemon.h"
#include "../../include/pokemon_include/charmander.h"

#include <string>
#include <iostream>


Charmander::Charmander(std::string nome,char tipo,int ataque,int defesa,int agilidade,int hp, int crit):
	Pokemon(nome,tipo,ataque,defesa,agilidade,hp,crit){};

// Métodos Polimórficos :

void Charmander::atacar(Pokemon *adv){
    std::cout<<"Dummy Function";
}

// Habilidades....
