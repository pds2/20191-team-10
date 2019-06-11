#include "../include/excecoes.h"
#include "../include/pokemon.h"
#include "../include/interface.h"
#include "../include/treinador.h"

#include <string>
#include <vector>

void verificar_nocaute(Pokemon *meu_poke, Pokemon *inimigo){
    if( (meu_poke->current_hp <= 0) || (inimigo->current_hp <= 0)  ){
        Excpt_Nocaute KO;
        throw KO;
    };
}

void verificar_habilidade_valida(std::string escolha, int lideranca){
    int a = (escolha[0] - '0');
    if(a>lideranca){
        Excpt_Habilidade_Invalida z;
        throw z;
    }
}

void tratamento_habilidade_invalida(std::string escolha, int lideranca){
    if(lideranca == 3){
        std::cout << "Voc� s� tem lideran�a o suficiente para ter acesso �s habilidades 1,2 e 3.\n";
        escolha = escolha_um_a_tres();
    }
    if(lideranca == 2){
        std::cout << "Voc� s� tem lideran�a o suficiente para ter acesso �s habilidades 1 e 2.\n";
        escolha = escolha_um_a_dois();
    }
    else{
        std::cout << "Voc� � um novato! S� consegue utilizar a primeira habilidade.\n";
        escolha = escolha_um_a_um();
    }
}

void verificar_lideranca_valida(int lideranca){
    if(lideranca<=0||lideranca>4){
        Excpt_Lideranca_Invalida z;
        throw z;
    }
}

int tratamento_lideranca_invalida(){
    std::string escolha = escolha_um_a_quatro();
    return (escolha[0] - '0');
}

void verificar_num_pokemon_valido(Treinador jogador){
    if(jogador._lista_de_pokemon.size()>=3){
        Excpt_Num_Pokemon_Invalido z;
        throw z;
	}
}

Treinador tratamento_num_pokemon_invalido(Treinador jogador){
    int doacao = doar_pokemon(jogador);
    jogador._lista_de_pokemon.erase(jogador._lista_de_pokemon.begin()+doacao);
    return jogador;
}
