#include "../include/pokemon.h"
#include "../include/squirtle.h"

#include <string>
#include <iostream>


Squirtle::Squirtle(std::string nome,char tipo,int ataque,int defesa,int agilidade,int hp, int crit):
	Pokemon(nome,tipo,ataque,defesa,agilidade,hp,crit){};

// Métodos Polimórficos :

void Squirtle::atacar(Pokemon *adv){
    std::cout<<"Dummy Function";
}

// Habilidades....
