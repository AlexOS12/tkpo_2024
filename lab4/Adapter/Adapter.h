#pragma once

#include <string>

// ����� ������� � �����
class GasCylinder {
protected:
	double volume; // ����� ������� � �^3
	double mass;   // ����� ���� � ��
	double molar;  // �������� ����� ���� � ��/����

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

	// ���������� ������� �������� � �������
	double getPressure(int t) {
		// 8.314 - ����� R
		double pressure = (amountOfMatter() * 8.314 * t) / volume;
		return pressure;
	};

	// ���������� ���-�� �������� � �������
	double amountOfMatter() {
		double amount = mass / molar;
		return amount;
	};

	// ���������� ������ � ���������� � �������
	std::string toString() {
		std::string data = "�������� � ����, ������������ � �������:\n";
		data += "����� �������: " + std::to_string(volume) + " �^3\n";
		data += "����� ����: " + std::to_string(mass) + " ��\n";
		data += "�������� ����� ����: " + std::to_string(molar) + " ��/����\n";
		data += "���������� ����: " + std::to_string(amountOfMatter()) + " ����\n";
		return data;
	};
};

// ����� ���������
class ITarget {
public:
	// �������� ����� ������� �� �������� dV
	virtual void modifyVolume(double dV) = 0 ;
	// ���������� ��������� �������� ��� ��������� �����������
	virtual double getDp(int t0, int t1) = 0;
	// �������� �������� � �������
	virtual std::string passport() = 0;
};

// ����� ��������
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