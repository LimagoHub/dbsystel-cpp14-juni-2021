// Tag2_02Random.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <random>

int main()
{
	std::random_device rn;
	std::mt19937 engine{ rn() };
	std::uniform_int_distribution<int> dice{ 0, 1000 };

	for (int i = 0; i < 10; ++i) {
		std::cout << dice(engine) << std::endl;
	}
	return 0;
}

