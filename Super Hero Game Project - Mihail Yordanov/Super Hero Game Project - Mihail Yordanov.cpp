#include <iostream>
#include <fstream>
#include "Interface.h"
#pragma once

void runSuperHeroGame()
{
	printGameCommands();
	heading_Super();
	heading_Hero();
	heading_Game();
	loadingSuperHeroGame();
}

int main()
{
	runSuperHeroGame();
}
