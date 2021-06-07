// Tag1_06SmartPointer.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <memory>

class MyClass
{
public:
	MyClass()
	{
		std::cout << "Ctor MyClass\n";
	}
	MyClass(const MyClass& other)
	{
		std::cout << "Copy Ctor MyClass\n";
	}
	MyClass &operator = (const MyClass& other)
	{
		std::cout << "Copy Ctor MyClass\n";
		return *this;
	}

	virtual ~MyClass()
	{
		std::cout << "Dtor MyClass\n";
	}

	void foo()
	{
		std::cout << "Hier ist foo\n";
	}
};

auto Source() -> std::unique_ptr<MyClass>
{
	return std::unique_ptr<MyClass> { new MyClass() };
}

auto Sink(std::unique_ptr<MyClass> p) ->std::unique_ptr<MyClass>
{
	std::cout << "Hallo Sink" << std::endl;
	return p;
}

int main()
{
	std::unique_ptr<MyClass> up = Source();
	

	up->foo();

	up = Sink(std::move(up));


	up->foo();

	//std::unique_ptr<MyClass> other = std::move(up);


	//other->foo(); // Richtig
	//// up->foo(); Bitte nicht verwenden
	//
}

//auto Source()->std::shared_ptr<MyClass>
//{
//	return std::shared_ptr<MyClass>{new MyClass()};
//}
//
//void Sink(std::shared_ptr<MyClass> c)
//{
//	std::cout << "Anzahl der Referenzen: " << c.use_count() << std::endl;
//	std::cout << "sink\n";
//}
//
//
//int main()
//{
//	std::shared_ptr<MyClass> sp = Source();
//	std::cout << "Anzahl der Referenzen: " << sp.use_count() << std::endl;
//
//	sp->foo();
//
//
//	Sink(sp);
//	std::cout << "Anzahl der Referenzen: " << sp.use_count() << std::endl;
//	
//	// std::cout << "vorher\n";
//	// //std::shared_ptr<MyClass> sp{ new MyClass };
//	// std::cout << "Anzahl der Referenzen: " << sp.use_count() << std::endl;
//	//
//	//
//	// {
//	// 	std::shared_ptr<MyClass> sp2 = sp;
//	// 	std::cout << "Anzahl der Referenzen: " << sp.use_count() << std::endl;
//	// }
//	//
//	// std::cout << "Anzahl der Referenzen: " << sp.use_count() << std::endl;
//	//
//	// sp->foo();
//	// std::cout << "nachher\n";
//}
//
