#include "Administrator.h"
#include "SuperHero.h"
#include "Player.h"
#pragma once

size_t powTen(int br)
{
	int ten = 1;
	for (int i = 1; i < br; i++)
		ten *= 10;
	return ten;
}
size_t makeNumberFromCharArray(const char* str)
{
	size_t num = 0;
	for (int i = 0; i < strlen(str); i++)
		num = num + (str[i] - '0') * powTen(strlen(str) - i);	
	return num;
}

size_t howManyUserReadFromFile(std::ifstream& readFromUserDB)
{
	char buff[1024];
	size_t counter = 0;
	while (!readFromUserDB.eof())
	{
		readFromUserDB.getline(buff, 1024);
		if (!strcmp(buff, "------------"))
			counter++;
	}
	readFromUserDB.clear();
	readFromUserDB.seekg(0, std::ios::beg);
	return counter;
}
void splitStrings(char* str, const char* buff, int& buffInd)
{
	size_t index = 0;
	while (buff[buffInd] != '-' && buff[buffInd] != '\0')
		str[index++] = buff[buffInd++];
	str[index] = '\0';
	buffInd++;
}

size_t howManyHerosHaveInShop(const MyVector<SuperHero>& heros)
{
	size_t counter = 0;
	for (int i = 0; i < heros.lenght(); i++)
		if (heros[i]->getState() == State::InShop)
			counter++;

	return counter;
}

//make Admins
void makeAdmin(const char* buff, MyVector<Administrator>& admins)
{
	Administrator admin;
	char str[64];
	int buffInd = 0;
	splitStrings(str, buff, buffInd);  //set firstName
	admin.setFirstName(str);

	splitStrings(str, buff, buffInd);  //set lastName
	admin.setLastName(str);

	splitStrings(str, buff, buffInd);  //set email
	admin.setEmail(str);

	splitStrings(str, buff, buffInd);  //set userName
	admin.setUserName(str);

	splitStrings(str, buff, buffInd);  //set password
	admin.setPass(str);

	admins.add(admin);
}

//make Players
void makePlayer(const char* buff, MyVector<Player>& players)
{
	Player pl;
	char str[64];
	int buffInd = 0;
	splitStrings(str, buff, buffInd);  //set firstName
	pl.setFirstName(str);

	splitStrings(str, buff, buffInd);  //set lastName
	pl.setLastName(str);

	splitStrings(str, buff, buffInd);  //set email
	pl.setEmail(str);

	splitStrings(str, buff, buffInd);  //set userName
	pl.setUserName(str);

	splitStrings(str, buff, buffInd);  //set password
	pl.setPass(str);

	splitStrings(str, buff, buffInd);  //set Balance
	pl.setBalance(makeNumberFromCharArray(str));

	splitStrings(str, buff, buffInd);  //set Id
	pl.setId(makeNumberFromCharArray(str)); 

	players.add(pl);
}

//make SuperHeros
void makeHero(const char* buff, MyVector<SuperHero>& heros)
{
	SuperHero hero;
	char str[64];
	int buffInd = 0;
	splitStrings(str, buff, buffInd);  //set firstName
	hero.setFirstName(str);

	splitStrings(str, buff, buffInd);  //set lastName
	hero.setLastName(str);

	splitStrings(str, buff, buffInd);  //set Hero name
	hero.setHeroName(str);

	splitStrings(str, buff, buffInd);  //set damage
	hero.setDamage(makeNumberFromCharArray(str));

	splitStrings(str, buff, buffInd);  //set price
	hero.setPrice(makeNumberFromCharArray(str));

	splitStrings(str, buff, buffInd);  //set Power
	hero.setPower(str);

	splitStrings(str, buff, buffInd);  //set State
	hero.setState(str);

	splitStrings(str, buff, buffInd);
	hero.setLevel(makeNumberFromCharArray(str)); //set level

	splitStrings(str, buff, buffInd);
	hero.setPlayerId(makeNumberFromCharArray(str)); //set playerId

	heros.add(hero);
}

void makingPlayerCounter(std::ifstream& readFrom,
	size_t& playerCounter, char* buff)
{
	while (strcmp(buff, "Admins:"))
	{
		readFrom.getline(buff, 1024);
		if (!strcmp(buff, "------------"))
			playerCounter++;
	}
}
void makingAdminCounter(std::ifstream& readFrom,
	size_t& adminCounter, char* buff)
{
	while (strcmp(buff, "Super Heros:"))
	{
		readFrom.getline(buff, 1024);
		if (!strcmp(buff, "------------"))
			adminCounter++;
	}
}
void makingHeroCounter(std::ifstream& readFrom,
	size_t& herosCounter, char* buff)
{
	while (!readFrom.eof())
	{
		readFrom.getline(buff, 1024);
		if (!strcmp(buff, "------------"))
			herosCounter++;
	}
}

void howManyObjectsExist(std::ifstream& readFrom, size_t& playerCounter,
	                          size_t& adminCounter, size_t& herosCounter)
{
	char buff[1024] = "";
	makingPlayerCounter(readFrom, playerCounter, buff);
	makingAdminCounter(readFrom, adminCounter, buff);
	makingHeroCounter(readFrom, herosCounter, buff);
	readFrom.clear();
	readFrom.seekg(0, std::ios::beg);
}

void createPlayers(std::ifstream& readFrom,
	MyVector<Player>& players, char* buff)
{
	readFrom.getline(buff, 1024);
	while (strcmp(buff, "Admins:"))
	{
		readFrom.getline(buff, 1024);
		if (strcmp(buff, "------------") && strcmp(buff, "") && strcmp(buff, "Admins:"))
			makePlayer(buff, players);
	}
}
void createAdmin(std::ifstream& readFrom,
	MyVector<Administrator>& admins, char* buff)
{
	while (strcmp(buff, "Super Heros:"))
	{
		readFrom.getline(buff, 1024);
		if (strcmp(buff, "------------") && strcmp(buff, "") && strcmp(buff, "Super Heros:"))
			makeAdmin(buff, admins);
	}
}
void createHeros(std::ifstream& readFrom,
	MyVector<SuperHero>& heros, char* buff)
{
	while (!readFrom.eof())
	{
		readFrom.getline(buff, 1024);
		if (strcmp(buff, "------------") && strcmp(buff, ""))
			makeHero(buff, heros);
	}
}

void createArraysFromObjects(std::ifstream& readFrom, MyVector<Player>& players,
	MyVector<Administrator>& admins, MyVector<SuperHero>& heros, size_t& curPlayerIndex,
	size_t& lastLoggedPlayerID)
{
	char buff[1024] = "";
	while (strcmp(buff, "Players:"))
		readFrom.getline(buff, 1024);
	readFrom >> curPlayerIndex;
	readFrom >> lastLoggedPlayerID;
	//create Players
	createPlayers(readFrom, players, buff);

	//create Admins
	createAdmin(readFrom, admins, buff);

	//create Heros
	createHeros(readFrom, heros, buff);
}

size_t howManyHerosHasPlayer(const Player* player, const MyVector<SuperHero>& heros)
{
	size_t counter = 0;
	for (int i = 0; i < heros.lenght(); i++)
		if (heros[i]->getPlayerId() == player->getId())
			counter++;
	return counter;
}
