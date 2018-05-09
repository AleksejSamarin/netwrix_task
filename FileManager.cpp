#include "FileManager.h"

std::string FileManager::readTargetString(const std::string & directory)
{
	std::string tempString;
	std::ifstream file(directory);
	getline(file, tempString);
	file.close();
	return tempString;
}

void FileManager::findTargetString(const std::string & wDirectory, const std::string & mask, OutputController * oc)
{
	std::vector<std::future<std::string>> currentFutures;
	for (auto & p : std::experimental::filesystem::v1::recursive_directory_iterator(wDirectory)) {
		std::string fullDirectory = p.path().string();
		std::string currentFile = p.path().filename().string();
		if (matchMask(currentFile, mask)) {
			currentFutures.push_back(std::async(&FileManager::threadFindTargetString, this, fullDirectory));
		}
	}
	for (auto &f : currentFutures) {
		std::string searchResult = static_cast<std::string>(f.get());
		if (searchResult != std::string()) {
			addTargetFile(searchResult);
		}
	}
	oc->addFileLogs(getTargetFiles());
}

void FileManager::setTargetString(const std::string & targetString)
{
	_target_string = targetString;
}

void FileManager::addTargetFile(const std::string & targetFile)
{
	_target_files.push_back(targetFile);
}

std::string FileManager::getTargetString()
{
	return _target_string;
}

std::string FileManager::threadFindTargetString(const std::string & directory)
{
	std::string tempString;
	std::ifstream file(directory);
	while (getline(file, tempString)) {
		size_t pos = tempString.find(getTargetString());
		if (pos != std::string::npos) {
			file.close();
			return directory;
		}
	}
	file.close();
	return std::string();
}

std::vector<std::string> FileManager::getTargetFiles()
{
	return _target_files;
}

bool FileManager::matchMask(const std::string & file, const std::string & mask)
{
	std::regex rgx(mask);
	if (std::regex_match(file, rgx)) {
		return true;
	} else {
		return false;
	}
}

FileManager::FileManager(const std::string & iDirectory)
{
	setTargetString(readTargetString(iDirectory));
}

FileManager::~FileManager() { }
