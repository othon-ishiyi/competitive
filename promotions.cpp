#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vi g[5010], par[5010];
vi visited;
vi degree;
queue<int> zero_in;
int n;
int cnt;

void dfs_up(int i) {
    visited[i] = 1; 
    for(int v: par[i]) {
        if(!visited[v]) {
            dfs_up(v);
        }
    }
    cnt++;
}

void topsort(int ignore, queue<int> zero, vi degree) {
    while(!zero.empty()) {
        int v = zero.front();
        cnt++;
        zero.pop();

        if(v == ignore) {
            continue;
        }

        for(int next: g[v]) {
            degree[next]--;
            if(degree[next] == 0) {
                zero.push(next);
            }
        }
    }
}

int get_min(int i) {
    visited.assign(n, 0);
    cnt = 0;
    dfs_up(i);
    return cnt;
}

int get_max(int i) {
    cnt = 0;
    topsort(i, zero_in, degree);
    return cnt;
}

void solve() {
    int a, b, m;
    cin >> a >> b >> n >> m;
    visited.assign(n, 0);
    degree.assign(n, 0);

    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        par[v].push_back(u);
        degree[v]++;
    }

    for(int i=0; i<n; i++) {
        if(par[i].size() == 0) {
            zero_in.push(i);
        }
    }

    int ans1=0, ans2=0, ans3=0;

    for(int i=0; i<n; i++) {
        int max_rank = get_max(i);
        int min_rank = get_min(i);

        if(max_rank <= a) ans1++;
        if(max_rank <= b) ans2++;
        if(min_rank > b) ans3++;
    }
    cout << ans1 << '\n' << ans2 << '\n' << ans3 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}