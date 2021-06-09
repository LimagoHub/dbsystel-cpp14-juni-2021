// Tag3_03Funktionsobjekte.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

void ausgabe(int value)
{
	cout << value << endl;
}


bool demo(double v) // Predicate
{
	return false;
}

class intgen // Supplier
{
private:
	int n;
public:
	intgen():n(5){}

	int operator()()
	{
		return n++;
	}
};

class akkumulator // Consumer
{
private:
	int n;
public:
	akkumulator() :n(5) {}

	void operator()(int value)
	{
		n += value;
	}

	int get_n() const
	{
		return n;
	}
};

template<typename   T>
bool greater_then(T first, T second)
{
	return first > second;
}

double my_plus(double x, double y)
{
	return x + y;
}

double my_multipier(double x, double y)
{
	return x * y;
}


int main()
{
	// (K - 273.15)* 1.8000
	std::function<double(double)> to_fahrenheit = std::bind(my_plus, std::bind(my_multipier, std::placeholders::_1, 1.8), -459.67);

	std::cout << "Boiling point of water: " << to_fahrenheit(373.15) << " °F\n";

	vector<int> v(10);

	generate(v.begin(), v.end(), intgen());

	//for_each(v.begin(), v.end(), ausgabe);
	vector<int> erg;

	auto myPredicate = std::bind(greater_then<int>, std::placeholders::_1, 10);

	
	
	copy_if(v.begin(), v.end(), std::back_inserter(erg),myPredicate);

	remove_if(v.begin(), v.end(), myPredicate);


	

	//akkumulator a = for_each(v.begin(), v.end(), akkumulator());

	for (int value : erg)
	{
		std::cout << value << "\n";
	}
	
	
    std::cout << "Hello World!\n";
}

