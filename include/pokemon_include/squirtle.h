#ifndef SQUIRTLE_H
#define SQUIRTLE_H

#include "../pokemon_agua.h"

#include <string>

class Squirtle : public Pokemon_Agua{
public:
		Squirtle(int ataque, int defesa, int agilidade, int hp, int crit);
		Squirtle(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit);
		Squirtle(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit,
				 std::string fraqueza, std::string resistencia);

		// Habilidades....
};

#endif // SQUIRTLE_H
