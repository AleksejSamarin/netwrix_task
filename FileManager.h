#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <future>
#include <vector>
#include <experimental/filesystem>
#include "OutputController.h"

/*****************************************************
* FileManager:
* Класс, который предназначен для работы с файлами. После
* того, как нужная для поиска строка прочитана, можно
* начинать искать ее в файлах указанной аргументом
* директории, а также ее поддиректориях всех уровней глубины
* с учетом маски. В данном приложении маска - это паттерн 
* регулярного выражения стандартной C++ библиотеки std::regex.
* Процедура отбора новых файлов разделяется по разным
* потокам для увеличения эффективности программы, каждый
* из которых ведет поиск в одном конкретном файле.
*****************************************************/

class FileManager
{
private:
	std::string _target_string;
	std::vector<std::string> _target_files;
protected:
	void setTargetString(const std::string & targetString);
	void addTargetFile(const std::string & targetFile);
	std::string getTargetString();
	std::string threadFindTargetString(const std::string & directory);
	std::vector<std::string> getTargetFiles();
	bool matchMask(const std::string & file, const std::string & mask);
public:
	FileManager(const std::string & iDirectory);
	~FileManager();
	std::string readTargetString(const std::string & directory);
	void findTargetString(const std::string & wDirectory, const std::string & mask, OutputController * oc);
};