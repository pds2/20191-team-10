#ifndef BATALHA_H
#define BATALHA_H

#include "pokemon.h"

int rola_dados(); // Gera um número aleatório entre 1 e 10. Utilizado para calcular a chance de crit, por exemplo.

void encerrar_batalha(Pokemon *, Pokemon *); // Encerra. Deve inclusive resetar o current_hp para o valor original.

#endif // BATALHA_H
