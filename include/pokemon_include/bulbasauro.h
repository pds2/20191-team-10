#ifndef BULBASAURO_H
#define BULBASAURO_H

#include "../pokemon_grama.h"

#include <string>

class Bulbasauro : public Pokemon_Grama {
	public:
		Bulbasauro(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::vector<std::string> fraqueza, std::vector<std::string> resistencia, std::vector<std::string> imunidade);
		Bulbasauro(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit);

		virtual void atacar(Pokemon *) override;

		// Habilidades....
};

#endif // BULBASAURO_H
