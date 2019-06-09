#ifndef POKEMON_FOGO_H
#define POKEMON_FOGO_H

#include "pokemon.h"

class Pokemon_Fogo : public Pokemon {
protected:
  std::string _fraqueza = {"agua"};
  std::string _resistencia = {"grama"};
  std::string _habilidades[4] = {"Investida", "Brasa", "Lanca Chamas", "Queimadura Explosiva"};
  //std::vector<std::string> _imunidade = {""};

public:
  Pokemon_Fogo(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit);
  virtual ~Pokemon_Fogo(){};

  std::string get_fraqueza();
  std::string get_resistencia();

  virtual void print_habilidades(int) override;

  virtual std::string get_habilidade(int) override;

	virtual void atacar(Pokemon *, int) override;
  //std::vector<std::string> get_imunidade();

};

#endif
