#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);
    cout << (((p+k)%n == 0)? n: (p+k)%n) << "\n";
}

int main() {
    int n, i;
    cin >> n;
    i = n;
    while(i--) {
        printf("Case %d: ", n-i);
        solve();
    }
    return 0;
}