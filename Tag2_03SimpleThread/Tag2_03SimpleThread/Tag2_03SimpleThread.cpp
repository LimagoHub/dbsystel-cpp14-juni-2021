// Tag2_03SimpleThread.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <chrono>
#include <iostream>
#include <random>
#include <thread>


class schwein
{
private:
	std::string name;
	volatile int gewicht;
public:
	schwein(std::string name = "Nobody") :name(name), gewicht(10){}

	int get_gewicht()
	{
		return gewicht;
	}

	std::string get_name()
	{
		return name;
	}

	void set_name(std::string name)
	{
		this->name = name;
	}

	void fressen()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		gewicht++;
	}

	void ausgabe()
	{
		std::cout << "Name: " << name << ", Gewicht: " << gewicht << std::endl;
	}
	
};

//void MyFunc(std::string message)
//{
//	std::random_device rn;
//	std::mt19937 engine{ rn() };
//	std::uniform_int_distribution<int> dice{ 0, 1000 };
//
//	for(int i = 0; i < 10; i ++)
//	{
//		std::cout << message << std::endl;
//		std::this_thread::sleep_for(std::chrono::milliseconds(dice(engine)));
//	}
//	
//	
//	
//}

int main()
{

	schwein piggy{ "Miss Piggy" };

	piggy.ausgabe();

	piggy.fressen();


	piggy.ausgabe();
	
	while(piggy.get_gewicht() < 11){}

	piggy.ausgabe();
	
	

	
	/*std::thread hund{MyFunc, "Wau"};
	
	std::thread katze{ MyFunc, "Miau" };
	
	

	hund.join();
	katze.join();
	
	std::thread maus{ MyFunc, "piep" };
	maus.join();
	
	std::cout << "Hauptprogramm Fertig" << std::endl;*/

	
	
}

