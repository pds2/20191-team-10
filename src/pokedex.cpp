#include "../include/pokedex.h"

void treinador_info(Treinador jogador) {
  std::cout << "----------------------------------------------------------------------------" << '\n';
  std::cout << "\t\t\tPOKÉDEX" << '\n';
  std::cout << "----------------------------------------------------------------------------" << '\n';
  std::cout << "Treinador " << jogador.get_treinador();
  std::cout << " - Liderança: " << jogador.get_lideranca() << "\n\n";
  if(jogador.get_pokeball() > POKEBOLA_INVALIDO)
    std::cout << "Pokeballs: " << jogador.get_pokeball() << '\n';
  if(jogador.get_greatball() > POKEBOLA_INVALIDO)
    std::cout << "Greatballs: " << jogador.get_greatball() << '\n';
  if(jogador.get_masterball() > POKEBOLA_INVALIDO)
    std::cout << "Masterballs: " << jogador.get_masterball() << '\n';
  if(jogador.get_capturas_totais() > 0) {
    std::cout << "\n\nTaxa de sucesso na captura de pokemons: " << jogador.get_taxa_sucesso() << '\n';
  } else {
    std::cout << "\n\nVocê ainda não tentou capturar pokemons, por isso sua taxa de sucesso na captura\
    de pokemons está indisponível." << '\n';
  }
  std::cout << "----------------------------------------------------------------------------" << '\n';
  std::cout << "Pokemons:\n\n";

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
