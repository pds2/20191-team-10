#ifndef POKEMON_AGUA_H
#define POKEMON_AGUA_H

#include "pokemon.h"

class Pokemon_Agua : public Pokemon {
protected:
  std::string _fraqueza = {"grama"};
  std::string _resistencia = {"fogo"};
  std::string _habilidades[4] = {"Investida", "Bolhas", "Pistola D'agua", "Hidro Bomba"};
  //std::vector<std::string> _imunidade = {""};
/*_fraqueza = {"grama"};
_resistencia = {"fogo"};*/

public:
  Pokemon_Agua(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit);

  std::string get_fraqueza();
  std::string get_resistencia();
  virtual void print_habilidades(int) override;

  virtual void atacar(Pokemon *, int) override;
  //std::vector<std::string> get_imunidade();

};


#endif
