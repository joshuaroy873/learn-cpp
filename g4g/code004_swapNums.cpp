#include <iostream>

int main()
{
	int a=10, b=250;
	std::cout << "Input: a = " << a << ", b = " << b << '\n';
	int temp;
	temp=a;
	a=b;
	b=temp;
	std::cout << "Output: a = " << a << ", b = " << b << '\n';
	return 0;

}
