#ifndef TREINADOR_H
#define TREINADOR_H

#include "pokemon.h"

#include <string>
#include <vector>

class Treinador{
	protected:
		std::string _jogador;
	public:
		int _lideranca; // Atributo Liderança do Treinador deve ser alterado logo está no escopo público

		std::vector<Pokemon*> _lista_de_pokemons;

		Treinador(std::string,int); // Construtor : Nome, Nível de lideranca

		// Métodos para manipulação do TAD :

		int get_lideranca();
		void set_lideranca(int);
		void add_pokemon(Pokemon*);
		std::string get_jogador();
};

#endif
