#pragma once
#include <iostream>
#include <mutex>
#include <random>
#include <thread>

class Bank
{
private:
	int konten[3] = { 30,50,100 };
	std::random_device rn;
	std::mt19937 engine{ rn() };
	std::uniform_int_distribution<int> dice{ 0, 1000 };

	//std::mutex myMutex;
	std::recursive_mutex myMutex;
public:
	Bank() = default;
	
	void kontostand_ausgeben()
	{
		std::lock_guard<std::recursive_mutex> myGuard(myMutex);
		for (int i = 0; i < (sizeof(konten) / sizeof(int)); i++) {
			std::cout << "Konto Nr. " << i << " hat den Wert " << konten[i] << std::endl;
		}
		std::cout << "------------------" << std::endl;
		std::cout << std::endl;
	}

	void ueberweisen(int von, int nach, int betrag)
	{
		
		std::lock_guard<std::recursive_mutex> myGuard(myMutex);
		int zettel = konten[von];
		zettel -= betrag;
		std::this_thread::sleep_for(std::chrono::milliseconds(dice(engine)));
		konten[von] = zettel;
		konten[nach] += betrag;

		kontostand_ausgeben();
	}
};

