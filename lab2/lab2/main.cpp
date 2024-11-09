#include <iostream>
#include <string>

#include "PrintEditions.h"

// Фукнция для чтения изданий а также вывода информации о них
void read(PrintEdition* printEdition) {
	printEdition->printInfo();
	std::cout << "\nСодержимое:\n";
	std::cout << printEdition->read() << "\n\n";
}

int main() {
	setlocale(LC_ALL, "Russian");

	PrintEdition printEdition(std::string("Печатное издание"), 2015, std::string("Содержимое печатного издания"));
	Magazine magazine(std::string("Журнал"), 2016, std::string("Содержимое журнала"), std::string("Издатель журнала"), 123);
	Book book(std::string("Книга"), 2017, std::string("Содержимое книги"), std::string("Автор книги"), std::string("Жесткий переплет"));
	TextBook textbook(std::string("Учебник"), 2018, std::string("Содержимое учебника"), std::string("Автор учебника"),
					  std::string("Жесткий переплет"), 10, std::string("Базовый уровень"));

	read(&printEdition);
	read(&magazine);
	read(&book);
	read(&textbook);

	return 0;
}