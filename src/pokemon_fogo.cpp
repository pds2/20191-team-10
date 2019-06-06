#include "../include/pokemon_fogo.h"


Pokemon_Fogo::Pokemon_Fogo(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit):
  Pokemon(apelido, ataque, defesa, agilidade, hp, crit) {};

std::string Pokemon_Fogo::get_fraqueza() {
  return this->_fraqueza;
}

std::string Pokemon_Fogo::get_resistencia() {
  return this->_resistencia;
}

void Pokemon_Fogo::print_habilidades(int lideranca){
	for(int i=0; i<lideranca; i++){
		std::cout << "\t" << i+1 << " - " << _habilidades[i] << std::endl;
	}
}
void Pokemon_Fogo::atacar(Pokemon *adv, int habilidade){
	if(habilidade == 1){
		adv->current_hp -= this->get_ataque() - adv->get_defesa();
	}else{
		if(adv->get_fraqueza() == "fogo"){
			adv->current_hp -= int ((this->get_ataque() + DANO_HABILIDADE * habilidade) * AUMENTO) - adv->get_defesa();
		}else if(adv->get_resistencia() == "fogo"){
			adv->current_hp -= int ((this->get_ataque() + DANO_HABILIDADE * habilidade) * REDUCAO) - adv->get_defesa();
		}else{
			adv->current_hp -= int ((this->get_ataque() + DANO_HABILIDADE * habilidade)) - adv->get_defesa();
		}
	}
}
/*
std::vector<std::string> Pokemon_Fogo::get_imunidade() {
  return this->_imunidade;
}
*/
