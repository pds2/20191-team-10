#include "../include/interface.h"
#include "../include/batalha.h"
#include "../include/excecoes.h"
#include "../include/pokebola.h"

#include <stdlib.h>

int escolher_pokebola(Treinador jogador, Pokemon *inimigo){
    int escolha;

    std::cout << "Qual pokebola deseja utilizar para capturar esse pokemon?" << '\n';
    if(jogador.get_pokeball() > POKEBOLA_INVALIDO)
      std::cout << "\t1- Pokeball" << '\n';
    if(jogador.get_greatball() > POKEBOLA_INVALIDO)
      std::cout << "\t2- Greatball" << '\n';
    if(jogador.get_masterball() > POKEBOLA_INVALIDO)
      std::cout << "\t3- Masterball" << '\n';
    if((jogador.get_pokeball() > POKEBOLA_INVALIDO)||(jogador.get_greatball() > POKEBOLA_INVALIDO)||(jogador.get_masterball() > POKEBOLA_INVALIDO)){
      std::cout << "Digite o número correspondente a pokebola desejada: ";
      std::cin >> escolha;
      if(escolha >= 1 && escolha <= 3)
        return escolha;
      else {
        while (escolha < 1 || escolha > 3) {
          std::cout << "Digite o número correspondente ao de uma das pokebolas acima: " << '\n';
          std::cin >> escolha;
        }
      }
    } else {
      std::cout << "Você não possui nenhum tipo de pokebola. Jogue mais batalhas para conseguir novas pokebolas!" << '\n';
      return 0;
    }
}

bool check_pokebola(Treinador jogador){
    if((jogador.get_pokeball() <= POKEBOLA_INVALIDO)&&(jogador.get_greatball() <= POKEBOLA_INVALIDO)&&(jogador.get_masterball() <= POKEBOLA_INVALIDO)){
      return false;
    } else return true;
}

bool deseja_capturar(Pokemon *inimigo) {
  std::string escolha;
  bool entrada_invalida = true;

  std::cout << "Deseja capturar " << inimigo->get_apelido() << "? (s/n)\n";
  while(entrada_invalida) {
    std::cout << "Digite s para sim e n para nao: ";
    std::cin >> escolha;
    if(escolha == "s") {
      entrada_invalida = false;
      return true;
    }
    else if(escolha == "n") {
      entrada_invalida = false;
      return false;
    }
    else
      entrada_invalida = true;
  }
}

int escolher_opcoes() {
  int opcao_escolhida;
  bool run_input = true;

  std::cout << "\nO que deseja fazer agora? " << '\n';
  std::cout << "1- Capturar pokemon" << '\n';
  std::cout << "2- Jogar outra batalha" << '\n';
  std::cout << "3- Consultar pokedex" << '\n';
  while (run_input) {
    std::cin >> opcao_escolhida;
    if(opcao_escolhida >= 1 && opcao_escolhida <= 3) {
      return opcao_escolhida;
      run_input = false;
    }
    else {
      std::cout << "Digite um número válido correspondente as opções mostradas acima: ";
      std::cin >> opcao_escolhida;
      if(opcao_escolhida >= 1 && opcao_escolhida <= 3) {
        return opcao_escolhida;
        run_input = false;
      }
    }
  }
}

int doar_pokemon(Treinador jogador){
    std::cout<<"Escolha um Pokemon a ser doado.\n";
    jogador.print_lista_pokemon();
    std::string escolha, confirmacao;
    do{
        escolha = escolha_um_a_quatro();

        std::cout << "Tem certeza que deseja doar o pokemon apelidado : ";
        std::cout << jogador._lista_de_pokemon.at((escolha[0] - '0')-1)->get_apelido() << "? ";
        std::cin >> confirmacao;
        if(confirmacao[0] != 'S' && confirmacao[0] != 's')
            std::cout << std::endl << "Ok, vamos selecionar outro Pokemon. Qual Pokemon você deseja doar? ";

    }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    return (escolha[0] - '0') - 1;
}

int escolher_pokemon(Treinador jogador){
    std::cout << "Escolha um dos Pokemon abaixo." << std::endl;
    jogador.print_lista_pokemon();
    std::string escolha, confirmacao;

 //Criar uma exce��o aqui depois & pensar numa maneira de o c�digo n�o crashar caso tenha apenas 2

    do{
        escolha = escolha_um_a_tres();

        std::cout << "Tem certeza que quer usar o pokemon apelidado : ";
        std::cout << jogador._lista_de_pokemon.at((escolha[0] - '0')-1)->get_apelido() << "? ";
        std::cin >> confirmacao;
        if(confirmacao[0] != 'S' && confirmacao[0] != 's')
            std::cout << std::endl << "Ok, vamos selecionar outro Pokemon. Qual Pokemon deseja escolher? ";

    }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    return (escolha[0] - '0') - 1;
}

int escolher_habilidade(Pokemon *meu_poke, int lideranca){
    std::string escolha;
    std::cout << "Qual habilidade você deseja usar?" << std::endl;
    meu_poke->print_habilidades(lideranca);

    //Criar mais exceções aqui.
    //Além disso, pensar numa forma de saber se está no nível de usar habilidades lvl alto

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

    return (escolha[0] - '0');
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

void confirmar_escolha(Treinador jogador,std::string escolha,std::string confirmacao){
    std::cout << "Tem certeza que quer usar o pokemon apelidado : ";
    std::cout << jogador._lista_de_pokemon.at((escolha[0] - '0')-1)->get_apelido() << "? ";
    std::cin >> confirmacao;
    if(confirmacao[0] != 'S' && confirmacao[0] != 's')
    std::cout << std::endl << "Ok, vamos selecionar outro Pokemon. Qual Pokemon quer levar? ";
}


std::string escolha_um_a_um(){
    std::string escolha;
    do{
        std::cout << "Err.... digite o numero 1, meu chapa. ";
        std::cin >> escolha;
    }while(escolha[0] != '1');
    return escolha;
}

std::string escolha_um_a_dois(){
    std::string escolha;
    do{
        std::cout << "Digite o numero correspondente: ";
        std::cin >> escolha;
    }while(escolha[0] != '1' && escolha[0] != '2');
    return escolha;
}

std::string escolha_um_a_tres(){
    std::string escolha;
    do{
        std::cout << "Digite o numero correspondente: ";
        std::cin >> escolha;
    }while(escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3');
    return escolha;
}

std::string escolha_um_a_quatro(){
    std::string escolha;
    do{
        std::cout << "Digite o numero correspondente: ";
        std::cin >> escolha;
    }while(escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3' && escolha[0] != '4');
    return escolha;
};
