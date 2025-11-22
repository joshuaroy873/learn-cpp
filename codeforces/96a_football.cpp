#include<iostream>
#include<string>

int main()
{
    std::string input;
    std::cin >> input;
    size_t flag0 = input.find("0000000"), flag1 = input.find("1111111");
    if (flag0 != std::string::npos || flag1 != std::string::npos)
        std::cout << "YES";
    else
        std::cout << "NO";

    return 0;
}