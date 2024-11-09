#include <string>

#pragma once
// ������� ����� ��� �������� �������
class PrintEdition {
protected:
	// ���������� �������
	std::string content;

public:
	std::string name; // ��������
	int year;	      // ��� �������

	PrintEdition() {
		// �������� ������������ ��� ��������
		this->content = "NoContent";
		this->name = "NoName";
		this->year = 0;
	}; 

	PrintEdition(std::string name, int year, std::string content) {
		this->name = name;
		this->year = year;
		this->content = content;
	}
	
	// ������� ��� ��������� ����������� ��������� �������
	std::string read() {
		return this->content;
	}

	// ������� ��� ������ ���������� � �������� �������
	// ��� �������-�������� ���������������� ���
	// ������������ �� ���������
	virtual void printInfo() {
		std::cout << "���:      " << typeid(*this).name() << "\n";
		std::cout << "��������: " << this->name << "\n";
		std::cout << "���:      " << this->year << "\n";
	}
};

class Magazine : public PrintEdition {
public:
	// �������� �������
	std::string publisher = "NoPublisher";
	// ����� �������
	int number = 0;

	Magazine(std::string name, int year, std::string content, std::string publisher, int number) {
		this->name = name;
		this->year = year;
		this->content = content;
		this->publisher = publisher;
		this->number = number;
	}


	virtual void printInfo() {
		std::cout << "���:      " << typeid(*this).name() << "\n";
		std::cout << "��������: " << this->name << "\n";
		std::cout << "���:      " << this->year << "\n";
		std::cout << "��������: " << this->publisher << "\n";
		std::cout << "�����:    " << this->number << "\n";
	}
};

class Book : public PrintEdition {
public:
	std::string author = "NoAuthor";           // ����� �����
	std::string bindingType = "NoBindingType"; // ��� ��������� (��������: �������, ������)

	Book() {};

	Book(std::string name, int year, std::string content, std::string author, std::string bindingType) {
		this->name = name;
		this->year = year;
		this->content = content;
		this->author = author;
		this->bindingType = bindingType;
	}

	virtual void printInfo() {
		std::cout << "���:      " << typeid(*this).name() << "\n";
		std::cout << "��������: " << this->name << "\n";
		std::cout << "���:      " << this->year << "\n";
		std::cout << "�����:    " << this->author << "\n";
		std::cout << "��������: " << this->bindingType << "\n";
	}
};

class TextBook : public Book {
public:
	int grade;			// �����, �� ������� ��������� �������
	std::string depth;  // ������� �������� (��������: �������, �����������)

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
		std::cout << "���:      " << typeid(*this).name() << "\n";
		std::cout << "��������: " << this->name << "\n";
		std::cout << "���:      " << this->year << "\n";
		std::cout << "�����:    " << this->author << "\n";
		std::cout << "��������: " << this->bindingType << "\n";
		std::cout << "�����:    " << this->grade << "\n";
		std::cout << "�������:  " << this->depth << "\n";
	}
};