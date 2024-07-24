#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define LSOne(x) ((x) & -(x))

ll memo[17][70000];
int kll[17][17];
int n;

ll dp(int i, int mask) {
    ll &ans = memo[i][mask];
    if(ans != -1) return ans;

    if(mask == 0) {
        return ans = 1;
    }

    ans = 0;
    for(int m=mask; m; m -= LSOne(m)) {
        int lsone = LSOne(m);
        int j = __builtin_ctz(lsone) + 1;

        int k = (1 << n) - mask - 1;

        if(kll[0][j] == 1) {
            ans += dp(j, mask-lsone);
            continue;
        }
        for(; k; k -= LSOne(k)) {
            int u = __builtin_ctz(LSOne(k)) + 1;
            if(kll[u][j] == 1) {
                ans += dp(j, mask-lsone);
                break;
            }
        }
    }
    return ans;
}

void solve() {
    for(int i=0; i<17; i++) {
        for(int j=0; j<70000; j++) {
            memo[i][j] = -1;
        }
    }
    memset(kll, 0, sizeof kll);
    cin >> n;

    for(int i=0; i<=n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {   
            kll[i][j+1] = s[j] - '0';
        }
    }

    cout << dp(0, (1 << n)-1) << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        cout << "Case " << i+1 << ": ";
        solve();
    }
    return 0;
}