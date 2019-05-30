#include "../include/interface.h"
#include "../include/batalha.h"
#include "../include/excecoes.h"


int escolher_pokemon(Treinador jogador){
    std::cout << "Qual dos seus Pokemon sera levado a batalha?";
    std::cout << std::endl;
    jogador.print_lista_pokemon();
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
            std::cout << std::endl << "Ok, vamos selecionar outro Pokemon. Qual Pokemon quer levar? ";

    }while((confirmacao[0] != 's') && (confirmacao[0] != 'S'));
    return (escolha[0] - '0') - 1;
}
