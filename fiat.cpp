#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vll factorial(200010, 1);
ll mod = (1e9) + 7;

ll pot(ll n, ll k) {
    if(k == 0) return 1;
    if(k == 1) return n;
    if(k % 2) return (n*pot(n, k-1))%mod;
    ll aux = pot(n, k/2);
    return (aux*aux)%mod;
}

ll inv(ll n) {
    return pot(n, mod-2);
}

ll comb(ll n, ll k) {
    ll ans = (factorial[n]*inv(factorial[k])) % mod;
    return (ans * inv(factorial[n-k])) % mod;
}

void solve() {
    ll n;
    cin >> n;
    for(int i=1; i<=2*n; i++) {
        factorial[i] = (factorial[i-1]*i) % mod;
    }

    ll ans = (comb(2*n, n) * inv(n+1)) % mod;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}