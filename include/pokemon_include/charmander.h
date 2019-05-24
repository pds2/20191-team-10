#ifndef CHARMANDER_H
#define CHARMANDER_H

#include "pokemon.h"

#include <string>

class Charmander: public Pokemon{
	public:
		Charmander(std::string,char,int,int,int,int,int);

		virtual void atacar(Pokemon *) override;

		// Habilidades....
};

#endif // CHARMANDER_H
