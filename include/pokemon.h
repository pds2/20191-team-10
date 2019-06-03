#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include <iostream>

#define AUMENTO 1.6
#define REDUCAO 0.63

// Pokemon não será uma interface. Motivo : Ao refatorar o código percebi muita repetição desnecessária.

class Pokemon{
  protected:
    std::string _nome;
    std::string _apelido;
    int _ataque;
		int _defesa;
		int _agilidade;
		int _hp;
		int _crit;
    int _iv;
		std::string _fraqueza;
		std::string _resistencia;
		std::string _habilidades[4];
	public:
	  int current_hp; // Esse será o HP modificado durante as lutas. Logo deve ser público.

    //Construtor: apelido,ataque,defesa,agilidade,hp,crit
	  Pokemon(std::string apelido, int ataque, int defesa, int agilidade, int hp, int crit);

    //Construtor sem apelido como parametro
    Pokemon(int ataque, int defesa, int agilidade, int hp, int crit);


  // Métodos Polimórficos :

		virtual void atacar(Pokemon *) = 0;

		virtual std::string get_resistencia() = 0;
		virtual std::string get_fraqueza() = 0;
		
		virtual void print_habilidades(int) = 0;

	// Métodos para manipulação do TAD :

		virtual int get_ataque();
		virtual int get_defesa();
		virtual int get_agilidade();
		virtual int get_hp();
		virtual int get_crit();
    virtual int get_iv();
    virtual void set_nome(std::string nome);
		virtual std::string get_nome();
    virtual void set_apelido(std::string apelido);
    virtual std::string get_apelido();

};

#endif //POKEMON_H
