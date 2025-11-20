// NOT FINISHED YET

#include<iostream>
#include<vector>

int main()
{
    int t;
    std::cin >> t;
    std::vector<std::pair<int, std::vector<int>>> results;

    while(t--)
    {
        int a, b;
        std::cin >> a >> b;
        int x = a ^ b;

        if (a == b)
            results.push_back({0, {}});

        if (x < a)
            results.push_back({1, {x}});
        else
        {
            int iter = x/a;
            if (iter+1>100)
                results.push_back({-1, {}});
            else
                results.push_back({iter+1, {}});
                int rem = x;
                for (int i=0; i<iter+1; i++)
                {
                    int x_temp = x/(iter+1);
                    rem = x - x_temp;
                    results.push_back({-1, {}});

                }
        }
    }

    for (auto& res : results)
    {
        std::cout << res.first << "\n";
        for (int val : res.second) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}