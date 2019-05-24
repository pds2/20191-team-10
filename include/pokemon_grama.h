#ifndef POKEMON_GRAMA_H
#define POKEMON_GRAMA_H

#include "pokemon.h"

class Pokemon_Grama : public Pokemon {
protected:
  std::vector<std::string> _fraqueza = {"fogo"};
  std::vector<std::string> _resistencia = {"grama", "agua", "eletrico"};
  std::vector<std::string> _imunidade = {""};

public:
  Pokemon_Grama(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit);
  Pokemon_Grama(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::vector<std::string> fraqueza, std::vector<std::string> resistencia, std::vector<std::string> imunidade);

  std::vector<std::string> get_fraqueza();
  std::vector<std::string> get_resistencia();
  std::vector<std::string> get_imunidade();
};

#endif
