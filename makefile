all:
		g++ -std=c++11 -o run_game src/pokemon.cpp src/treinador.cpp src/batalha.cpp src/excecoes.cpp src/pokemon_agua.cpp src/pokemon_grama.cpp src/pokemon_fogo.cpp src/pokemon_src/bulbasauro.cpp src/pokemon_src/charmander.cpp src/pokemon_src/squirtle.cpp program/main.cpp

clean:
		rm -rf *o run_game