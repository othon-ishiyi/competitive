#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve(int n) {
    int ans = 0, sum = 0;
    while(n--) {
        int a;
        cin >> a;
        sum += a;
        ans = max(ans, sum);
        if(sum < 0) sum = 0;
    }
    if(ans > 0)
        cout << "The maximum winning streak is " << ans << ".\n";
    else {
        cout << "Losing streak.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(true) {
        cin >> n;
        if(n == 0) break;
        solve(n);
    }
    return 0;
}