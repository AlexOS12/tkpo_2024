#include <iostream>
#include "Factory.h"

int main() {
	setlocale(LC_ALL, "Russian");

	RuMovieFactory ruMovieFactory;
	EnMovieFactory enMovieFactory;
	DeMovieFactory deMovieFactory;

	BaseMovie* movie;

	// Создаем и проигрываем фильм на русском
	movie = ruMovieFactory.createMovie();
	movie->play();
	std::cout << "\n\n";

	// Создаем и проигрываем фильм на английском
	movie = enMovieFactory.createMovie();
	movie->play();
	std::cout << "\n\n";

	// Создаем и проигрываем фильм на немецком
	movie = deMovieFactory.createMovie();
	movie->play();

	return 0;
}

// Задание
// Паттерн Abstract Factory.Разработать систему Кинопрокат.Пользователь
// может выбрать определённую киноленту, при заказе киноленты
// указывается язык звуковой дорожки, который совпадает с языком файла
// субтитров.Система должна поставлять фильм с требуемыми
// характеристиками, причём при смене языка звуковой дорожки должен
// меняться и язык файла субтитров и наоборот