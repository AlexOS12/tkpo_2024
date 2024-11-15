#include <iostream>
#include <string>
#include <fstream>

#include "Builder.h"

std::string readFile(std::string path) {
	std::string content;

	std::ifstream file(path);
	
	for (std::string line; std::getline(file, line);)
		content += line + "\n";

	file.close();

	return content;
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::string fileContent = readFile("test.txt");
	std::cout << "Оригинал файла:\n";
	std::cout << fileContent << "\n";

	XMLBuilder builder(fileContent);
	Director director(&builder);
	director.construct();
	Product* xml = builder.getResult();

	std::cout << xml->toString() << "\n";
	std::cout << "XML хеш верный?: " << (xml->checkHash() ? "Да" : "Нет") << "\n";

	return 0;
}

// Задание
// Паттерн Builder.Имеется текст статьи в формате TXT. Статья состоит из
// заголовка(первая строка), фамилий авторов(вторая строка), самого текста
// статьи и хеш - кода текста статьи(последняя строка). Написать приложение,
// позволяющее конвертировать документ в формате ТХТ в документ
// формата XML. Необходимо также проверять корректность хеш - кода
// статьи.
