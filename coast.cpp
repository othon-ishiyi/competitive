
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vector<ii> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};

string grid[1010];
int visited[1010][1010];
int margin[1010][1010];

int n, m;

bool valid(int x, int y) {
    if(x >= 0 and x <= m+1 and y >=0 and y<=n+1) {
        if(grid[x][y] == '0') {
            if(!visited[x][y]) 
                return true;
        }
    }
    return false;
}

void dfs(int x, int y) {
    visited[x][y] = 1;

    for(auto &[i, j] : moves) {
        int u = x+i, v = y+j;
        if(u>=0 and u<=m+1 and v>=0 and v<=n+1)
            margin[u][v]++;
    }

    for(auto &[i, j] : moves) {
        int u = x+i, v = y+j;
        if(valid(u, v)) {
            dfs(u, v);
        }
    }
}

void solve() {
    memset(visited, 0, sizeof visited);
    memset(margin, 0, sizeof margin);

    for(int i=1; i<=m; i++) {
        string s;
        cin >> s;
        grid[i] = "0"+s+"0";
    }

    grid[0] = grid[m+1] = string(n+2, '0');

    int ans = 0;
    dfs(0, 0);

    for(int i=0; i<=m+1; i++) {
        for(int j=0; j<=n+1; j++) {
            if(grid[i][j] == '1') {
                ans += margin[i][j];
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    solve();
    return 0;
}