#include "../include/pokemon_fogo.h"

Pokemon_Fogo::Pokemon_Fogo(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit):
  Pokemon(nome, ataque, defesa, agilidade, hp, crit) {}

Pokemon_Fogo::Pokemon_Fogo(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::vector<std::string> fraqueza, std::vector<std::string> resistencia, std::vector<std::string> imunidade):
  Pokemon(nome, ataque, defesa, agilidade, hp, crit), _fraqueza(fraqueza), _resistencia(resistencia), _imunidade(imunidade) {}

std::vector<std::string> Pokemon_Fogo::get_fraqueza() {
  return this->_fraqueza;
}

std::vector<std::string> Pokemon_Fogo::get_resistencia() {
  return this->_resistencia;
}

std::vector<std::string> Pokemon_Fogo::get_imunidade() {
  return this->_imunidade;
}
