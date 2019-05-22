#include "../include/batalha.h"
#include "../include/pokemon.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

int rola_dados(){

	int temp = (rand()%10) + 1;
	return(temp);
}

void verificar_morto(Pokemon *adv){
    if(adv->current_hp<=0){
        std::cout<<"Fim da batalha!";
        // Possibilidade de tratamento de exceção
        // throw ....
    }
}

void encerrar_batalha(Pokemon *meu_poke, Pokemon *adv){ // Função para tratar a exceção : Pokemon Morto
    meu_poke->current_hp=meu_poke->get_hp();
    adv->current_hp=adv->get_hp();
}
