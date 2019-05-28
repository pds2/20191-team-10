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

void gera_oponente_facil(Pokemon *inimigo){
    int rand= rola_dados();
    
    if((rand<=4) && (rand>0)){
        inimigo = new Bulbasauro("Bulbasauro", 15, 10, 10, 50, 5);

    }else if((rand<=7) && (rand>4)){
        inimigo = new Charmander("Charmander", 15, 10, 10, 50, 5);

    }else{
        inimigo = new Squirtle("Squirtle", 15, 10, 10, 50, 5);
    }
}

void set_current_hp(Pokemon *meu_poke, Pokemon *inimigo){
    meu_poke->current_hp = meu_poke->get_hp();
    inimigo->current_hp = inimigo->get_hp();
}

void batalha_x1(Treinador jogador, Pokemon *meu_poke, int dificuldade){
    Pokemon *inimigo;
    if(dificuldade== 1){
        gera_oponente_facil(inimigo);
    /*}else if(dificuldade== 2){
        gera_oponente_medio(inimigo);
    }else if(dificuldade== 3){
        gera_oponente_dificil(inimigo);*/
    }

    set_current_hp(meu_poke, inimigo); //Atualiza a vida atual para a batalha

    if((jogador.get_lideranca() * meu_poke->get_agilidade()) >= (dificuldade * inimigo->get_agilidade())){

        while(1){
            meu_poke->atacar(inimigo);
            if(meu_poke->current_hp<=0 || inimigo->current_hp<=0){
                break;
            }
            inimigo->atacar(meu_poke);
            if(meu_poke->current_hp<=0 || inimigo->current_hp<=0){
                break;
            }
        }
    }else{
        while(1){
            inimigo->atacar(meu_poke);
            if(meu_poke->current_hp<=0 || inimigo->current_hp<=0){
                break;
            }
            meu_poke->atacar(inimigo);
            if(meu_poke->current_hp<=0 || inimigo->current_hp<=0){
                break;
            }
        }
    }
}

