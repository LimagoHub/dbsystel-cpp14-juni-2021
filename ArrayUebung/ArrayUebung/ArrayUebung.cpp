// ArrayUebung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

#include "ArrayManager.h"


int main() noexcept
{
	
	ArrayManager manager;

	manager.fill_array_parallel_with_random_numbers();


	
    std::cout << "\n\nFertig!!!!" << std::endl;
}

