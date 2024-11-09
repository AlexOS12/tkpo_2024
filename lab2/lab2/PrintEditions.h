#include <string>

#pragma once
// Базовый класс для печатных изданий
class PrintEdition {
protected:
	// Содержимое издания
	std::string content;

public:
	std::string name; // Название
	int year;	      // Год выпуска

	PrintEdition() {
		// Значения используются как заглушки
		this->content = "NoContent";
		this->name = "NoName";
		this->year = 0;
	}; 

	PrintEdition(std::string name, int year, std::string content) {
		this->name = name;
		this->year = year;
		this->content = content;
	}
	
	// Функция для получения содержимого печатного издания
	std::string read() {
		return this->content;
	}

	// Функция для вывода информации о печатном издании
	// Для классов-потомков переопределяется для
	// соответствия их атрибутам
	virtual void printInfo() {
		std::cout << "Тип:      " << typeid(*this).name() << "\n";
		std::cout << "Название: " << this->name << "\n";
		std::cout << "Год:      " << this->year << "\n";
	}
};

class Magazine : public PrintEdition {
public:
	// Издатель журнала
	std::string publisher = "NoPublisher";
	// Номер журнала
	int number = 0;

	Magazine(std::string name, int year, std::string content, std::string publisher, int number) {
		this->name = name;
		this->year = year;
		this->content = content;
		this->publisher = publisher;
		this->number = number;
	}


	virtual void printInfo() {
		std::cout << "Тип:      " << typeid(*this).name() << "\n";
		std::cout << "Название: " << this->name << "\n";
		std::cout << "Год:      " << this->year << "\n";
		std::cout << "Издатель: " << this->publisher << "\n";
		std::cout << "Номер:    " << this->number << "\n";
	}
};

class Book : public PrintEdition {
public:
	std::string author = "NoAuthor";           // Автор книги
	std::string bindingType = "NoBindingType"; // Тип переплета (например: жесткий, мягкий)

	Book() {};

	Book(std::string name, int year, std::string content, std::string author, std::string bindingType) {
		this->name = name;
		this->year = year;
		this->content = content;
		this->author = author;
		this->bindingType = bindingType;
	}

	virtual void printInfo() {
		std::cout << "Тип:      " << typeid(*this).name() << "\n";
		std::cout << "Название: " << this->name << "\n";
		std::cout << "Год:      " << this->year << "\n";
		std::cout << "Автор:    " << this->author << "\n";
		std::cout << "Переплет: " << this->bindingType << "\n";
	}
};

class TextBook : public Book {
public:
	int grade;			// Класс, на который рассчитан учебник
	std::string depth;  // Уровень учебника (например: базовый, углубленный)

	TextBook(std::string name, int year, std::string content, std::string author, std::string bindingType, int grade, std::string depth) {
		this->name = name;
		this->year = year;
		this->content = content;
		this->author = author;
		this->bindingType = bindingType;
		this->grade = grade;
		this->depth = depth;
	}

	virtual void printInfo() {
		std::cout << "Тип:      " << typeid(*this).name() << "\n";
		std::cout << "Название: " << this->name << "\n";
		std::cout << "Год:      " << this->year << "\n";
		std::cout << "Автор:    " << this->author << "\n";
		std::cout << "Переплет: " << this->bindingType << "\n";
		std::cout << "Класс:    " << this->grade << "\n";
		std::cout << "Уровень:  " << this->depth << "\n";
	}
};