#ifndef POKEMON_AGUA_H
#define POKEMON_AGUA_H

#include <vector>

#include "pokemon.h"


class PokemonAgua : public Pokemon {
protected:
  std::vector<std::string> _fraqueza;
  std::vector<std::string> _resistencia;
  std::vector<std::string> _imunidade;

public:
  PokemonAgua(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::vector<std::string> fraqueza, std::vector<std::string> resistencia, std::vector<std::string> imunidade);

  std::vector<std::string> get_fraqueza();
  std::vector<std::string> get_resistencia();
  std::vector<std::string> get_imunidade();

};


#endif
