// Tag1_04Stapel.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
#include "Stapel.h"

int main()
{
	Stapel s;
	

	s.push(10);
	s.push(20);
	s.push(30);

	Stapel other = 100;

	other = std::move(s);

	std::cout << other.pop() << std::endl;
	std::cout << other.pop() << std::endl;
	std::cout << other.pop() << std::endl;

	//std::string a = "Hallo Welt";
	//std::string b = std::move(a);

	//
	//std::cout << a << std::endl;
	//std::cout << b << std::endl;
	

	
	
    std::cout << "Hello World!\n";
}

