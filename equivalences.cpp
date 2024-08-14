#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int n, m;
vi g[20010];
int visited[20010];
int dfs_num[20010], dfs_low[20010];
stack<int> s;
int idx, cnt;
int component;
vi leaf, leaf_vertex;
vi root;
void tarjanSCC(int i) {
    visited[i] = -1;
    dfs_num[i] = idx++;
    dfs_low[i] = dfs_num[i];
    s.push(i);

    for(int v: g[i]) {
        if(!visited[v]) {
            tarjanSCC(v);
        }
        if(visited[v] == -1){
            dfs_low[i] = min(dfs_low[i], dfs_low[v]);
        }
        if(visited[v] > 0) {
            leaf_vertex[i] = false;
            root[visited[v]] = false;
        }
    }

    if(dfs_low[i] == dfs_num[i]) {
        cnt++;
        while(!s.empty()) {
            int aux = s.top();
            visited[aux] = component;
            if(!leaf_vertex[aux]) {
                leaf_vertex[i] = false;
            }
            s.pop();
            if(i == aux) {
                break;
            }
        }
        if(!leaf_vertex[i]) {
            leaf[component] = false;
        }
        component++;
    }
    
}

void solve() {
    for(auto &v: g) {
        v.clear();
    }
    memset(visited, 0, sizeof visited);
    
    while(m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    idx = cnt = 0;
    component = 1;
    leaf.assign(n+1, 1);
    leaf_vertex.assign(n+1, 1);
    root.assign(n+1, 1);
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            tarjanSCC(i);
        }
    }
    int nLeaf = 0, nRoot = 0;
    for(int i=1; i<=cnt; i++) {
        if(leaf[i]) {
            nLeaf++;
        }
        if(root[i]) {
            nRoot++;
        }
    }
    if(cnt == 1) {
        cout << 0 << '\n';
        return;
    }
    cout << max(nLeaf, nRoot) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    while(cases--) {
        cin >> n >> m;
        if(n == 0) break;
        solve();
    }

    return 0;
}