#pragma once
#include  <iostream>
class Stapel
{
private:
	int* data;
	int index;
	

	void initFromOther(const Stapel& other)
	{
		data = new int[other.size];
		size = other.size;
		index = other.index;

		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}
public:
	int size;
	Stapel(const int size = 10):data(new int[size]),index(0),size(size)
	{
		std::cout << "Default Ctor" << std::endl;
	}

	

	Stapel(const Stapel& other) // Copy-Constructor
	{
		std::cout << "Copy Ctor" << std::endl;
		initFromOther(other);
	};

	Stapel(Stapel&& other) // Move Construktor
	{

		std::cout << "Move Ctor" << std::endl;
		data = other.data;
		size = other.size;
		index = other.index;

		other.data = new int[0]; // other.data = NULL
		other.size = 0;
		other.index = 0;
		
	};

	Stapel& operator = (const Stapel& other)
	{
		std::cout << "Copy Operator" << std::endl;
		delete[] data;
		initFromOther(other);
		return *this;
	}



	Stapel& operator = (Stapel&& other)
	{
		std::cout << "Move Operator" << std::endl;
		data = other.data;
		size = other.size;
		index = other.index;

		other.data = new int[0]; // other.data = NULL
		other.size = 0;
		other.index = 0;
		return *this;
	}



	~Stapel()
	{
		delete[] data;
	}

	void push(int value)
	{
		data[index++] = value;
	}

	int pop()
	{
		return data[--index];
	}

	bool isEmpty()
	{
		return index <= 0;
	}

	bool isFull()
	{
		return index >= size;
	}

};

