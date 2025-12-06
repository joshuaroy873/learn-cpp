#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

int main()
{
    int t;
    std::cin >> t;
    std::vector<int> n(t);
    std::vector<int> k(t);
    std::vector<int> sleep(t);

    for (int i = 0; i < t; i++)
    {
        std::cin >> n[i] >> k[i];
        std::string s;
        std::vector<int> awake(n[i], 0);
        std::cin >> s;
        int j = 0;
        while (j < n[i]) {
            if (s[j] == '1') {
                std::fill(awake.begin()+j, awake.begin()+std::min(j+k[i]+1, n[i]), 1);
                j ++;
            } else {
                j++;
            }
        }
        sleep[i] = std::count(awake.begin(), awake.end(), 0);
    }
    for (int i = 0; i < t; i++) {
        std::cout << sleep[i] << std::endl;
    }
    return 0;
}