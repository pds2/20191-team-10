#include "../include/batalha.h"
#include "../include/excecoes.h"

#include <stdexcept>
#include <exception>
#include <ctime>
#include <cstdlib>

int rola_dados(){

	int temp = (rand()%10) + 1;

	return(temp);
}

void encerrar_batalha(Pokemon *poke){
    try{
        excpt_verificar_morto(poke);
    }
    catch(std::out_of_range &e){
        poke->current_hp=poke->get_hp();
    }
}
