// Tag2_04SimpleBank.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Angestellter.h"

int main()
{
    int dummy;

	Bank bank;

	
	Angestellter a1{ bank, 0, 1, 20 };
	Angestellter a2{ bank, 1, 2, 20 };
	Angestellter a3{ bank, 2, 0, 20 };
	

	std::cout << "Vorher" << std::endl;
	bank.kontostand_ausgeben();

	a1.run();
	a2.run();
	a3.run();


	std::cin >> dummy;
}


