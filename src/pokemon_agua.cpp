#include "../include/pokemon_agua.h"

Pokemon_Agua::Pokemon_Agua(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit):
  Pokemon(apelido, ataque, defesa, agilidade, hp, crit) {};

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

std::string Pokemon_Agua::get_habilidade(int indice){
	return _habilidades[indice-1];
}

void Pokemon_Agua::atacar(Pokemon *adv, int habilidade){
	if(habilidade == 1){
		if((this->get_ataque() - adv->get_defesa())<=0){
			adv->current_hp -= DANO_MINIMO;
		}else{
			adv->current_hp -= (this->get_ataque()*this->critical_hit()) - adv->get_defesa() + DANO_MINIMO;
		}
	}else{
		if(adv->get_fraqueza() == "agua"){
			adv->current_hp -= int ((this->critical_hit() * (this->get_ataque() + DANO_HABILIDADE * habilidade)) * AUMENTO) - adv->get_defesa();
		}else if(adv->get_resistencia() == "agua"){
			if((this->get_ataque() - adv->get_defesa())<=0){
			adv->current_hp -= DANO_MINIMO;
			}else{
				adv->current_hp -= int ((this->critical_hit() * (this->get_ataque() + DANO_HABILIDADE * habilidade)) * REDUCAO) - adv->get_defesa();
			}
		}else{
			adv->current_hp -= int ((this->critical_hit() * (this->get_ataque() + DANO_HABILIDADE * habilidade))) - adv->get_defesa();
		}
	}
}
/*
std::vector<std::string> Pokemon_Agua::get_imunidade() {
  return this->_imunidade;
}
*/
