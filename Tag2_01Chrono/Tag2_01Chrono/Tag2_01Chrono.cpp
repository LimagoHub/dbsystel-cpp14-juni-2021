// Tag2_01Chrono.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <chrono>
#include <iostream>
#include <thread>

int main()
{
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();  // Zeitpunkt
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

	std::chrono::duration<double, std::ratio<1>> dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	
    std::cout << "Hello World!, Dauer: " << dur.count() << std::endl;
}

/*
 *
 typedef duration<signed int, nano> nanoseconds;
typedef duration<signed int, micro> microseconds;
typedef duration<signed int, milli> milliseconds;
typedef duration<signed int> seconds;
typedef duration<signed int, ratio< 60>> minutes;
typedef duration<signed int, ratio<3600>> hours;
 *
 *
 * 
 */