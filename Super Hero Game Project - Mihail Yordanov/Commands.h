#pragma once
#include "AdminCommands.h"
#include "PlayerCommands.h"
#include "LogIn.h"

void getLogged(const MyVector<Player>& players, const MyVector<Administrator>& admins,
	size_t& curState, int& curUserInd)
{
	logIn(players, admins, curState, curUserInd);
}

void showAllHerosInShop_Command(const char* buff, const MyVector<SuperHero>& heros)
{
	if (!strcmp(buff, "show all heros in shop") || !strcmp(buff, "show all heros") ||
		!strcmp(buff, "show heros") || !strcmp(buff, "show shop"))
	{
		printAllHerosInShop(heros);
		std::cout << '\n';
	}
}