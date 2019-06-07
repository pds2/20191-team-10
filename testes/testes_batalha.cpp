// #include "../include/pokemon.h"
// #include "../include/introducao.h"
#include "../include/pokemon_include/charmander.h"
#include "../include/pokemon_include/bulbasauro.h"
#include "../include/pokemon_include/squirtle.h"
#include "../include/treinador.h"
#include "../include/excecoes.h"
#include "../include/batalha.h"
#include "../include/interface.h"
#include "../include/pokebola.h"
#include "../include/pokedex.h"

#include "../third_party/doctest.h"
#include <iostream>
#include <string>

//Sessão de testes relacionados a classe batalha

TEST_CASE("Batalha"){
    //Contrutores
    Treinador Celso = Treinador("Celso",4);
    Squirtle Ocean = Squirtle("Ocean");
    Charmander Fire = Charmander("Fire");

    Celso.add_pokemon(&Ocean);
    Celso.add_pokemon(&Fire);

    CHECK_NOTHROW(batalha_x1(Celso, (Celso._lista_de_pokemon.at(0)), 1));
    CHECK_NOTHROW(batalha_x1(Celso, (Celso._lista_de_pokemon.at(1)), 3));
}
