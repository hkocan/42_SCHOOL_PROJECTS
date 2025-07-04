#include <iostream>
#include <vector>
#include "easyfind.hpp"

template <typename T>
void printContainer(const T &container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> numbers;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(40);

	printContainer(numbers);

	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 30);
		std::cout << "Bulunan değer: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Hata: " << e.what() << std::endl;
	}
	numbers.erase(numbers.begin());
	printContainer(numbers);

	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 10);
		std::cout << "Bulunan değer: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Hata: " << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 99);
		std::cout << "Bulunan değer: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Hata: " << e.what() << std::endl;
	}

	return 0;
}
