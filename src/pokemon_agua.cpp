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
/*
std::vector<std::string> Pokemon_Agua::get_imunidade() {
  return this->_imunidade;
}
*/
