#ifndef POKEMON_FOGO_H
#define POKEMON_FOGO_H

#include "pokemon.h"

class Pokemon_Fogo : public Pokemon {
protected:
  std::vector<std::string> _fraqueza = {"agua"};
  std::vector<std::string> _resistencia = {"fogo", "grama"};
  std::vector<std::string> _imunidade = {""};

public:
  Pokemon_Fogo(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit);
  Pokemon_Fogo(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::vector<std::string> fraqueza, std::vector<std::string> resistencia, std::vector<std::string> imunidade);

  std::vector<std::string> get_fraqueza();
  std::vector<std::string> get_resistencia();
  std::vector<std::string> get_imunidade();

};

#endif
