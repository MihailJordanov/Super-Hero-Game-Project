#include "Administrator.h"
#include "Player.h"
#pragma once

void savePlayersInDataBase(std::ofstream& writeToDB, const MyVector<Player>& players,
	size_t curPlayerId, size_t lastLoggedPlayerID)
{
	writeToDB << "Players:\n";
	writeToDB << curPlayerId << '\n';
	writeToDB << lastLoggedPlayerID;
	for (int i = 0; i < players.lenght(); i++)
		players[i]->savePlayerInDB(writeToDB);
}

void saveAdminsInDataBase(std::ofstream& writeTo, const MyVector<Administrator>& admins)
{
	writeTo << "\n\nAdmins:";
	for (int i = 0; i < admins.lenght(); i++)
		admins[i]->saveAdminInDB(writeTo);
}

void saveSuperHerosInDataBase(std::ofstream& writeTo, const MyVector<SuperHero>& heros)
{
	writeTo << "\n\nSuper Heros:";
	for (int i = 0; i < heros.lenght(); i++)
		heros[i]->saveHeroInDB(writeTo);
}

void saveNewChangesInDataBase(std::ofstream& writeToDB, const MyVector<Player>& players,
	const MyVector<Administrator>& admins, const MyVector<SuperHero>& heros,
	size_t& curPlayerId, size_t lastLoggedPlayerID)
{
	savePlayersInDataBase(writeToDB, players, curPlayerId, lastLoggedPlayerID);
	saveAdminsInDataBase(writeToDB, admins);
	saveSuperHerosInDataBase(writeToDB, heros);
}


void saveNewChanges(const MyVector<Player>& players,
	const MyVector<Administrator>& admins, const MyVector<SuperHero>& heros,
	size_t& curPlayerId, size_t lastLoggedPlayerID)
{
	std::ofstream writeToDB("_DataBase.txt");
	if (!writeToDB.is_open())
		return;

	writeToDB.seekp(0);
	saveNewChangesInDataBase(writeToDB, players, admins, heros, curPlayerId,
		lastLoggedPlayerID);

	writeToDB.close();
}