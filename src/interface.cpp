#include "../include/interface.h"
#include "../include/batalha.h"
#include "../include/excecoes.h"
#include "../include/pokebola.h"

#include <stdlib.h>

int escolher_pokebola(Treinador jogador, Pokemon *inimigo){
    int escolha;

    std::cout << "\n\nQual pokebola deseja utilizar para capturar esse pokemon?" << '\n';
    if(jogador.get_pokeball() > POKEBOLA_INVALIDO)
      std::cout << "\t1- Pokeball" << '\n';
    if(jogador.get_greatball() > POKEBOLA_INVALIDO)
      std::cout << "\t2- Greatball" << '\n';
    if(jogador.get_masterball() > POKEBOLA_INVALIDO)
      std::cout << "\t3- Masterball" << '\n';
    if((jogador.get_pokeball() > POKEBOLA_INVALIDO)||(jogador.get_greatball() > POKEBOLA_INVALIDO)||(jogador.get_masterball() > POKEBOLA_INVALIDO)){
      escolha = verifica_inteiro("Digite o número correspondente a pokebola desejada: ");
      if(escolha >= 1 && escolha <= 3)
        return escolha;
      else {
        while (escolha < 1 || escolha > 3) {
          escolha = verifica_inteiro("Digite o número correspondente ao de uma das pokebolas acima: ");
          if(escolha >= 1 && escolha <= 3)
            if((escolha == 1 && jogador.get_pokeball() <= POKEBOLA_INVALIDO)||\
            (escolha == 2 && jogador.get_greatball() <= POKEBOLA_INVALIDO)||\
            (escolha == 3 && jogador.get_masterball() <= POKEBOLA_INVALIDO))
              return 4;
            else return escolha;
        }
      }
    } else {
      std::cout << "Você não possui nenhum tipo de pokebola. Jogue mais batalhas para conseguir novas pokebolas!" << '\n';
      return 0;
    }
    return 0;
}

int escolher_opcoes(Pokemon *meu_poke) {
  int opcao_escolhida;
  bool run_input = true;

  std::cout << "\nO que deseja fazer agora? " << '\n';
  if(meu_poke->current_hp <= 0)
    std::cout << "Voce perdeu, logo nao tem a opcao de capturar o pokemon\n\n";
  else
    std::cout << "1- Capturar pokemon" << '\n';
  std::cout << "2- Jogar outra batalha" << '\n';
  std::cout << "3- Consultar pokedex" << '\n';
  while (run_input) {
    opcao_escolhida = verifica_inteiro("Digite um número correspondente a umas das opções acima: ");
    if(opcao_escolhida >= 1 && opcao_escolhida <= 3) {
      if(meu_poke->current_hp <= 0 && opcao_escolhida == 1) {
        opcao_escolhida = 0;
        continue;
      } else {
        return opcao_escolhida;
        run_input = false;
      }
    } else {
      opcao_escolhida = verifica_inteiro("Digite um número válido correspondente as opções mostradas acima: ");
      if(opcao_escolhida >= 1 && opcao_escolhida <= 3) {
        if(meu_poke->current_hp <= 0 && opcao_escolhida == 1) {
          opcao_escolhida = 0;
          continue;
        } else {
          run_input = false;
          return opcao_escolhida;
        }
      }
    }
  }
  return opcao_escolhida;
}

std::string confirmar_escolha(Treinador jogador,std::string escolha,std::string confirmacao){
    print_ascii_art(jogador._lista_de_pokemon.at((escolha[0] - '0')-1)->get_nome());
    std::cout << "Tem certeza que quer levar para a batalha o Pokemon apelidado : ";
    std::cout << jogador._lista_de_pokemon.at((escolha[0] - '0')-1)->get_apelido() << "? (S/N) ";
    std::getline(std::cin, confirmacao);
    if(confirmacao[0] != 'S' && confirmacao[0] != 's')
        std::cout << std::endl << "Ok, vamos selecionar outro Pokemon. Qual Pokemon deseja escolher? ";
    return confirmacao;
}

int escolher_pokemon(Treinador jogador){
    std::cout << "Escolha um dos Pokemon abaixo para leva'-lo para a batalha!" << std::endl;
    jogador.print_lista_pokemon();
    std::string escolha, confirmacao;

    if(jogador._lista_de_pokemon.size()==1){
        do{
        escolha = escolha_um_a_um();
        confirmacao = confirmar_escolha(jogador,escolha,confirmacao);
        }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    }
    else if(jogador._lista_de_pokemon.size()==2){
        do{
        escolha = escolha_um_a_dois();
        confirmacao = confirmar_escolha(jogador,escolha,confirmacao);
        }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    }
    else if(jogador._lista_de_pokemon.size()==3){
        do{
        escolha = escolha_um_a_tres();
        confirmacao = confirmar_escolha(jogador,escolha,confirmacao);
        }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    }
    else if(jogador._lista_de_pokemon.size()==4){
        do{
        escolha = escolha_um_a_quatro();
        confirmacao = confirmar_escolha(jogador,escolha,confirmacao);
        }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    }
    else if(jogador._lista_de_pokemon.size()==5){
        do{
        escolha = escolha_um_a_cinco();
        confirmacao = confirmar_escolha(jogador,escolha,confirmacao);
        }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    }
    else if(jogador._lista_de_pokemon.size()==6){
        do{
        escolha = escolha_um_a_seis();
        confirmacao = confirmar_escolha(jogador,escolha,confirmacao);
        }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    }
    else if(jogador._lista_de_pokemon.size()==7){
        do{
        escolha = escolha_um_a_sete();
        confirmacao = confirmar_escolha(jogador,escolha,confirmacao);
        }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    }
    else if(jogador._lista_de_pokemon.size()==8){
        do{
        escolha = escolha_um_a_oito();
        confirmacao = confirmar_escolha(jogador,escolha,confirmacao);
        }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    }
    else if(jogador._lista_de_pokemon.size()==9){
        do{
        escolha = escolha_um_a_nove();
        confirmacao = confirmar_escolha(jogador,escolha,confirmacao);
        }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    }
    return (escolha[0] - '0') - 1;
}

int escolher_habilidade(Pokemon *meu_poke, int lideranca, short int *vetor_limite){
    std::string escolha;
    std::cout << "Qual habilidade você deseja usar?" << std::endl;
    meu_poke->print_habilidades(lideranca);

    if(lideranca == 1){
        escolha = escolha_um_a_um();
    }
    else if(lideranca == 2){
        escolha = escolha_um_a_dois();
    }
    else if(lideranca == 3){
        escolha = escolha_um_a_tres();
    }
    else if(lideranca == 4){
        escolha = escolha_um_a_quatro();
    }

    try{
        verificar_habilidade_valida(escolha, lideranca);
    }
    catch(Excpt_Habilidade_Invalida &e){
        tratamento_habilidade_invalida(escolha, lideranca);
    }

    try{
        verificar_limite_habilidade(escolha, vetor_limite);
    }
    catch(Excpt_Limite_Habilidade &e){
        tratamento_limite_habilidade(escolha, vetor_limite);
    }

    return (escolha[0] - '0');
}

int escolher_dificuldade(){
    system("clear||cls");
    std::cout<<"Escolha a dificuldade para a próxima batalha:\n1)Facil\n2)Medio\n3)Dificil\n4)Mestre\n";
    std::string escolha = escolha_um_a_quatro();
    return (escolha[0] - '0');
}

bool check_pokebola(Treinador jogador){
    if((jogador.get_pokeball() <= POKEBOLA_INVALIDO)&&(jogador.get_greatball() <= POKEBOLA_INVALIDO)&&(jogador.get_masterball() <= POKEBOLA_INVALIDO)){
      return false;
    } else return true;
}

void deseja_apelidar(Pokemon *inimigo) {
  std::string escolha;
  std::string apelido;
  bool entrada_invalida = true;

  std::cout << "\nVocê quer apelidar " << inimigo->get_apelido() << "? (s/n)\n";
  while(entrada_invalida) {
    std::cout << "Digite s para sim e n para nao: ";
    std::getline(std::cin, escolha);
    if(escolha == "s") {
      entrada_invalida = false;
      print_ascii_art(inimigo->get_nome());
      std::cout << "\nDigite o apelido desejado: ";
      std::getline(std::cin, apelido);
      inimigo->set_apelido(apelido);
    }
    else if(escolha == "n") {
      entrada_invalida = false;
      std::cout << "Como você não deseja apelidar " << inimigo->get_apelido() << ", o apelido dele ficará assim mesmo...";
    }
    else
      entrada_invalida = true;
  }
}

bool deseja_capturar(Pokemon *inimigo) {
    std::string escolha;
    bool entrada_invalida = true;

    std::cout << "\nDeseja capturar " << inimigo->get_apelido() << "? (s/n)\n";
    while(entrada_invalida) {
        std::cout << "Digite s para sim e n para nao: ";
        std::getline(std::cin, escolha);
        if(escolha == "s" ||escolha == "S") {
            entrada_invalida = false;
            deseja_apelidar(inimigo);
            return true;
        }
        else if(escolha == "n" || escolha == "N") {
            entrada_invalida = false;
            return false;
        }
        else {
            entrada_invalida = true;
        }
    }
    return false;
}

bool deseja_continuar_jogando(){
    std::string escolha;
    bool entrada_invalida = true;

    std::cout<<"\n\nDeseja continuar jogando? (s/n)\n";
    while(entrada_invalida) {
        std::cout << "Digite s para sim e n para nao: ";
        std::getline(std::cin, escolha);
        if(escolha == "s" || escolha == "S") {
            entrada_invalida = false;
            return true;
        }
        else if(escolha == "n" || escolha == "N") {
            entrada_invalida = false;
            return false;
        }
        else {
            entrada_invalida = true;
        }
    }
    return false;
}

int doar_pokemon(Treinador jogador){
    std::cout<<"Escolha um de seus antigos Pokemon a ser doado.\n";
    jogador.print_lista_pokemon();
    std::string escolha, confirmacao;
    do{
        escolha = escolha_um_a_nove();

        print_ascii_art(jogador._lista_de_pokemon.at((escolha[0] - '0')-1)->get_nome());
        std::cout << "Tem certeza que deseja doar o pokemon apelidado : ";
        std::cout << jogador._lista_de_pokemon.at((escolha[0] - '0')-1)->get_apelido() << "? ";
        std::getline(std::cin, confirmacao);
        if(confirmacao[0] != 'S' && confirmacao[0] != 's')
            std::cout << std::endl << "Ok, vamos selecionar outro Pokemon. Qual Pokemon você deseja doar? ";

    }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    return (escolha[0] - '0') - 1;
}

void print_ataque(std::string poke1, std::string poke2, std::string habilidade, int dano, int vida){
    if(vida >= 0){
        std::cout << "\n\t" << poke1 << " usa " << habilidade << " e inflige " << dano << " hit points em " << poke2 << "!" << std::endl;
        std::cout << "\t" << poke2 << " esta' com " << vida << " pontos de vida! \n" << std::endl;
    }else{
        std::cout << "\n\t" << poke1 << " usa " << habilidade << " e inflige " << dano << " hit points em " << poke2 << "!" << std::endl;
        std::cout << "\t" << poke2 << " esta' com 0 pontos de vida! \n" << std::endl;
    }
}

//----------------------------------------------------------------------------------------------------------------
//Abaixo temos métodos com lógica semelhante. Ler o primeiro já basta para entender os demais

std::string escolha_um_a_um(){
    std::string escolha;
    do{
        std::cout << "Err.... digite o numero 1, meu chapa. ";
        std::getline(std::cin, escolha);
    }while(escolha[0] != '1');
    return escolha;
}

std::string escolha_um_a_dois(){
    std::string escolha;
    do{
        std::cout << "Digite o numero correspondente: ";
        std::getline(std::cin, escolha);
    }while(escolha[0] != '1' && escolha[0] != '2');
    return escolha;
}

std::string escolha_um_a_tres(){
    std::string escolha;
    do{
        std::cout << "Digite o numero correspondente: ";
        std::getline(std::cin, escolha);
    }while(escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3');
    return escolha;
}

std::string escolha_um_a_quatro(){
    std::string escolha;
    do{
        std::cout << "Digite o numero correspondente: ";
        std::getline(std::cin, escolha);
    }while(escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3' && escolha[0] != '4');
    return escolha;
};

std::string escolha_um_a_cinco(){
    std::string escolha;
    do{
        std::cout << "Digite o numero correspondente: ";
        std::getline(std::cin, escolha);
    }while(escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3' && escolha[0] != '4' && escolha[0] != '5');
    return escolha;
};

std::string escolha_um_a_seis(){
    std::string escolha;
    do{
        std::cout << "Digite o numero correspondente: ";
        std::getline(std::cin, escolha);
    }while(escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3' && escolha[0] != '4' && escolha[0] != '5'
                             && escolha[0] != '6');
    return escolha;
};

std::string escolha_um_a_sete(){
    std::string escolha;
    do{
        std::cout << "Digite o numero correspondente: ";
        std::getline(std::cin, escolha);
    }while(escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3' && escolha[0] != '4' && escolha[0] != '5'
                             && escolha[0] != '6' && escolha[0] != '7');
    return escolha;
};

std::string escolha_um_a_oito(){
    std::string escolha;
    do{
        std::cout << "Digite o numero correspondente: ";
        std::getline(std::cin, escolha);
    }while(escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3' && escolha[0] != '4' && escolha[0] != '5'
                             && escolha[0] != '6' && escolha[0] != '7' && escolha[0] != '8');
    return escolha;
};

std::string escolha_um_a_nove(){
    std::string escolha;
    do{
        std::cout << "Digite o numero correspondente: ";
        std::getline(std::cin, escolha);
    }while(escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3' && escolha[0] != '4' && escolha[0] != '5'
                             && escolha[0] != '6' && escolha[0] != '7' && escolha[0] != '8' && escolha[0] != '9');
    return escolha;
};
