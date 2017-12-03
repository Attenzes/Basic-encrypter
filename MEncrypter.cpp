/*
Basic encryption program utilising bitwise operators and rand(), with the encryption key put into srand()
UPDATED AS OF 28/11/2017
Version 1.0.1
*/

#include "MEncrypter.h"

int main()
{
	for (char user_input = LOOPCHARACTER; user_input != 'e';)
	{
		std::cout << "Welcome to the Main Menu if the Basic Encryption program by Mac. Version " << VERSIONNUMBER << std::endl;
		std::cout << "1)Encrypt\n" << "2)Decrypt\n" << "e)Exit" << std::endl;

		std::cin >> user_input;
		if (!validInput()) user_input = LOOPCHARACTER; //Checks if input is valid
		else
		{
			switch (user_input)
			{
			case '1':
				runEncrypt();
				std::cout << std::endl;
				break;
			case '2':
				runDecrypt();
				std::cout << std::endl;
				break;
			case 'e':
				break;
			default: //Valid but unknown input
				std::cout << "Unknown option, please try again\n" << std::endl;
			}
		}
	}//End of main loop

	return 0;
}