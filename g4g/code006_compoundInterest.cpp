#include <iostream>

int main()
{
	float principle, rate, time;
	std::cout << "Principle (in $): ";
	std::cin >> principle;
	std::cout << "Rate (in %): ";
	std::cin >> rate;
	std::cout << "Time (in years): ";
	std::cin >> time;
	float amount = principle * std::pow(1+rate/100, time);
	float interest = amount - principle;
	std::cout << "Compount Interest (in $): " << interest;
	return 0;
}
