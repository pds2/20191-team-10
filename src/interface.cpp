#include "../include/interface.h"
#include "../include/batalha.h"
#include "../include/excecoes.h"

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
      return escolha;
    } else {
      std::cout << "Você não possui nenhum tipo de pokebola. Jogue mais batalhas para conseguir novas pokebolas!" << '\n';
    }
}

int escolher_pokemon(Treinador jogador){
    std::cout << "Qual dos seus Pokemon sera levado a batalha?" << std::endl;
    jogador.print_lista_pokemon();
    std::string escolha, confirmacao;


 //Criar uma exce��o aqui depois & pensar numa maneira de o c�digo n�o crashar caso tenha apenas 2


    do{
        do{
            std::cout << "Digite o numero correspondente: ";
            std::cin >> escolha;
        }while((escolha[0] != '1') && (escolha[0] != '2') && (escolha[0] != '3'));

        std::cout << "Tem certeza que quer usar ";
        std::cout << jogador._lista_de_pokemon.at((escolha[0] - '0')-1)->get_apelido() << "? ";
        std::cin >> confirmacao;
        if(confirmacao[0] != 'S' && confirmacao[0] != 's')
            std::cout << std::endl << "Ok, vamos selecionar outro Pokemon. Qual Pokemon quer levar? ";

    }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    return (escolha[0] - '0') - 1;
}

int escolher_habilidade(Pokemon *meu_poke, int lideranca){
    std::string escolha;
    std::cout << "Qual habilidade você deseja usar?" << std::endl;
    meu_poke->print_habilidades(lideranca);

    //Criar mais exceções aqui.
    //Além disso, pensar numa forma de saber se está no nível de usar habilidades lvl alto

    do{
        std::cout << "Digite o numero correspondente: ";
        std::cin >> escolha;
    }while(escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3' && escolha[0] != '4');
    return (escolha[0] - '0');
}
