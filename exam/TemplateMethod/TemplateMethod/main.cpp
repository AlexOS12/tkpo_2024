#include <iostream>
#include "TemplateMethod.h"

// Выполнил студент группы 221-3210 Обухов Алексей

/* Задание:
*	Паттерн «Шаблонный Метод». 
*	Применить паттерн при написании программы решения квадратного уравнения. 
*	Шаги алгоритма должны меняться в зависимости от значения дискриминанта 
*	(положительный, отрицательный, равен нулю).
*/


void SolveEquation(double a, double b, double c) {
	ConcreteEquationSolver* solver = new ConcreteEquationSolver(a, b, c);

	std::vector<double> roots = solver->Solve();

	std::cout << "Roots of the equation:\n";

	if (roots.size() == 0) 
		std::cout << "This equation has no roots.\n";
	else {
		std::cout << "This equation has " << roots.size() << " roots: ";

		for (int i = 0; i < roots.size(); i++) {
			std::cout << roots[i] << " ";
		}
		std::cout << "\n";
	}

	delete solver;
	return;
}

int main() {
	double a, b, c;

	std::cout << "Enter A >> ";
	std::cin >> a;
	std::cout << "Enter B >> ";
	std::cin >> b;
	std::cout << "Enter C >> ";
	std::cin >> c;

	SolveEquation(a, b, c);

	return 0;
}