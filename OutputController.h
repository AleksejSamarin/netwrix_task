#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>

/*****************************************************
* OutputController:
* Класс, отвечающий за вывод нужной информации. Вывод
* может быть в консоль, а также в файл, путь к которому
* следует указать аргументом при вызове соответсвующего 
* метода.
*****************************************************/

class OutputController
{
private:
	std::vector<std::string> _logs_console;
	std::vector<std::string> _logs_file;
protected:
	void outputConsole();
	void outputFile(const std::string & oDirectory);
	std::vector<std::string> getConsoleLogs();
	std::vector<std::string> getFileLogs();
public:
	OutputController();
	~OutputController();
	void addConsoleLog(const std::string & log);
	void addFileLogs(const std::vector<std::string> & logs);
	void outputAll(const std::string & oDirectory);
};

