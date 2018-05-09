#include "InputController.h"
#include "FileManager.h"
#include "OutputController.h"

/*****************************************************
* main:
* Глобальная функция, которая является точкой входа в
* программу. Здесь создаются обьекты контроллеров
* входных и выходных данных, файлового менеджера. После
* этого вызываются методы для поиска нужной строки в
* файлах, вывода директорий, где она была найдена в
* качестве подстроки.
*****************************************************/

int main(int argc, char **argv)
{
	auto outputController = new OutputController();
	auto inputController = new InputController(argc, argv, outputController);
	auto fileManager = new FileManager(inputController->getDirectoryInput());

	fileManager->findTargetString(inputController->getDirectoryWork(), inputController->getMask(), outputController);
	outputController->outputAll(inputController->getDirectoryOutput());

	system("pause");
	return 0;
}