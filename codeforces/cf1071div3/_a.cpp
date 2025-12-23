#include <iostream>

using namespace std;

/**
 * Problem Logic:
 * The string is partitioned into x disjoint sets based on index % x.
 * Within each set, all characters must be distinct.
 * Since there are only k available characters, each set can have at most k elements.
 * Max valid length = k * x.
 * Smallest invalid length n = (k * x) + 1.
 */

void solve() {
    long long k, x;
    if (!(cin >> k >> x)) return;
    
    long long result = (k * x) + 1;
    cout << result << endl;
}

int main() {
    // Speed up I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}