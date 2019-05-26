#include "../../include/pokemon_fogo.h"
#include "../../include/pokemon_include/charmander.h"

#include <iostream>

Charmander::Charmander(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Fogo(nome, ataque, defesa, agilidade, hp, crit){};

Charmander::Charmander(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::string fraqueza, std::string resistencia):
	Pokemon_Fogo(nome, ataque, defesa, agilidade, hp, crit, fraqueza, resistencia){};

// Métodos Polimórficos :

void Charmander::atacar(Pokemon *adv){
    std::cout<<"Dummy Function";
}

// Habilidades....
