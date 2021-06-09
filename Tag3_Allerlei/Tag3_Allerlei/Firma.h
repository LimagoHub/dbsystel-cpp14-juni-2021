#pragma once
#include <vector>
#include <functional>
#include "Mitarbeiter.h"

class firma
{
private:
	std::vector<std::reference_wrapper<mitarbeiter>> mitarbeiters;
public:
	firma(int x){}
	firma(){
		std::cout << "Default Ctor" << std::endl;
	}

	firma(const firma& firma){

		std::cout << "Copy Ctor" << std::endl;
	}
	firma(firma && other)
	{
		std::cout << "Move Ctor" << std::endl;
		mitarbeiters = std::move(other.mitarbeiters);
	}

	auto add_mitarbeiter(mitarbeiter& mitarbeiter) -> void
	{
		mitarbeiters.push_back(std::ref(mitarbeiter));
	}
	/*void remove_mitarbeiter(mitarbeiter& mitarbeiter)
	{
		mitarbeiters.erase(std::find(mitarbeiters.begin(), mitarbeiters.end(), mitarbeiter));
	}*/

	firma & operator = (firma&& other) noexcept
	{
		std::cout << "Move Operator" << std::endl;
		mitarbeiters = std::move(other.mitarbeiters);
		return *this;
	}

	
	template<typename T>
	auto for_each(T consumer) -> T
	{
		return std::for_each(mitarbeiters.begin(), mitarbeiters.end(), consumer);
	}
	
};

