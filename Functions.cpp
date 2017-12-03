#include "MEncrypter.h"

bool validInput()
{
	if (!std::cin || !(std::cin.peek() == '\n'))
	{
		std::cout << "Invalid input, please try again\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		return false;
	}
	return true;
}

std::string getFileName(std::string full_filename)
{
	std::string filename;
	size_t dot_pos = full_filename.find('.');
	filename = full_filename.substr(0, dot_pos);
	return filename;
}

std::string encrypt(std::string to_encrypt) {
	std::string encrypted{ "" };
	for (char i : to_encrypt) {
		if (int(i) < 32);	//Do nothing if it is a control character
		else {
			i ^= (rand() % 32);
		}
		encrypted += i;
	}
	return encrypted;
}

