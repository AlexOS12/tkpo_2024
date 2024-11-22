#pragma once

#include <iostream>
#include <string>


// Базовый класс фигуры
class Figure {
	friend class Tetris;
protected:
	std::string type;
	std::string look;
	int width = 0, height = 0;

public:
	Figure() {};
	void display() {
		std::cout << this->type << " : " << this->look << " (" << this->height << ", " << this->width << ")\n";
	}
};

//Класс фигуры "палка"
class Line : public Figure {
	friend class Tetris;
	Line() {
		this->width = 1;
		this->height = 4;
		this->look = "|";
		this->type = "line";
	}
};

// Класс фигуры "квадрат 2 на 2"
class Square : public Figure {
	friend class Tetris;
	Square() {
		this->width = 2;
		this->height = 2;
		this->look = "[]";
		this->type = "square";
	}
};

// Класс Т-образной фигуры
class TFigure : public Figure {
	friend class Tetris;
	TFigure() {
		this->width = 3;
		this->height = 2;
		this->look = "т";
		this->type = "t_figure";
	}
};


// Класс большой фигуры 
class SuperFigure : public Figure {
	friend class Tetris;
	SuperFigure() {
		this->width = 5;
		this->height = 5;
		this->look = "-|||-";
		this->type = "super";
	}
};

// Класс игры тетрис
class Tetris {
private:
	unsigned int generatedFigures = 0;
	unsigned int generatedSuperFigures = 0;


public:
	Tetris() {
		srand(time(NULL));
	}

	// Функция генерации фигур
	Figure generateFigure() {
		int random = rand() % 4;
		
		this->generatedFigures++;

		switch (random)
		{
		case 0:
			return Line();
			break;
		case 1:
			return Square();
			break;
		case 2:
			return TFigure();
			break;
		case 3:
			this->generatedSuperFigures++;
			return SuperFigure();
			break;
		default:
			break;
		}
	}

	// Вывод статистики
	void displayStatistics() {
		std::cout << "Статистика:\n";
		std::cout << "Создано фигур: " << this->generatedFigures << "\n";
		std::cout << "Из них суперфигур: " << this->generatedSuperFigures << "\n";
	}
};