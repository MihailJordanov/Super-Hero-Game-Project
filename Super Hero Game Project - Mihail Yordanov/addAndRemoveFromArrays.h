#include "Administrator.h"
#include "MyVector.hpp"
#include "Player.h"
#pragma once


bool isPowerLegit(const MyString& power)
{
	return (power == "Earth" || power == "Fire" || power == "Air" ||
		power == "Water" || power == "Cosmic");
}

bool isTextNumberLegit(const MyString& number)
{
	for (int i = 0; i < number.length(); i++)
		if (number[i] > '9' || number[i] < '0')
			return false;
	
	return true;
}

bool itHasThatUserName(const MyVector<Player>& players, const Player player)
{
	for (int i = 0; i < players.lenght(); i++)
	{
		if (players[i]->getUserName() == player.getUserName())
		{
			return true;
		}
	}
	return false;
}

bool itHasThatUserName(const MyVector<Administrator>& admins, const Administrator admin)
{
	for (int i = 0; i < admins.lenght(); i++)
	{
		if (admins[i]->getUserName() == admin.getUserName())
		{
			return true;
		}
	}
	return false;
}

bool itHasThatUserName(const MyVector<SuperHero>& heros, const SuperHero hero)
{
	for (int i = 0; i < heros.lenght(); i++)
	{
		if (heros[i]->getHeroName() == hero.getHeroName())
		{
			return true;
		}
	}
	return false;
}

void removeHerosFromDeletedPlayer(MyVector<SuperHero>& heros, size_t id)
{
	for (int i = 0; i < heros.lenght(); i++)
	{
		if (heros[i]->getPlayerId() == id)
		{
			heros[i]->setState(State::deleted);
		}
	}
}

void removePlayer(MyVector<Player>& players, size_t id)
{
	bool isHasIt = false;
	for (int i = 0; i < players.lenght(); i++)
	{
		if (players[i]->getId() == id)
		{
			players.remove(i);
			isHasIt = true;
			break;
		}
	}
	if (!isHasIt)
		throw 0;
}

void addNewPlayer(MyVector<Player>& players, size_t& curPlayerInd)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char buff[1024];
	Player player;

	// set first name
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter FirstName:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	player.setFirstName(buff);

	// set last name
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter LastName:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	player.setLastName(buff);

	// set email
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter Email:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	player.setEmail(buff);

	// set username
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter UserName:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	player.setUserName(buff);

	if (itHasThatUserName(players, player))
		throw 0;

	// set password
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter Password:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	player.setPass(buff);

	// set balance
	player.setBalance(1000);

	// set ID
	player.setId(curPlayerInd++);


	// add player
	players.add(player);
}

void deletePlayer(MyVector<Player>& players, MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char id[16];
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter ID for deleted player:\n";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(id, 16);
	removePlayer(players, makeNumberFromCharArray(id));
	removeHerosFromDeletedPlayer(heros, makeNumberFromCharArray(id));
}

void addNewAdmin(MyVector<Administrator>& admins)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char buff[1024];
	Administrator admin;

	// set first name
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter FirstName:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	admin.setFirstName(buff);

	// set last name
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter LastName:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	admin.setLastName(buff);

	// set email
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter Email:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	admin.setEmail(buff);

	// set username
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter UserName:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	admin.setUserName(buff);

	if (itHasThatUserName(admins, admin))
		throw 0;

	// set password
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter Password:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	admin.setPass(buff);

	// add admin
	admins.add(admin);
}

void addHeroToShop(MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	char buff[1024];
	SuperHero hero;

	// set first name
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter Hero's firstName:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	hero.setFirstName(buff);

	// set last name
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter Hero's lastName:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	hero.setLastName(buff);


	// set hero name
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter SuperHero name:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	hero.setHeroName(buff);

	if (itHasThatUserName(heros, hero))
		throw 0;

	// set hero power
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter power:  (Earth / Fire / Air / Water / Cosmic)\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	if (!isPowerLegit(buff))
		throw std::bad_cast();
	hero.setPower(buff);

	// set hero damage
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter damage:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	if (!isTextNumberLegit(buff))
		throw std::bad_exception();
	hero.setDamage(makeNumberFromCharArray(buff));

	// set hero price
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter price:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 1024);
	if (!isTextNumberLegit(buff))
		throw std::bad_exception();
	hero.setPrice(makeNumberFromCharArray(buff));

	hero.setPlayerId(0);
	hero.setState(State::InShop);

	// add in heros list
	heros.add(hero);
}

void buySuperHero(MyVector<SuperHero>& heros, Player* curPlayer,
	size_t& playedCommandCounter)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter Superhero name from the market you wish to buy:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	char buff[1024];
	std::cin.getline(buff, 1024);

	curPlayer->buyHero(buff, heros, playedCommandCounter);
}

void addThreeHerosInShop(MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "\nFirst hero:\n";
	SetConsoleTextAttribute(hConsole, 15);
	addHeroToShop(heros);
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "\nSecond hero:\n";
	SetConsoleTextAttribute(hConsole, 15);
	addHeroToShop(heros);
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "\nThird hero:\n";
	SetConsoleTextAttribute(hConsole, 15);
	addHeroToShop(heros);
}

void fillShop(MyVector<SuperHero>& heros)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "There is no heros in the store!\n";
	std::cout << "You have to add 3 new heros in the shop!\n\n";
	SetConsoleTextAttribute(hConsole, 15);
	try
	{
		addThreeHerosInShop(heros);
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "successfully added 3 heros!\n\n";
		SetConsoleTextAttribute(hConsole, 15);

	}
	catch (std::length_error)
	{
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "Too long syntax!\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	catch (std::out_of_range)
	{
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "Hero name can't be empty!\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	catch (std::bad_cast)
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

void isShopEmpty(MyVector<SuperHero>& heros)
{
	if (howManyHerosHaveInShop(heros) == 0)
		fillShop(heros);
}

void addAllPassedPlayersMoney(MyVector<Player>& players, int curUserInd,
	int lastLoggedPlayerInd)
{
	size_t passedExtraMoney = 1000;

	if (lastLoggedPlayerInd < curUserInd)
	{
		for (int i = lastLoggedPlayerInd + 1; i < curUserInd; i++)
		{
			//std::cout << players[i]->getUserName() << "  +1000\n";
			players[i]->addToBalace(passedExtraMoney);
		}
	}
	else
	{
		for (int i = lastLoggedPlayerInd + 1; i < players.lenght(); i++)
		{
			//std::cout << players[i]->getUserName() << "  +1000\n";
			players[i]->addToBalace(passedExtraMoney);
		}

		for (int i = 0; i < curUserInd; i++)
		{
			//std::cout << players[i]->getUserName() << "  +1000\n";
			players[i]->addToBalace(passedExtraMoney);
		}
	}
}

void addAllPassedPlayersExtraMoney(MyVector<Player>& players, int curUserInd,
	size_t lastLoggedPlayerID)
{
	int lastLoggedPlayerInd = -1;
	for (int i = 0; i < players.lenght(); i++)
	{
		if (players[i]->getId() == lastLoggedPlayerID)
		{
			lastLoggedPlayerInd = i;
			break;
		}
	}

	if (lastLoggedPlayerInd != -1)
		addAllPassedPlayersMoney(players, curUserInd, lastLoggedPlayerInd);
}

void updateHeroIfHaveEnoughtMoney(SuperHero* hero, Player* curPlayer)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hero->getLevel() >= 5)
		throw false;


	int updatePrice = (hero->getLevel() * hero->getLevel()) * 10 *
		(hero->getPrice() / 100);
	int updateDamage = (hero->getDamage() +
		2 * hero->getLevel() * 5 * (((hero->getDamage() / 100) + 1)));

	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "\n Cost: ";
	SetConsoleTextAttribute(hConsole, 10);
	std::cout << updatePrice;
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "  New Damage: ";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << hero->getDamage();
	std::cout << " -> ";
	std::cout << updateDamage;
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "  Level: ";
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << hero->getLevel() << " -> " <<
		hero->getLevel() + 1 << '\n';

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << " Do you want to update:\n ";
	SetConsoleTextAttribute(hConsole, 15);
	char buff[16];
	std::cin.getline(buff, 16);


	if (strcmp(buff, "yes") && strcmp(buff, "Yes"))
		throw 0.0;

	if (int(curPlayer->getBalance() - updatePrice) < 0)
		throw '0';


	hero->setDamage(updateDamage);
	hero->setLevel(hero->getLevel() + 1);
	curPlayer->setBalance(curPlayer->getBalance() - updatePrice);
}

void updateHero(MyVector<SuperHero>& heros, Player* curPlayer)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (howManyHerosHasPlayer(curPlayer, heros) == 0)
		throw std::bad_alloc();

	char buff[64];
	bool isHasIt = false;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "\n >Enter the superhero you want to update:\n ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 64);
	MyString heroName(buff);

	for (int i = 0; i < heros.lenght(); i++)
	{
		if (heroName == heros[i]->getHeroName() &&
			curPlayer->getId() == heros[i]->getPlayerId())
		{
			updateHeroIfHaveEnoughtMoney(heros[i], curPlayer);
			isHasIt = true;
		}
	}

	if (!isHasIt)
		throw 0;

}

