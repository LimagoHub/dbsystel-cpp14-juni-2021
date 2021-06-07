#pragma once
#include  <iostream>

namespace math {

	class calculator
	{
	protected:
		virtual ~calculator() = default;
	public:
		
		virtual double Add(double a, double b) = 0;

		virtual double Sub(double a, double b) = 0;
	};


	class calculator_impl:public  calculator
	{
	public:
		double Add(double a, double b)
		{
			return a + b;
		}

		double Sub(double a, double b)
		{
			return a - b;
		}
	};

	class calculator_logger: public calculator
	{
		calculator& calc;
		
	public:

		calculator_logger(calculator  &calc):calc(calc){}
		virtual ~calculator_logger()
		{
			
		}
		
		virtual double Add(double a, double b)
		{
			std::cout << "Add wurde gerufen" << std::endl;
			return calc.Add(a, b);
		}

		virtual double Sub(double a, double b)
		{
			return a - b;
		}
	};
	class calculator_secure : public calculator
	{
		calculator &calc;

	public:

		calculator_secure(calculator &calc) :calc(calc) {}
		virtual ~calculator_secure()
		{

		}

		double Add(double a, double b)
		{
			std::cout << "Du kommst rein" << std::endl;
			return calc.Add(a, b);
		}

		double Sub(double a, double b)
		{
			return a - b;
		}
	};

}
