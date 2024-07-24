#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int n, t;
    cin >> n >> t;

    vector<ii> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());
    priority_queue<int> pq;

    auto it=v.rbegin();
    int ans = 0;
    for(int u=t-1; u>=0; u--) {
        while(it != v.rend() and it->first == u) {
            pq.push(it->second);
            it++;
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
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