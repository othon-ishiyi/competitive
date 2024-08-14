#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vector<ii> g[10010];
int visited[10010];
int dfs_order[10010], dfs_low[10010], parent[10010];
int idx;
int n, m, q;

void bridge(int v) {
    visited[v] = 1;
    dfs_order[v] = idx++;
    dfs_low[v] = dfs_order[v];
    int p = 0;
    int* p_edge;
    for(auto &[i, b]: g[v]) {
        if(!visited[i]) {
            parent[i] = v;
            bridge(i);
            dfs_low[v] = min(dfs_low[v], dfs_low[i]);
            if(dfs_low[i] > dfs_order[v]) {
                b = true;
            }
        }
        else if(i != parent[v]) {
            dfs_low[v] = min(dfs_low[v], dfs_order[i]);
        }
        else {
            p = i;
            p_edge = &b;
        }
    }
    
    if(p) {
        if(dfs_low[v] > dfs_order[p]) {
            *p_edge = true;
        }
    }
}

void dfs(int v) {
    visited[v] = idx;
    for(auto &[i, b]: g[v]) {
        if(!visited[i] and b) {
            dfs(i);
        }
    }
}

void solve() {
    memset(visited, 0, sizeof visited);
    memset(parent, 0, sizeof parent);
    for(auto &v: g) {
        v.clear();
    }

    while(m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, 0});
        g[b].push_back({a, 0});
    }

    idx = 0;
    for(int i=1; i<=n; i++) {
        if(!visited[i]){
            bridge(i);
        }
    }

    memset(visited, 0, sizeof visited);
    idx = 1;

    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            dfs(i);
            idx++;
        }
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        if(visited[a] == visited[b]) {
            cout << "Y\n";
        }
        else {
            cout << "N\n";
        }
    }
    cout << "-\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n >> m >> q) {
        if(n == 0) break;
        solve();
    }
    return 0;
}