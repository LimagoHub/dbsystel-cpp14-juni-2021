// templates.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

template<typename T1, typename T2>
auto add(T1 t1, T2 t2)-> decltype(t1 + t2)
{
	static_assert (std::is_arithmetic<T1>::value, "Parameter 1 sollte eine Zahl sein"); // Prüfung zur Compilezeit
	static_assert (std::is_arithmetic<T2>::value, "Parameter 2 sollte eine Zahl sein");
	return t1 + t2;
}


// Variadic Template
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

// typedef typename Last<Tail...>::Type Type;
template<typename T>
T sum(T head)
{
	static_assert (std::is_arithmetic<T>::value, "Parameter 1 sollte eine Zahl sein"); // Prüfung zur Compilezeit
	return head;

}


template<typename T, typename... Tail>



auto sum(T head, Tail... tail)->double
{
		
	static_assert (std::is_arithmetic<T>::value, "Parameter 1 sollte eine Zahl sein"); // Prüfung zur Compilezeit
	
	return head + sum(tail...);

}





int main() noexcept
{

	try
	{
		auto e1 = add(5, 4);
		auto e2 = add(3.0, 4);

		f(1, 3.4, "Hallo", e1, 5);

		auto c = sum(30, 40, 50);
		
		std::cout << c << std::endl;

	}
	catch (const std::exception&)
	{
		std::cout << "Haaaaaaalloooooo?" << std::endl;
	}
	return 0;
}


