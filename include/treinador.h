#ifndef TREINADOR_H
#define TREINADOR_H

#include "pokemon.h"

#include <string>
#include <vector>

class Treinador{
	private:
		std::string _treinador;
		int _pokeball;
		int _greatball;
		int _masterball;

		//serão utilizadas para armazenar a taxa de captura dos treinadores.
		int _capturas_efetivas;
		int _capturas_totais;

	public:
		int _lideranca; // Atributo Liderança do Treinador deve ser alterado logo está no escopo público


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

		int get_capturas_efetivas();
		void set_capturas_efetivas(int capturas);

		int get_capturas_totais();
		void set_capturas_totais(int capturas);

		void add_pokemon(Pokemon*);
		void print_lista_pokemon();
};

#endif
