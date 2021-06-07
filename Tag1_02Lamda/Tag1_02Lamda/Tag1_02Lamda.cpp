#include <iostream>
#include <functional>


struct MyClass
{
	int* feld;

	MyClass()
	{
		feld = new int[4];
		for(auto i = 0; i < 4; i++)
		{
			feld[i] = i * 10;
		}
	}

	void foreach(std::function<void(int)> myPtr)
	{
		for (auto i = 0; i < 4; i++)
		{
			myPtr(feld[i]);
		}
	} 
};

auto foo() -> int
{
	return 42;
}

auto demo()-> std::function<int(void)>
{
	auto x = 10;

	auto fptr = [x=x]()->int { return x + 10; };

	x++;
	
	return fptr;
}


auto main() -> int
{

	
	MyClass c;

	c.foreach([](int i) {std::cout << i << std::endl; });
	
	
    std::cout << demo()()  << "Hello World!\n";
}

