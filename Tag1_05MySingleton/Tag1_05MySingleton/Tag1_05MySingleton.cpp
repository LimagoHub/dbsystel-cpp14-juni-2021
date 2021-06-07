// Tag1_05MySingleton.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "MySingleton.h"

int main()
{
	{
		//std::shared_ptr<MySingleton> ptr = MySingleton::GetInstance();

		MySingleton::GetInstance()->foo();
		MySingleton::GetInstance()->foo();
		MySingleton::GetInstance()->foo();
	}
	
	{
		//std::shared_ptr<MySingleton> ptr = MySingleton::GetInstance();

		MySingleton::GetInstance()->foo();
		MySingleton::GetInstance()->foo();
		MySingleton::GetInstance()->foo();
	}
    std::cout << "Hello World!\n";
}


