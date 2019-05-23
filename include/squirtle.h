#ifndef SQUIRTLE_H
#define SQUIRTLE_H

#include "pokemonAgua.h"

#include <string>

class Squirtle: public PokemonAgua{
	public:
		Squirtle(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit,/
		std::vector<std::string> fraqueza, std::vector<std::string> resistencia, std::vector<std::string> imunidade);

		virtual void atacar(Pokemon *) override;

		// Habilidades....
};

#endif // SQUIRTLE_H
