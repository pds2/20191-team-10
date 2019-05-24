#ifndef POKEMON_AGUA_H
#define POKEMON_AGUA_H

#include "pokemon.h"

#include <vector>


class Pokemon_Agua : public Pokemon {
protected:
  std::vector<std::string> _fraqueza = {"grama", "eletrico"};
  std::vector<std::string> _resistencia = {"fogo", "agua"};
  std::vector<std::string> _imunidade = {""};

public:
  Pokemon_Agua(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit);
  Pokemon_Agua(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::vector<std::string> fraqueza, std::vector<std::string> resistencia, std::vector<std::string> imunidade);

  std::vector<std::string> get_fraqueza();
  std::vector<std::string> get_resistencia();
  std::vector<std::string> get_imunidade();

};


#endif
