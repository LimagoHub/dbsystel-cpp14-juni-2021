// Tag1_03Move.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

void foo(int &x)
{
	//x = 100;
	std::cout << "Lvalue: " << x << std::endl;
}


void foo(int&& x)
{
	std::cout << "Rvalue: " << x << std::endl;
}

int main()
{
	
	int a = 10;

	foo(a);
	foo(std::move(a));
	foo(10);

	
    std::cout << a << "   Hello World!\n";
}

