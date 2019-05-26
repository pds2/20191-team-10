#ifndef POKEMON_GRAMA_H
#define POKEMON_GRAMA_H

#include "pokemon.h"

class Pokemon_Grama : public Pokemon {
protected:
  std::string _fraqueza = {"fogo"};
  std::string _resistencia = {"grama"};
  //std::vector<std::string> _imunidade = {""};

public:
  Pokemon_Grama(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit);
  Pokemon_Grama(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, 
                std::string fraqueza, std::string resistencia);

  std::string get_fraqueza();
  std::string get_resistencia();
  //std::vector<std::string> get_imunidade();
};

#endif
