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

void capturar_pokemon(Treinador jogador, Pokemon *inimigo) {
    int escolha;
    std::string alternativa;
    int num_sorte;
    num_sorte = (rand() % 100) + 1;

    if((inimigo->current_hp > 0) && ((jogador.get_pokeball() > 0)||\
    (jogador.get_greatball() > 0)||(jogador.get_masterball() > 0))) {
        std::cout << "Qual pokebola deseja utilizar para capturar esse pokemon?" << '\n';
        if(jogador.get_pokeball() > 0)
          std::cout << "\t1- Pokeball" << '\n';
        if(jogador.get_greatball() > 0)
          std::cout << "\t2- Greatball" << '\n';
        if(jogador.get_masterball() > 0)
          std::cout << "\t3- Masterball" << '\n';
        std::cout << "Digite o número correspondente a pokebola desejada: ";
        std::cin >> escolha;

        switch (escolha) {
          case 1:
            if((jogador.get_pokeball() > 0)) {
              if (num_sorte <= 25) {
                jogador.add_pokemon(inimigo);
                jogador._pokeball -= 1;
                std::cout << "Você utilizou uma Pokebola com sucesso!" << '\n';
              } else {
                while(num_sorte > 25) {
                  std::cout << "Essa Pokebola nao foi suficiente para capturar o pokemon.\
                  Deseja tentar novamente? (s/n)" << '\n';
                  do {
                    std::cin >> alternativa;
                  } while((alternativa != "s")||(alternativa != "n"));
                  if(alternativa == "s") {
                    num_sorte = (rand() % 100) + 1;
                    if(num_sorte <= 25) {
                      jogador.add_pokemon(inimigo);
                      jogador._pokeball -= 1;
                      std::cout << "Você utilizou uma Pokebola com sucesso!" << '\n';
                      break;
                    }
                  } else {
                      std::cout << "Captura cancelada..." << '\n';
                      break;
                  }
                }
              }
            } else {
              std::cout << "Voce nao possui pokebolas do tipo Pokeball, digite o numero correspondente\
              a uma pokebola que você tenha: ";
              std::cin >> escolha;
            } break;
          case 2:
            if((jogador.get_greatball() > 0) && (num_sorte <= 50)) {
              jogador.add_pokemon(inimigo);
              jogador._greatball -= 1;
              std::cout << "Você utilizou uma Greatball!" << '\n';
            } else {
              std::cout << "Voce nao possui pokebolas do tipo Greatball, digite o numero correspondente\
              a uma pokebola que você tenha: ";
              std::cin >> escolha;
            } break;
          case 3:
            if((jogador.get_masterball() > 0)) {
              jogador.add_pokemon(inimigo);
              jogador._masterball -= 1;
              std::cout << "Você utilizou uma Masterball!" << '\n';
            } else {
              std::cout << "Voce nao possui pokebolas do tipo Masterball, digite o numero correspondente\
              a uma pokebola que você tenha: ";
              std::cin >> escolha;
            } break;
          default:
            std::cout << "Digite uma entrada válida(1-3): ";
            break;
        }
    }
}
