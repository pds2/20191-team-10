#ifndef INTERFACE_H
#define INTERFACE_H

#include "pokemon.h"
#include "treinador.h"
#include "pokebola.h"
#include "../include/pokemon_include/charmander.h"
#include "../include/pokemon_include/bulbasauro.h"
#include "../include/pokemon_include/squirtle.h"

#include <string>
#include <iostream>

// Esse header tem como prop�sito armazenar fun��es relacionadas � interface.
// Um bom crit�rio para escolher se voc� deve ou n�o colocar um m�todo nesse header
// � pensar :

// 1) Esse m�todo est� relacionado � funcionalidade de uma classe? Se n�o, o implemente aqui
// 2) O n�mero de prints e inputs utilizado pelo m�todo � grande? Se sim, o implemente aqui.
int escolher_pokebola(Treinador jogador, Pokemon *inimigo);

int escolher_pokemon(Treinador); //Fun��o que recebe um treinador e escolhe um de seus Pok�mon.

int escolher_habilidade(Pokemon *, int);

#endif // INTERFACE_H
