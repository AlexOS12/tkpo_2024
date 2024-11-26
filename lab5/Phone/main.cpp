#include <iostream>
#include <string>
#include "Phone.h"


int main() {
	setlocale(LC_ALL, "Russian");

	Phone phone(123, 30, 0.5); 
	std::cout << phone.toString() << "\n";
	std::cout << phone.call() << "\n";
	std::cout << phone.answerCall() << "\n";
	std::cout << phone.toString() << "\n";
	std::cout << phone.endCall() << "\n";
	std::cout << phone.toString();

	return 0;
}