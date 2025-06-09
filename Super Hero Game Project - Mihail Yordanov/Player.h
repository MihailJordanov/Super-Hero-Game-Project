#include "User.h"
#pragma once

class Player : public User
{
	size_t _id;
	size_t _balance;

public:
	Player();

	void setId(size_t id);
	void setBalance(size_t balance);
	void addToBalace(size_t exrtraMoney);

	size_t getId() const;
	size_t getBalance() const;

	void savePlayerInDB(std::ofstream& playerDB) const;
	void printPlayerInformation() const;

	void buyHero(const MyString& heroName, MyVector<SuperHero>& heros,
		size_t& playedCommandCounter);

	friend void makePlayer(const char* buff, MyVector<Player>& players);
	friend bool isValidPlayerPass(const MyString& str, const MyVector<Player>& players,
		size_t& curPlayerInd);
	friend void addNewPlayer(MyVector<Player>& players, size_t& curPlayerInd);
};
















