#include "Phone.h"

std::string IdleState::call(Phone* phone)
{
	if (phone->balance > CALL_PRICE) {
		phone->state = new CallState;
		phone->balance -= CALL_PRICE;
		return "��������� ������";
	}
	return "������������ ������� ��� ������";
}

std::string IdleState::answerCall(Phone* phone)
{
	if (rand() % 100 < phone->callChance) {
		phone->state = new TalkState;
		return "�������� �� ������";
	}
	else
		return "��� ��������� ������";
}

std::string IdleState::endCall(Phone* phone)
{
	return "� ������� ������ ��� ������, ������� ����� ���� �� ���������";
}

std::string IdleState::toString()
{
	return "��������";
}

std::string CallState::call(Phone* phone)
{
	return "� ��������� ������ ������ ��� �����������";
}

std::string CallState::answerCall(Phone* phone)
{
	return "������ �������� �� ������, �� ����� ���������� ������";
}

std::string CallState::endCall(Phone* phone)
{
	phone->state = new IdleState;
	return "������ ��������";
}

std::string CallState::toString()
{
	return "����������� ������";
}

std::string TalkState::call(Phone* phone)
{
	return "������ ������ ����� ������, ��������� �� ��� ��������������";
}

std::string TalkState::answerCall(Phone* phone)
{
	return "������ �������� �� ������, ��������� �� ��� ��������������";
}

std::string TalkState::endCall(Phone* phone)
{
	phone->state = new IdleState;
	return "�������� ��� ��������";
}

std::string TalkState::toString()
{
	return "���� ��������";
}

std::string BlockState::call(Phone* phone)
{
	return "���������� ��������� ������ � ������������� ��������";
}

std::string BlockState::answerCall(Phone* phone)
{
	return "���������� �������� �� ������ � ������������� ��������";
}

std::string BlockState::endCall(Phone* phone)
{
	return "� ������� ������ ��� ������, ������� ����� ���� �� ���������";
}

std::string BlockState::toString()
{
	return "����������";
}

std::string BlockState::topupBalance(Phone* phone, int amount)
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
	callChance = 50;
	state = new IdleState();
}

Phone::Phone(int number, int balance, int callChance)
{
	this->number = number;
	this->balance = balance;
	this->callChance = callChance;
	if (balance < 0)
		state = new BlockState();
	else
		state = new IdleState();
}

std::string State::topupBalance(Phone* phone, int amount)
{
	phone->balance += amount;
	std::string res;
	res += "������ ��� �������� �� " + std::to_string(amount) + "\n";
	res += "����� ������: " + std::to_string(phone->balance);
	if (phone->balance < 0)
		phone->state = new BlockState;
	return res;
}