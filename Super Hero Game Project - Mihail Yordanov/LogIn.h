#include <iostream>
#include <fstream>
#include "MakeArraysHelperFunvtions.h"
#pragma once
#pragma warning(disable:4996)

// Log In as Admin!
bool isValidAdminUser(const MyString& str, const MyVector<Administrator>& admins,
	size_t& curAdminInd)
{
	for (curAdminInd = 0; curAdminInd < admins.lenght(); curAdminInd++)
		if (admins[curAdminInd]->getUserName() == str)
			return 1;
	curAdminInd = 0;
	return 0;
}
bool isValidAdminPass(const MyString& str, const MyVector<Administrator>& admins,
	size_t& curAdminInd)
{
	return admins[curAdminInd]->getPassword() == str;
}
bool isValidAdmin(const MyString& user, const MyString& pass,
	const MyVector<Administrator>& admins, size_t& curAdminInd)
{
	return (isValidAdminUser(user, admins, curAdminInd)
		&& isValidAdminPass(pass, admins, curAdminInd));
}
void signInAsAdmin(const MyVector<Administrator>& admins,
	size_t& curState, int& curUserInd)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	size_t curInd = 0;
	char user[32];
	char pass[32];
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Enter Username: \n";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(user, 32);
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Enter Password: \n";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(pass, 32);
	if (isValidAdmin(user, pass, admins, curInd))
	{
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << admins[curInd]->getFirstName() << ", ";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout<<"you have successfully logged in as administrator!\n\n";
		SetConsoleTextAttribute(hConsole, 15);
		curState = 1;
		curUserInd = curInd;
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 4);
		std::cout << "Not correct username or password!\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
}


// Log In as Player!
bool isValidPlayerUser(const MyString& str, const MyVector<Player>& players,
	size_t& curPlayerInd)
{
	for (curPlayerInd = 0; curPlayerInd < players.lenght(); curPlayerInd++)
		if (players[curPlayerInd]->getUserName() == str)
			return 1;
	curPlayerInd = 0;
	return 0;
}
bool isValidPlayerPass(const MyString& str, const MyVector<Player>& players,
	size_t& curPlayerInd)
{
	return players[curPlayerInd]->getPassword() == str;
}
bool isValidPlayer(const MyString& user, const MyString& pass,
	const MyVector<Player>& players, size_t& curPlayerInd)
{
	return (isValidPlayerUser(user, players, curPlayerInd)
		&& isValidPlayerPass(pass, players, curPlayerInd));
}
void singInAsPlayer(const MyVector<Player>& players, size_t& curState, int& curUserInd)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	size_t curInd = 0;
	char user[32];
	char pass[32];
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Enter Username: \n";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(user, 32);
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Enter Password: \n";
	SetConsoleTextAttribute(hConsole, 15);
	std::cin.getline(pass, 32);
	if (isValidPlayer(user, pass, players, curInd))
	{
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << players[curInd]->getFirstName() << ", ";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "you have successfully logged in as player!\n\n";
		SetConsoleTextAttribute(hConsole, 15);
		curState = 2;
		curUserInd = curInd;
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 4);
		std::cout << "Not correct username or password!\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
}


// Log In as Admin Or Player!
void logIn(const MyVector<Player>& players,const MyVector<Administrator>& admins,
	size_t& curState, int& curUserInd)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char buff[32];
	std::cin.getline(buff, 32);
	if (!strcmp(buff, "sign in as ad")
		|| !strcmp(buff, "sign in as admin")
		|| !strcmp(buff, "sign in as administrator"))
	{
		signInAsAdmin(admins, curState, curUserInd);
	}
	else if (!strcmp(buff, "sign in as pl")
		|| !strcmp(buff, "sign in as player")
		|| !strcmp(buff, "sign in as gamer"))
	{
		singInAsPlayer(players, curState, curUserInd);
	}
	else if (!strcmp(buff, "stop")
		|| !strcmp(buff, "end")
		|| !strcmp(buff, "endgame"))
	{
		throw 5;
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 4);
		std::cout << "Incorrect Command!\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
}