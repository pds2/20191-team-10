#ifndef INTERFACE_H
#define INTERFACE_H

#include "pokemon.h"
#include "treinador.h"
#include "../include/pokemon_include/charmander.h"
#include "../include/pokemon_include/bulbasauro.h"
#include "../include/pokemon_include/squirtle.h"

#include <string>
#include <iostream>

// Esse header tem como propósito armazenar funções relacionadas à interface.
// Um bom critério para escolher se você deve ou não colocar um método nesse header
// é pensar :

// 1) Esse método está relacionado à funcionalidade de uma classe? Se não, o implemente aqui
// 2) O número de prints e inputs utilizado pelo método é grande? Se sim, o implemente aqui.

int escolher_pokemon(Treinador); //Função que recebe um treinador e escolhe um de seus Pokémon.

#endif // INTERFACE_H
