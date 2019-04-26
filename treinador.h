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
		
		Treinador(std::string,int); // Construtor : Nome, Nível de lideranca
		//~Treinador();
		
		std::vector<Pokemon> _lista_de_pokemons;
		
		std::string get_jogador();
		int get_lideranca();
		void set_lideranca(int);
		void add_pokemon(Pokemon);
};

#endif
