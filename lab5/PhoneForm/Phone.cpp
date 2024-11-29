#include "Phone.h"

std::string IdleState::call(Phone* phone)
{
	if (phone->balance > CALL_PRICE) {
		phone->state = new CallState;
		phone->balance -= CALL_PRICE;
		return "Выполняем звонок";
	}
	return "Недостаточно средств для звонка";
}

std::string IdleState::answerCall(Phone* phone)
{
	if (rand() % 100 < phone->callChance) {
		phone->state = new TalkState;
		return "Отвечаем на звонок";
	}
	else
		return "Нет входящего звонка";
}

std::string IdleState::endCall(Phone* phone)
{
	return "В текущий момент нет звонка, который можно было бы заврешить";
}

std::string IdleState::toString()
{
	return "Ожидание";
}

std::string CallState::call(Phone* phone)
{
	return "В настоящий момент звонок уже выполняется";
}

std::string CallState::answerCall(Phone* phone)
{
	return "Нельзя ответить на звонок, во время выполнения звонка";
}

std::string CallState::endCall(Phone* phone)
{
	phone->state = new IdleState;
	return "Звонок завершен";
}

std::string CallState::toString()
{
	return "Выполняется звонок";
}

std::string TalkState::call(Phone* phone)
{
	return "Нельзя начать новый звонок, поскольку Вы уже разговариваете";
}

std::string TalkState::answerCall(Phone* phone)
{
	return "Нельзя ответить на звонок, посколько Вы уже разговариваете";
}

std::string TalkState::endCall(Phone* phone)
{
	phone->state = new IdleState;
	return "Разговор был завершен";
}

std::string TalkState::toString()
{
	return "Идет разговор";
}

std::string BlockState::call(Phone* phone)
{
	return "Невозможно совершить звонок с отрицательным балансом";
}

std::string BlockState::answerCall(Phone* phone)
{
	return "Невозможно ответить на звонок с отрицательным балансом";
}

std::string BlockState::endCall(Phone* phone)
{
	return "В текущий момент нет звонка, который можно было бы заврешить";
}

std::string BlockState::toString()
{
	return "Блокировка";
}

std::string BlockState::topupBalance(Phone* phone, int amount)
{
	phone->balance += amount;
	std::string res;
	res += "Баланс был пополнен на " + std::to_string(amount) + "\n";
	res += "Новый баланс: " + std::to_string(phone->balance);

	if (phone->balance >= 0) {
		phone->state = new IdleState;
		res += "\nБлокировка снята";
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
	data += "Номер:  " + std::to_string(number) + "\n";
	data += "Баланс: " + std::to_string(balance) + "\n";
	data += "Вероятность звонка: " + std::to_string(callChance) + "\n";
	data += "Состояние: " + state->toString() + "\n";

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
	res += "Баланс был пополнен на " + std::to_string(amount) + "\n";
	res += "Новый баланс: " + std::to_string(phone->balance);
	if (phone->balance < 0)
		phone->state = new BlockState;
	return res;
}