#include <iostream>


auto foo() noexcept ->int
{
	return 42;
}


template<typename T1, typename T2>
auto add(T1 t1, T2 t2)-> decltype(t1 + t2)
{
	return t1 + t2;
}


auto main() noexcept -> int
{
	auto ergebnis = add(1, 1.0);
	
	auto a = 10.0;
	
	auto b = a - 2;

	auto* ptr = &a;

	
	
}


