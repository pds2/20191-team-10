#include "../include/batalha.h"
#include "../include/excecoes.h"

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

/*void encerrar_batalha(Pokemon *poke){
    try{
        excpt_verificar_morto(poke);
    }
    catch(std::out_of_range &e){
        poke->current_hp=poke->get_hp();
    }
}*/

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

void set_current_hp(Pokemon *meu_poke, Pokemon *inimigo){
    meu_poke->current_hp = meu_poke->get_hp();
    inimigo->current_hp = inimigo->get_hp();
}

int escolher_pokemon(Treinador jogador){
    std::cout << "Qual Poke'mon tu vai querer usar na batalha?";
    std::cout << std::endl;
    jogador.get_lista_pokemon();
    std::string escolha, confirmacao;


 //Criar uma exceção aqui depois & pensar numa maneira de o código não crashar caso tenha apenas 2


    do{
        do{
            std::cout << "Digite o numero correspondente: ";
            std::cin >> escolha;
        }while((escolha[0] != '1') && (escolha[0] != '2') && (escolha[0] != '3'));
        std::cout << "Tem certeza que quer usar ";
        std::cout << jogador._lista_de_pokemon.at((escolha[0] - '0')-1)->get_apelido() << "? ";
        std::cin >> confirmacao;
        if(confirmacao[0] != 'S' && confirmacao[0] != 's')
            std::cout << std::endl << "Qual Poke'mon quer levar? ";
    }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    return (escolha[0] - '0') - 1;
}

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
    int randomico= rola_dados();
    if((randomico<=4) && (randomico>0)){
        inimigo = new Bulbasauro("Bulbasauro", 15, 10, 10, 50, 5);
    }else if((randomico<=7) && (randomico>4)){
        inimigo = new Charmander("Charmander", 15, 10, 10, 50, 5);
    }else{
        inimigo = new Squirtle("Squirtle", 15, 10, 10, 50, 5);
    }
    set_current_hp(meu_poke, inimigo); //Atualiza a vida atual para a batalha

    if((jogador.get_lideranca() * meu_poke->get_agilidade()) >= (dificuldade * inimigo->get_agilidade())){
        while(true){
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


//Fazer uma função para isto depois


    if(meu_poke->current_hp <= 0){
        std::cout << meu_poke->get_apelido() << " esta' fora de combate! O vencedor e' ";
        std::cout << inimigo->get_apelido() << std::endl;
    }else{
        std::cout << inimigo->get_apelido() << " esta' fora de combate! O vencedor e' ";
        std::cout << meu_poke->get_apelido() << std::endl;
    }
    delete inimigo;
}
