#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

double memo[101][10];
int n, k;

double dp(int len, int last) {
    double &ans = memo[len][last];

    if(ans >= 0) {
        return ans;
    }

    if(k == 0 or k == 1) {
        return ans = 1.0/(k+1);
    }

    if(len == 1) {
        return ans = 1.0/double(k+1);
    }

    if(last == k) {
        return ans = (dp(len-1, k) + dp(len-1, k-1))/double(k+1);
    }
    if(last == 0) {
        return ans = (dp(len-1, 0) + dp(len-1, 1))/double(k+1);
    }

    return ans = (dp(len-1, last) + dp(len-1, last-1) + dp(len-1, last+1))/double(k+1);
}

void solve() {
    for(int i=0; i<101; i++) {
        for(int j=0; j<10; j++) {
            memo[i][j] = -1.0;
        }
    }

    double ans = 0;

    for(int i=0; i<=k; i++) {
        ans += dp(n, i);
    }

    cout << fixed << setprecision(9) << 100*ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> k >> n)
        solve();
    return 0;
}