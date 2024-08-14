#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define LSOne(x) ((x) & -(x))

int dist[1001][1001];
int d[16][16];
int visited[1001][1001];
vector<ii> points(16);
vector<ii> moves;
int n=1000;
int k;
int memo[17][(1 << 16)+1];

int dp(int i, int mask) {
    int &ans = memo[i][mask];
    if(ans != -1) return ans;
    if(mask == 0) return ans = d[i][0];
    ans = INT_MAX;
    for(int m=mask; m; m-=LSOne(m)) {
        int lsone = LSOne(m);
        int next = __builtin_ctz(lsone);
        if(i != next) {
            ans = min(ans, dp(next, mask-lsone) + d[i][next]);
        }
    }
    return ans;
}

bool isCorner(int x, int y) {
    if((x == 1 or x == n) and (y == 1 or y == n)) return true;
    return false;
}

bool isValid(int x, int y, int sta) {
    if(x>0 and x<=1000 and y>0 and y<=1000) {
        if(!visited[x][y]) {
            return true;
        }
    }
    return false;
}

void bfs() {
    queue<ii> q;
    q.push({1,1});
    visited[1][1] = 1;
    dist[1][1] = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;

        for(auto &[dx, dy]: moves) {
            int u=x+dx, v=y+dy;
            if(isValid(u, v, 0)) {
                q.push({u,v});
                visited[u][v] = true;
                dist[u][v] = dist[x][y] + 1;
            }
        }
    }
}

void solve() {
    for(int i=0; i<k; i++) {
        cin >> points[i].first >> points[i].second;
    }

    for(int i=0; i<k; i++) {
        int xi = points[i].first;
        int yi = points[i].second;
        for(int j=i+1; j<k; j++) {
            int xf = points[j].first;
            int yf = points[j].second;
            int x = abs(xf-xi) + 1;
            int y = abs(yf-yi) + 1;

            int &a = d[i][j];

            if(n >= 5) {
                if(x == 2 and y == 2 and !isCorner(xi, yi) and !isCorner(xf, yf))
                    a = 2;
                else
                    a = dist[x][y];
            }

            if(n == 4) {
                if(x == 2 and y == 2 and !isCorner(xi, yi) and !isCorner(xf, yf))
                    a = 2;
                else if((x == 4 and y == 1) or (x == 1 and y == 4))
                    a = 5;
                else
                    a = dist[x][y];
            }

            d[j][i] = d[i][j];
        }
    }

    memset(memo, -1, sizeof memo);
    cout << dp(0, (1 << k)-2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    moves = {{-2,1}, {2, 1}, {-2, -1},
            {2, -1}, {1, -2}, {1,2},
            {-1, -2}, {-1,2}};

    memset(visited, 0, sizeof visited);
    for(int i=0; i<1001; i++) {
        for(int j=0; j<1001; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    bfs();

    int cases;
    cin >> cases;

    for(int c=1; c<=cases; c++) {
        cin >> n >> k;
        cout << "Case " << c << ": ";
        solve();
    }
    return 0;
}