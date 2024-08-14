#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

ll memo[31];

ll fill(int n) {
    ll &ans = memo[n];
    if(ans != -1) return ans;
    if(n % 2) return ans = 0;
    if(n == 0)
        return ans = 1;
    if(n == 2) {
        return ans = 3;
    }
    ans = fill(n-2);
    while(n) {
        n -= 2;
        ans += 2*fill(n);   
    }
    return ans;
}

void solve() {
    int n;
    memset(memo, -1, sizeof memo);

    while(cin >> n) {
        if(n == -1) return;
        cout << fill(n) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}