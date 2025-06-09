#pragma once
#include "MakeArraysHelperFunvtions.h"


bool isCurPlayerHasCurHero(const MyVector<SuperHero>& heros,
	const Player* curPlayer, const char* buff, size_t& heroInd)
{
	MyString heroName(buff);
	for (int i = 0; i < heros.lenght(); i++)
	{
		if (heroName == heros[i]->getHeroName() &&
			heros[i]->getPlayerId() == curPlayer->getId())
		{
			heroInd = i;
			return true;
		}
	}
	return false;
}

// Fire > Earth
// Earth > Water
// Water > Fire
// Fire > Air
// Water > Air
// Air > Earth
void strongerPower(Power heroOnePower, Power heroTwoPower, size_t& strongestHero)
{
	if (heroOnePower == heroTwoPower)
		strongestHero = 0;
	else if (heroOnePower == Power::Fire &&
		(heroTwoPower == Power::Earth || heroTwoPower == Power::Air))
		strongestHero = 1;
	else if (heroOnePower == Power::Water &&
		(heroTwoPower == Power::Air || heroTwoPower == Power::Fire))
		strongestHero = 1;
	else if (heroOnePower == Power::Air && heroTwoPower == Power::Earth)
		strongestHero = 1;
	else if (heroOnePower == Power::Earth && heroTwoPower == Power::Water)
		strongestHero = 1;
	else
		strongestHero = 2;

}

void whichPowerIsStronger(const SuperHero* curHero,
	const SuperHero* enemyHero, size_t& strongestHero)
{
	if (curHero->getPower() == Power::Cosmic && enemyHero->getPower() == Power::Cosmic)
		strongestHero = 0;
	else if (curHero->getPower() == Power::Cosmic)
		strongestHero = 1;
	else if (enemyHero->getPower() == Power::Cosmic)
		strongestHero = 2;
	else
	{
		strongerPower(curHero->getPower(), enemyHero->getPower(), strongestHero);
	}

}

void fightIfCurHeroStronger(Player* curPlayer, Player* enemyPlayer,
	const SuperHero* curHero, SuperHero* enemyHero)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	size_t extramoney = (curHero->getDamage() - enemyHero->getDamage());
	if (enemyHero->getState() == State::Deff) // enemy lose hero but not money
	{
		enemyHero->setState(State::deleted);
		enemyHero->setPlayerId(0);
		curPlayer->setBalance(curPlayer->getBalance() + extramoney);
	}
	else // enemy lose hero and money
	{
		enemyHero->setState(State::deleted);
		enemyHero->setPlayerId(0);
		curPlayer->setBalance(curPlayer->getBalance() + extramoney);

		if (enemyPlayer->getBalance() < (curHero->getDamage() - enemyHero->getDamage()))
		{
			enemyPlayer->setBalance(0);
		}
		else
		{

			enemyPlayer->setBalance(enemyPlayer->getBalance() -
				(curHero->getDamage() - enemyHero->getDamage()));
		}
	}

	// message
	std::cout << '\n';
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << curHero->getPowerStr() << " ";
	SetConsoleTextAttribute(hConsole, 1);
	std::cout << curHero->getHeroName() << " ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << curHero->getDamage();
	SetConsoleTextAttribute(hConsole, 7);
	std::cout << " > ";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << enemyHero->getPowerStr() << " ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << enemyHero->getHeroName() << " ";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << enemyHero->getDamage() << '\n';
	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "Your Hero won!\nYou defeted enemy hero and won ";
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << extramoney << "$\n\n";
	SetConsoleTextAttribute(hConsole, 15);
}

void fightIfEnemyHeroStronger(Player* curPlayer, Player* enemyPlayer,
	SuperHero* curHero, const SuperHero* enemyHero)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	size_t lostMoney = (enemyHero->getDamage() - curHero->getDamage());
	if (enemyHero->getState() == State::Deff) // lose hero and money, enemy dont get money
	{
		curHero->setState(State::deleted);
		curHero->setPlayerId(0);
		curPlayer->setBalance(curPlayer->getBalance() - lostMoney);
	}
	else  // lose hero and money, enemy get money
	{
		curHero->setState(State::deleted);
		curHero->setPlayerId(0);
		curPlayer->setBalance(curPlayer->getBalance() - lostMoney);
		enemyPlayer->setBalance(enemyPlayer->getBalance() +
			(curHero->getDamage() - enemyHero->getDamage()));
	}

	// message
	std::cout << '\n';
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << curHero->getPowerStr() << " ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << curHero->getHeroName() << " ";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << curHero->getDamage();
	SetConsoleTextAttribute(hConsole, 7);
	std::cout << " < ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << enemyHero->getPowerStr() << " ";
	SetConsoleTextAttribute(hConsole, 1);
	std::cout << enemyHero->getHeroName() << " ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << enemyHero->getDamage() << '\n';
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "Enemy Hero won!\nYou lose your hero and ";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << lostMoney << "$\n\n";
	SetConsoleTextAttribute(hConsole, 15);
}

void fightIfEqual(Player* curPlayer, const Player* enemyPlayer,
	const SuperHero* curHero, const SuperHero* enemyHero)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (int(curPlayer->getBalance()) < 500)
		curPlayer->setBalance(0);
	else
		curPlayer->setBalance(curPlayer->getBalance() - 500);



	// message
	std::cout << '\n';
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << curHero->getPowerStr() << " ";
	SetConsoleTextAttribute(hConsole, 1);
	std::cout << curHero->getHeroName() << " ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << curHero->getDamage();
	SetConsoleTextAttribute(hConsole, 7);
	std::cout << " = ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << enemyHero->getPowerStr() << " ";
	SetConsoleTextAttribute(hConsole, 1);
	std::cout << enemyHero->getHeroName() << " ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << enemyHero->getDamage() << '\n';
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "Equal battle!\nYou just lose";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << " 500$";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout<<"!\n\n";
	SetConsoleTextAttribute(hConsole, 15);
}

void fight(Player* curPlayer, Player* enemyPlayer, SuperHero* curHero, SuperHero* enemyHero)
{
	if (curHero->getDamage() > enemyHero->getDamage())
	{
		fightIfCurHeroStronger(curPlayer, enemyPlayer, curHero, enemyHero);
	}
	else if (enemyHero->getDamage() > curHero->getDamage())
	{
		fightIfEnemyHeroStronger(curPlayer, enemyPlayer, curHero, enemyHero);
	}
	else
	{
		fightIfEqual(curPlayer, enemyPlayer, curHero, enemyHero);
	}
}

void fightTwoHeros(Player* curPlayer, Player* enemyPlayer, SuperHero* curHero,
	SuperHero* enemyHero, size_t& strongestHero)
{
	if (strongestHero == 1)
	{
		curHero->setDamage(2 * curHero->getDamage());
		fight(curPlayer, enemyPlayer, curHero, enemyHero);
		curHero->setDamage(curHero->getDamage() / 2);

	}
	else if (strongestHero == 2)
	{
		enemyHero->setDamage(2 * enemyHero->getDamage());
		fight(curPlayer, enemyPlayer, curHero, enemyHero);
		enemyHero->setDamage(enemyHero->getDamage() / 2);
	}
	else
	{
		fight(curPlayer, enemyPlayer, curHero, enemyHero);
	}
}

void battle(Player* curPlayer, Player* enemyPlayer,
	SuperHero* curHero, SuperHero* enemyHero)
{
	size_t whichHeroIsStronger = 0; // 0 - equal, 1 - curHero, 2 - enemyHero
	whichPowerIsStronger(curHero, enemyHero, whichHeroIsStronger);
	fightTwoHeros(curPlayer, enemyPlayer, curHero, enemyHero, whichHeroIsStronger);
}

void attackWhenEnemyHasHeros(MyVector<SuperHero>& heros, Player* curPlayer,
	Player* enemyPlayer, SuperHero* curHero)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter the superhero you want to attack:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	char buff[64];
	std::cin.getline(buff, 64);
	size_t attackedHeroInd = 0;
	if (!isCurPlayerHasCurHero(heros, enemyPlayer, buff, attackedHeroInd))
		throw '0';

	battle(curPlayer, enemyPlayer, curHero, heros[attackedHeroInd]);

}

void attackWhenEnemyHasNoHeros(Player* curPlayer, Player* enemyPlayer,
	const SuperHero* curHero)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (int(enemyPlayer->getBalance()) - int(curHero->getDamage()) < 0)
	{
		curPlayer->setBalance(curPlayer->getBalance() +
			(curHero->getDamage() - enemyPlayer->getBalance()));
		enemyPlayer->setBalance(0);
	}
	else
	{
		curPlayer->setBalance(curPlayer->getBalance() + curHero->getDamage());
		enemyPlayer->setBalance(enemyPlayer->getBalance() - curHero->getDamage());
	}

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "Player ";
	SetConsoleTextAttribute(hConsole, 13);
	std::cout << enemyPlayer->getUserName();
	SetConsoleTextAttribute(hConsole, 10);
	std::cout << " successfully attacked!\n\n";
	SetConsoleTextAttribute(hConsole, 15);
}

void startTheAttack(MyVector<SuperHero>& heros, MyVector<Player>& players,
	Player* curPlayer, Player* attackedPlayer)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	char buff[64];
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter the superhero you want to attack with:\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 64);

	size_t attackedHeroInd = 0;
	if (!isCurPlayerHasCurHero(heros, curPlayer, buff, attackedHeroInd))
		throw '0';

	if (!(heros[attackedHeroInd]->getState() == State::Attack))
		throw 0.0;

	if (!howManyHerosHasPlayer(attackedPlayer, heros))
		attackWhenEnemyHasNoHeros(curPlayer, attackedPlayer, heros[attackedHeroInd]);
	else
		attackWhenEnemyHasHeros(heros, curPlayer, attackedPlayer, heros[attackedHeroInd]);

}

void runAttackToPlayer(const char* buff, MyVector<Player>& players,
	MyVector<SuperHero>& heros, Player* curPlayer)
{
	bool isHasIt = false;
	MyString attackedPlayerName(buff);
	Player* attackedPlayer = new Player();
	for (int i = 0; i < players.lenght(); i++)
	{
		if (attackedPlayerName == players[i]->getUserName() &&
			attackedPlayerName != curPlayer->getUserName())
		{
			attackedPlayer = players[i];
			isHasIt = true;
			break;
		}
	}

	if (!isHasIt)
		throw std::bad_alloc();

	startTheAttack(heros, players, curPlayer, attackedPlayer);
}

void attackPlayer(MyVector<Player>& players,
	MyVector<SuperHero>& heros, Player* curPlayer)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!howManyHerosHasPlayer(curPlayer, heros))
		throw 0;

	char buff[64];
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  >Enter wanted Player's Username to attack!\n  ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(buff, 64);

	runAttackToPlayer(buff, players, heros, curPlayer);

}
