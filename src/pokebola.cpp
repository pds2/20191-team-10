#include "../include/pokebola.h"

void pokemon_capturado(Treinador jogador, Pokemon *inimigo, int tipo_chance){
  jogador.add_pokemon(inimigo);
  jogador.set_capturas_efetivas(jogador.get_capturas_efetivas() + 1);
  jogador.set_capturas_totais(jogador.get_capturas_totais() + 1);

  if(tipo_chance == POKEBALL_CHANCE)
    std::cout << "\nVocê utilizou uma Pokebola do tipo Pokeball com sucesso!" << '\n';
  else if(tipo_chance == GREATBALL_CHANCE)
    std::cout << "\nVocê utilizou uma Pokebola do tipo Greatball com sucesso!" << '\n';
  else if(tipo_chance == MASTERBALL_CHANCE)
    std::cout << "\nVocê utilizou uma Pokebola do tipo Masterball com sucesso!" << '\n';
}

void utilizar_pokebola(Treinador jogador, Pokemon *inimigo, int tipo_chance){
  int escolha;
  int num_sorte;
  std::string alternativa;
  bool run;

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
                  std::cout << "\nVocê desistiu de capturar Wild " << inimigo->get_nome() << "!\n\n";
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
