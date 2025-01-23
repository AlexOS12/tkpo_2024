#pragma once

#include <vector>

// јбстрактный класс решател€ уравнений
class AbstractEquationSolver {
protected:
	double a, b, c;
	double discriminant;
public:
	AbstractEquationSolver(double a, double b, double c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	// Ўаблонный метод дл€ решени€ уравнени€
	std::vector<double> Solve() {
		discriminant = DefineDiscriminant();

		if (discriminant > 0) 
			return FindSolutionWithPositiveD();
		
		if (discriminant == 0)
			return FindSolutionWitZeroD();

		return FindSolutionWitNegativeD();
	}

	// Ўаг определни€ дискриминанта
	virtual double DefineDiscriminant() {
		return b * b - (4 * a * c);
	}

	// –ешение, в случае если D > 0
	virtual std::vector<double> FindSolutionWithPositiveD() = 0;

	// –ешение, в случае если D = 0
	virtual std::vector<double> FindSolutionWitZeroD() = 0;

	// –ешение, в случае если D < 0
	virtual std::vector<double> FindSolutionWitNegativeD() = 0;

};

//  онкретный класс дл€ решени€ уравнений
class ConcreteEquationSolver : public AbstractEquationSolver {
public:
	ConcreteEquationSolver(double a, double b, double c) : AbstractEquationSolver(a, b, c) {}

	// –ешение, в случае если D > 0
	virtual std::vector<double> FindSolutionWithPositiveD() override {
		// квадратный корень из дискриминанта
		double sqrtD = sqrt(discriminant);

		double x1 = (0 - b + sqrtD) / (2 * a);
		double x2 = (0 - b - sqrtD) / (2 * a);

		std::vector<double> solution;
		solution.push_back(x1);
		solution.push_back(x2);

		return solution;
	}

	// –ешение, в случае если D = 0
	virtual std::vector<double> FindSolutionWitZeroD() override {
		double x1 = (-b) / (2 * a);

		std::vector<double> solution;

		// x1 добавл€етс€ в решение, поскольку при D = 0 
		// уравнение имеет два равных корн€
		solution.push_back(x1);
		solution.push_back(x1);

		return solution;
	}

	// –ешение, в случае если D < 0
	virtual std::vector<double> FindSolutionWitNegativeD() override {
		// ¬озвращаем пустой вектор, поскольку решений нет (в вещественных числах)
		return std::vector<double>{};
	}
};

