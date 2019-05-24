#ifndef CHARMANDER_H
#define CHARMANDER_H

#include "../pokemon_fogo.h"

#include <string>

class Charmander : public Pokemon_Fogo {
	public:
		Charmander(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::vector<std::string> fraqueza, std::vector<std::string> resistencia, std::vector<std::string> imunidade);
		Charmander(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit);

		virtual void atacar(Pokemon *) override;

		// Habilidades....
};

#endif // CHARMANDER_H
