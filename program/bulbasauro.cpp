#include "../include/pokemon.h"
#include "../include/bulbasauro.h"

#include <string>
#include <iostream>


Bulbasauro::Bulbasauro(std::string nome,char tipo,int ataque,int defesa,int agilidade,int hp, int crit):
	Pokemon(nome,tipo,ataque,defesa,agilidade,hp,crit){};

// Métodos Polimórficos :

void Bulbasauro::atacar(Pokemon *adv){
    std::cout<<"Dummy Function";
}

// Habilidades....

