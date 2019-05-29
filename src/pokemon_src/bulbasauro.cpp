#include "../../include/pokemon_grama.h"
#include "../../include/pokemon_include/bulbasauro.h"

#include <iostream>

Bulbasauro::Bulbasauro(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Grama(apelido, ataque, defesa, agilidade, hp, crit){};

Bulbasauro::Bulbasauro(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit,
					   std::string fraqueza, std::string resistencia):
	Pokemon_Grama(apelido, ataque, defesa, agilidade, hp, crit, fraqueza, resistencia){};

// Métodos Polimórficos :

/*void Bulbasauro::atacar(Pokemon *adv){
    if(this->_resistencia == adv->_tipo){
		adv->current_hp -= this->get_ataque * AUMENTO - adv->get_defesa;
	}else if(this->_fraqueza == adv->tipo){
		adv->current_hp -= this->get_ataque * REDUCAO - adv->get_defesa;
	}else{
		adv->current_hp -= this->get_ataque - adv->get_defesa;
	}
}*/

void Bulbasauro::atacar(Pokemon *adv){
    if(adv->get_fraqueza() == "grama"){
		adv->current_hp -= int (this->get_ataque() * AUMENTO) - adv->get_defesa();
	}else if(adv->get_resistencia() == "grama"){
		adv->current_hp -= int (this->get_ataque() * REDUCAO) - adv->get_defesa();
	}else{
		adv->current_hp -= this->get_ataque() - adv->get_defesa();
	}
}
// Habilidades....
