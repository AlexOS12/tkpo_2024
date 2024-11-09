#include <iostream>
#include <string>

#include "PrintEditions.h"

// ������� ��� ������ ������� � ����� ������ ���������� � ���
void read(PrintEdition* printEdition) {
	printEdition->printInfo();
	std::cout << "\n����������:\n";
	std::cout << printEdition->read() << "\n\n";
}

int main() {
	setlocale(LC_ALL, "Russian");

	PrintEdition printEdition(std::string("�������� �������"), 2015, std::string("���������� ��������� �������"));
	Magazine magazine(std::string("������"), 2016, std::string("���������� �������"), std::string("�������� �������"), 123);
	Book book(std::string("�����"), 2017, std::string("���������� �����"), std::string("����� �����"), std::string("������� ��������"));
	TextBook textbook(std::string("�������"), 2018, std::string("���������� ��������"), std::string("����� ��������"),
					  std::string("������� ��������"), 10, std::string("������� �������"));

	read(&printEdition);
	read(&magazine);
	read(&book);
	read(&textbook);

	return 0;
}