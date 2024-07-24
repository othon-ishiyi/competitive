#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define LSOne(x) ((x) & -(x))

int h, w;
int x_, y_, n;

int memo[11][1024];

vector<ii> beeper(10);

int dist(ii a, ii b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}


int dp(int idx, int mask) {
    ii pos;
    if(idx == n)
        pos = {x_, y_};
    else {
        pos = beeper[idx];
    }

    int x = pos.first, y = pos.second;
    
    int &ans = memo[idx][mask];

    if(ans != -1) return ans;

    if(mask == 0) {
        return ans = dist({x, y}, {x_, y_});
    }

    ans = INT_MAX;

    int i;
    for(int m=mask; m; m -= LSOne(m)) {
        i = LSOne(m);
        int next_idx = __builtin_ctz(i);
        ii next = beeper[next_idx];
        ans = min(ans, dp(next_idx, mask-i) + dist(pos, next));
    }
    return ans;
}

void solve() {
    memset(memo, -1, sizeof memo);

    cin >> h >> w;
    cin >> x_ >> y_ >> n;
    x_--; y_--;

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        beeper[i] = {--a, --b};
    }

    cout << dp(n, (1 << n)-1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    while(N--)
        solve();
    return 0;
}