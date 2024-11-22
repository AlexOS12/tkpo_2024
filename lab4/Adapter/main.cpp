#include <iostream>
#include "Adapter.h"

int main() {
	setlocale(LC_ALL, "Russian");

	ITarget* target = new Adapter(1.0, 1.0, 32.0);

	std::cout << target->passport() << "\n";
	target->modifyVolume(2);
	std::cout << target->passport() << "\n";

	std::cout << "Разница в давлении между 22°C и 30°C: " << target->getDp(22, 30) << " Па\n";

	return 0;
}