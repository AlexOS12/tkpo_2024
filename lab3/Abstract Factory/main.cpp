#include <iostream>
#include "Factory.h"

int main() {
	setlocale(LC_ALL, "Russian");

	RuMovieFactory ruMovieFactory;
	EnMovieFactory enMovieFactory;
	DeMovieFactory deMovieFactory;

	BaseMovie* movie;

	// ������� � ����������� ����� �� �������
	movie = ruMovieFactory.createMovie();
	movie->play();
	std::cout << "\n\n";

	// ������� � ����������� ����� �� ����������
	movie = enMovieFactory.createMovie();
	movie->play();
	std::cout << "\n\n";

	// ������� � ����������� ����� �� ��������
	movie = deMovieFactory.createMovie();
	movie->play();

	return 0;
}

// �������
// ������� Abstract Factory.����������� ������� ����������.������������
// ����� ������� ����������� ���������, ��� ������ ���������
// ����������� ���� �������� �������, ������� ��������� � ������ �����
// ���������.������� ������ ���������� ����� � ����������
// ����������������, ������ ��� ����� ����� �������� ������� ������
// �������� � ���� ����� ��������� � ��������