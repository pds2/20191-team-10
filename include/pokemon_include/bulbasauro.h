#ifndef BULBASAURO_H
#define BULBASAURO_H

#include "../pokemon_grama.h"

#include <string>

class Bulbasauro : public Pokemon_Grama {
	public:
		Bulbasauro(int ataque, int defesa, int agilidade, int hp, int crit);
		Bulbasauro(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit);
		Bulbasauro(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit,
				   std::string fraqueza, std::string resistencia);

		virtual void atacar(Pokemon *) override;

		// Habilidades....
};

#endif // BULBASAURO_H
