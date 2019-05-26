#include "../include/excecoes.h"
#include "../include/pokemon.h"

#include <iostream>

void excpt_verificar_morto(Pokemon *poke){
    if(poke->current_hp<=0){
        throw std::out_of_range("Pokemon nocauteado!\n");
    }
}
