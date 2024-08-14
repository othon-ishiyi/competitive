#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

ll _sieve_size;
bitset<10000010> bs;
vi p;
ll n;

void sieve(ll upperbound) {
    _sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i=0; i<_sieve_size; i++) {
        if(bs[i]) {
            for(ll j=i*i; j<_sieve_size; j+=i) {
                bs[j] = 0;
            }
            p.push_back(i);
        }
    }
}

void solve() {
    auto lb = lower_bound(p.begin(), p.end(), n);
    if(*lb == n) {
        cout << 0 << '\n';
        return;
    }
    cout << *lb - *(lb-1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(2000000);

    while(cin >> n) {
        if(n == 0) break;
        solve();
    }
    
    return 0;
}