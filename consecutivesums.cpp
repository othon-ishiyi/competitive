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

ll lowest_p(ll n) {
    for(auto p: primes) {
        if(p*p > n) break;
        if(n % p == 0) {
            return p;
        }
    }
    return n;
}

void solve() {
    cin >> n;
    ll u = 1, v = 1;
    ll m = n;
    n *= 2;
    while(n % 2 == 0) {
        n /= 2;
        u *= 2;
    }
    if(n == 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    ll p = lowest_p(n);

    if(p > u) {
        v = n;
    }
    else {
        v = p;
        u *= n/p;
    }

    if(u < v) swap(u,v);

    ll a, b;
    a = (u+v-1)/2; b = (u-v+1)/2;

    //cout << u << ' ' << v << '\n';

    cout << m << " =";
    for(ll i=b; i<a; i++) {
        cout << ' ' << i << " +";
    }
    cout << ' ' << a << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    sieve(100000);

    while(cases--)
        solve();
        
    return 0;
}