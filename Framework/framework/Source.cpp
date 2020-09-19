#include"Game.h"




int main()
{
	Game* game = new Game();
	

	game->Initialized("", 800, 600);

	game->Run();

	return 0;
}