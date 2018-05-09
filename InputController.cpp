#include "InputController.h"

bool InputController::checkArguments(const int & c, OutputController * oc)
{
	if (getWordsCount() == c) {
		return true;
	} else {
		std::string tempLog = "Неверное количество составляющих аргумента.";
		oc->addConsoleLog(tempLog);
		return false;
	}
}

std::string InputController::findAttribute(char ** args, const int & count, const std::string & key)
{
	for (int i = 0; i < count; i++) {
		if (static_cast<std::string>(args[i]) == key) {
			if (i + 1 < count) {
				return static_cast<std::string>(args[i + 1]);
			}
		}
	}
	return std::string();
}

void InputController::setDirectoryWork(const std::string & directory)
{
	_directory_work = directory;
}

void InputController::setMask(const std::string & mask)
{
	_mask = mask;
}

void InputController::setDirectoryInput(const std::string & directory)
{
	_directory_input = directory;
}

void InputController::setDirectoryOutput(const std::string & directory)
{
	_directory_output = directory;
}

std::string InputController::getDirectoryWork()
{
	return _directory_work;
}

std::string InputController::getMask()
{
	return _mask;
}

std::string InputController::getDirectoryInput()
{
	return _directory_input;
}

std::string InputController::getDirectoryOutput()
{
	return _directory_output;
}

int InputController::getWordsCount()
{
	return _words_count;
}

InputController::InputController(const int & count, char ** args, OutputController * oc)
{
	if (checkArguments(count, oc)) {
		setDirectoryWork(findAttribute(args, count, "-p"));
		setMask(findAttribute(args, count, "-m"));
		setDirectoryInput(findAttribute(args, count, "-i"));
		setDirectoryOutput(findAttribute(args, count, "-o"));

		std::string tempLog = "Поиск в директории: " + getDirectoryWork();
		oc->addConsoleLog(tempLog);
	}
}

InputController::~InputController() { }
