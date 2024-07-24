#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int n;
vector<ii> v(100);
int memo[100][100];

int dp(int i, int balls) {
    if(i == n) {
        return 0;
    }
    int &ans = memo[i][balls];

    if(ans != -1) return ans;

    if(balls >= n-i) {
        ans = 0;
        for(int u=i; u<n; u++) {
            ans += v[u].first/2;
        }
        return ans;
    }

    ans = INT_MAX;
    int b = v[i].second;
    int t = v[i].first;
    if(balls >= 1)
        ans = min(ans, dp(i+1, balls + b - 1) + t/2);
    ans = min(ans, dp(i+1, balls + b) + t);
    return ans;
}

void solve() {
    memset(memo, -1, sizeof memo);
    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    cout << dp(0, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n) {
        if (n==0) break;
        solve();
    }
        
    return 0;
}