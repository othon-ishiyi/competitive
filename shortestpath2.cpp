    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef vector<vector<int>> vvi;
    typedef pair<int,int> ii;

    class ed {
    public:
        int v, t0, p;
        ll d;
        ed(int v, ll d, int t0, int p) {
            this->v = v;
            this->d = d;
            this->t0 = t0;
            this->p = p;
        }
    };

    int n, m, s, q;
    vector<ed> g[10001];
    vll dist(10001, LONG_LONG_MAX);

    void djikstra() {
        dist[s] = 0;
        priority_queue<pair<ll, int>> pq;
        pq.push({0, s});

        while(!pq.empty()) {
            auto t = pq.top(); pq.pop();
            ll d = -t.first;
            int v = t.second;
            if(d == dist[v]) {
                for(auto e: g[v]) {
                    int i = e.v;
                    ll w = e.d;
                    ll t0_ = e.t0;
                    ll p_ = e.p;
                    if(d <= t0_ and dist[i] > w + t0_) {
                        dist[i] = t0_ + w;
                        pq.push({-dist[i], i});
                    }
                    else if(p_ > 0 and d > t0_) {
                        ll k = (d-t0_+p_-1)/p_;
                        ll new_d = t0_ + k*p_;
                        if(dist[i] > w + new_d) {
                            dist[i] = new_d + w;
                            pq.push({-dist[i], i});
                        }
                    }
                }
            }
        }
    }

    void solve() {
        for(auto &v: g) {
            v.clear();
        }

        dist.assign(10001, LONG_LONG_MAX);

        while(m--) {
            int u,v, a, b;
            ll d;
            cin >> u >> v >> a >> b >> d;   
            g[u].push_back(ed(v, d, a, b));
        } 

        djikstra();

        while(q--) {
            int target;
            cin >> target;
            if(dist[target] == LONG_LONG_MAX) {
                cout << "Impossible\n";
            }
            else {
                cout << dist[target] << '\n';
            }
        }
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        while(cin >> n >> m >> q >> s) {
            if(n == 0) break;
            solve();
            cout << '\n';
        }
        
        return 0;
    }