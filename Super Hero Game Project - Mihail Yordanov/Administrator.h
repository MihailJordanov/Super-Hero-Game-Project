#include "User.h"
#include "SuperHero.h"
#pragma once

class Administrator : public User
{
public:

	Administrator();
	Administrator(const MyString& firstName, const MyString& lastName, 
		const MyString& email, const MyString& userName, 
		const MyString& password);

	void getAdminInf() const;
	void saveAdminInDB(std::ofstream& adminDB) const;

	friend bool isValidAdminPass(const MyString& str, const MyVector<Administrator>& admins,
		size_t& curAdminInd);
	friend void makeAdmin(const char* buff, MyVector<Administrator>& admins);
	friend void addNewAdmin(MyVector<Administrator>& admins);
};







