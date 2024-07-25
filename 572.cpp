#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int n, m;
string grid[101];
int visited[101][101];

void dp(int x, int y) {
    visited[x][y] = 1;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int u = x+i, v = y+j;
            if(u>=0 and u<n and v>=0 and v<m) {
                if(!visited[u][v] and grid[u][v] == '@') {
                    dp(u, v);
                }
            }
        }
    }
}

void solve() {
    memset(visited, 0, sizeof visited);
    for(auto &s: grid) {
        s.clear();
    }

    for(int i=0; i<n; i++) {
        cin >> grid[i];
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] and grid[i][j] == '@') {
                dp(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true) {
        cin >> n >> m;
        if(n == 0) break;
        solve();
    }
    
    return 0;
}