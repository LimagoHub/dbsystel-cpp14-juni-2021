#pragma once
#include <iostream>
class MySingleton
{
private:
	MySingleton()
	{
		
	}

	static std::weak_ptr<MySingleton> instance;

public:

	~ MySingleton()
	{
		std::cout << "DTOR" << std::endl;
		
	}
	static std::shared_ptr<MySingleton> GetInstance()
	{
		std::shared_ptr<MySingleton> retval = instance.lock();
		if(retval == nullptr)
		{
			retval.reset(new MySingleton());
			instance = retval;
			
			
		}

		return retval;
	}

	void foo() {
		std::cout << this << std::endl;
	}
	
};

std::weak_ptr<MySingleton> MySingleton::instance;

