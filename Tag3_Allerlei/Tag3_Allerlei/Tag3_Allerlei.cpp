// Tag3_Allerlei.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Firma.h"

void ausgabe(mitarbeiter& m)
{
	std::cout << m << std::endl;
}

void increase_salary_impl(mitarbeiter& m, double delta)
{
	m.set_gehalt(m.get_gehalt() + delta);
}


class statistik_visitor
{
private:
	int john_count{ 0 };
public:

	statistik_visitor() = default;
	void operator() (mitarbeiter& m)
	{
		if (m.get_vorname() == "John")
			john_count++;
	}


	int get_john_count() const
	{
		return john_count;
	}
};

int main()
{

	firma f;

	std::vector<mitarbeiter> v{
		mitarbeiter{ "John","Wayne", 2500 } ,
		mitarbeiter{ "John","Wick", 1500 } ,
		mitarbeiter{ "John","McClane", 4500 } ,
		mitarbeiter{ "John","Rambo", 500 } ,
		mitarbeiter{ "John Boy","Walton", 2500 } ,

		mitarbeiter{ "Erika","Rambo", 500 } ,
		mitarbeiter{ "Manuela","Walton", 2500 },
		mitarbeiter{ "Jane","Wayne", 2500 } ,
		mitarbeiter{ "Jane","Wick", 1500 } ,
		mitarbeiter{ "Jane","McClane", 4500 } ,
		mitarbeiter{ "Jane","Rambo", 500 } ,
		mitarbeiter{ "Jane Boy","Walton", 2500 } 
		
	};

	auto increase_salary = std::bind(increase_salary_impl, std::placeholders::_1, 100.0);
	
	for (auto & mitarbeiter : v)
	{
		f.add_mitarbeiter(mitarbeiter);
	}

	f.for_each(ausgabe);
	std::cout << "-----------------------------------------------\n";
	f.for_each(increase_salary);
	std::cout << "-----------------------------------------------\n";
	f.for_each(ausgabe);

	statistik_visitor sv = f.for_each(statistik_visitor{});
	
	std::cout << sv.get_john_count() << std::endl;

	
    std::cout << "Hello World!\n";

	firma opfer;
	firma jaeger;
	

	jaeger = std::move(opfer);
	
}

