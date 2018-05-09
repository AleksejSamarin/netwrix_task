#include "OutputController.h"

void OutputController::outputConsole()
{
	for (auto &logs : getConsoleLogs()) {
		std::cout << logs << std::endl;
	}
}

void OutputController::outputFile(const std::string & oDirectory)
{
	std::ofstream out(oDirectory);
	for (auto &logs : getFileLogs()) {
		out << logs << std::endl;
	}
	out.close();
}

std::vector<std::string> OutputController::getConsoleLogs()
{
	return _logs_console;
}

std::vector<std::string> OutputController::getFileLogs()
{
	return _logs_file;
}

OutputController::OutputController()
{
	setlocale(LC_ALL, "Russian");
}

OutputController::~OutputController() { }

void OutputController::addConsoleLog(const std::string & log)
{
	_logs_console.push_back(log);
}

void OutputController::addFileLogs(const std::vector<std::string>& logs)
{
	_logs_file.insert(_logs_file.end(), logs.begin(), logs.end());
}

void OutputController::outputAll(const std::string & oDirectory)
{
	outputConsole();
	outputFile(oDirectory);
}
