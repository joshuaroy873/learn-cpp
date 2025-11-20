#include<iostream>
#include<string>

int main() {
	int n;
	std::cin >> n;
	for (int i=0; i<n; i++) {
		std::string term;
		std::cin >> term;
		if (term.length()>10)
		{
			term = term[0] + std::to_string(term.length()-2) + term.back();
			std::cout << term << "\n";
		}
		else std::cout << term << "\n";
	}
	return 0;
}
