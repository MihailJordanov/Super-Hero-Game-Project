#include <iostream>
#include <windows.h>
#pragma warning(disable:4996)
#pragma once


void printGameCommands()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 6);
	std::cout << "Commands:\n";

	// sign in as administrator
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "sign in as ad";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - log in as Administrator" << std::endl;

	// sign in as player
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "sign in as pl";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - log in as Player" << std::endl;

	// stop game
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "end";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - stop the game and saving changes" << std::endl;

	// add player in game
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "add new player";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - add player in game" << std::endl;

	// add player in game
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "delete player";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - delete player account" << std::endl;

	// delete player in game
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "show player information";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - show some player information" << std::endl;

	// add new admin
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "add new admin";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - create new Administrator" << std::endl;

	// show admin inf
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "show admin information";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - show some Administrator information" << std::endl;

	// show all pl inf
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "show all players";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - show all players information" << std::endl;


	// show all admins inf
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "show all admins";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - show all administrators information" << std::endl;

	// add in shop
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "add hero to store";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - create and add hero in store" << std::endl;

	// show shop
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "show shop";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - show all heros in shop" << std::endl;

	// show selled
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "show selled heros";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - show all selled heros" << std::endl;

	// back hero
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "back in shop";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - get deleted hero and back it in shop" << std::endl;

	// log out
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "log out";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - log out" << std::endl;

	// show balance
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "show balance";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - visit your balance" << std::endl;


	// show shop
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "show shop";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - show all heros in shop" << std::endl;

	// buy hero
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "buy hero";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - buying hero from shop" << std::endl;

	// buy hero
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "show players";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - show other players information" << std::endl;

	// show other players
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "show players";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - show other players information" << std::endl;

	// show my heros
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "show my heros";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - show your collection" << std::endl;

	// change type
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "change type";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - changing your hero type" << std::endl;

	// show top players
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "show top players";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - visit top 5 players" << std::endl;

	// attack player
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "attack player";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - attacking other player" << std::endl;

	// update hero
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "update hero";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - updating your heros" << std::endl;

	// log out
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Write: ";
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << "log out";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - log out" << std::endl;

	SetConsoleTextAttribute(hConsole, 34);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - when you'r not logged" << std::endl;

	SetConsoleTextAttribute(hConsole, 68);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - when you'r logged as Administrator" << std::endl;

	SetConsoleTextAttribute(hConsole, 51);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - when you'r logged as Player" << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
}


void heading_Super()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "===================================================";
	std::cout << "====================================================================\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "                _____         \n";
	std::cout << "               / ___ \\       " << std::endl;
	std::cout << "              / /  /_/        " << std::endl;
	std::cout << "              | |      __  __     ____      ___    ______      \n";
	std::cout << "               \\ \\    | |  | |   |  _ \\    / _ \\   |  __/  " << std::endl;
	std::cout << "           __   | |   | |  | |   | |_| |  | |_| |  | |         " << std::endl;
	std::cout << "          / /__/ /    \\ \\__/ /   |   _/   |  __/   | |       ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                      .=.,\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "          \\_____/      \\____/    |  |      \\___/   |_|      ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                      ;c =\\\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "                                 |__|                          ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                 __|  _/\n";

}

void heading_Hero()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "             ___     ___                                     ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                 .'-'-._/-'-._\n";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "            |  |    |  |                                     ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                /..   ____    \\\n";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "            |  |    |  |                                     ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "               /' _  [<_->] )  \\\n";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "            |  |____|  |    ___   ______   ___               ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "              (  / \\--\\_>/-/'._ )\n";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "            |   ____   |   / _ \\  |  __/  / _ \\            ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                 \\-;_/\\__;__/ _/ _/\n";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "            |  |    |  |  | |_| | | |    | / \\ |            ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                 '._}|==o==\\{_\\/\n";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "            |  |    |  |  |  __/  | |    | \\_/ |            ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                  /  /-._.--\\  \\_\n";
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "            |__|    |__|   \\___/  |_|     \\___/            ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                  // /   /|   \\ \\ \\\n";
	std::cout << "                                                           ";
	std::cout << "                 / | |   | \\;  |  \\ \\\n";
}

void heading_Game()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "       _______                                          ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                   / /  | :/   \\: \\   \\_\\\n";
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "      /  __   \\                                        ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                   /  |  /.'|   /: |    \\ \\\n";
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "     /  /  \\___\\                                         ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                 |  |  |--| . |--|     \\_\\\n";
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "     |  | _____    ____        __  ____  ____      ___     ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "               / _/   \\ | : | /___--._) \\\n";
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "     |  | |__  |  /__  \\      |  |/    \\/    \\    / _ \\ ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                 |_(---'-| >-'-| |       '-'\n";
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "     |  |   |  |  /  _  \\     |   __    __   |   | |_| |     ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "                   /_/     \\_\\\n";
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "     \\  \\___/  /  | |_|  \\_   |  /  |  /  |  |   |  __/  " << std::endl;
	std::cout << "      \\_______/    \\___/|__/  |__|  |__|  |__|    \\___/ \n" << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "===================================================";
	std::cout << "====================================================================\n";
}

