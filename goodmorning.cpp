#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vvi options(10, vi(10));
int num, ans, goal;

void rb(int col, int cur) {
    if(abs(goal - num) < abs(goal - ans)) {
        ans = num;
    }
    if(col == -1) {
        return;
    }
    for(int i=0; i<=9; i++) {
        if(col == 2 or options[cur][i]) {
            num = 10*num + i;
            rb(col - 1, i);
            num = (num-i)/10;
        }
    }
}

void solve() {
    ans = INT_MAX;
    num = 0;
    cin >> goal;

    rb(2, 0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    options[0] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    options[1] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    options[2] = {1, 0, 1, 1, 0, 1, 1, 0, 1, 1};
    options[3] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 1};
    options[4] = {1, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    options[5] = {1, 0, 0, 0, 0, 1, 1, 0, 1, 1};
    options[6] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 1};
    options[7] = {1, 0, 0, 0, 0, 0, 0, 1, 1, 1};
    options[8] = {1, 0, 0, 0, 0, 0, 0, 0, 1, 1};
    options[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    while(n--)
        solve();
    return 0;
}