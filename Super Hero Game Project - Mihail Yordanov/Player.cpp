#include "Player.h"
#pragma once

Player::Player()
{
	_id = 0;
	_balance = 0;
}

void Player::setId(size_t id)
{
	_id = id;
}
void Player::setBalance(size_t balance)
{
	_balance = balance;
}
void Player::addToBalace(size_t exrtraMoney)
{
	_balance = _balance + exrtraMoney;
}

size_t Player::getId() const
{
	return _id;
}
size_t Player::getBalance() const
{
	return _balance;
}

void Player::savePlayerInDB(std::ofstream& playerDB) const
{
	playerDB << "\n------------\n";
	playerDB << _firstName << "-";
	playerDB << _lastName << "-";
	playerDB << _email << "-";
	playerDB << _userName << "-";
	playerDB << _password << "-";
	playerDB << _balance << "-";
	playerDB << _id;
}
void Player::printPlayerInformation() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << '\n';
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << " ID: ";
	SetConsoleTextAttribute(hConsole, 9);
	std::cout << _id << '\n';
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << " Name: ";
	SetConsoleTextAttribute(hConsole, 9);
	std::cout << _firstName << " " << _lastName << '\n';
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << " Email: ";
	SetConsoleTextAttribute(hConsole, 9);
	std::cout << _email << '\n';
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << " Username: ";
	SetConsoleTextAttribute(hConsole, 9);
	std::cout << _userName;
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << " Password: ";
	SetConsoleTextAttribute(hConsole, 9);
	std::cout << _password << '\n';
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << " Balance: ";
	SetConsoleTextAttribute(hConsole, 9);
	std::cout << _balance << '\n';
	SetConsoleTextAttribute(hConsole, 15);
}

void Player::buyHero(const MyString& heroName, MyVector<SuperHero>& heros,
	size_t& playedCommandCounter)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool isExisted = false;
	for (int i = 0; i < heros.lenght(); i++)
	{
		if (heros[i]->getHeroName() == heroName)
		{
			isExisted = true;
			if (_balance >= heros[i]->getPrice())
			{
				_balance = _balance - heros[i]->getPrice();
				heros[i]->setState("Deff");
				heros[i]->setPlayerId(_id);
				playedCommandCounter++;
				SetConsoleTextAttribute(hConsole, 10);
				std::cout << "Successfully Purchased!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
				break;
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Not enough money!\n\n";
				SetConsoleTextAttribute(hConsole, 15);
				break;
			}
		}
	}

	if (!isExisted)
	{
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "Hero with name ";
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << heroName;
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << " out of stock\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
}












