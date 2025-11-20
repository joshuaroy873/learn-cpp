#include<iostream>
#include<string>

int main() {
	int n; std::cin>>n;
	int x=0;
	for (int i=0; i<n; i++) {
		std::string action; std::cin>>action;
		if (action[1]=='+') x++;
		else x--;
	}
	std::cout<<x;
	return 0;
}
