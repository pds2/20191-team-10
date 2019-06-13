#ifndef EXCECOES_H
#define EXCECOES_H

#include "pokemon.h"
#include "treinador.h"

#include <stdexcept>
#include <exception>
#include <limits>
#include <sstream>

// As funções que desse .h simplesmente verificam casos de exceção e jogam o tipo de exceção específica
// O tratamento específico para cada exceção será tratato em outras funcões
// Ex: excpt_verificar_morto(Pokemon*) joga exceção std::out_of_range()
// Que será tratada na função encerrar_batalha(Pokemon*) presente no batalha.h

// Nada impede de criarmos novos tipos de exceções

// Ex: Todas exceçoes devem começar com "excpt_"

// class excpt_qualquer : public std::exception{
// public:
//		const char *what(){
//			return "Ocorreu Exceção Qualquer\n";
//		}
//};

class Excpt_Nocaute : public std::exception{
public:
	const char *what(){
		return "Pokemon Nocauteado!\n";
	}
};

class Excpt_Habilidade_Invalida : public std::exception{
public:
    const char *what(){
        return "Seu treinador não tem liderança suficiente para usar essa habilidade\n";
    }
};

class Excpt_Limite_Habilidade : public std::exception{
public:
    const char *what(){
        return "A habilidade escolhida esgotou! Escolha outra!\n";
    }
};

class Excpt_Lideranca_Invalida : public std::exception{
public:
    const char *what(){
        return "A liderança deve ser um valor entre 1 e 4\n";
    }
};

class Excpt_Num_Pokemon_Invalido : public std::exception{
public:
    const char *what(){
        return "Você pode ter apenas 9 pokemon! Escolha um de seus Pokemons antigos para doar :\n ";
    }
};

class Excpt_Entrada_Inicial : public std::exception {
public:
    const char *what() {
        return "Entrada Invalida! Digite 1, 2 ou 3!\n";
    }
};

class Excpt_Dificuldade_Invalida : public std::exception{
public:
    const char *what(){
        return "Dificuldade Invalida! Como padrão a dificuldade será colocada como Fácil!\n";
    }
};

void verificar_dificuldade_valida(int);

void verifica_entrada(std::string);

void verificar_lideranca_valida(int);
int tratamento_lideranca_invalida();

void verificar_nocaute(Pokemon*,Pokemon*);

void verificar_habilidade_valida(std::string,int);
void tratamento_habilidade_invalida(std::string,int);

void verificar_limite_habilidade(std::string, short int *);
void tratamento_limite_habilidade(std::string &, short int *);

void verificar_num_pokemon_valido(Treinador);
Treinador tratamento_num_pokemon_invalido(Treinador);

int verifica_inteiro(std::string);

#endif // EXCECOES_H
