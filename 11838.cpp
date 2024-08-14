#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int n, m;
vi g[2001];
int visited[2001];
int dfs_num[2001], dfs_low[2001];
stack<int> s;
int idx, cnt;
void tarjanSCC(int i) {
    visited[i] = 1;
    dfs_num[i] = idx++;
    dfs_low[i] = dfs_num[i];
    s.push(i);

    for(int v: g[i]) {
        if(!visited[v]) {
            tarjanSCC(v);
        }
        if(visited[v] == 1){
            dfs_low[i] = min(dfs_low[i], dfs_low[v]);
        }
    }

    if(dfs_low[i] == dfs_num[i]) {
        cnt++;
        while(!s.empty()) {
            int aux = s.top();
            visited[aux] = 2;
            s.pop();
            if(i == aux) {
                break;
            }
        }
    }
    
}

void solve() {
    for(auto &v: g) {
        v.clear();
    }
    memset(visited, 0, sizeof visited);
    idx = 0;
    cnt = 0;
    while(m--) {
        int a, b, p;
        cin >> a >> b >> p;
        g[a].push_back(b);
        if(p == 2) {
            g[b].push_back(a);
        }
    }

    
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            tarjanSCC(i);
        }
    }

    if(cnt == 1) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
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