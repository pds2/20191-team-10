#ifndef POKEMON_H
#define POKEMON_H

#include <string>

// Pokemon não será uma interface. Motivo : Ao refatorar o código percebi muita repetição desnecessária.

class Pokemon{
    protected:
        std::string _nome;
		char _tipo;
        int _ataque;
		int _defesa;
		int _agilidade;
		int _hp;
		int _crit;
	public:
	    int current_hp; // Esse será o HP modificado durante as lutas. Logo deve ser público.

	    Pokemon(std::string,char,int,int,int,int,int); // Construtor:
                                                      // nome,tipo,ataque,defesa,agilidade,hp,crit

        // Métodos Polimórficos :

		virtual void atacar(Pokemon *) = 0;

	// Métodos para manipulação do TAD :

		virtual int get_ataque();
		virtual int get_defesa();
		virtual int get_agilidade();
		virtual int get_hp();
		virtual int get_crit();
		virtual char get_tipo();
		virtual std::string get_nome();
};

#endif //POKEMON_H
