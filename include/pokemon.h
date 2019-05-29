#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>

#define AUMENTO 1.6
#define REDUCAO 0.63

// Pokemon não será uma interface. Motivo : Ao refatorar o código percebi muita repetição desnecessária.

class Pokemon{
  protected:
    std::string _nome;
    int _ataque;
		int _defesa;
		int _agilidade;
		int _hp;
		int _crit;
		std::string _fraqueza;
		std::string _resistencia;
	public:
	  int current_hp; // Esse será o HP modificado durante as lutas. Logo deve ser público.

	  Pokemon(std::string nome, int ataque, int defesa, int agilidade, int hp, int crit); // Construtor:
                                                  // nome,ataque,defesa,agilidade,hp,crit

  // Métodos Polimórficos :

		virtual void atacar(Pokemon *) = 0;
		
		virtual std::string get_resistencia() = 0;
		virtual std::string get_fraqueza() = 0;

	// Métodos para manipulação do TAD :

		virtual int get_ataque();
		virtual int get_defesa();
		virtual int get_agilidade();
		virtual int get_hp();
		virtual int get_crit();
		virtual std::string get_nome();

};

#endif //POKEMON_H
