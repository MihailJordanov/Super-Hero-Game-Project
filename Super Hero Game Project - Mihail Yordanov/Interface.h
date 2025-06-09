#include <iostream>
#include <fstream>
#include "Commands.h"
#include "Colored.h"
#pragma warning(disable:4996)
#pragma once



void runAsAdmin(MyVector<Player>& players, MyVector<Administrator>& admins,
	MyVector<SuperHero>& heros, size_t& curState, int& curUserInd, size_t& curPlayerInd)
{	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	isShopEmpty(heros); 

	Administrator* curAdmin = admins[curUserInd];
	char buff[1024];
	while (true)
	{
		std::cin.getline(buff, 1024);

		// log out
		if (!strcmp(buff, "log out"))
		{
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << curAdmin->getFirstName();
			SetConsoleTextAttribute(hConsole, 13);
			std::cout << " has logged out successfully!\n\n";
			SetConsoleTextAttribute(hConsole, 15);
			curState = 0;
			break;
		}

		// add new player
		addNewPlayer_Command(buff, players, curPlayerInd);

		// delete player
		deletePlayer_Command(buff, players, heros);

		// show player information
		showPlayerInfo_Commnad(buff, players, heros);

		// add new admin
		addNewAdmin_Commnad(buff, admins);

		// show admin information
		showAdminInfo_Command(buff, admins);
		
		// show all players
		showAllPlayers_Command(buff, players);

		// show all admins
		showAllAdmins_Command(buff, admins);

		// add super hero to shop
		addSuperHeroToShop_Command(buff, heros);

		// show all heros in shop
		showAllHerosInShop_Command(buff, heros);

		// show all selled heros
		showAllSelledHeros_Command(buff, heros);

		// back deleted hero in shop
		backDeletedHeroInShop_Command(buff, heros);

	}
}

void runAsPlayer(MyVector<Administrator>& admins, MyVector<Player>& players,
	MyVector<SuperHero>& heros, size_t& curState, int& curUserInd,
	size_t& curPlayerInd,size_t& lastLoggedPlayerID)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	size_t playedCommandCounter = 0;
	Player* curPlayer = players[curUserInd];
	lastLoggedPlayerID = curPlayer->getId();
	char buff[1024];
	while (true)
	{
		std::cin.getline(buff, 1024);

		// log out
		if (!strcmp(buff, "log out"))
		{
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << curPlayer->getFirstName();
			SetConsoleTextAttribute(hConsole, 13);
			std::cout << " has logged out successfully!\n\n";
			SetConsoleTextAttribute(hConsole, 15);
			curState = 0;
			break;
		}

		// show balance
		showBalance_Command(buff, curPlayer);

		// show all heros in shop
		showAllHerosInShop_Command(buff, heros);

		// buy hero
		buySuperHero_Command(buff, heros, curPlayer, playedCommandCounter);

		// visit other players
		visitOtherPlayers_Command(buff, players, heros, curUserInd);
				
		// show my heros
		showMyHeros_Command(buff, heros, curPlayer);

		// change hero type
		changeHeroType_Command(buff, heros, curPlayer, playedCommandCounter);

		// visit top players
		showTopPlayers_Command(buff, players);

		// attack player
		attackPlayer_Command(buff, players, heros, curPlayer, playedCommandCounter);

		// update hero
		updateHero_Command(buff, heros, curPlayer, playedCommandCounter);
	}

}

void runGame(MyVector<Player>& players, MyVector<Administrator>& admins,
	MyVector<SuperHero>& heros, size_t& curPlayerInd, size_t& lastLoggedPlayerID)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	size_t curState = 0;   // 0 - not logged;  1 - admin;  2 - player
	while (true)
	{
		int curUserInd = -1;

		SetConsoleTextAttribute(hConsole, 3);
		std::cout << "You have to sign in!\n";
		SetConsoleTextAttribute(hConsole, 15);

		if (!curState)
		{
			try
			{
				getLogged(players, admins, curState, curUserInd);
			}
			catch (int)
			{
				break;
			}
			
		}
		if (curState == 1)
		{ 
			runAsAdmin(players, admins, heros, curState, curUserInd, curPlayerInd);
		}
		if (curState == 2)
		{
			addAllPassedPlayersExtraMoney(players, curUserInd, lastLoggedPlayerID);
			runAsPlayer(admins, players, heros, curState, curUserInd,
				curPlayerInd, lastLoggedPlayerID);
		}
	}

	saveNewChanges(players, admins, heros, curPlayerInd, lastLoggedPlayerID);

}

void loadingCurrentProgres(std::ifstream& readFromDB)
{

	// reading current progress from Database!
	size_t curPlayerInd;
	size_t lastLoggedPlayerID = 0;
	MyVector<Player> players;
	MyVector<Administrator> admins;
	MyVector<SuperHero> heros;
	createArraysFromObjects(readFromDB, players, admins, heros,
		curPlayerInd, lastLoggedPlayerID);

	// run game!
	runGame(players, admins, heros, curPlayerInd, lastLoggedPlayerID);
}

void loadingSuperHeroGame()
{
	std::ifstream readFromDB("_DataBase.txt");
	if (!readFromDB.is_open())
		return;

	loadingCurrentProgres(readFromDB);

	readFromDB.close();
}










