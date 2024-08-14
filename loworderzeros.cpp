#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    vll ans(1000001, 0);
    ll d = 1;
    for(ll i=1; i<1000001; i++) {
        d *= i;
        while(d % 10 == 0) d /= 10;
        d = d % 100000000000;
        ans[i] = d;
    }

    int n;
    while(cin >> n) {
        if(n == 0) break;
        cout << ans[n] % 10 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}