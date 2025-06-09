#pragma once
#include "Administrator.h"
#include "SuperHero.h"
#include "Player.h"

void printAllHerosInShop(const MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	size_t number = 1;
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << " Shop:\n";
	SetConsoleTextAttribute(hConsole, 15);
	for (int i = 0; i < heros.lenght(); i++)
	{
		if (heros[i]->getState() == State::InShop)
		{	
			SetConsoleTextAttribute(hConsole, 3);
			std::cout << " " << number << ". ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << heros[i]->getHeroName();
			SetConsoleTextAttribute(hConsole, 3);
			std::cout << "  " << heros[i]->getFirstName() << " "
				<< heros[i]->getLastName() << "\n ";
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "   Power: ";
			SetConsoleTextAttribute(hConsole, 9);
			std::cout << heros[i]->getPowerStr() << "\n ";
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "   Damage: ";
			SetConsoleTextAttribute(hConsole, 9);
			std::cout << heros[i]->getDamage() << "\n ";
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "   Price: ";
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << heros[i]->getPrice() << "\n\n";
			SetConsoleTextAttribute(hConsole, 15);
			number++;
		}
	}
}

void printAllAdmins(const MyVector<Administrator>& admins)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << " Admins:\n";
	for (int i = 0; i < admins.lenght(); i++)
	{
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << " " << (i + 1) << ". " << admins[i]->getFirstName() << " " <<
			admins[i]->getLastName() << '\n';
		SetConsoleTextAttribute(hConsole, 15);
	}
}

void printAllPlayers(const MyVector<Player>& players)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << " Players:\n";
	for (int i = 0; i < players.lenght(); i++)
	{
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << " " << (i + 1) << ". " << players[i]->getFirstName() << " " <<
			players[i]->getLastName();
		SetConsoleTextAttribute(hConsole, 13);
		std::cout << "  " << players[i]->getUserName();
		SetConsoleTextAttribute(hConsole, 2);
		std::cout << "   ID: " << players[i]->getId() << '\n';
		SetConsoleTextAttribute(hConsole, 15);
	}
}

void showAdminInformation(const MyVector<Administrator>& admins)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	char name[64];
	bool isHasIt = false;
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter Admin FirstName:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(name, 64);
	MyString nameStr(name);

	for (int i = 0; i < admins.lenght(); i++)
	{
		if (admins[i]->getFirstName() == nameStr)
		{
			admins[i]->getAdminInf();
			isHasIt = true;
			break;
		}
	}

	if (!isHasIt)
		throw 0;
}

void printAllSuperHeroOnCurPlayer(const MyVector<SuperHero>& heros, size_t playerId)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int counter = 1;
	for (int i = 0; i < heros.lenght(); i++)
	{
		if (heros[i]->getPlayerId() == playerId)
		{
			SetConsoleTextAttribute(hConsole, 3);	
			std::cout << "   " << counter << ". " << heros[i]->getHeroName();
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "   Power: ";
			SetConsoleTextAttribute(hConsole, 9);
			std::cout << heros[i]->getPowerStr();
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "   Damage: ";
			SetConsoleTextAttribute(hConsole, 9);
			std::cout << heros[i]->getDamage() << '\n';
			SetConsoleTextAttribute(hConsole, 15);
			counter++;
		}
	}
}

void showPlayerInformation(const MyVector<Player>& players, const MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char id[8];
	bool isHasIt = false;
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter player ID:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(id, 8);

	for (int i = 0; i < players.lenght(); i++)
	{
		if (players[i]->getId() == makeNumberFromCharArray(id))
		{
			players[i]->printPlayerInformation();
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << " Super Heros Collection:\n";
			SetConsoleTextAttribute(hConsole, 15);
			printAllSuperHeroOnCurPlayer(heros, makeNumberFromCharArray(id));
			isHasIt = true;
		}
	}

	if (!isHasIt)
		throw 0;
}

void showPlayers(const MyVector<Player>& players, const MyVector<SuperHero>& heros,
	int curUserInd)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	size_t playerIndex = 1;

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << " Players:\n";
	SetConsoleTextAttribute(hConsole, 15);
	for (int i = 0; i < players.lenght(); i++)
	{
		if (i != curUserInd)
		{
			int heroNumber = 1;
			SetConsoleTextAttribute(hConsole, 3);
			std::cout << " " << playerIndex << ". ";
			SetConsoleTextAttribute(hConsole, 13);
			std::cout << players[i]->getUserName() << "  ";
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << players[i]->getBalance() << "$\n";
			SetConsoleTextAttribute(hConsole, 15);
			for (int j = 0; j < heros.lenght(); j++)
			{

				if (heros[j]->getPlayerId() == players[i]->getId())
				{
					SetConsoleTextAttribute(hConsole, 3);
					std::cout << "   " << playerIndex << "." << heroNumber++ << ". ";
					SetConsoleTextAttribute(hConsole, 4);
					std::cout << heros[j]->getHeroName();
					SetConsoleTextAttribute(hConsole, 6);
					std::cout << "  Damage: ";
					SetConsoleTextAttribute(hConsole, 9);
					std::cout << heros[j]->getDamage() << '\n';
					SetConsoleTextAttribute(hConsole, 15);
				}

			}
			playerIndex++;
			std::cout << std::endl;
		}
	}
}

void showSelledHeros(const MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	size_t number = 1;
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << " Selled heros:\n";
	for (int i = 0; i < heros.lenght(); i++)
	{
		if (heros[i]->getState() != State::InShop && heros[i]->getPlayerId() != 0 &&
			heros[i]->getState() != State::deleted)
		{
			SetConsoleTextAttribute(hConsole, 3);
			std::cout << " " << number << ". " << heros[i]->getHeroName();
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "   PlayerId: ";
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << heros[i]->getPlayerId() << '\n';
			SetConsoleTextAttribute(hConsole, 15);
			number++;
		}
	}
}

void showMyHeros(const MyVector<SuperHero>& heros, const Player* curPlayer)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	size_t number = 1;
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "My Collection: \n";
	SetConsoleTextAttribute(hConsole, 15);
	for (int i = 0; i < heros.lenght(); i++)
	{
		if (heros[i]->getPlayerId() == curPlayer->getId())
		{
			SetConsoleTextAttribute(hConsole, 3);
			std::cout << "  " << number << ". ";
			SetConsoleTextAttribute(hConsole, 13);
			std::cout << heros[i]->getHeroName();
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "   State: ";
			SetConsoleTextAttribute(hConsole, 9);
			std::cout << heros[i]->getStateStr();
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "   Power: ";
			SetConsoleTextAttribute(hConsole, 9);
			std::cout << heros[i]->getPowerStr();
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "   Damage: ";
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << heros[i]->getDamage();
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "   Level: ";
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << heros[i]->getLevel() << '\n';
			SetConsoleTextAttribute(hConsole, 15);
			number++;
		}
	}
}

void swaping(MyVector<Player>& players, size_t index)
{
	Player* swapVar = new Player(*players[index]);
	players[index] = players[index + 1];
	players[index + 1] = swapVar;
}

void bubbleSort(MyVector<Player>& players)
{
	for (int i = 0; i < players.lenght() - 1; i++)
	{
		for (int j = 0; j < players.lenght() - 1; j++)
		{
			if (players[j]->getBalance() < players[j + 1]->getBalance())
			{
				swaping(players, j);
			}
		}
	}
}

void showTopPlayers(MyVector<Player>& players)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int number = 1;
	bubbleSort(players);
	for (int i = 0; i < players.lenght() && i < 5; i++)
	{

		SetConsoleTextAttribute(hConsole, 6);
		std::cout << "  " << number << ". " << players[i]->getUserName();
		if (!i)
			SetConsoleTextAttribute(hConsole, 4);
		else
			SetConsoleTextAttribute(hConsole, 2);
		std::cout << "   " << players[i]->getBalance();

		if (!i)
		{
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "  |\\/\\/|";
		}

		std::cout << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		number++;
	}
}

void changeState(MyVector<SuperHero>& heros, int i)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	char buff[16];
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter type:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 16);
	if (!strcmp(buff, "Attack") || !strcmp(buff, "attack"))
	{
		heros[i]->setState(State::Attack);
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "Type change to Attack successfully!\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else if (!strcmp(buff, "Deff") || !strcmp(buff, "deff") ||
		!strcmp(buff, "Deffense") || !strcmp(buff, "deffense"))
	{
		heros[i]->setState(State::Deff);
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "Type change to Deffense successfully!\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else
	{
		throw std::bad_alloc();
	}
}

void changeType(MyVector<SuperHero>& heros,const Player* curPlayer)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	char buff[64];
	bool isHasIt = false;
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter Hero's name for changing:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 64);
	MyString heroName(buff);
	for (int i = 0; i < heros.lenght(); i++)
	{
		if (heroName == heros[i]->getHeroName() &&
			curPlayer->getId() == heros[i]->getPlayerId())
		{
			changeState(heros, i);
			isHasIt = true;
		}
	}

	if (!isHasIt)
		throw 0;
}

void returnThisHeroInShop(SuperHero* hero)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// set Damage
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter Damage:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	char damage[64];
	std::cin.getline(damage, 64);

	// set Price
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter Price:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	char price[64];
	std::cin.getline(price, 64);

	hero->setDamage(makeNumberFromCharArray(damage));
	hero->setPrice(makeNumberFromCharArray(price));
	hero->setPlayerId(0);
	hero->setState(State::InShop);
	hero->setLevel(1);

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "Successfully Back ";
	SetConsoleTextAttribute(hConsole, 13);
	std::cout << hero->getHeroName();
	SetConsoleTextAttribute(hConsole, 10);
	std::cout << " In Shop!\n\n";
	SetConsoleTextAttribute(hConsole, 15);
}

void returnDeletedHeroByName(const char* buff, MyVector<SuperHero>& heros)
{
	MyString heroName(buff);
	bool isHasIt = false;
	for (int i = 0; i < heros.lenght(); i++)
	{
		if (heros[i]->getHeroName() == heroName && heros[i]->getState() == State::deleted)
		{
			returnThisHeroInShop(heros[i]);
			isHasIt = true;
			break;
		}
	}

	if (!isHasIt)
		throw 0;
}

void printAllDeletedHeros(const MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "  Deleted Heros:\n";
	SetConsoleTextAttribute(hConsole, 15);

	int number = 1;
	for (int i = 0; i < heros.lenght(); i++)
	{
		if (heros[i]->getState() == State::deleted)
		{
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << number << ". ";
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << heros[i]->getHeroName();
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << "   Damage: ";
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << heros[i]->getDamage();
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << "   Power: ";
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << heros[i]->getPowerStr() << "\n";
			SetConsoleTextAttribute(hConsole, 15);
			number++;
		}
	}
	std::cout << std::endl;
}

void returnDeletedHero(MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	printAllDeletedHeros(heros);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Entert Hero's name to return in shop\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	char buff[64];
	std::cin.getline(buff, 64);

	returnDeletedHeroByName(buff, heros);

}

