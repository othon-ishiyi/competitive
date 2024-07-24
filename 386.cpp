#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define NMAX 200

bool verify(int a, int b, int c, int d) {
    return a*a*a == b*b*b + c*c*c + d*d*d;
}



void solve() {
    int a, b, c, d;
    for(a=2; a<=NMAX; a++) {
        for(b=2; b<a; b++) {
            for(c=b; c<a; c++) {
                for(d=c; d<a; d++) {
                    if(verify(a,b,c,d)) {
                        cout << "Cube = " << a << ", Triple = (" << b << ',' << c << ',' << d << ")\n";
                    }
                }
            }
        }
    }
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}