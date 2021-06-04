// templates.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

template<typename T1, typename T2>
auto add(T1 t1, T2 t2)-> decltype(t1 + t2)
{
	return t1 + t2;
}

template<typename T>
void f(T t)
{
	std::cout << t << std::endl;
	
}


template<typename T, typename... Tail>
void f(T head, Tail... tail)
{
	std::cout << head << std::endl;
	f(tail...);
	
}
//void f(){}

int main()
{

	auto e1 = add(3, 4);
	auto e2 = add(3.0, 4);

	f(1, 3.4, "Hallo", e1,5);
	
    std::cout << "Hello World!\n";
}


