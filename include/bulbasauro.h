#ifndef BULBASAURO_H
#define BULBASAURO_H

#include "pokemon.h"

#include <string>

class Bulbasauro: public Pokemon{
	public:
		Bulbasauro(std::string,char,int,int,int,int,int);

		virtual void atacar(Pokemon *) override;

		// Habilidades....
};

#endif // BULBASAURO_H
