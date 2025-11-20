#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<int> p(n+1), pre(n+1, n);
    vector<pair<int, int>> suf(n+2);
    for(int i=1; i<=n; i++){
        cin >> p[i];
        pre[i] = min(pre[i-1], p[i]);
    }
    for(int i=n; i>=1; i--)
        suf[i] = max(suf[i+1], {p[i], i});
    for(int i=2; i<=n; i++)
        if(pre[i-1] > suf[i].first){
            cout << "No" << '\n';
            return;
        }
    cout << "Yes" << '\n';
    for(int l=1; l<=n;){
        int r = suf[l].second;
        for(int i=l; i<r; i++)
            cout << p[i] << ' ' << p[r] << '\n';
        if(l > 1)
            cout << pre[l-1] << ' ' << p[r] << '\n';
        l = r+1;
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}