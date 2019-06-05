#include "pokebola.h"


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
