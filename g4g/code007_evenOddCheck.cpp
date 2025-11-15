#include <iostream>

int main()
{
	int number;
	std::cout << "Input: ";
	std::cin >> number;
	if (number%2 == 0)
		std::cout << "Number is even";
	else
		std::cout << "Number is odd";
	return 0;
}
