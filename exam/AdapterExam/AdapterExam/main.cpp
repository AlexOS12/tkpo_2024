#include <iostream>
#include <string>

#include "Adapter.h"

// Выполнил студент группы 221-3210 Обухов Алексей

/* Задание:
*	Паттерн «Адаптер». Приложение «Запись в файл». 
*   Клиент – умеет писать в файл только посимвольно. 
*   Сервис – реализует только блочный способ записи в файл. 
*   Написать адаптер, который обеспечит взаимодействие между 
*   клиентом и сервисом. Тип файла – любой.
*/


void ClientCode(std::string path, std::string text) {
	std::cout << "Writing to " << path << "\n";

	Adapter* writer = new Adapter();
	writer->Open(path);

	for (int i = 0; i < text.size(); i++) {
		writer->WriteCharToFile(text[i]);
	}
	
	writer->Close();

	std::cout << "Successfuly wrote to " << path;

	delete writer;
}

int main() {

	ClientCode("text.txt", "Some Random Text");

	return 0;
}