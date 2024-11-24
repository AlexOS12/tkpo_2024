#include <string>

#pragma once
#define CALL_PRICE 10

class State;

// Интерфейс телефона
class PhoneInterace
{
	friend class State;
	friend class IdleState;
	friend class CallState;
	friend class TalkState;
	friend class BlockState;

protected:
	int number;        // Номер телефона
	int balance;       // Баланс
	double callChance; // Вероятность поступления звонка
	State* state;      // Состояние телефона

public:
	virtual std::string call() = 0;
	virtual std::string answerCall() = 0;
	virtual std::string endCall() = 0;
	virtual std::string topupBalance(int amount) = 0;
	virtual std::string toString() = 0;

	PhoneInterace() {};
};


// Базовый класс состояния
class State {
public:
	virtual std::string call(PhoneInterace* phone) = 0;
	virtual std::string answerCall(PhoneInterace* phone) = 0;
	virtual std::string endCall(PhoneInterace* phone) = 0;
	virtual std::string toString() = 0;
	virtual std::string topupBalance(PhoneInterace* phone, int amount) {
		phone->balance += amount;
		std::string res;
		res += "Баланс был пополнен на " + std::to_string(amount) + "\n";
		res += "Новый баланс: " + std::to_string(phone->balance);
		return res;
	};
};

// Состояние ожидания
class IdleState : public State {
	std::string call(PhoneInterace* phone) override;

	std::string answerCall(PhoneInterace* phone) override;

	std::string endCall(PhoneInterace* phone) override;

	std::string toString() override;
};

// Состояние звонка
class CallState : public State {
	std::string call(PhoneInterace* phone) override;

	std::string answerCall(PhoneInterace* phone) override;

	std::string endCall(PhoneInterace* phone) override;

	std::string toString() override;
};

// Состояние разговора
class TalkState : public State {
	std::string call(PhoneInterace* phone) override;

	std::string answerCall(PhoneInterace* phone) override;

	std::string endCall(PhoneInterace* phone) override;

	std::string toString() override;
};


// Состояние блокировки
class BlockState : public State {
	std::string call(PhoneInterace* phone) override;

	std::string answerCall(PhoneInterace* phone) override;

	std::string endCall(PhoneInterace* phone) override;

	std::string toString() override;

	std::string topupBalance(PhoneInterace* phone, int amount) override;
};

// Телефон
class Phone : public PhoneInterace {
	friend class State;
	friend class IdleState;
	friend class CallState;
	friend class TalkState;
	friend class BlockState;

public:
	std::string call() override;
	std::string answerCall() override;
	std::string endCall() override;
	std::string topupBalance(int amount) override;
	std::string toString() override;

	Phone();
	Phone(int number, int balance, double callChance);
};



