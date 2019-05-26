#ifndef POKEMON_AGUA_H
#define POKEMON_AGUA_H

#include "pokemon.h"

#include <string>

class Pokemon_Agua : public Pokemon {
protected:
  std::string _fraqueza = {"grama"};
  std::string _resistencia = {"agua"};
  //std::vector<std::string> _imunidade = {""};

public:
  Pokemon_Agua(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit);
  Pokemon_Agua(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::string fraqueza, std::string resistencia);

  std::string get_fraqueza();
  std::string get_resistencia();
  //std::vector<std::string> get_imunidade();

};


#endif
