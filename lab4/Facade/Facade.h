#pragma once

#include <iostream>

namespace subsystem {
	// Базовый класс недвижимости
	class RealEstateType {
	public:
		// Базовый платеж
		virtual int getBasePrice() = 0;
	};

	// Класс квартиры
	class Flat : public RealEstateType {
		int getBasePrice() override {
			return 3500;
		}
	};

	// Класс таунхауса
	class TownHouse : public RealEstateType {
		int getBasePrice() override {
			return 2700;
		}
	};

	// Класс коттеджа 
	class Cottage : public RealEstateType {
		int getBasePrice() override {
			return 4200;
		}
	};

}

// Фасад для расчета стоимости страхового взноса
class Facade {
protected:
	// Тип недвижимости
	subsystem::RealEstateType* realEstate;
	// Площадь недвижимости
	int area;
	// Износ недвижимости
	int wear;
	
public:
	Facade(subsystem::RealEstateType* realEstate, int area, int wear) {
		this->realEstate = realEstate;
		this->area = area;
		this->wear = wear;
	}

	int calculateInsurancePrice() {
		double wearCoefficient = 1.0 + ((double)wear / 100.0);
		int insurancePrice = realEstate->getBasePrice() * area * wearCoefficient;
		return insurancePrice;
	}
};