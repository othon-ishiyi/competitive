#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ii> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());

    multiset<int, greater<int>> s;

    for(int i=0; i<k; i++) {
        s.insert(0);
    }

    int ans = 0;

    for(auto p: v) {
        if(p.second > *s.rbegin()) {
            auto ub = s.upper_bound(p.second);
            s.erase(ub);
            s.insert(p.first);
            ans++;
        }
    }
    
    cout << ans << '\n';


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}