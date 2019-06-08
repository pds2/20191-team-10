#include "../include/batalha.h"
#include "../include/excecoes.h"
#include "../include/interface.h"

#include <iostream>
#include <stdexcept>
#include <exception>
#include <ctime>
#include <cstdlib>
#include <memory>

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
            std::cout << meu_poke->get_apelido() << " esta' fora de combate!\n\n YOU LOSE!!!";
        }else{
            std::cout << inimigo->get_apelido() << " esta' fora de combate!\n\n YOU WIN!!!";
        }
        reset_current_hp(meu_poke, inimigo);
    }
}

Pokemon *gera_oponente_facil(){
    Pokemon *inimigo;
    int randomico = rola_dados();
    if((randomico<=4) && (randomico>0)){
        inimigo = new Bulbasauro("Wild Bulbasauro");
    }else if((randomico<=7) && (randomico>4)){
        inimigo = new Charmander("Wild Charmander");
    }else{
        inimigo = new Squirtle("Wild Squirtle");
    }

    std::cout<<"SEU OPONENTE SERÁ... "<<inimigo->get_apelido()<<"!!!\n";
    inimigo->print_atributos();

    return inimigo;
}

Pokemon *gera_oponente_medio(){
    Pokemon *inimigo;
    int randomico = rola_dados();
    if((randomico<=4) && (randomico>0)){
        inimigo = new Ivysaur("Wild Ivysaur");
    }else if((randomico<=7) && (randomico>4)){
        inimigo = new Charmeleon("Wild Charmeleon");
    }else{
        inimigo = new Wartotle("Wild Wartotle");
    }

    std::cout<<"SEU OPONENTE SERÁ... "<<inimigo->get_apelido()<<"!!!\n";
    inimigo->print_atributos();

    return inimigo;
}

Pokemon *gera_oponente_dificil(){
    Pokemon *inimigo;
    int randomico = rola_dados();
    if((randomico<=4) && (randomico>0)){
        inimigo = new Venosauro("Wild Venosauro");
    }else if((randomico<=7) && (randomico>4)){
        inimigo = new Charizard("Wild Charizard");
    }else{
        inimigo = new Blastoise("Wild Blastoise");
    }

    std::cout<<"SEU OPONENTE SERÁ... "<<inimigo->get_apelido()<<"!!!\n";
    inimigo->print_atributos();

    return inimigo;
}

void batalha_x1(Treinador jogador, Pokemon *meu_poke, int dificuldade){
    system("cls||clear");

    Pokemon *inimigo;
    if(dificuldade== 1){
        inimigo = gera_oponente_facil();
    }
    else if(dificuldade== 2){
        inimigo = gera_oponente_medio();
    }
    else if(dificuldade== 3){
        inimigo = gera_oponente_dificil();
    }

    reset_current_hp(meu_poke, inimigo); //Atualiza a vida atual para a batalha
    int habilidade_jogador = 1;
    int dano_meu_poke = inimigo->get_hp();
    int dano_inimigo = meu_poke->get_hp();

    if((jogador.get_lideranca() + meu_poke->get_agilidade()) >= (dificuldade + inimigo->get_agilidade())){
        std::cout << meu_poke->get_apelido() << " e' mais veloz e inicia a batalha!" << std::endl;
        while(true){
            //Como implementar a IA?
            /*std::cout<<meu_poke->get_apelido()<<" esta com : "<<meu_poke->current_hp<<" de HP.\n";
            std::cout<<inimigo->get_apelido()<<" esta com : "<<inimigo->current_hp<<" de HP.\n";*/
            habilidade_jogador = escolher_habilidade(meu_poke, jogador.get_lideranca());

            meu_poke->atacar(inimigo, habilidade_jogador);
            dano_meu_poke -= inimigo->current_hp; //Para não mexermos com o método atacar, usamos esta artimanha
            print_ataque(meu_poke->get_apelido(), inimigo->get_apelido(), dano_meu_poke, inimigo->current_hp);
            dano_meu_poke= inimigo->current_hp;
            if(meu_poke->current_hp<=0 || inimigo->current_hp<=0){
                break;
            }
            inimigo->atacar(meu_poke, dificuldade);
            dano_inimigo -= meu_poke->current_hp;
            print_ataque(inimigo->get_apelido(), meu_poke->get_apelido(), dano_inimigo, meu_poke->current_hp);
            dano_inimigo = meu_poke->current_hp;
            if(meu_poke->current_hp<=0 || inimigo->current_hp<=0){
                break;
            }
        }
    }else{
        std::cout << inimigo->get_apelido() << " e' mais veloz e inicia a batalha!" << std::endl;
        while(true){
            inimigo->atacar(meu_poke, dificuldade);
            dano_inimigo -= meu_poke->current_hp;
            print_ataque(inimigo->get_apelido(), meu_poke->get_apelido(), dano_inimigo, meu_poke->current_hp);
            dano_inimigo = meu_poke->current_hp;
            if(meu_poke->current_hp<=0 || inimigo->current_hp<=0){
                break;
            }
            habilidade_jogador= escolher_habilidade(meu_poke, jogador.get_lideranca());
            meu_poke->atacar(inimigo, habilidade_jogador);
            dano_meu_poke -= inimigo->current_hp;
            print_ataque(meu_poke->get_apelido(), inimigo->get_apelido(), dano_meu_poke, inimigo->current_hp);
            dano_meu_poke = inimigo->current_hp;
            if(meu_poke->current_hp<=0 || inimigo->current_hp<=0){
                break;
            }
        }
    }
    encerrar_batalha(meu_poke,inimigo);
    delete inimigo;
}
