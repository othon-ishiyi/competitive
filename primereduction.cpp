#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

ll _sieve_size;
vll primes;
ll n;
bitset<10000010> bs;

void sieve(ll upperbound) {
    _sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i=0; i<_sieve_size; i++) {
        if(bs[i]) {
            for(ll j=i*i; j<_sieve_size; j+=i) {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

ll reduce(ll n) {
    ll ans = 0;
    for(ll p: primes) {
        if(p*p > n) break;
        while(n % p == 0) {
            n /= p;
            ans += p;
        }
    }
    if(n > 1) {
        ans += n;
    }
    return ans;
}

void solve() {
    int i = 1;
    int r = reduce(n);
    while(r != n) {
        n = r;
        r = reduce(n);
        i++;
    }


    cout << n << ' ' << i << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(100000);
    while(cin >> n) {
        if(n == 4) break;
        solve();
    }

    return 0;
}