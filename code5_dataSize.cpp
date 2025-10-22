#include <iostream>

int main()
{
	int int_val;
	char char_val;
	float float_val;
	double double_val;
	std::cout << "size of int: " << sizeof(int_val) << '\n';
	std::cout << "size of float: " << sizeof(float_val) << '\n';
	std::cout << "size of double: " << sizeof(double_val) << '\n';
	std::cout << "size of char: " << sizeof(char_val) << '\n';
	return 0;
}
