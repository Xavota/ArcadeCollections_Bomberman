#include "Game.h"
#include <time.h>

int main()
{
	srand(time(NULL));//Hace que los números random sean realmente random
	Game game;//Crea un objeto de tipo juego
	game.run();//Corre el juego
}