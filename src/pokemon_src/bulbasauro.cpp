#include "../../include/pokemon_grama.h"
#include "../../include/pokemon_include/bulbasauro.h"

#include <iostream>

Bulbasauro::Bulbasauro(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Grama(nome, ataque, defesa, agilidade, hp, crit){};

Bulbasauro::Bulbasauro(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::vector<std::string> fraqueza, std::vector<std::string> resistencia, std::vector<std::string> imunidade):
	Pokemon_Grama(nome, ataque, defesa, agilidade, hp, crit, fraqueza, resistencia, imunidade){};

// Métodos Polimórficos :

void Bulbasauro::atacar(Pokemon *adv){
    std::cout<<"Dummy Function";
}

// Habilidades....
