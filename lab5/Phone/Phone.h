#include <string>

#pragma once
#define CALL_PRICE 10

class State;

// ��������� ��������
class PhoneInterace
{
	friend class State;
	friend class IdleState;
	friend class CallState;
	friend class TalkState;
	friend class BlockState;

protected:
	int number;        // ����� ��������
	int balance;       // ������
	double callChance; // ����������� ����������� ������
	State* state;      // ��������� ��������

public:
	virtual std::string call() = 0;
	virtual std::string answerCall() = 0;
	virtual std::string endCall() = 0;
	virtual std::string topupBalance(int amount) = 0;
	virtual std::string toString() = 0;

	PhoneInterace() {};
};


// ������� ����� ���������
class State {
public:
	virtual std::string call(PhoneInterace* phone) = 0;
	virtual std::string answerCall(PhoneInterace* phone) = 0;
	virtual std::string endCall(PhoneInterace* phone) = 0;
	virtual std::string toString() = 0;
	virtual std::string topupBalance(PhoneInterace* phone, int amount) {
		phone->balance += amount;
		std::string res;
		res += "������ ��� �������� �� " + std::to_string(amount) + "\n";
		res += "����� ������: " + std::to_string(phone->balance);
		return res;
	};
};

// ��������� ��������
class IdleState : public State {
	std::string call(PhoneInterace* phone) override;

	std::string answerCall(PhoneInterace* phone) override;

	std::string endCall(PhoneInterace* phone) override;

	std::string toString() override;
};

// ��������� ������
class CallState : public State {
	std::string call(PhoneInterace* phone) override;

	std::string answerCall(PhoneInterace* phone) override;

	std::string endCall(PhoneInterace* phone) override;

	std::string toString() override;
};

// ��������� ���������
class TalkState : public State {
	std::string call(PhoneInterace* phone) override;

	std::string answerCall(PhoneInterace* phone) override;

	std::string endCall(PhoneInterace* phone) override;

	std::string toString() override;
};


// ��������� ����������
class BlockState : public State {
	std::string call(PhoneInterace* phone) override;

	std::string answerCall(PhoneInterace* phone) override;

	std::string endCall(PhoneInterace* phone) override;

	std::string toString() override;

	std::string topupBalance(PhoneInterace* phone, int amount) override;
};

// �������
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



