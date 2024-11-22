#include <iostream>
#include "Facade.h"

int insurancePriceCalculator(subsystem::RealEstateType* realEstateType, int area, int wear) {
	Facade* facade = new Facade(realEstateType, area, wear);
	int price = facade->calculateInsurancePrice();
	delete facade;
	return price;
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "Стоимость страхового взноса за:\n";

	subsystem::RealEstateType* flat = new subsystem::Flat;
	std::cout << "Кватиру:  " << insurancePriceCalculator(flat, 60, 10) << "\n";
	delete flat;
	subsystem::RealEstateType* townHouse = new subsystem::TownHouse;
	std::cout << "Таунхаус: " << insurancePriceCalculator(townHouse, 60, 10) << "\n";
	delete townHouse;
	subsystem::RealEstateType* cottage = new subsystem::Cottage;
	std::cout << "Коттедж:  " << insurancePriceCalculator(cottage, 60, 10) << "\n";
	delete cottage;
	
	return 0;
}