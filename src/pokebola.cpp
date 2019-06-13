#include "../include/pokebola.h"
#include "../include/batalha.h"
#include "../include/excecoes.h"

void recompensar_treinador(Pokemon *meu_poke, Treinador jogador, int dificuldade){
  if(meu_poke->current_hp <= 0) {
    if (dificuldade == 1 || dificuldade == 2) {
      std::cout << "\nVocê ganhou 2 pokebolas do tipo Pokeball!" << '\n';
      jogador.set_pokeball(jogador.get_pokeball() + 2);
    }
    else if (dificuldade == 3) {
      std::cout << "\nVocê ganhou 2 pokebolas do tipo Pokeball e uma do tipo Greatball!" << '\n';
      jogador.set_pokeball(jogador.get_pokeball() + 2);
      jogador.set_greatball(jogador.get_greatball() + 1);
    }
    else if (dificuldade == 4) {
      std::cout << "\nVocê ganhou 3 pokebolas do tipo Pokeball e uma do tipo Greatball!" << '\n';
      jogador.set_pokeball(jogador.get_pokeball() + 3);
      jogador.set_greatball(jogador.get_greatball() + 1);

    }
  } else {
    if (dificuldade == 1 || dificuldade == 2) {
      std::cout << "\nVocê ganhou 5 pokebolas do tipo Pokeball!" << '\n';
      jogador.set_pokeball(jogador.get_pokeball() + 5);
    }
    else if (dificuldade == 3) {
      std::cout << "\nVocê ganhou 5 pokebolas do tipo Pokeball e duas do tipo Greatball!" << '\n';
      jogador.set_pokeball(jogador.get_pokeball() + 5);
      jogador.set_greatball(jogador.get_greatball() + 2);
    }
    else if (dificuldade == 4) {
      std::cout << "\nVocê ganhou 5 pokebolas do tipo Pokeball, duas do tipo Greatball e uma MASTERBALL!!!" << '\n';
      jogador.set_pokeball(jogador.get_pokeball() + 5);
      jogador.set_greatball(jogador.get_greatball() + 2);
      jogador.set_masterball(jogador.get_masterball() + 1);
    }
  }
}

void pokemon_capturado(Treinador jogador, Pokemon *inimigo, int tipo_chance){
  try{
    verificar_num_pokemon_valido(jogador);
  }
  catch(Excpt_Num_Pokemon_Invalido &e){
        std::cout<<e.what();
        Treinador copia = tratamento_num_pokemon_invalido(jogador);
        jogador = copia;
  }
  jogador.add_pokemon(inimigo);
  jogador.set_capturas_efetivas(jogador.get_capturas_efetivas() + 1);
  jogador.set_capturas_totais(jogador.get_capturas_totais() + 1);

  if(tipo_chance == POKEBALL_CHANCE){
    std::cout << "\nVocê utilizou uma Pokebola do tipo Pokeball com sucesso!\nVocê agora possui os pokemon : " << '\n';
    jogador.print_lista_pokemon();
    if(deseja_continuar_jogando()){
      int escolha, dificuldade;
      dificuldade = escolher_dificuldade();
      escolha = escolher_pokemon(jogador);
      batalha_x1(jogador, (jogador._lista_de_pokemon.at(escolha)), dificuldade);
    } else std::cout << "Saindo do jogo..." << '\n';
  }
  else if(tipo_chance == GREATBALL_CHANCE){
    std::cout << "\nVocê utilizou uma Pokebola do tipo Greatball com sucesso!\nVocê agora possui os pokemon : " << '\n';
    jogador.print_lista_pokemon();
    if(deseja_continuar_jogando()){
      int escolha, dificuldade;
      dificuldade = escolher_dificuldade();
      escolha = escolher_pokemon(jogador);
      batalha_x1(jogador, (jogador._lista_de_pokemon.at(escolha)), dificuldade);
    } else std::cout << "Saindo do jogo..." << '\n';
  }
  else if(tipo_chance == MASTERBALL_CHANCE){
    std::cout << "\nVocê utilizou uma Pokebola do tipo Masterball com sucesso!\nVocê agora possui os pokemon : " << '\n';
    jogador.print_lista_pokemon();
    if(deseja_continuar_jogando()){
      int escolha, dificuldade;
      dificuldade = escolher_dificuldade();
      escolha = escolher_pokemon(jogador);
      batalha_x1(jogador, (jogador._lista_de_pokemon.at(escolha)), dificuldade);
    } else std::cout << "Saindo do jogo..." << '\n';
  }
}

void utilizar_pokebola(Treinador jogador, Pokemon *inimigo, int tipo_chance){
  int escolha;
  int num_sorte;
  std::string alternativa;
  bool run = true;

  if(tipo_chance == POKEBALL_CHANCE || tipo_chance == GREATBALL_CHANCE) {
      if((jogador.get_pokeball() > POKEBOLA_INVALIDO)||(jogador.get_masterball() > POKEBOLA_INVALIDO)) {
        if (num_sorte <= tipo_chance) {
          pokemon_capturado(jogador, inimigo, tipo_chance);
        } else {
            std::cout << "\n\nEssa pokebola nao foi suficiente para capturar o pokemon. Deseja tentar novamente? (s/n)" << '\n';
            while(run) {
              if(num_sorte > tipo_chance) {
                  // if((jogador.get_pokeball() <= POKEBOLA_INVALIDO)&&(jogador.get_masterball() <= POKEBOLA_INVALIDO)) {
                  //   std::cout << "Suas pokebolas acabaram!" << '\n';
                  //   run = false;
                  // }
                  std::cout << "Digite s para sim ou n para nao: ";
                  std::cin >> alternativa;
                if(alternativa == "s") {
                  if((jogador.get_pokeball() > POKEBOLA_INVALIDO)||(jogador.get_masterball() > POKEBOLA_INVALIDO)) {
                    num_sorte = (rand() % 100) + 1;
                    jogador.set_capturas_totais(jogador.get_capturas_totais() + 1);
                    if(tipo_chance == GREATBALL_CHANCE)
                      jogador.set_greatball(jogador.get_greatball() - 1);
                    else if(tipo_chance == POKEBALL_CHANCE)
                      jogador.set_pokeball(jogador.get_pokeball() - 1);
                    if(num_sorte <= tipo_chance) {
                      pokemon_capturado(jogador, inimigo, tipo_chance);
                      run = false;
                    } else
                      std::cout << "\n\nEssa pokebola nao foi suficiente para capturar o pokemon. Deseja tentar novamente? (s/n)" << '\n';
                  } else {
                      std::cout << "\nVocê não possui mais Pokeballs nem Greatballs. Jogue mais batalhas\n\
                      para conseguir novas pokebolas!" << '\n';
                      run = false;
                  }
                } else if(alternativa == "n"){
                  std::cout << "\nVocê desistiu de capturar " << inimigo->get_apelido() << "!\n";
                  if(deseja_continuar_jogando()){
                  	int escolha, dificuldade;
            				dificuldade = escolher_dificuldade();
            				escolha = escolher_pokemon(jogador);
            				batalha_x1(jogador, (jogador._lista_de_pokemon.at(escolha)), dificuldade);
            			} else std::cout << "Saindo do jogo..." << '\n';
                  run = false;
                }
              }
            }
        }
      } else
          std::cout << "Voce nao possui pokebolas do tipo Pokeball ou Greatball. Jogue mais batalhas\n\
          para conseguir novas pokebolas!" << '\n';
  }
  else if(tipo_chance == MASTERBALL_CHANCE) {
    if((jogador.get_masterball() > POKEBOLA_INVALIDO)) {
      pokemon_capturado(jogador, inimigo, tipo_chance);
    } else
        std::cout << "Voce nao possui pokebolas do tipo Masterball.";
  }
}

void capturar_pokemon(Treinador jogador, Pokemon *inimigo) {
    int escolha;

    if((inimigo->current_hp <= 0) && ((jogador.get_pokeball() > POKEBOLA_INVALIDO)||\
    (jogador.get_greatball() > POKEBOLA_INVALIDO)||(jogador.get_masterball() > POKEBOLA_INVALIDO))) {
        escolha = escolher_pokebola(jogador, inimigo);
        switch (escolha) {
          case 1:
            utilizar_pokebola(jogador, inimigo, POKEBALL_CHANCE);
            break;
          case 2:
            utilizar_pokebola(jogador, inimigo, GREATBALL_CHANCE);
            break;
          case 3:
            utilizar_pokebola(jogador, inimigo, MASTERBALL_CHANCE);
            break;
          default:
            std::cout << "Você não possui pokebolas! Jogue batalhas para conseguir pokebolas.";
            break;
        }
    }
}
