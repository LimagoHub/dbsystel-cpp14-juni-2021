// Tag3_03Funktionsobjekte.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void ausgabe(int value)
{
	cout << value << endl;
}

class intgen // Supplier
{
private:
	int n;
public:
	intgen():n(0){}

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
	akkumulator() :n(0) {}

	void operator()(int value)
	{
		n += value;
	}

	int get_n() const
	{
		return n;
	}
};


int main()
{

	vector<int> v(10);

	generate(v.begin(), v.end(), intgen());

	for_each(v.begin(), v.end(), ausgabe);

	akkumulator a = for_each(v.begin(), v.end(), akkumulator());

	std::cout << a.get_n() << "Hello World!\n";
    std::cout << "Hello World!\n";
}

