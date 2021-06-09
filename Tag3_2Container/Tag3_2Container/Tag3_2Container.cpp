// Tag3_2Container.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <ostream>
#include <tuple>
#include <unordered_set>



class Schwein
{
private:
	std::string name;
	int gewicht;
public:
	Schwein(std::string name = "Nobody") :name(name),gewicht(10) {}

	void fressen()
	{
		gewicht++;
	}
	std::string get_name() const
	{
		return name;
	}

	void set_name(const std::string& name)
	{
		this->name = name;
	}

	int get_gewicht() const
	{
		return gewicht;
	}

	void set_gewicht(int gewicht)
	{
		this->gewicht = gewicht;
	}


	friend bool operator==(const Schwein& lhs, const Schwein& rhs)  noexcept
	{
		return lhs.name == rhs.name	&& lhs.gewicht == rhs.gewicht;
	}

	friend bool operator!=(const Schwein& lhs, const Schwein& rhs)
	{
		return !(lhs == rhs);
	}


	std::size_t hash(const Schwein& obj) const noexcept
	{
		std::hash<std::string> str_hash;
		std::hash<int> int_hash;
		return str_hash (obj.get_name()) * int_hash(obj.gewicht);
			
		
	}

	friend std::ostream& operator<<(std::ostream& os, const Schwein& obj)
	{
		return os
			<< "name: " << obj.name
			<< " gewicht: " << obj.gewicht;
	}
};

struct PigEqual {
public:
	bool operator()(const Schwein& str1, const Schwein& str2) const {
		return str1.get_name() == str2.get_name() && str1.get_gewicht() == str2.get_gewicht();
	}
};

struct PigHash {
public:
	size_t operator()(const Schwein& obj) const {
		std::hash<std::string> str_hash;
		std::hash<int> int_hash;
		return str_hash(obj.get_name()) * int_hash(obj.get_gewicht());
	}
};

int main()
{
	std::tuple<int, int, double> myTup{ 10,20,30 };

	auto e1 = std::get<0>(myTup);
	std::cout << e1 << std::endl;
	std::cout << std::get<2>(myTup) << std::endl;

	
	std::unordered_set<Schwein,PigHash,PigEqual> X{ Schwein{"Piggy"},Schwein{"Babe"}, Schwein{"Piggy"} };
	for (auto Y : X)
		if (Y.get_name() == "Piggy")
			Y.fressen();

	for (auto Y : X)
		std::cout << Y << std::endl;



	std::cout << "Hello World!\n";
}

