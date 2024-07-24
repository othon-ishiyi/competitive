#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int,int>>

using namespace std;


void solve() {
    multiset<ll> m;
    int N;
    cin >> N;
    ll A, B, C, X, Y = 0;

    cin >> A >> B >> C;
    cin >> X >> Y;
    ll S = A;
    
    m.insert(S);

    while(--N) {
        S = (S*B + A)%C;
        m.insert(S);
    }

    ll V=0;


    for(auto u: m){
        V = (V*X+u)%Y;
    }

    cout << V << '\n'; 
}

int main() {
    int N;
    cin >> N;
    while(N--)
        solve();
    return 0;
}