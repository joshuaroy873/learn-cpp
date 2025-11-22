#include<iostream>
#include<vector>
#include<set>

int main()
{
    int t; std::cin >> t;
    std::vector<int> results(t);
    for (int i=0; i < t; i++)
    {
        int n=0; std::cin >> n;
        std::set<int> current;
        for (int j=0; j<n; j++)
        {
            int value;
            std::cin >> value;
            current.insert(value);
        }
        results[i] = 2*current.size() - 1;
    }
    for (auto& res : results)
        std::cout << res << "\n";
}