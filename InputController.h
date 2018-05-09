#pragma once

#include <iostream>
#include <string>
#include "OutputController.h"

/*****************************************************
* InputController:
* Класс, отвечающий за обработку и хранение аргументов
* командной строки при запуске приложения.
*****************************************************/

class InputController
{
private:
	std::string _directory_work;
	std::string _mask;
	std::string _directory_input;
	std::string _directory_output;
	const int _words_count = 9;
protected:
	bool checkArguments(const int & c, OutputController * oc);
	std::string findAttribute(char** args, const int & count, const std::string & key);
	void setDirectoryWork(const std::string & directory);
	void setMask(const std::string & mask);
	void setDirectoryInput(const std::string & directory);
	void setDirectoryOutput(const std::string & directory);
	int getWordsCount();
public:
	InputController(const int &count, char** args, OutputController * oc);
	~InputController();
	std::string getDirectoryWork();
	std::string getMask();
	std::string getDirectoryInput();
	std::string getDirectoryOutput();
};
