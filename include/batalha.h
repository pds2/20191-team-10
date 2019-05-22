#ifndef BATALHA_H
#define BATALHA_H

#include "pokemon.h"

void verificar_morto(Pokemon *); // Verifica se o HP do pokemon é <=0. Caso seja gera uma exceção ou trata essa exceção

int rola_dados(); // Gera um número aleatório entre 1 e 10. Utilizado para calcular a chance de crit, por exemplo.

void encerrar_batalha(Pokemon *, Pokemon *); // Encerra. Deve inclusive resetar o current_hp para o valor original.

#endif // BATALHA_H
