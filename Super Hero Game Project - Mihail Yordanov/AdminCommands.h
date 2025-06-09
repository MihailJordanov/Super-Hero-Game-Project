#pragma once
#include "MakeArraysHelperFunvtions.h"
#include "SaveArrayInDataBase.h"
#include "addAndRemoveFromArrays.h"
#include "PrintObjectsInformation.h"


void addNewPlayer_Command(const char* buff, MyVector<Player>& players, size_t& curPlayerInd)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!strcmp(buff, "add new player") || !strcmp(buff, "add new pl") ||
		!strcmp(buff, "add player") || !strcmp(buff, "add pl"))
	{
		try
		{
			addNewPlayer(players, curPlayerInd);
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "Player created successfully!\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (std::bad_alloc)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Not Correct Password!\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (std::length_error)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Too long syntax!\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (int)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Already existing username\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (std::invalid_argument)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Not awolled using \'-\',\'\'\',\'\"\'!\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}

void deletePlayer_Command(const char* buff, MyVector<Player>& players,
	MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!strcmp(buff, "delete player") || !strcmp(buff, "delete pl") ||
		!strcmp(buff, "remove player") || !strcmp(buff, "remove pl"))
	{
		try
		{
			deletePlayer(players, heros);
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "Player deleted successfully!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (int)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Not Existing player!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}

void showPlayerInfo_Commnad(const char* buff, const MyVector<Player>& players,
	const MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!strcmp(buff, "show player") || !strcmp(buff, "show pl") ||
		!strcmp(buff, "show player information") || !strcmp(buff, "show pl inf"))
	{
		try
		{
			showPlayerInformation(players, heros);
			std::cout << '\n';
		}
		catch (int)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Not Existing player!\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}

void addNewAdmin_Commnad(const char* buff, MyVector<Administrator>& admins)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!strcmp(buff, "add new admin") || !strcmp(buff, "add new ad") ||
		!strcmp(buff, "add admin") || !strcmp(buff, "add ad"))
	{
		try
		{
			addNewAdmin(admins);
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "Administrator created successfully!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (std::bad_alloc())
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Not Correct Password!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (std::length_error())
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Too long syntax!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (int)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Already existing username\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (std::invalid_argument)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Not awolled using \'-\',\'\'\',\'\"\'!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}

void showAdminInfo_Command(const char* buff, const MyVector<Administrator>& admins)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!strcmp(buff, "show admin") || !strcmp(buff, "show ad") ||
		!strcmp(buff, "show admin information") || !strcmp(buff, "show ad inf"))
	{
		try
		{
			showAdminInformation(admins);
			std::cout << '\n';
		}
		catch (int)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Not Existing admin!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}

void showAllPlayers_Command(const char* buff, const MyVector<Player>& players)
{
	if (!strcmp(buff, "show all players") || !strcmp(buff, "show all pl") ||
		!strcmp(buff, "print all players") || !strcmp(buff, "print all pl"))
	{
		printAllPlayers(players);
		std::cout << '\n';
	}
}

void addSuperHeroToShop_Command(const char* buff, MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!strcmp(buff, "add hero to shop") || !strcmp(buff, "add in shop") ||
		!strcmp(buff, "add hero to store") || !strcmp(buff, "add in store"))
	{
		try
		{
			addHeroToShop(heros);
			std::cout << '\n';
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "Hero added in shop successfully!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (std::length_error)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Too long syntax!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (int)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Already existing hero with that name!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (std::invalid_argument)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Not awolled using \'-\',\'\'\',\'\"\'!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (std::out_of_range)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Hero name can't be empty!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch(std::bad_cast)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Not correct Power Type!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		catch (std::bad_exception)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "You have to use only digits!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}

}

void showAllAdmins_Command(const char* buff, const MyVector<Administrator>& admins)
{
	if (!strcmp(buff, "show all admins") || !strcmp(buff, "show all ad") ||
		!strcmp(buff, "print all admins") || !strcmp(buff, "print all ad"))
	{
		printAllAdmins(admins);
		std::cout << '\n';
	}
}

void showAllSelledHeros_Command(const char* buff, const MyVector<SuperHero>& heros)
{
	if (!strcmp(buff, "show selled heros") || !strcmp(buff, "show selled") ||
		!strcmp(buff, "selled heros") || !strcmp(buff, "selled"))
	{
		showSelledHeros(heros);
		std::cout << std::endl;
	}
}

void backDeletedHeroInShop_Command(const char* buff, MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!strcmp(buff, "back in shop") || !strcmp(buff, "back hero") ||
		!strcmp(buff, "back deleted hero") || !strcmp(buff, "select deleted hero") ||
		!strcmp(buff, "get deleted hero") || !strcmp(buff, "return hero"))
	{
		try
		{
			returnDeletedHero(heros);
		}
		catch (int)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Hero not Found!\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}
