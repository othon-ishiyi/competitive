#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

ll _sieve_size;
int n;
vll primes;
bitset<1000010> bs;
vi divisors[100030];

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i=0; i<_sieve_size; i++) {
        if(bs[i]) {
            for(ll j = i*i; j<_sieve_size; j+=i) {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

void getdivisors(ll upperbound) {
    _sieve_size = upperbound+1;
    for(ll i=2; i<_sieve_size; i++) {
        if(divisors[i].size() == 0) {
            for(ll j=i; j<_sieve_size; j+=i) {
                divisors[j].push_back(i);
            }
        }
    }
}


void solve() {
    ll ans = sum_divisors(n);
    cout << n << ' ';
    if(2*n == ans) {
        cout << "perfect\n";
    }
    else if(abs(2*n-ans) <= 4) {
        cout << "almost perfect\n";
    }
    else
        cout << "not perfect\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(100000);
    getdivisors(100000);

    while(cin >> n)
        solve();
    return 0;
}