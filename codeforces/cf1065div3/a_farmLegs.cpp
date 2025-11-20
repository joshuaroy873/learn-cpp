#include<iostream>
#include<vector>

int main()
{
    int t;
    std::cin >> t;
    std::vector<int> n(t), results(t);
    for (int i = 0; i < t; ++i)
    {
        std::cin >> n[i];
        if (n[i]%2 != 0)
        {
            results[i] = 0;
        }
        else
        {
            results[i] = n[i]/4 + 1;
        }
    }
    for (int i = 0; i < t; ++i)
    {
        std::cout << results[i] << std::endl;
    }

    return 0;
}