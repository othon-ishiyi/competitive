#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int n;
int m, b, p;
vector<pair<int, ll>> g[1001];
vll dist(1001, LONG_LONG_MAX);

void djikstra() {
    dist[n] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, n});

    while(!pq.empty()) {
        auto t = pq.top(); pq.pop();
        ll d = -t.first;
        int v = t.second;
        for(auto &[i, w]: g[v]) {
            if(dist[i] > d + w) {
                dist[i] = d + w;
                pq.push({-dist[i], i});
            }
        }
    }
}

void solve() {
    set<int> banks;
    for(auto &v: g) v.clear();
    dist.assign(1001, LONG_LONG_MAX);

    while(m--) {
        int u,v;
        ll t;
        cin >> u >> v >> t;
        g[u].push_back({v, t});
        g[v].push_back({u, t});
    } 
    while(b--) {
        int u;
        cin >> u;
        banks.insert(u);
    }
    while(p--) {
        int u;
        cin >> u;
        g[n].push_back({u, 0});
        g[u].push_back({n, 0});
    }

    ll ans = 0;
    int cnt = 0;
    vi list;
    djikstra();
    for(int i=0; i<n; i++) {
        if(banks.count(i)) {
            if(ans < dist[i]) {
                ans = dist[i];
                cnt = 1;
                list.clear();
                list.push_back(i);
            }
            else if(ans == dist[i]) {
                cnt++;
                list.push_back(i);
            } 
        }
    }

    if(ans == LONG_LONG_MAX) {
        cout << cnt << " *\n";
        for(int i=0; i<list.size()-1; i++) {
            cout << list[i] << ' ';
        }
        cout << list.back() << '\n';
    }
    else {
        cout << cnt << ' ' << ans << '\n';
        for(int i=0; i<list.size()-1; i++) {
            cout << list[i] << ' ';
        }
        cout << list.back() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> m >> b >> p)
        solve();
    return 0;
}