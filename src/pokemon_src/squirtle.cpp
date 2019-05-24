#include "../include/pokemon_agua.h"
#include "../../include/pokemon_include/squirtle.h"

#include <string>
#include <iostream>

Squirtle::Squirtle(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit):
	Pokemon_Agua(nome, ataque, defesa, agilidade, hp, crit){};

Squirtle::Squirtle(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit, std::vector<std::string> fraqueza, std::vector<std::string> resistencia, std::vector<std::string> imunidade):
	Pokemon_Agua(nome, ataque, defesa, agilidade, hp, crit, fraqueza, resistencia, imunidade){};

// Métodos Polimórficos :

void Squirtle::atacar(Pokemon *adv){
    std::cout<<"Dummy Function"; //vamos utilizar os metodos get_fraqueza/get_resistencia/get_imunidade
																//para determinar o ataque
}

// Habilidades....
