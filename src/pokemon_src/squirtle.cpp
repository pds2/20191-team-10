#include "../../include/pokemon_agua.h"
#include "../../include/pokemon_include/squirtle.h"

#include <iostream>

Squirtle::Squirtle(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Agua(nome, ataque, defesa, agilidade, hp, crit){};

Squirtle::Squirtle(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::string fraqueza, std::string resistencia):
	Pokemon_Agua(nome, ataque, defesa, agilidade, hp, crit, fraqueza, resistencia){};

// Métodos Polimórficos :

void Squirtle::atacar(Pokemon *adv){
    if(adv->get_fraqueza() == "agua"){
		adv->current_hp -= int (this->get_ataque() * AUMENTO) - adv->get_defesa();
	}else if(adv->get_resistencia() == "agua"){
		adv->current_hp -= int (this->get_ataque() * REDUCAO) - adv->get_defesa();
	}else{
		adv->current_hp -= this->get_ataque() - adv->get_defesa();
	}
}

// Habilidades....
