#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int cursum = 0, sum = 0, winner;

    for(int i=0; i<5; i++) {
        for(int j=0; j<4; j++) {
            int a;
            cin >> a;
            sum += a;
        }
        if(sum > cursum) {
            cursum = sum;
            winner = i+1;
        }
        sum = 0;
    }

    cout << winner << ' ' << cursum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}