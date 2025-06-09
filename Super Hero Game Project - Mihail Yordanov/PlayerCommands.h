#pragma once
#include "Battle.h"
#include "SaveArrayInDataBase.h"
#include "addAndRemoveFromArrays.h"
#include "PrintObjectsInformation.h"

void showBalance_Command(const char* buff, const Player* curPlayer)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!strcmp(buff, "show balance") || !strcmp(buff, "show money") ||
		!strcmp(buff, "balance") || !strcmp(buff, "money"))
	{
		SetConsoleTextAttribute(hConsole, 6);
		std::cout << "Current Balance: ";
		SetConsoleTextAttribute(hConsole, 2);
		std::cout << curPlayer->getBalance() << "$" << "\n\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
}

void buySuperHero_Command(const char* buff, MyVector<SuperHero>& heros, Player* curPlayer,
	size_t& playedCommandCounter)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!strcmp(buff, "buy hero") || !strcmp(buff, "buy"))
	{
		if (playedCommandCounter < 3)
		{
			buySuperHero(heros, curPlayer, playedCommandCounter);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "\n>You have reached your limit of operations for this round!\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}

void visitOtherPlayers_Command(const char* buff, const MyVector<Player>& players,
	const MyVector<SuperHero>& heros,int curUserInd)
{
	if (!strcmp(buff, "show players") || !strcmp(buff, "show pl"))
	{
		showPlayers(players, heros, curUserInd);
	}
}

void showMyHeros_Command(const char* buff, const MyVector<SuperHero>& heros,
	const Player* curPlayer)
{
	if (!strcmp(buff, "show my heros") || !strcmp(buff, "my heros") ||
		!strcmp(buff, "print my heros") || !strcmp(buff, "my collection"))
	{
		showMyHeros(heros, curPlayer);
		std::cout << std::endl;
	}
}

void attackPlayer_Command(const char* buff, MyVector<Player>& players,
	MyVector<SuperHero>& heros, Player* curPlayer, size_t& playedCommandCounter)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!strcmp(buff, "attack") || !strcmp(buff, "Attack") ||
		!strcmp(buff, "attack pl") || !strcmp(buff, "attack player"))
	{
		if (playedCommandCounter < 3)
		{
			try
			{
				attackPlayer(players, heros, curPlayer);
				playedCommandCounter++;
			}
			catch (int)
			{
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "You don't have any heros!\n" <<
					"Have to buy some hero to attack player!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			catch (std::bad_alloc)
			{
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Not Existing player!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			catch (char)
			{
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Incorrect Hero name!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			catch (double)
			{
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Your hero has to be in Attack type!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "\n>You have reached your limit of operations for this round!\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}

	}
}

void showTopPlayers_Command(const char* buff, MyVector<Player>& players)
{
	if (!strcmp(buff, "show top") || !strcmp(buff, "show top players") ||
		!strcmp(buff, "show top pl") || !strcmp(buff, "top"))
	{
		showTopPlayers(players);
		std::cout << '\n';
	}
}

void changeHeroType_Command(const char* buff, MyVector<SuperHero>& heros,
	const Player* curPlayer, size_t& playedCommandCounter)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!strcmp(buff, "change type") || !strcmp(buff, "change state") ||
		!strcmp(buff, "change hero") || !strcmp(buff, "change"))
	{
		if (playedCommandCounter < 3)
		{
			try
			{
				changeType(heros, curPlayer);
				std::cout << std::endl;
				playedCommandCounter++;
			}
			catch (int)
			{
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Incorrect Hero name!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			catch (std::bad_alloc)
			{
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Incorrect input type!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "\n>You have reached your limit of operations for this round!\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}

void updateHero_Command(const char* buff, MyVector<SuperHero>& heros,
	Player* curPlayer, size_t& playedCommandCounter)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!strcmp(buff, "update") || !strcmp(buff, "update hero") ||
		!strcmp(buff, "upgrade") || !strcmp(buff, "upgrade hero"))
	{
		if (playedCommandCounter < 3)
		{
			try
			{
				updateHero(heros, curPlayer);
				playedCommandCounter++;
				SetConsoleTextAttribute(hConsole, 10);
				std::cout << "\n You have update your heros successfully!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			catch (int)
			{
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Incorrect Hero name!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			catch (std::bad_alloc)
			{
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "You don't have any Heros!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			catch (char)
			{
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "You don't have enough money!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			catch (double)
			{
				SetConsoleTextAttribute(hConsole, 5);
				std::cout << "May be next Time :D\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			catch (bool)
			{
				SetConsoleTextAttribute(hConsole, 13);
				std::cout << "You have reached ";
				SetConsoleTextAttribute(hConsole, 5);
				std::cout << "Max ";
				SetConsoleTextAttribute(hConsole, 13);
				std::cout << "level of this hero!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "\n>You have reached your limit of operations for this round!\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}


