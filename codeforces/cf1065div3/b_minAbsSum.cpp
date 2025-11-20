#include<iostream>
#include<vector>

int main()
{
    int t;
    std::cin >> t;
    std::vector<int> results(t);
    std::vector<std::vector<int>> vectors;

    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;
        std::vector<int> a(n);

        for (int j = 0; j < n; j++)
        {
            std::cin >> a[j];
        }

        if (a[0] == -1 && a[n-1] == -1) {
            results[i] = 0;
            a[0] = 0; a[n-1] = 0;
            for (int j = 1; j < n-1; j++) {
                if (a[j] == -1) {
                    a[j] = 0;
                }
            }
        } 
        else if (a[0] == -1 && a[n-1] != -1) {
            results[i] = 0;
            a[0] = a[n-1];
            for (int j = 1; j < n-1; j++) {
                if (a[j] == -1) {
                    a[j] = 0;
                }
            }
        } 
        else if (a[0] != -1 && a[n-1] == -1) {
            a[n-1] = a[0];
            results[i] = 0;
            for (int j = 1; j < n-1; j++) {
                if (a[j] == -1) {
                    a[j] = 0;
                }
            }
        }
        else {
            results[i] = std::abs(a[0] - a[n-1]);
            for (int j = 1; j < n-1; j++) {
                if (a[j] == -1) {
                    a[j] = 0;
                }
            }
        }

        vectors.push_back(a);

    }

    for (int i = 0; i < t; i++)
    {
        std::cout << results[i] << "\n";
        for (int val : vectors[i]) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}