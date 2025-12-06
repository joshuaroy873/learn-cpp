#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
// #include <algorithm>

int main() {
    int r, n;
    std::cin >> r >> n;
    std::vector<std::pair<int, int>> points(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> points[i].first >> points[i].second;
    }

    int m, c;
    float costMin = INFINITY;
    int mMin, cMin;

    for (int i=0; i<n; ++i)
    {
        for (int j=i+1; j<n; ++j)
        {

            m = (points[j].second - points[i].second) / (points[j].first - points[i].first);
            c = points[i].second - m * points[i].first;

            std::vector<float> d(n);
            std::vector<int> sign(n);
            for (int k=0; k<n; ++k)
            {
                d[k] = ( m*points[k].first - points[k].second + c ) / sqrt(m*m+1);
                sign[k] = d[k]/abs(d[k]);
            }
            if ( abs(std::accumulate(sign.begin(), sign.end(), 0)) != n-2)
            {
                continue;
            }
            else
            {
                if (std::accumulate(d.begin(), d.end(), 0.0f) < costMin)
                {
                    costMin = std::accumulate(d.begin(), d.end(), 0.0f);
                    mMin = m;
                    cMin = c;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    
    
}