#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef pair<int,int> ii;

vector<pair<int, ll>> g_djikstra[100010];
vi g[100010];
vll d(100010, LONG_LONG_MAX);
vector<pair<int, ll>> p_djikstra[100010];
vi visited(100010, 0);
int start, last;

vi parent(100010, 0);
vi dfs_order(100010, 0);
vi dfs_low(100010, 0);
vi art(100010, 0);
vi seq(100010, 0);
int idx = 0;
int root_children = 0;

void articulation(int i) {
    visited[i] = 1;
    dfs_order[i] = idx++;
    dfs_low[i] = dfs_order[i];
    for(int v: g[i]) {
        if(visited[v] and v != parent[i]) {
            dfs_low[i] = min(dfs_low[i], dfs_order[v]);
        }
        if(!visited[v]) {
            if(i == 1) root_children++;
            parent[v] = i;
            articulation(v);
            dfs_low[i] = min(dfs_low[i], dfs_low[v]);
            if(dfs_order[i] <= dfs_low[v])
                art[i] = true;
        }
    }
}

void djikstra(int start) {
    d[start] = 0LL;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        auto p = pq.top();
        ll min_dist = p.first;
        int idx = p.second;
        pq.pop();

        for(auto i: g_djikstra[idx]) {
            if(i.second + min_dist < d[i.first]) {
                d[i.first] = i.second + min_dist;
                pq.push({d[i.first], i.first});
                p_djikstra[i.first].clear();
                p_djikstra[i.first].push_back({idx, i.second});
            }
            else if(i.second + min_dist == d[i.first]) {
                p_djikstra[i.first].push_back({idx, i.second});
            }
        }
    }
}

void create_g(int v) {
    seq[v] = 1;
    for(auto &[i, w]: p_djikstra[v]) {
        g[i].push_back(v);
        g[v].push_back(i);
        if(!seq[i]) {
            create_g(i);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        g_djikstra[a].push_back({b, w});
        g_djikstra[b].push_back({a, w});
    }

    cin >> start >> last;

    djikstra(start);

    create_g(last);

    articulation(last);

    vi ans;

    ans.push_back(start);
    ans.push_back(last);

    for(int i=0; i<n; i++) {
        if(art[i] and i != start and i != last) {
            ans.push_back(i);
        }
    }
    
    sort(ans.begin(), ans.end());
    for(auto i: ans) {
        cout << i << ' ';
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}