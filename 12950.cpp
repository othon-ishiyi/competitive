    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef vector<vector<int>> vvi;
    typedef pair<int,int> ii;
    typedef pair<ll,int> li;

    int n, m;
    vector<pair<int ,ll>> g[10001];
    vll dist[2];

    void djikstra() {
        dist[0][1] = 0;
        priority_queue<li> pq[2];
        pq[0].push({0, 1});

        int it = 0;
        while(!pq[0].empty() or !pq[1].empty()) {
            auto t = pq[it].top(); pq[it].pop();
            ll d = -t.first;
            int v = t.second;
            for(auto &[i, w] : g[v]) {
                if(dist[1-it][i] > d + w) {
                    dist[1-it][i] = d + w;
                    pq[1-it].push({-d-w, i});
                }
            }
            if(pq[it].empty())
                it = 1 - it;
        }
    }

    void solve() {
        for(auto &v: g) {
            v.clear();
        }

        dist[0].assign(10001, LONG_LONG_MAX);
        dist[1].assign(10001, LONG_LONG_MAX);

        while(m--) {
            int u,v;
            ll d;
            cin >> u >> v >> d;   
            g[u].push_back({v, d});
            g[v].push_back({u,d});
        } 

        djikstra();

        if(dist[0][n] == LONG_LONG_MAX) {
            cout << "-1\n";
        }
        else {
            cout << dist[0][n] << '\n';
        }
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        while(cin >> n >> m) {
            if(n == 0) break;
            solve();
        }
        
        return 0;
    }