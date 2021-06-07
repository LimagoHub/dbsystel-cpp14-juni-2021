// Tag1_07WeakPointer.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
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
	MyClass& operator = (const MyClass& other)
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

int main()
{

	std::weak_ptr<MyClass > sp2;
	
		std::shared_ptr<MyClass > sp{ new MyClass() };
		sp2 = sp;
		
	std::cout << sp2.use_count() << std::endl;

	if (!sp2.expired()) {
		std::shared_ptr<MyClass > sp3 = sp2.lock();
		std::cout << sp2.use_count() << std::endl;
	}
    std::cout << "Hello World!\n";
}

