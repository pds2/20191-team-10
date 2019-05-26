#include "../include/pokemon_fogo.h"

Pokemon_Fogo::Pokemon_Fogo(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit):
  Pokemon(nome, ataque, defesa, agilidade, hp, crit) {};

Pokemon_Fogo::Pokemon_Fogo(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, 
                           std::string fraqueza, std::string resistencia):
  Pokemon(nome, ataque, defesa, agilidade, hp, crit), _fraqueza(fraqueza), _resistencia(resistencia) {};

std::string Pokemon_Fogo::get_fraqueza() {
  return this->_fraqueza;
}

std::string Pokemon_Fogo::get_resistencia() {
  return this->_resistencia;
}
/*
std::vector<std::string> Pokemon_Fogo::get_imunidade() {
  return this->_imunidade;
}
*/
