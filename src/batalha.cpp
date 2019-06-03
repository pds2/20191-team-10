#include "../include/batalha.h"
#include "../include/excecoes.h"
#include "../include/interface.h"

#include <iostream>
#include <stdexcept>
#include <exception>
#include <ctime>
#include <cstdlib>

int rola_dados(){
    srand (time(NULL));
	int temp = (rand() % 10 + 1);
	return(temp);
}

void reset_current_hp(Pokemon *meu_poke, Pokemon *inimigo){
    meu_poke->current_hp = meu_poke->get_hp();
    inimigo->current_hp = inimigo->get_hp();
}

void encerrar_batalha(Pokemon *meu_poke, Pokemon *inimigo){
    try{
        verificar_nocaute(meu_poke,inimigo);
    }
    catch(Excpt_Nocaute &KO){
        if(meu_poke->current_hp <= 0){
            std::cout << meu_poke->get_apelido() << " esta' fora de combate! O vencedor e' ";
            std::cout << inimigo->get_apelido() << std::endl;
        }else{
            std::cout << inimigo->get_apelido() << " esta' fora de combate! O vencedor e' ";
            std::cout << meu_poke->get_apelido() << std::endl;
        }
        reset_current_hp(meu_poke, inimigo);
    }
}

/*void gera_oponente_facil(Pokemon *inimigo){
    int randomico= rola_dados();
    std::cout << "Dados: " << randomico << std::endl;
    if((randomico<=4) && (randomico>0)){
        inimigo = new Bulbasauro("Bulbasauro", 15, 10, 10, 50, 5);
    }else if((randomico<=7) && (randomico>4)){
        inimigo = new Charmander("Charmander", 15, 10, 10, 50, 5);
    }else{
        inimigo = new Squirtle("Squirtle", 15, 10, 10, 50, 5);
    }
    std::cout << "Seu inimigo: " << inimigo->get_apelido() << std::endl;
    std::cout << "Vida do inimigo: " << inimigo->current_hp << std::endl;
}*/

void batalha_x1(Treinador jogador, Pokemon *meu_poke, int dificuldade){
    Pokemon *inimigo;
    /*if(dificuldade== 1){
        gera_oponente_facil(inimigo);
    }else if(dificuldade== 2){
        gera_oponente_medio(inimigo);
    }else if(dificuldade== 3){
        gera_oponente_dificil(inimigo);
    }*/
    //Não estou conseguindo passar o Pokémon criado na função acima para esta função
    int randomico = rola_dados();
    if((randomico<=4) && (randomico>0)){
        inimigo = new Bulbasauro("Bulbasauro", 15, 10, 10, 50, 5);
    }else if((randomico<=7) && (randomico>4)){
        inimigo = new Charmander("Charmander", 15, 10, 10, 50, 5);
    }else{
        inimigo = new Squirtle("Squirtle", 15, 10, 10, 50, 5);
    }

    reset_current_hp(meu_poke, inimigo); //Atualiza a vida atual para a batalha

    if((jogador.get_lideranca() * meu_poke->get_agilidade()) >= (dificuldade * inimigo->get_agilidade())){
        while(true){

            //Após escolher a habilidade, ela precisa passar para o método atacar
            //Como implementar a IA?
            escolher_habilidade(meu_poke, jogador.get_lideranca());

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
        while(true){
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

    encerrar_batalha(meu_poke,inimigo);
    delete inimigo;
    // Gera warning devido ao delete : "deleting object of abstract class type 'Pokemon' which has non-virtual
    // destructor will cause undefined behavior [-Wdelete-non-virtual-dtor]|"
}
