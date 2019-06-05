#include "../include/pokebola.h"

void pokemon_capturado(Treinador jogador, Pokemon *inimigo, int tipo_chance){
  jogador.add_pokemon(inimigo);
  jogador.set_capturas_efetivas(jogador.get_capturas_efetivas() + 1);
  jogador.set_capturas_totais(jogador.get_capturas_totais() + 1);

  if(tipo_chance == POKEBALL_CHANCE) {
    jogador.set_pokeball(jogador.get_pokeball() - 1);
    std::cout << "Você utilizou uma Pokebola do tipo Pokeball com sucesso!" << '\n';
  }
  else if(tipo_chance == GREATBALL_CHANCE) {
    jogador.set_greatball(jogador.get_greatball() - 1);
    std::cout << "Você utilizou uma Pokebola do tipo Greatball com sucesso!" << '\n';
  }
  else if(tipo_chance == MASTERBALL_CHANCE) {
    jogador.set_masterball(jogador.get_masterball() - 1);
    std::cout << "Você utilizou uma Pokebola do tipo Masterball com sucesso!" << '\n';
  }
}

void utilizar_pokebola(Treinador jogador, Pokemon *inimigo, int tipo_chance){
  int escolha;
  int num_sorte;
  std::string alternativa;

  if(tipo_chance == POKEBALL_CHANCE || tipo_chance == GREATBALL_CHANCE) {
      if((jogador.get_pokeball() > POKEBOLA_INVALIDO)||(jogador.get_masterball() > POKEBOLA_INVALIDO)) {
        if (num_sorte <= tipo_chance) {
          pokemon_capturado(jogador, inimigo, tipo_chance);
        } else {
          while(num_sorte > tipo_chance) {
            std::cout << "Essa Pokebola nao foi suficiente para capturar o pokemon.\
            Deseja tentar novamente? (s/n)" << '\n';
            do {
              std::cin >> alternativa;
            } while((alternativa != "s")||(alternativa != "n"));
            if(alternativa == "s") {
              if((jogador.get_pokeball() > POKEBOLA_INVALIDO)||(jogador.get_masterball() > POKEBOLA_INVALIDO)) {
                num_sorte = (rand() % 100) + 1;
                jogador.set_capturas_totais(jogador.get_capturas_totais() + 1);
                if(num_sorte <= tipo_chance) {
                  pokemon_capturado(jogador, inimigo, tipo_chance);
                  break;
                }
              } else {
                  std::cout << "Você não possui Pokeballs nem Masterballs. Jogue mais batalhas\n\
                  para conseguir novas pokebolas!" << '\n';
                  break;
              }
            } else {
                std::cout << "Captura cancelada..." << '\n';
                break;
            }
          }
        }
      } else
          std::cout << "Voce nao possui pokebolas do tipo Pokeball ou Masterball. Jogue mais batalhas\n\
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

    if((inimigo->current_hp > 0) && ((jogador.get_pokeball() > POKEBOLA_INVALIDO)||\
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
            std::cout << "Você não possui pokebolas! Jogue batalhas para conseguir pokebolas!";
            break;
        }
    }
}
