#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vll phi;
int _sieve_size;
int n, k;

void sieve(int size) {
    _sieve_size = size + 1;
    phi.assign(_sieve_size, 0);

    for(int i=1; i<_sieve_size; i++) {
        phi[i] = i;
    }

    for(int i=2; i<_sieve_size; i++) {
        if(phi[i] == i) {
            for(int j=i; j<_sieve_size; j+=i) {
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

void solve() {
    ll cnt = 2;
    for(int i=2; i<=n; i++) {
        cnt += phi[i];
    }
    cout << k << ' ' << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(10010);

    int cases;
    cin >> cases;

    while(cases--) {
        cin >> k >> n;
        solve();
    }

    return 0;
}