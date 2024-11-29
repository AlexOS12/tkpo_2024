#include <string>

#pragma once
#define CALL_PRICE 10

class State;

//// Интерфейс телефона
//class PhoneInterace
//{
//	friend class State;
//	friend class IdleState;
//	friend class CallState;
//	friend class TalkState;
//	friend class BlockState;
//
//protected:
//	int number;        // Номер телефона
//	int balance;       // Баланс
//	double callChance; // Вероятность поступления звонка
//	State* state;      // Состояние телефона
//
//public:
//	virtual std::string call() = 0;
//	virtual std::string answerCall() = 0;
//	virtual std::string endCall() = 0;
//	virtual std::string topupBalance(int amount) = 0;
//	virtual std::string toString() = 0;
//
//	PhoneInterace() {};
//};

// Телефон
class Phone {
	friend class State;
	friend class IdleState;
	friend class CallState;
	friend class TalkState;
	friend class BlockState;

private:
	int number;        // Номер телефона
	int balance;       // Баланс
	int callChance;    // Вероятность поступления звонка
	State* state;      // Состояние телефона

public:
	std::string call();
	std::string answerCall();
	std::string endCall();
	std::string topupBalance(int amount);
	std::string toString();

	Phone();
	Phone(int number, int balance, int callChance);
};



// Базовый класс состояния
class State {
public:
	virtual std::string call(Phone* phone) = 0;
	virtual std::string answerCall(Phone* phone) = 0;
	virtual std::string endCall(Phone* phone) = 0;
	virtual std::string toString() = 0;
	virtual std::string topupBalance(Phone* phone, int amount);
};

// Состояние ожидания
class IdleState : public State {
	std::string call(Phone* phone) override;

	std::string answerCall(Phone* phone) override;

	std::string endCall(Phone* phone) override;

	std::string toString() override;
};

// Состояние звонка
class CallState : public State {
	std::string call(Phone* phone) override;

	std::string answerCall(Phone* phone) override;

	std::string endCall(Phone* phone) override;

	std::string toString() override;
};

// Состояние разговора
class TalkState : public State {
	std::string call(Phone* phone) override;

	std::string answerCall(Phone* phone) override;

	std::string endCall(Phone* phone) override;

	std::string toString() override;
};


// Состояние блокировки
class BlockState : public State {
	std::string call(Phone* phone) override;

	std::string answerCall(Phone* phone) override;

	std::string endCall(Phone* phone) override;

	std::string toString() override;

	std::string topupBalance(Phone* phone, int amount) override;
};




