// ArrayUebung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <random>
#include <thread>

const int MAX_ARRAY_SIZE = INT32_MAX >> 4;
const int NUM_OF_PROCESSORS = 16;

int main()
{
	int* data = new int[MAX_ARRAY_SIZE]; // Smartpointer

	// Für Zufallszahlen
	std::random_device rn;
	std::mt19937 engine{ rn() };
	std::uniform_int_distribution<int> dice{ INT32_MIN, INT32_MAX };

	auto start = std::chrono::system_clock::now();
	
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		data[i] = dice(engine);

	auto ende = std::chrono::system_clock::now();
	std::chrono::duration<double> dur = ende - start;
	std::cout << "Duration: " << dur.count() << std::endl << "#########################" << std::endl << std::endl;

	
	delete[] data;
    std::cout << std::thread::hardware_concurrency() << std::endl;
}

