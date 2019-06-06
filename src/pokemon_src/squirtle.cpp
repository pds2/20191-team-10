#include "../../include/pokemon_agua.h"
#include "../../include/pokemon_include/squirtle.h"

#include <iostream>

Squirtle::Squirtle(int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Agua(ataque, defesa, agilidade, hp, crit) {set_nome("squirtle");set_apelido("squirtle");};

Squirtle::Squirtle(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Agua(apelido, ataque, defesa, agilidade, hp, crit) {set_nome("squirtle");};

Squirtle::Squirtle(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit, std::string fraqueza, std::string resistencia):
	Pokemon_Agua(apelido, ataque, defesa, agilidade, hp, crit, fraqueza, resistencia) {set_nome("squirtle");};

// Métodos Polimórficos :

// Habilidades....
