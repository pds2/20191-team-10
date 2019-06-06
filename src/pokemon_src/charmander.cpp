#include "../../include/pokemon_fogo.h"
#include "../../include/pokemon_include/charmander.h"

#include <iostream>

Charmander::Charmander(int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Fogo(ataque, defesa, agilidade, hp, crit) {set_nome("charmander");set_apelido("charmander");};

Charmander::Charmander(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Fogo(apelido, ataque, defesa, agilidade, hp, crit) {set_nome("charmander");};

Charmander::Charmander(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit, std::string fraqueza, std::string resistencia):
	Pokemon_Fogo(apelido, ataque, defesa, agilidade, hp, crit, fraqueza, resistencia) {set_nome("charmander");};

// Métodos Polimórficos :


// Habilidades....
