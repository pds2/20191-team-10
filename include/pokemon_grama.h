#ifndef POKEMON_GRAMA_H
#define POKEMON_GRAMA_H

#include "pokemon.h"

class Pokemon_Grama : public Pokemon {
protected:
  std::string _fraqueza = {"fogo"};
  std::string _resistencia = {"agua"};
  std::string _habilidades[4] = {"Investida", "Folha Navalha", "Chicote de Vinha", "Raio Solar"};
  //std::vector<std::string> _imunidade = {""};
  /*_fraqueza = {"fogo"};
  _resistencia = {"agua"};*/

public:
  Pokemon_Grama(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit);
  virtual ~Pokemon_Grama(){};

  std::string get_fraqueza();
  std::string get_resistencia();
  
  virtual void print_habilidades(int) override;

  virtual std::string get_habilidade(int) override;

  virtual void atacar(Pokemon *, int) override;
  //std::vector<std::string> get_imunidade();
};

#endif
