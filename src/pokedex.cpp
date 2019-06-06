#include "../include/pokedex.h"

void treinador_info(Treinador jogador) {
  std::cout << "----------------------------------------------------------------------------" << '\n';
  std::cout << "\t\t\tPOKÉDEX" << '\n';
  std::cout << "----------------------------------------------------------------------------" << '\n';
  std::cout << "Treinador " << jogador.get_treinador() << '\n';
  std::cout << "----------------------------------------------------------------------------" << '\n';
  std::cout << "Pokemons: " << '\n';
  std::cout << "________________________________________________" << '\n';

  for (auto& it : jogador._lista_de_pokemon) {
    std::cout << it->get_nome() << '\n';
    std::cout << "Apelido:    " << it->get_apelido() << '\n';
    std::cout << "Ataque:     " << it->get_ataque() << '\n';
    std::cout << "Defesa:     " << it->get_defesa() << '\n';
    std::cout << "Agilidade:  " << it->get_agilidade() << '\n';
    std::cout << "Hp:         " << it->get_hp() << '\n';
    std::cout << "Crítico:    " << it->get_crit() << '\n';
    std::cout << "IV:         " << it->get_iv() << '\n';
    std::cout << "Fraqueza:   " << it->get_fraqueza() << '\n';
    std::cout << "Resistência:" << it->get_resistencia() << '\n';
    std::cout << "________________________________________________" << '\n';

  }
}
