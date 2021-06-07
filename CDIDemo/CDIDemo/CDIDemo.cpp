// CDIDemo.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "calculator_impl.h"
#include "Client.h"




int main()
{

	
	math::calculator_impl calc;
	math::calculator_logger logger{ calc };
	math::calculator_secure secure{ logger };
	
	client::calculator_client client{ secure };
	client.run();
}

