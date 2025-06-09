#include <iostream>
#include <fstream>
#include "Power.h"
#include "State.h"
#include "MyString.h"
#pragma warning(disable:4996)
#pragma once

class SuperHero
{
	MyString _firstName;
	MyString _lastName;
	MyString _heroName;
	size_t _damage;
	size_t _price;
	Power _power;
	State _state;
	size_t _playerId;
	size_t _level;

public:

	SuperHero();
	SuperHero(const MyString& firstName, const MyString& lastName,
		const MyString& heroName, size_t damage, size_t price,
		size_t playerId, const MyString& power, const MyString& state);

	void setFirstName(const MyString& firstName);
	void setLastName(const MyString& lastName);
	void setHeroName(const MyString& heroName);
	void setDamage(size_t damage);
	void setPrice(size_t price);
	void setPlayerId(size_t playerId);
	void setLevel(size_t level);
	void setPower(const MyString& power);
	void setState(const MyString& state);
	void setPower(const Power& power);
	void setState(const State& state);


	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	const MyString& getHeroName() const;
	size_t getDamage() const;
	size_t getPrice() const;
	size_t getPlayerId() const;
	size_t getLevel() const;
	const Power& getPower() const;
	const State& getState() const;
	const char* getPowerStr() const;
	const char* getStateStr() const;
	const char* getHeroNameStr() const;

	void saveHeroInDB(std::ofstream& superHeroDB) const;

};














