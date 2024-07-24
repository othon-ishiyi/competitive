#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

ll encrypt(int x, int y){
    return (ll(x) << 31) + y;
}

void solve() {
    unordered_map<ll, int> m;
    ll ans = 0;
    int N;
    cin >> N;
    int x, y;

    while(N--){
        cin >> x >> y;
        ans += m[encrypt(x, y)];
        m[encrypt(x+2018, y)]++;
        m[encrypt(x-2018, y)]++;
        m[encrypt(x, y+2018)]++;
        m[encrypt(x, y-2018)]++;
        m[encrypt(x+1680, y+1118)]++;
        m[encrypt(x+1680, y-1118)]++;
        m[encrypt(x-1680, y+1118)]++;
        m[encrypt(x-1680, y-1118)]++;
        m[encrypt(x+1118, y+1680)]++;
        m[encrypt(x-1118, y+1680)]++;
        m[encrypt(x+1118, y-1680)]++;
        m[encrypt(x-1118, y-1680)]++;
    }

    std::cout << ans;
}

int main() {

    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   

    solve();
    return 0;
}