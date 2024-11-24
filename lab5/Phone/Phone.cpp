#include "Phone.h"

std::string IdleState::call(PhoneInterace* phone)
{
	if (phone->balance > CALL_PRICE) {
		phone->state = new CallState;
		phone->balance -= CALL_PRICE;
		return "��������� ������";
	}
	return "������������ ������� ��� ������";
}

std::string IdleState::answerCall(PhoneInterace* phone)
{
	return "�������� �� ������";
}

std::string IdleState::endCall(PhoneInterace* phone)
{
	return "� ������� ������ ��� ������, ������� ����� ���� �� ���������";
}

std::string IdleState::toString()
{
	return "��������";
}

std::string CallState::call(PhoneInterace* phone)
{
	return "� ��������� ������ ������ ��� �����������";
}

std::string CallState::answerCall(PhoneInterace* phone)
{
	return "������ �������� �� ������, �� ����� ���������� ������";
}

std::string CallState::endCall(PhoneInterace* phone)
{
	phone->state = new IdleState;
	return "������ ��������";
}

std::string CallState::toString()
{
	return "����������� ������";
}

std::string TalkState::call(PhoneInterace* phone)
{
	return "������ ������ ����� ������, ��������� �� ��� ��������������";
}

std::string TalkState::answerCall(PhoneInterace* phone)
{
	return "������ �������� �� ������, ��������� �� ��� ��������������";
}

std::string TalkState::endCall(PhoneInterace* phone)
{
	phone->state = new IdleState;
	return "�������� ��� ��������";
}

std::string TalkState::toString()
{
	return "���� ��������";
}

std::string BlockState::call(PhoneInterace* phone)
{
	return "���������� ��������� ������ � ������������� ��������";
}

std::string BlockState::answerCall(PhoneInterace* phone)
{
	return "���������� �������� �� ������ � ������������� ��������";
}

std::string BlockState::endCall(PhoneInterace* phone)
{
	return "� ������� ������ ��� ������, ������� ����� ���� �� ���������";
}

std::string BlockState::toString()
{
	return "����������";
}

std::string BlockState::topupBalance(PhoneInterace* phone, int amount)
{
	phone->balance += amount;
	std::string res;
	res += "������ ��� �������� �� " + std::to_string(amount) + "\n";
	res += "����� ������: " + std::to_string(phone->balance);

	if (phone->balance >= 0) {
		phone->state = new IdleState;
		res += "\n���������� �����";
	}

	return res;
}

std::string Phone::call()
{
	return state->call(this);
}

std::string Phone::answerCall()
{
	return state->answerCall(this);
}

std::string Phone::endCall()
{
	return state->endCall(this);
}

std::string Phone::topupBalance(int amount)
{
	return state->topupBalance(this, amount);
}

std::string Phone::toString()
{
	std::string data;
	data += "�����:  " + std::to_string(number) + "\n";
	data += "������: " + std::to_string(balance) + "\n";
	data += "����������� ������: " + std::to_string(callChance) + "\n";
	data += "���������: " + state->toString() + "\n";

	return data;
}

Phone::Phone()
{
	number = rand() % 1'000;
	balance = 100;
	callChance = 0.5;
	state = new IdleState();
}

Phone::Phone(int number, int balance, double callChance)
{
	this->number = number;
	this->balance = balance;
	this->callChance = callChance;
	if (balance < 0)
		state = new BlockState();
	else
		state = new IdleState();
}
