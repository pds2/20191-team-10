#ifndef SQUIRTLE_H
#define SQUIRTLE_H

#include "pokemon_agua.h"

#include <string>

class Squirtle : public Pokemon_Agua{
	public:
		Squirtle(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::vector<std::string> fraqueza, std::vector<std::string> resistencia, std::vector<std::string> imunidade);
		Squirtle(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit);

		virtual void atacar(Pokemon *) override;

		// Habilidades....
};

#endif // SQUIRTLE_H
