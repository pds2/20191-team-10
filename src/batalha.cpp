#include "../include/batalha.h"
#include "../include/excecoes.h"
#include "../include/interface.h"
#include "../include/pokedex_ascii.h"


#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdlib>
#include <memory>

int rola_dados(int limite){
	int temp = (rand() % limite + 1);
	return(temp);
}

void reset_current_hp(Pokemon *meu_poke, Pokemon *inimigo){
    meu_poke->current_hp = meu_poke->get_hp();
    inimigo->current_hp = inimigo->get_hp();
}

Pokemon *gera_oponente_facil(){
    Pokemon *inimigo;
    int randomico = rola_dados(9);
    if((randomico<=3) && (randomico>0)){
        inimigo = new Bulbasauro("Wild Bulbasauro");
    }else if((randomico<=7) && (randomico>3)){
        inimigo = new Charmander("Wild Charmander");
    }else{
        inimigo = new Squirtle("Wild Squirtle");
    }

    std::cout << "SEU OPONENTE SERÁ... " << inimigo->get_apelido() << "!!!" << std::endl;
    print_ascii_art(inimigo->get_nome());
    inimigo->print_atributos();

    return inimigo;
}

Pokemon *gera_oponente_medio(){
    Pokemon *inimigo;
    int randomico = rola_dados(9);
    if((randomico<=3) && (randomico>0)){
        inimigo = new Ivysaur("Wild Ivysaur");
    }else if((randomico<=7) && (randomico>3)){
        inimigo = new Charmeleon("Wild Charmeleon");
    }else{
        inimigo = new Wartotle("Wild Wartotle");
    }

    std::cout << "SEU OPONENTE SERÁ... " << inimigo->get_apelido() << "!!!" << std::endl;
    std::cout << "SEU OPONENTE SERÁ... " << inimigo->get_apelido() << "!!!" << std::endl;
    print_ascii_art(inimigo->get_nome());
    inimigo->print_atributos();

    return inimigo;
}

Pokemon *gera_oponente_dificil(){
    Pokemon *inimigo;

    int randomico = rola_dados(9);
    if((randomico<=3) && (randomico>0)){
        inimigo = new Venosauro("Wild Venosauro");
    }else if((randomico<=7) && (randomico>3)){
        inimigo = new Charizard("Wild Charizard");
    }else{
        inimigo = new Blastoise("Wild Blastoise");
    }

    std::cout << "SEU OPONENTE SERÁ... " << inimigo->get_apelido() << "!!!" << std::endl;
    std::cout << "SEU OPONENTE SERÁ... " << inimigo->get_apelido() << "!!!" << std::endl;
    print_ascii_art(inimigo->get_nome());
    inimigo->print_atributos();

    return inimigo;
}

void limite_nivel(short int *vet, int lideranca){
    if(lideranca>=1 && lideranca<=4){
        if(lideranca==1){
            vet[1]= vet[2]= vet[3]= 0;
        }else if(lideranca==2){
            vet[2]= vet[3]= 0;
        }else if(lideranca==3){
            vet[3]= 0;
        }
    }
}

void batalha_x1(Treinador jogador, Pokemon *meu_poke, int dificuldade){
    system("clear||cls"); //Limpa a tela
    int dificuldade_inicial = dificuldade;
    Pokemon *inimigo;

    try{
        verificar_dificuldade_valida(dificuldade);
    }
    catch(Excpt_Dificuldade_Invalida &e){
        std::cout<<e.what();
        dificuldade = 1;
    }

    if((dificuldade== 1) || (dificuldade== 2)){
        inimigo = gera_oponente_facil();
    }else if(dificuldade== 3){
        inimigo = gera_oponente_medio();
    }else if(dificuldade== 4){
        inimigo = gera_oponente_dificil();
    }

    reset_current_hp(meu_poke, inimigo); //Atualiza a vida atual para a batalha
    int habilidade_jogador = 1;
    int dano_meu_poke = inimigo->get_hp();
    int dano_inimigo = meu_poke->get_hp();

    short int limite_habilidade_jogador[4] = {100, 5, 3, 1};
    limite_nivel(limite_habilidade_jogador, jogador.get_lideranca());
    short int limite_habilidade_inimigo[4] = {100, 5, 3, 1};

    if((jogador.get_lideranca() + meu_poke->get_agilidade()) >= (dificuldade + inimigo->get_agilidade())){
        std::cout << meu_poke->get_apelido() << " e' mais veloz e inicia a batalha!" << std::endl;
        while(true){
            habilidade_jogador = escolher_habilidade(meu_poke, jogador.get_lideranca(), limite_habilidade_jogador);

            meu_poke->atacar(inimigo, habilidade_jogador);
            limite_habilidade_jogador[habilidade_jogador-1]--;
            dano_meu_poke -= inimigo->current_hp; //Para não mexermos com o método atacar, usamos esta artimanha
            print_ataque(meu_poke->get_apelido(), inimigo->get_apelido(),
                         meu_poke->get_habilidade(habilidade_jogador), dano_meu_poke, inimigo->current_hp);
            dano_meu_poke= inimigo->current_hp;
            if(meu_poke->current_hp<=0 || inimigo->current_hp<=0){
                break;
            }

            if(dificuldade>1){
                if(limite_habilidade_inimigo[dificuldade-1] == 0){
                dificuldade--;
                }
            }

            inimigo->atacar(meu_poke, dificuldade);
            limite_habilidade_inimigo[dificuldade-1]--;
            dano_inimigo -= meu_poke->current_hp;
            print_ataque(inimigo->get_apelido(), meu_poke->get_apelido(),
                         inimigo->get_habilidade(dificuldade), dano_inimigo, meu_poke->current_hp);
            dano_inimigo = meu_poke->current_hp;
            if(meu_poke->current_hp<=0 || inimigo->current_hp<=0){
                break;
            }
        }
    }else{
        std::cout << inimigo->get_apelido() << " e' mais veloz e inicia a batalha!" << std::endl;
        while(true){

            if(dificuldade>1){
                if(limite_habilidade_inimigo[dificuldade-1] == 0){
                dificuldade--;
                }
            }

            inimigo->atacar(meu_poke, dificuldade);
            limite_habilidade_inimigo[dificuldade-1]--;
            dano_inimigo -= meu_poke->current_hp;
            print_ataque(inimigo->get_apelido(), meu_poke->get_apelido(),
                         inimigo->get_habilidade(dificuldade), dano_inimigo, meu_poke->current_hp);
            dano_inimigo = meu_poke->current_hp;
            if(meu_poke->current_hp<=0 || inimigo->current_hp<=0){
                break;
            }
            habilidade_jogador= escolher_habilidade(meu_poke, jogador.get_lideranca(), limite_habilidade_jogador);
            meu_poke->atacar(inimigo, habilidade_jogador);
            limite_habilidade_jogador[habilidade_jogador-1]--;
            dano_meu_poke -= inimigo->current_hp;
            print_ataque(meu_poke->get_apelido(), inimigo->get_apelido(),
                         meu_poke->get_habilidade(habilidade_jogador), dano_meu_poke, inimigo->current_hp);
            dano_meu_poke = inimigo->current_hp;
            if(meu_poke->current_hp<=0 || inimigo->current_hp<=0){
                break;
            }
        }
    }
    encerrar_batalha(meu_poke,inimigo,jogador,dificuldade_inicial);
    delete inimigo;
}

void encerrar_batalha(Pokemon *meu_poke, Pokemon *inimigo, Treinador jogador, int dificuldade_inicial){
    try{
        verificar_nocaute(meu_poke,inimigo);
    }
    catch(Excpt_Nocaute &KO){
        if(meu_poke->current_hp <= 0){
            std::cout << meu_poke->get_apelido() << " esta' fora de combate!\n\n YOU LOSE!!!\n" << std::endl;
						recompensar_treinador(meu_poke, jogador, dificuldade_inicial);
        }else{
            std::cout << inimigo->get_apelido() << " esta' fora de combate!\n\n YOU WIN!!!\n" << std::endl;
            if(jogador.get_lideranca()>=1 && jogador.get_lideranca()<4 && jogador.get_lideranca()<=dificuldade_inicial){
                int exp = jogador.get_lideranca() + 1;
                jogador.set_lideranca(exp);
                std::cout << "Sua capacidade de liderança aumentou! Agora você tem acesso a " << jogador.get_lideranca()
                          << " habilidades de seu Pokemon.\n";
            }
            recompensar_treinador(meu_poke, jogador, dificuldade_inicial);
        }
        escolher_pos_batalha(meu_poke, inimigo, jogador);
        reset_current_hp(meu_poke, inimigo);
    }
}

void escolher_pos_batalha(Pokemon *meu_poke, Pokemon *inimigo, Treinador jogador) {
	int exit;
	exit = escolher_opcoes(meu_poke);
	switch (exit) {
		case 1:{
			if(check_pokebola(jogador)){
				if(deseja_capturar(inimigo))
        	capturar_pokemon(jogador, inimigo);
				else {
					if(deseja_continuar_jogando()){
		      	int escolha, dificuldade;
						dificuldade = escolher_dificuldade();
						escolha = escolher_pokemon(jogador);
						batalha_x1(jogador, (jogador._lista_de_pokemon.at(escolha)), dificuldade);
					} else std::cout << "Saindo do jogo..." << '\n';
			 	}
			}
			break;
    }
		case 2:{
		  int dif = escolher_dificuldade();
		 	int escolha = escolher_pokemon(jogador);
			meu_poke = jogador._lista_de_pokemon.at(escolha);
			batalha_x1(jogador, meu_poke, dif );
			break;
    }
		case 3:{
			treinador_info(jogador);
			if(deseja_continuar_jogando()){
      	int escolha, dificuldade;
				dificuldade = escolher_dificuldade();
				escolha = escolher_pokemon(jogador);
				batalha_x1(jogador, (jogador._lista_de_pokemon.at(escolha)), dificuldade);
			} else std::cout << "Saindo do jogo..." << '\n';
			break;
    }
	}
}
