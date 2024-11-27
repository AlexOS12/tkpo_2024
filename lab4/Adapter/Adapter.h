#pragma once

#include <string>

// Класс баллона с газом
class GasCylinder {
protected:
	double volume; // объем баллона в м^3
	double mass;   // масса газа в кг
	double molar;  // молярная масса газа в кг/моль

public:
	GasCylinder() {
		volume = 0.0;
		mass = 0.0;
		molar = 0.0;
	}

	GasCylinder(double volume, double mass, double molar) {
		this->volume = volume;
		this->mass = mass;
		this->molar = molar;
	}

	// Возвращает текущее давление в баллоне
	double getPressure(int t) {
		// 8.314 - число R
		double pressure = (amountOfMatter() * 8.314 * t) / volume;
		return pressure;
	};

	// Возвращает кол-во вещества в баллоне
	double amountOfMatter() {
		double amount = mass / molar;
		return amount;
	};

	// Возвращает строку с сведениями о баллоне
	std::string toString() {
		std::string data = "Сведения о газе, содержащемся в баллоне:\n";
		data += "Объем баллона: " + std::to_string(volume) + " м^3\n";
		data += "Масса газа: " + std::to_string(mass) + " кг\n";
		data += "Молярная масса газа: " + std::to_string(molar) + " кг/моль\n";
		data += "Количество газа: " + std::to_string(amountOfMatter()) + " моль\n";
		return data;
	};
};

// Класс интерфейс
class ITarget {
public:
	// Изменяет объем баллона на величину dV
	virtual void modifyVolume(double dV) = 0 ;
	// Определяет изменение давления при изменении температуры
	virtual double getDp(int t0, int t1) = 0;
	// Получить сведения о баллоне
	virtual std::string passport() = 0;
};

// Класс адаптера
class Adapter : public ITarget, private GasCylinder {
public:
	Adapter(double volume, double mass, double molar) {
		this->volume = volume;
		this->mass = mass;
		this->molar = molar;
	}

	void modifyVolume(double dV) override {
		this->volume += dV;
	}

	double getDp(int t0, int t1) override {
		double pressureT0 = getPressure(t0);
		double pressureT1 = getPressure(t1);
		return pressureT1 - pressureT0;
	}

	std::string passport() override {
		return toString();
	}
};