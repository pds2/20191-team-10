#include "pokemon.h"

#include <iostream>
#include <string>

Pokemon::Pokemon(std::string nome,float crit,int HP,char ataque,char defesa,char agilidade):
	_nome(nome), _crit(crit), _HP(HP), _ataque(ataque), _defesa(defesa), _agilidade(agilidade){};

int Pokemon::get_ataque(){
	if(_ataque=='A'){
		return 30;
	}
	else if(_ataque=='B'){
		return 25;
	}
	else if(_ataque=='C'){
		return 20;
	}
	else if(_ataque=='D'){
		return 15;
	}
	else if(_ataque=='E'){
		return 10;
	}
	else if(_ataque=='F'){
		return 5;
	}
}

int Pokemon::get_agilidade(){
	if(_agilidade=='A'){
		return 6;
	}
	else if(_agilidade=='B'){
		return 5;
	}
	else if(_agilidade=='C'){
		return 4;
	}
	else if(_agilidade=='D'){
		return 3;
	}
	else if(_agilidade=='E'){
		return 2;
	}
	else if(_agilidade=='F'){
		return 1;
	}
}

int Pokemon::get_crit(){
	return _crit;
}

int Pokemon::get_defesa(){
	if(_ataque=='A'){
		return 18;
	}
	else if(_ataque=='B'){
		return 15;
	}
	else if(_ataque=='C'){
		return 12;
	}
	else if(_ataque=='D'){
		return 9;
	}
	else if(_ataque=='E'){
		return 6;
	}
	else if(_ataque=='F'){
		return 3;
	}
}

int Pokemon::get_HP(){
	return _HP;
}

std::string Pokemon::get_nome(){
	return _nome;
}

int Pokemon::get_id(){
	return _id;
}
