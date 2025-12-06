#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

int main()
{
    int t;
    std::cin >> t;
    std::vector<long long> finalScore(t, 0);

    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
        }
        for (int j = 0; j < n; j++) {
            std::cin >> b[j];
        }
        long long currentMax = 0, currentMin = 0;
        for (int j = 0; j < n; j++) {
            long long redMax = currentMax - a[j];
            long long redMin = currentMin - a[j];
            long long blueMax = b[j] - currentMax;
            long long blueMin = b[j] - currentMin;
            currentMax = std::max(std::max(redMax, redMin), std::max(blueMax, blueMin));
            currentMin = std::min(std::min(redMax, redMin), std::min(blueMax, blueMin));
        }
        finalScore[i] = currentMax;
    }
    for (int i = 0; i < t; i++) {
        std::cout << finalScore[i] << std::endl;
    }


    return 0;
}