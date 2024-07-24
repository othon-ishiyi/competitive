#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    ll v[20][20][20];

    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
            for(int k=0; k<c; k++) {
                cin >> v[i][j][k];
            }
        }
    }

    for(int i=1; i<a; i++) {
        for(int j=0; j<b; j++) {
            for(int k=0; k<c; k++) {
                v[i][j][k] += v[i-1][j][k];
            }
        }
    }

    for(int j=1; j<b; j++) {
        for(int i=0; i<a; i++) {
            for(int k=0; k<c; k++) {
                v[i][j][k] += v[i][j-1][k];
            }
        }
    }


    ll ans = -LONG_LONG_MAX;
    for(int i1=0; i1<a; i1++) {
        for(int i2=i1; i2<a; i2++) {
            for(int j1=0; j1<b; j1++) {
                for(int j2=j1; j2<b; j2++) {
                    ll sum = 0;
                    for(int k=0; k<c; k++) {
                        sum += v[i2][j2][k];
                        if(i1>0) sum -= v[i1-1][j2][k];
                        if(j1>0) sum -= v[i2][j1-1][k];
                        if(i1>0 and j1>0) sum += v[i1-1][j1-1][k];
                        ans = max(ans, sum);
                        if(sum < 0) sum = 0;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n--) {
        solve();
        if(n) cout << '\n';
    }
    return 0;
}