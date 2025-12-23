#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Calculate the total sum of absolute differences of the original array
    long long total_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        total_sum += abs(a[i] - a[i + 1]);
    }

    // Try removing the first element
    long long max_reduction = abs(a[0] - a[1]);

    // Try removing the last element
    max_reduction = max(max_reduction, (long long)abs(a[n - 2] - a[n - 1]));

    // Try removing any middle element k (indices are 0-based, so 1 to n-2)
    for (int k = 1; k < n - 1; k++) {
        long long current_diffs = abs(a[k - 1] - a[k]) + abs(a[k] - a[k + 1]);
        long long new_diff = abs(a[k - 1] - a[k + 1]);
        long long reduction = current_diffs - new_diff;
        max_reduction = max(max_reduction, reduction);
    }

    // The answer is the original total minus the best reduction found
    cout << total_sum - max_reduction << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}