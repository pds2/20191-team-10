all:
		g++ -std=c++11 -o run_game src/pokemon.cpp src/introducao.cpp src/treinador.cpp src/pokebola.cpp src/interface.cpp src/batalha.cpp src/excecoes.cpp src/pokemon_agua.cpp src/pokemon_grama.cpp src/pokemon_fogo.cpp src/pokemon_src/bulbasauro.cpp src/pokemon_src/charmander.cpp src/pokemon_src/squirtle.cpp program/main.cpp

run_linux:
		./run_game

run_win:
		run_game.exe

clean:
		rm -rf *o run_game

old:
	g++ -std=c++11 -o run_game src/pokemon.cpp src/treinador.cpp src/batalha.cpp src/excecoes.cpp src/pokemon_agua.cpp src/pokemon_grama.cpp src/pokemon_fogo.cpp src/pokemon_src/bulbasauro.cpp src/pokemon_src/charmander.cpp src/pokemon_src/squirtle.cpp program/main.cpp
