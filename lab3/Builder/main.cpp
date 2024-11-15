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
	std::cout << "�������� �����:\n";
	std::cout << fileContent << "\n";

	XMLBuilder builder(fileContent);
	Director director(&builder);
	director.construct();
	Product* xml = builder.getResult();

	std::cout << xml->toString() << "\n";
	std::cout << "XML ��� ������?: " << (xml->checkHash() ? "��" : "���") << "\n";

	return 0;
}

// �������
// ������� Builder.������� ����� ������ � ������� TXT. ������ ������� ��
// ���������(������ ������), ������� �������(������ ������), ������ ������
// ������ � ��� - ���� ������ ������(��������� ������). �������� ����������,
// ����������� �������������� �������� � ������� ��� � ��������
// ������� XML. ���������� ����� ��������� ������������ ��� - ����
// ������.
