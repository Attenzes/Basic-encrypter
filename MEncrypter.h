#pragma once

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#define LOOPCHARACTER 127
#define VERSIONNUMBER "1.0.1"
#define DEFAULTKEY 510298374

//Encrypt.cpp
void runEncrypt();
void runDecrypt();

//Functions.cpp
bool validInput();
std::string getFileName(std::string full_filename);
std::string encrypt(std::string input);