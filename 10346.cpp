#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

const double pi = acos(-1);

void solve() {
    int a, b;
    double v, A, s;

    while(true) {
        cin >> a >> b >> v >> A >> s;
        if(a == 0 and b == 0) return;
        double vx = v * cos(pi*A/180);
        double vy = v * sin(pi*A/180);

        double sx = vx*s/2;
        double sy = vy*s/2;

        int horiz = int(sx/(a/2.0)), vert = int(sy/(b/2.0));

        cout << (horiz+1)/2 << ' ' << (vert+1)/2 << '\n';
        
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}