#pragma once

#include <iostream>

#include "calculator_impl.h"

namespace client {

	
	class calculator_client
	{

	private:
		math::calculator &calc;
	public:
		
		calculator_client(math::calculator &calc) :calc(calc){};

		
		void run()
		{
			
			std::cout << calc.Add(3, 4) << std::endl;
		}
	};
}
