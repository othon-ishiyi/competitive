#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int n, m;
vi g[100010];
int visited[100010];
int dfs_num[100010], dfs_low[100010];
stack<int> s;
int idx, cnt;
int component;
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
            root[visited[v]] = false;
        }
    }

    if(dfs_low[i] == dfs_num[i]) {
        cnt++;
        while(!s.empty()) {
            int aux = s.top();
            visited[aux] = component;
            s.pop();
            if(i == aux) {
                break;
            }
        }
        component++;
    }
    
}

void solve() {
    for(auto &v: g) {
        v.clear();
    }
    memset(visited, 0, sizeof visited);
    root.assign(n+1, 1);
    
    while(m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    idx = cnt = 0;
    component = 1;
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            tarjanSCC(i);
        }
    }
    int ans = 0;
    for(int i=1; i<=cnt; i++) {
        if(root[i]) {
            ans++;
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
        cin >> n >> m;
        if(n == 0) break;
        solve();
    }

    return 0;
}