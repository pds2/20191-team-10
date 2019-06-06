#ifndef CHARMANDER_H
#define CHARMANDER_H

#include "../pokemon_fogo.h"

#include <string>

class Charmander : public Pokemon_Fogo {
	public:
		Charmander(int ataque, int defesa, int agilidade, int hp, int crit);
		Charmander(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit);
		Charmander(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit,
				   std::string fraqueza, std::string resistencia);

		// Habilidades....
};

#endif // CHARMANDER_H
