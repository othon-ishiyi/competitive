#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i=0; i<n; i++) {
        ll a;
        cin >> a;
        pq.push(a);
    }

    ll ans = 0;

    while(pq.size() > 1) {
        ll sum_area = 0;
        sum_area += pq.top();
        pq.pop();
        sum_area += pq.top();
        pq.pop();
        ans += sum_area;
        pq.push(sum_area);
    }

    cout << ans << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--)
        solve();
    return 0;
}