#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int cnt = 0;
vvi board(15, vi(15, 0));
int n = 1;

bool canPlace(int r, int col) {
    return ((board[r][col] == 1)? false: true);
}

void backtrack(int col, ll rw, ll ld, ll rd) {
    if(col == n) {
        cnt++;
        return;
    }
    ll p;
    for(ll i = ((1ll << n) - 1) & (~(rw | ld | rd)); i; i -= p) {
        p = ((i) & -(i));
        if(canPlace(__builtin_ctzll(p), col)) {
            backtrack(col+1, rw|p, ((ld|p) << 1), ((rd|p) >> 1));
        }
    }
}

void solve() {
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {
            if(s[j] == '*') board[i][j] = 1;
            else board[i][j] = 0;
        }
    }
    backtrack(0, 0ll, 0ll, 0ll);
    cout << cnt << '\n';
    cnt = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i = 1;

    while(true) {
        cin >> n;
        if(n == 0) {
            break;
        }
        cout << "Case " << i << ": ";
        solve();
        i++;
    }
    return 0;
}