#ifndef TREINADOR_H
#define TREINADOR_H

#include "pokemon.h"
#include "pokemon_agua.h"

#include <string>
#include <vector>

class Treinador{
	protected:
		std::string _treinador;
	public:
		int _lideranca; // Atributo Liderança do Treinador deve ser alterado logo está no escopo público
		int _pokeball;
		int _greatball;
		int _masterball;

		std::vector<Pokemon*> _lista_de_pokemon;

		Treinador(std::string nome, int lideranca); // Construtor : Nome, Nível de lideranca

		// Métodos para manipulação do TAD :
    std::string get_treinador();

		int get_lideranca();
		void set_lideranca(int);

		int get_pokeball();
		void set_pokeball(int quantidade);

		int get_greatball();
		void set_greatball(int quantidade);

		int get_masterball();
		void set_masterball(int quantidade);

		void add_pokemon(Pokemon*);
		void print_lista_pokemon();
};

#endif
