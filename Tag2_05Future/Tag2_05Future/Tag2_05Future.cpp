// Tag2_05Future.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <chrono>
#include <future>
#include <iostream>
#include <thread>

int sinn_des_lebens()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return 42;
}

int bar() {
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	return 4711;
}


int main()
{

	std::future<int> erg1 = std::async(sinn_des_lebens);
	std::future<int> erg2 = std::async(bar);

	std::future<int> erg3 = std::async(sinn_des_lebens);
	std::future<int> erg4 = std::async(bar);

	std::cout << "Methode 2: " << erg2.get() << std::endl;
	std::cout << "Methode 1: " << erg1.get() << std::endl;
	std::cout << "Methode 3: " << erg3.get() << std::endl;
	std::cout << "Methode 4: " << erg4.get() << std::endl;
	
	
    std::cout << "Hello World!\n";
}

