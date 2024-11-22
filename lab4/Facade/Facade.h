#pragma once

#include <iostream>

namespace subsystem {
	// ������� ����� ������������
	class RealEstateType {
	public:
		// ������� ������
		virtual int getBasePrice() = 0;
	};

	// ����� ��������
	class Flat : public RealEstateType {
		int getBasePrice() override {
			return 3500;
		}
	};

	// ����� ���������
	class TownHouse : public RealEstateType {
		int getBasePrice() override {
			return 2700;
		}
	};

	// ����� �������� 
	class Cottage : public RealEstateType {
		int getBasePrice() override {
			return 4200;
		}
	};

}

// ����� ��� ������� ��������� ���������� ������
class Facade {
protected:
	// ��� ������������
	subsystem::RealEstateType* realEstate;
	// ������� ������������
	int area;
	// ����� ������������
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