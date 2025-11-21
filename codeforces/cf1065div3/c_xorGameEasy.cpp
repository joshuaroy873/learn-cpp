#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<string> results(t);
    for (int test = 0; test < t; test++)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<int> Xor(n);
        int XorSum = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
        {
            XorSum = XorSum ^ a[i] ^ b[i];
            Xor[i] = a[i] ^ b[i];
        }
        if (XorSum)
        {
            for (int i = n-1; i>=0; i--)
            {
                if (Xor[i]==1 && i%2==0)
                {
                    results[test] = "Ajisai";
                    break;
                }
                if (Xor[i]==1 && i%2==1) 
                {
                    results[test] = "Mai";
                    break;
                }
            }
        }
        else results[test] = "Tie";
    }

    for (auto& res:results)
        cout << res << '\n';

    return 0;
}