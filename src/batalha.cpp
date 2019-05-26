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

void gera_oponente_facil(Pokemon *npc){
    int rand= rola_dados();
    
    if((rand<=4) && (rand>0)){
        npc = new Bulbasauro("npc",15,10,10,50,5);

    }else if((rand<=7) && (rand>4)){
        npc = new Charmander("npc",15,10,10,50,5);

    }else{
        npc = new Squirtle("npc", 15, 10, 10, 50, 5);
    }
}

void batalha_x1(Treinador jogador, Pokemon *meu_poke, int dificuldade){
    Pokemon *npc;
    if(dificuldade== 1){
        gera_oponente_facil(npc);
    /*}else if(dificuldade== 2){
        gera_oponente_medio(npc);
    }else if(dificuldade== 3){
        gera_oponente_dificil(npc);*/
    }

    while(1){

        //Antes de implementar, precisamos do metodo atacar

        if(meu_poke->current_hp<=0 || npc->current_hp<=0){
            break;
        }
    }
}

