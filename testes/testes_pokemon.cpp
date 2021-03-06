// #include "../include/pokemon.h"
// #include "../include/introducao.h"

#include "../include/pokemon_include/charmander.h"
#include "../include/pokemon_include/bulbasauro.h"
#include "../include/pokemon_include/squirtle.h"
#include "../include/treinador.h"
#include "../include/excecoes.h"
#include "../include/batalha.h"
#include "../include/interface.h"

#include "../third_party/doctest.h"
#include <string>

//Sessão de testes relacionados a classe Pokemon: testes_pokemon

TEST_CASE("Contrutor do Pokemons"){
    CHECK_NOTHROW(Squirtle("Ocean"));
    CHECK_NOTHROW(Charmander("Fire"));
    CHECK_NOTHROW(Bulbasauro("Leaf"));
}

TEST_CASE("Testando getters de Fraqueza e Resistência de Pokemons tipo Água"){
    Squirtle Ocean = Squirtle("Ocean");
    //Polimorfismo com a Superclasse Pokemon
    CHECK(Ocean.get_fraqueza() == "grama");
    CHECK(Ocean.get_resistencia() == "fogo");
}

TEST_CASE("Testando getters de Fraqueza e Resistência de Pokemons tipo Fogo"){
    Charmander Fire = Charmander("Fire");
    //Polimorfismo com a Superclasse Pokemon
    CHECK(Fire.get_fraqueza() == "agua");
    CHECK(Fire.get_resistencia() == "grama");
}

TEST_CASE("Testando getters de Resistência e Fraqueza de Pokemons tipo Grama"){
    Bulbasauro Leaf = Bulbasauro("Leaf");
    //Polimorfismo com a Superclasse Pokemon
    CHECK(Leaf.get_fraqueza() == "fogo");
    CHECK(Leaf.get_resistencia() == "agua");
}

TEST_CASE("Testando getters de Status do pokemon"){
    //Contrutores
    Treinador Celso = Treinador("Celso",4);
    Bulbasauro Leaf = Bulbasauro("Leaf");

    Celso.add_pokemon(&Leaf);

    CHECK(Celso._lista_de_pokemon.at(0)->get_ataque() == 15);
    CHECK(Celso._lista_de_pokemon.at(0)->get_defesa() == 10);
    CHECK(Celso._lista_de_pokemon.at(0)->get_agilidade() == 10);
    CHECK(Celso._lista_de_pokemon.at(0)->get_hp() == 50);
    CHECK(Celso._lista_de_pokemon.at(0)->get_crit() == 5);

}
