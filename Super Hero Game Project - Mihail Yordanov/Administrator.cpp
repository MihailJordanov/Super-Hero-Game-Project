#include "Administrator.h"

Administrator::Administrator() {}
Administrator::Administrator(const MyString& firstName, const MyString& lastName,
	const MyString& email, const MyString& userName,
	const MyString& password)
{
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setUserName(userName);
	setPass(password);
}

void Administrator::getAdminInf() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 6);
	std::cout << " Name: ";
	SetConsoleTextAttribute(hConsole, 9);
	std::cout << _firstName << " " << _lastName << '\n';
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << " Email: ";
	SetConsoleTextAttribute(hConsole, 9);
	std::cout << _email << '\n';
	SetConsoleTextAttribute(hConsole, 15);
}

void Administrator::saveAdminInDB(std::ofstream& adminDB) const
{
	adminDB << "\n------------\n";
	adminDB << _firstName << "-";
	adminDB << _lastName << "-";
	adminDB << _email << "-";
	adminDB << _userName << "-";
	adminDB << _password;
}








