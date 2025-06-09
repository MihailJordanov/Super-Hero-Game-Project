#include <iostream>
#include <fstream>
#include <windows.h>
#include "MyVector.hpp"
#include "MyString.h"
#include "SuperHero.h"
#pragma warning(disable:4996)
#pragma once

class User
{
protected:
	MyString _firstName;
	MyString _lastName;
	MyString _email;
	MyString _userName;
	MyString _password;

	const MyString& getPassword() const;
	void setPass(const MyString& password);

public:
	User();

	void setFirstName(const MyString& firstName);
	void setLastName(const MyString& lastName);
	void setEmail(const MyString& email);
	void setUserName(const MyString& userName);

	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	const MyString& getEmail() const;
	const MyString& getUserName() const;
};















