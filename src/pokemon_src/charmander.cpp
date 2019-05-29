#include "../../include/pokemon_fogo.h"
#include "../../include/pokemon_include/charmander.h"

#include <iostream>

Charmander::Charmander(int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Fogo(ataque, defesa, agilidade, hp, crit) {set_nome("charmander");set_apelido("charmander");};

Charmander::Charmander(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Fogo(apelido, ataque, defesa, agilidade, hp, crit) {set_nome("charmander");};

Charmander::Charmander(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit, std::string fraqueza, std::string resistencia):
	Pokemon_Fogo(apelido, ataque, defesa, agilidade, hp, crit, fraqueza, resistencia) {set_nome("charmander");};

// Métodos Polimórficos :

void Charmander::atacar(Pokemon *adv){
    if(adv->get_fraqueza() == "fogo"){
		adv->current_hp -= int (this->get_ataque() * AUMENTO) - adv->get_defesa();
	}else if(adv->get_resistencia() == "fogo"){
		adv->current_hp -= int (this->get_ataque() * REDUCAO) - adv->get_defesa();
	}else{
		adv->current_hp -= this->get_ataque() - adv->get_defesa();
	}
}

// Habilidades....
