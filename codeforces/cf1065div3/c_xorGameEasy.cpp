#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main()
{
    int t;
    std::cin >> t;
    std::vector<std::string> results(t);

    for (int i = 0; i < t; ++i)
    {
        int n;
        std::cin >> n;
        std::string a = "", b = "";

        for (int j=0; j< n; j++)
        {
            std::cin >> a[j];
        }
        for (int j=0; j< n; j++)
        {
            std::cin >> b[j];
        }

        std::string Xor = "";
        for (int j=0; j< n; j++)
        {
            if (a[j] == b[j])
                Xor += '0';
            else
                Xor += '1';
        }

        int a_result = 0, b_result = 0;

        // Count '1's in odd positions (1, 3, 5, ...)
        for (size_t j=1; j < Xor.length(); j+=2)
        {
            if (Xor[j] == '1')
                b_result++;
        }

        // Count '1's in even positions (0, 2, 4, ...)
        for (size_t j=0; j < Xor.length(); j+=2)
        {
            if (Xor[j] == '1')
                a_result++;
        }

        if (a_result == b_result)
            results[i] = "Tie";
        else if (a_result > b_result)
            results[i] = "Ajisai";
        else
            results[i] = "Mai";    

    }

    for (const auto& result : results)
    {
        std::cout << result << std::endl;
    }

    return 0;
}