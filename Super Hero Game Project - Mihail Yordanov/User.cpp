#include "User.h"


bool isCorrectSymbols_U(const MyString& str)
{
	for (int i = 0; i < str.length(); i++)
		if (str[i] == '-' || str[i] == '\"' || str[i] == '\'')
			return false;
	return true;
}

bool isPassEncapsulated(const MyString& pass)
{
	bool isOneUpper = false;
	bool isOneDown = false;
	bool isOneNumber = false;
	for (int i = 0; i < pass.length(); i++)
	{
		if (pass[i] >= 'A' && pass[i] <= 'Z')
			isOneUpper = true;
		if (pass[i] >= 'a' && pass[i] <= 'z')
			isOneDown = true;
		if (pass[i] >= '0' && pass[i] <= '9')
			isOneNumber = true;
	}
	return (isOneDown && isOneUpper && isOneNumber);
}

User::User()
{
	_firstName = "Unknown";
	_lastName = "Unknown";
	_email = "Unknown";
	_userName = "Unknown";
	_password = "None1234";
}

void User::setFirstName(const MyString& firstName)
{
	if (!isCorrectSymbols_U(firstName))
		throw std::invalid_argument("Not awolled using \'-\',\'\'\',\'\"\'!\n");

	if (firstName.length() < 16)
		_firstName = firstName;
	else
		throw std::length_error("Too long first name!");
}
void User::setLastName(const MyString& lastName)
{
	if (!isCorrectSymbols_U(lastName))
		throw std::invalid_argument("Not awolled using \'-\',\'\'\',\'\"\'!\n");

	if (lastName.length() < 32)
		_lastName = lastName;
	else
		throw std::length_error("Too long last name!");
}
void User::setEmail(const MyString& email)
{
	if (!isCorrectSymbols_U(email))
		throw std::invalid_argument("Not awolled using \'-\',\'\'\',\'\"\'!\n");

	if (email.length() < 32)
		_email = email;
	else
		throw std::length_error("Too long email!");
}
void User::setUserName(const MyString& userName)
{
	if (!isCorrectSymbols_U(userName))
		throw std::invalid_argument("Not awolled using \'-\',\'\'\',\'\"\'!\n");

	if (userName.length() < 16)
		_userName = userName;
	else
		throw std::length_error("Too long nickname!");
}
void User::setPass(const MyString& password)
{
	if (!isCorrectSymbols_U(password))
		throw std::invalid_argument("Not awolled using \'-\',\'\'\',\'\"\'!\n");

	if (password.length() < 16)
		if (isPassEncapsulated(password))
			_password = password;
		else
			throw std::bad_alloc();
	else
		throw std::length_error("Too long password!");
}

const MyString& User::getFirstName() const
{
	return _firstName;
}
const MyString& User::getLastName() const
{
	return _lastName;
}
const MyString& User::getEmail() const
{
	return _email;
}
const MyString& User::getUserName() const
{
	return _userName;
}
const MyString& User::getPassword() const
{
	return _password;
}













