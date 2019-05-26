#ifndef EXCECOES_H
#define EXCECOES_H

#include "pokemon.h"

#include <stdexcept>
#include <exception>

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

void excpt_verificar_morto(Pokemon*);

#endif // EXCECOES_H
