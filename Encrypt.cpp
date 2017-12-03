#include "MEncrypter.h"

void runEncrypt()
{
	for (char user_input = LOOPCHARACTER;;)
	{

		std::cout << "\nEnter the full name of the file you want to encrypt and the key (0 for default key), separated by space\n"
			<< "Include the extension. E.g. filename.txt 0 (Enter 127 to go back)  (Does not support names with spaces)" << std::endl;
		std::string full_filename; //With extension
		std::cin >> full_filename;
		if (full_filename == "127") return; //User goes back to main menu
		unsigned int key;
		std::cin >> key;

		if (!validInput()) user_input = LOOPCHARACTER;
		else
		{
			if (key == 0) key = DEFAULTKEY;	//Default key was requested
			std::ifstream inputFile;
			inputFile.open(full_filename, std::ios::in);

			if (!inputFile.is_open())
			{
				std::cout << "Entered file or its encrypted file cannot be created, please try again\n" << std::endl;
			}
			else
			{
				std::string filename = getFileName(full_filename); //Remove the extension
				std::ofstream outputFile;
				outputFile.open((filename + ".enc"), std::ios::out | std::ios::trunc);

				srand(key);	//Enter seed for encryption
				std::string to_encrypt;
				while (!inputFile.eof())
				{
					std::getline(inputFile, to_encrypt);
					outputFile << encrypt(to_encrypt) << std::endl;
				}
				inputFile.close();
				outputFile.close();
				std::cout << "\nSuccessfully encrypted!" << std::endl;
			}
		}
	}
}

void runDecrypt()
{
	for (char user_input = LOOPCHARACTER;;)
	{
		std::cout << "\nEnter the full name of the file you want to decrypt and the key (0 for default key), separated by space\n"
			<< "Include the extension. E.g. filename.enc 0 (Enter 127 to go back)  (Does not support names with spaces)" << std::endl;
		std::string full_filename; //With extension
		std::cin >> full_filename;
		if (full_filename == "127") return; //User goes back to main menu
		unsigned int key;
		std::cin >> key;

		if (!validInput()) user_input = LOOPCHARACTER;
		else
		{
			if (key == 0) key = DEFAULTKEY;	//Default key was requested
			std::ifstream inputFile;
			inputFile.open(full_filename, std::ios::in);

			if (!inputFile.is_open())
			{
				std::cout << "Entered file or its encrypted file cannot be created, please try again\n" << std::endl;
			}
			else
			{
				std::string filename = getFileName(full_filename); //Remove the extension
				std::ofstream outputFile;
				outputFile.open((filename + ".txt"), std::ios::out | std::ios::trunc);

				srand(key);	//Enter seed for encryption
				std::string to_encrypt;
				while (!inputFile.eof())
				{
					std::getline(inputFile, to_encrypt);
					outputFile << encrypt(to_encrypt) << std::endl;
				}
				inputFile.close();
				outputFile.close();
				std::cout << "\nSuccessfully decrypted!" << std::endl;
			}
		}
	}
}