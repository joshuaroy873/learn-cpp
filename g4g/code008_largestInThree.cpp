#include<iostream>

#define printVarName(var) std::cout << #var << std::endl

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a>b && a>c) printVarName(a);
    else if (b>c) printVarName(b);
    else printVarName(c);

    return 0;
}
