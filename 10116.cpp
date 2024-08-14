#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int n, m;
ii g[11][11];
int visited[11][11];
string grid[11];
int start;

bool cycle = false;
int cycle_size;

vector<ii> moves(26);

ii move(char c) {
    return moves[c-'A'];
}

int dfs(ii p) {
    int x=p.first, y=p.second;
    visited[x][y] = 1;
    ii next = g[x][y];

    if(visited[next.first][next.second]) {
        visited[next.first][next.second] = 2;
        cycle = true;
        return 1;
    }

    if(next.first == 0 and next.second == 0) {
        return 1;
    }

    int ans = dfs(next) + 1;

    if(visited[x][y] == 2) {
        cycle_size = ans;
    }

    return ans;
}

void solve() {
    memset(visited, 0, sizeof visited);
    cycle = false;
    for(auto &s: grid) {
        s.clear();
    }

    for(int i=1; i<=n; i++) {
        cin >> grid[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            ii mv = move(grid[i][j-1]);
            int u=i+mv.first, v=j+mv.second;
            if(u <= 0 or u>n or v<=0 or v>m) {
                g[i][j] = {0, 0};
            }
            else {
                g[i][j] = {u, v};
            }
        }
    }

    int ans = dfs({1, start});

    if(cycle) {
        cout << ans-cycle_size << " step(s) before a loop of " << cycle_size << " step(s)\n";
    }
    else {
        cout << ans << " step(s) to exit\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    moves['N'-'A'] = {-1, 0};
    moves['S'-'A'] = {1, 0};
    moves['W'-'A'] = {0, -1};
    moves['E'-'A'] = {0, 1};

    while(true) {
        cin >> n >> m >> start;
        if(n == 0) break;
        solve();
    }

    return 0;
}