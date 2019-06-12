#ifndef INTERFACE_H
#define INTERFACE_H

#include "pokemon.h"
#include "pokedex.h"
#include "treinador.h"
#include "pokebola.h"
#include "../include/pokemon_include/charmander.h"
#include "../include/pokemon_include/bulbasauro.h"
#include "../include/pokemon_include/squirtle.h"

#include <string>
#include <iostream>

// Esse header tem como prop�sito armazenar fun��es relacionadas � interface.
// Um bom crit�rio para escolher se voc� deve ou n�o colocar um m�todo nesse header
// � pensar :

// 1) Esse m�todo est� relacionado � funcionalidade de uma classe? Se n�o, o implemente aqui
// 2) O n�mero de prints e inputs utilizado pelo m�todo � grande? Se sim, o implemente aqui.
int escolher_pokebola(Treinador jogador, Pokemon *inimigo);

bool check_pokebola(Treinador jogador); //verifica se o treinador tem pokebolas

void deseja_apelidar(Pokemon *inimigo);

bool deseja_capturar(Pokemon *inimigo);

bool deseja_continuar_jogando();

int escolher_opcoes(Pokemon *meu_poke);
// é auxiliar da função de interface escolher_pos_batalha (retorna o numero do
// modo de jogo ou opção escolhida).

int escolher_pokemon(Treinador); //Fun��o que recebe um treinador e escolhe um de seus Pok�mon.

std::string confirmar_escolha(Treinador,std::string,std::string); // Método auxiliar a escolher_pokemon

int doar_pokemon(Treinador); //Fun��o que recebe um treinador e escolhe um de seus Pok�mon a ser doado.

int escolher_habilidade(Pokemon *, int, short int *);

void print_ataque(std::string, std::string, std::string, int, int);
//Printa quanto o dano de 1 foi tirado de 2 e mostra o nome da habilidade.
//O primeiro int é o dano e o segundo é a vida atual.

// Exemplo de programação defensiva :
// As seguintes funções estão retornando string para evitar loops infinitos devido a entradas impróprias.
std::string escolha_um_a_nove(); //Função que retorna uma string a qual representa uma escolha de 1 a 9
std::string escolha_um_a_oito();
std::string escolha_um_a_sete();
std::string escolha_um_a_seis();
std::string escolha_um_a_cinco();
std::string escolha_um_a_quatro();
std::string escolha_um_a_tres();
std::string escolha_um_a_dois();
std::string escolha_um_a_um();

#endif // INTERFACE_H
