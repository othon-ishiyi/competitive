#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

ld t, s, d;

ld diff(ld m) {
    ld new_speed = -m;
    return d - new_speed * t;
}

void solve() {
    cin >> t >> s >> d;

    t *= 24*3600;
    d *= 1000000;

    ld lo = ld(-1e9), hi = ld(1e9);
    int rep = 100;

    while(rep--) {
        ld m = (lo+hi)/2;
        if(diff(m) < 0) {
            lo = m;
        }
        else {
            hi = m;
        }
    }

    if(hi < 0) {
        int ans = int(abs(hi));
        if(ans > 0)
            cout << "Remove " << ans << " tons\n";
        else
            cout << "Add " << ans << " tons\n";
    }
    else {
        int ans = int(hi);
        cout << "Add " << ans << " tons\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n--)
        solve();
    return 0;
}