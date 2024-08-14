#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define LMAX 2e17

int n, m, start, target;
ll p;
vector<pair<int, ll>> g1[10001], g2[10001];
vll dist1(10001, LMAX);
vll dist2(10001, LMAX);

void djikstra1(int s) {
    dist1[s] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        auto t = pq.top(); pq.pop();
        ll d = -t.first;
        int v = t.second;
        for(auto &[i, w]: g1[v]) {
            if(dist1[i] > d + w) {
                dist1[i] = d + w;
                pq.push({-dist1[i], i});
            }
        }
    }
}

void djikstra2(int s) {
    dist2[s] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        auto t = pq.top(); pq.pop();
        ll d = -t.first;
        int v = t.second;
        for(auto &[i, w]: g2[v]) {
            if(dist2[i] > d + w) {
                dist2[i] = d + w;
                pq.push({-dist2[i], i});
            }
        }
    }
}

void solve() {
    for(auto &v: g1) v.clear();
    for(auto &v: g2) v.clear();
    dist1.assign(10001, LMAX);
    dist2.assign(10001, LMAX);

    while(m--) {
        int u,v;
        ll d;
        cin >> u >> v >> d;
        g1[u].push_back({v, d});
        g2[v].push_back({u, d});
    } 


    djikstra1(start);
    djikstra2(target);

    if(dist1[target] > p) {
        cout << "-1\n";
        return;
    }

    int ans = -1;
    for(int u=1; u<=n; u++) {
        for(auto [v, w]: g1[u]) {
            if(dist1[u] + dist2[v] + w <= p) {
                ans = max(ans, int(w));
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    while(cases--) {
        cin >> n >> m >> start >> target >> p;
        solve();
    }
        
    return 0;
}