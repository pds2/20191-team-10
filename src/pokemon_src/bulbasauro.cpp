#include "../../include/pokemon_grama.h"
#include "../../include/pokemon_include/bulbasauro.h"

#include <iostream>

Bulbasauro::Bulbasauro(int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Grama(ataque, defesa, agilidade, hp, crit) {set_nome("bulbasauro");set_apelido("bulbasauro");};

Bulbasauro::Bulbasauro(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Grama(apelido, ataque, defesa, agilidade, hp, crit) {set_nome("bulbasauro");};

Bulbasauro::Bulbasauro(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit,
					   std::string fraqueza, std::string resistencia):
	Pokemon_Grama(apelido, ataque, defesa, agilidade, hp, crit, fraqueza, resistencia) {set_nome("bulbasauro");};

// Métodos Polimórficos :

// Habilidades....
