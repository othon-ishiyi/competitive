//! Another solution using meet in the middle technique in bagoftiles2.cpp

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int memo[31][10010][31];
ll comb[31][31];
int value[31];
int n, t, k;

int dp(int i, int val, int cnt) {
    if(val < 0) {
        return 0;
    }
    int &ans = memo[i][val][cnt];
    if(ans != -1) {
        return ans;
    }
    if(cnt == k) {
        return ans = (val == 0);
    }
    if(i == n) {
        return 0;
    }
    return ans = dp(i+1, val, cnt) + dp(i+1, val-value[i], cnt+1);
}

ll dp_comb(int n, int k) {
    ll &ans = comb[n][k];
    if(ans != -1) {
        return ans;
    }
    if(k == 0) {
        return ans = 1;
    }
    return ans = dp_comb(n, k-1)*ll(n-k+1)/ll(k);
}


void solve() {
    for(int i=0; i<31; i++) {
        for(int j=0; j<10010; j++) {
            for(int u=0; u<31; u++)
                memo[i][j][u] = -1;
        }
    }
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> value[i];
    }
    cin >> k >> t;
    int sol = dp(0, t, 0);
    ll total = dp_comb(n, k);
    cout << sol << " : " << total - sol << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i=0; i<31; i++) {
        for(int j=0; j<31; j++) {
            comb[i][j] = -1;
        }
    }
    for(int i=1; i<=N; i++) {
        cout << "Game " << i << " -- ";
        solve();
    }
        
    return 0;
}