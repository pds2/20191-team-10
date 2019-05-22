#ifndef SQUIRTLE_H
#define SQUIRTLE_H

#include "pokemon.h"

#include <string>

class Squirtle: public Pokemon{
	public:
		Squirtle(std::string,char,int,int,int,int,int);

		virtual void atacar(Pokemon *) override;

		// Habilidades....
};

#endif // SQUIRTLE_H
