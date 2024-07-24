#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ii> v(n);
    for(int i=0; i<n; i++) {
        int a, s;
        cin >> a >> s;
        v[i].first = a;
        v[i].second = a+s;
    }

    sort(v.begin(), v.end());
    priority_queue<int, vi, greater<int>> pq;

    int unlock = 0;
    for(auto p: v) {
        while(!pq.empty() and p.first - pq.top() > m) {
            pq.pop();
        }
        if(!pq.empty() and p.first >= pq.top()) {
            pq.pop();
        }
        else {
            unlock++;
        }
        pq.push(p.second);
    }

    cout << n - unlock << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}