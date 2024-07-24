#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int a, b;
    scanf("%d %d", &a, &b);
    cout << ((a < b)? "<": ((a>b)? ">":"=")) << "\n";
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        solve();
    }

    return 0;
}