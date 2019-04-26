#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon{
	protected:
		std::string _nome; // Atributos são estáticos logo não devem ser alterados com a execução do jogo
	public:
		float _crit;
		int _HP;
		char _ataque;
		char _defesa;
		char _agilidade;
		
		Pokemon(std::string,float,int,char,char,char); // Construtor: Nome, Crit, HP, ataque, defesa, agilidade
		//~Pokemon();
		
		int get_ataque();
		int get_defesa();
		int get_agilidade();
		int get_HP();
		int get_crit();
		std::string get_nome();
};

#endif
