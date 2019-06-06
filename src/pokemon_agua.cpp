#include "../include/pokemon_agua.h"

Pokemon_Agua::Pokemon_Agua(int ataque, int defesa, int agilidade, int hp, int crit):
  Pokemon(ataque, defesa, agilidade, hp, crit) {};

Pokemon_Agua::Pokemon_Agua(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit):
  Pokemon(apelido, ataque, defesa, agilidade, hp, crit) {};

Pokemon_Agua::Pokemon_Agua(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit,
                           std::string fraqueza, std::string resistencia):
  Pokemon(apelido, ataque, defesa, agilidade, hp, crit), _fraqueza(fraqueza), _resistencia(resistencia) {}

std::string Pokemon_Agua::get_fraqueza() {
  return this->_fraqueza;
}

std::string Pokemon_Agua::get_resistencia() {
  return this->_resistencia;
}

void Pokemon_Agua::print_habilidades(int lideranca){
	for(int i=0; i<lideranca; i++){
		std::cout << "\t" << i+1 << " - " << _habilidades[i] << std::endl;
	}
}

void Pokemon_Agua::atacar(Pokemon *adv, int habilidade){
	if(habilidade == 1){
		adv->current_hp -= this->get_ataque() - adv->get_defesa();
	}else{
		if(adv->get_fraqueza() == "agua"){
			adv->current_hp -= int ((this->get_ataque() + DANO_HABILIDADE * habilidade) * AUMENTO) - adv->get_defesa();
		}else if(adv->get_resistencia() == "agua"){
			adv->current_hp -= int ((this->get_ataque() + DANO_HABILIDADE * habilidade) * REDUCAO) - adv->get_defesa();
		}else{
			adv->current_hp -= int ((this->get_ataque() + DANO_HABILIDADE * habilidade)) - adv->get_defesa();
		}
	}
}
/*
std::vector<std::string> Pokemon_Agua::get_imunidade() {
  return this->_imunidade;
}
*/
