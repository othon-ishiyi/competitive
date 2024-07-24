#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int s, d;
vi cash(13, 0);

int surplus(int m) {
    int ans = -1;
    if(m == 12) {
        ans++;
        for(int i=1; i<=12; i++) {
            ans += cash[i];
        }
        return ans;
    }

    int last_4m = 0;
    if(m >= 4) {
        for(int i=0; i<4; i++) {
            last_4m += cash[m-i];
        }
    }

    cash[m+1] = s;
    if(last_4m + s < 0 or m < 4)
        ans = max(ans, surplus(m+1));

    cash[m+1] = -d;
    if(last_4m - d < 0 or m < 4)
        ans = max(ans, surplus(m+1));

    return ans;
}

void solve() {
    cash[1] = s;
    int ans = surplus(1);
    cash[1] = -d;
    ans = max(ans, surplus(1));
    if(ans >= 0) {
        cout << ans << '\n';
    }
    else {
        cout << "Deficit\n";
    }
}

int main() {
    while(cin >> s >> d) {
        solve();
    }
    return 0;
}