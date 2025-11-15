#include <iostream>

int main()
{
	char char_char;
	int char_int;
	std::cout << "Input Character: ";
	std::cin >> char_char;
	char_int = char_char;
	std::cout << "\nASCII value of '" << char_char << "' = " << char_int << "\n";
	return 0;

}
