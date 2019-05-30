#include "../include/excecoes.h"
#include "../include/pokemon.h"

void verificar_nocaute(Pokemon *meu_poke, Pokemon *inimigo){
    if( (meu_poke->current_hp <= 0) || (inimigo->current_hp <= 0)  ){
        Excpt_Nocaute KO;
        throw KO;
    };
}
