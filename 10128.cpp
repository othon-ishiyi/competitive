/*The pre-computing is in 10128_pre.cpp*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define NMAX 13
int result[NMAX][NMAX][NMAX];

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    cout << result[n][a-1][b-1] << '\n';
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