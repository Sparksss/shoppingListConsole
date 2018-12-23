#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

int main(int argsc, char *argsv)
{

	std::string str;
	std::getline(std::cin, str);


	std::cout << "enter (w) to write a file, or enter (r) for read a file" << std::endl;
	char action;

	std::cin >> action;

	if (action == 'r') {
		std::ifstream rFile;
		rFile.open("lystbyings.txt", std::fstream::in | std::fstream::out | std::fstream::app);

		//check for error

		std::string contains;

		if (rFile.fail()) {
			std::cerr << "error opening file" << std::endl;
			exit(1);
		}

		std::cout << "list of buyings" << std::endl;

		while (!rFile.eof()) {

			contains = "";

			std::getline(rFile, contains);

			std::cout << contains << std::endl;
		}

	}
	else if (action == 'w') {

		std::ofstream wfile;


		wfile.open("lystbyings.txt", std::fstream::in | std::fstream::out | std::fstream::app);

		str += '\n';

		std::cout << str;

		wfile << str;

		wfile.close();
	}


	return 0;
}
