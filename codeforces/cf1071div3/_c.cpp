#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> a(n);
    long long min_val = 2e18; // Large enough for constraints

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < min_val) {
            min_val = a[i];
        }
    }

    // Option 1: Reduce all elements to 0
    // k can be at most the smallest element to satisfy x >= k
    long long option1 = min_val;

    // Option 2: Reduce all elements to min_val
    // k can be at most the smallest difference (a[i] - min_val)
    long long option2 = 2e18;
    bool has_greater = false;
    for (int i = 0; i < n; i++) {
        if (a[i] > min_val) {
            option2 = min(option2, a[i] - min_val);
            has_greater = true;
        }
    }

    if (!has_greater) {
        // All elements are already equal
        cout << min_val << endl;
    } else {
        // Maximize k between the two strategies
        cout << max(option1, option2) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}