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

// Sessão de testes relacionados a Classe Treinador: testes_treinador

TEST_CASE("Testando Construtor do Treinador Pokemon"){
    CHECK_NOTHROW(Treinador("Leandro",4));
}


TEST_CASE("Testando definições do Treinador"){
    Treinador Leandro = Treinador("Leandro",4);
    CHECK(Leandro.get_pokeball() == 5); //Quantidade predefinida no construtor
    CHECK(Leandro.get_treinador() == "Leandro");
    CHECK(Leandro.get_lideranca() == 4);
}

TEST_CASE("Testando getters e setters do Treinador"){
    Treinador Leandro = Treinador("Leandro",4);

    Leandro.set_lideranca(3);
    CHECK(Leandro.get_lideranca() == 3);
    Leandro.set_pokeball(17);
    CHECK(Leandro.get_pokeball() == 17); //Quantidade predefinida no construtor
    Leandro.set_greatball(25);
    CHECK(Leandro.get_greatball() == 25);
    Leandro.set_masterball(31);
    CHECK(Leandro.get_masterball() == 31);

}

TEST_CASE("Testando Métodos Pokemons"){
    //Contrutores
    Treinador Celso = Treinador("Celso",4);
    Squirtle Ocean = Squirtle("Ocean");
    Charmander Fire = Charmander("Fire");
    Bulbasauro Leaf = Bulbasauro("Leaf");

    //Métodos
    Celso.add_pokemon(&Ocean);
    Celso.add_pokemon(&Fire);
    Celso.add_pokemon(&Leaf);

    CHECK(Celso._lista_de_pokemon.at(0)->get_apelido() == "Ocean");
    CHECK(Celso._lista_de_pokemon.at(1)->get_apelido() == "Fire");
    CHECK(Celso._lista_de_pokemon.at(2)->get_apelido() == "Leaf");
}
