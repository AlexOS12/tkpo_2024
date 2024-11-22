#include <iostream>
#include "FactoryMethod.h"

int main() {
	setlocale(LC_ALL, "Russian");

	Tetris tetris;
	Figure figure;

	for (int i = 0; i < 5; i++) {
		figure = tetris.generateFigure();
		figure.display();
	}
	
	std::cout << "\n";

	tetris.displayStatistics();

	return 0;
}

// Задание:
// Паттерн Factory Method. Фигуры игры «тетрис».Реализовать процесс
// случайного выбора фигуры из конечного набора фигур. Предусмотреть
// появление супер - фигур с большим числом клеток, чем обычные.