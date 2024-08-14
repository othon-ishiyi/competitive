#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

typedef complex<double> cd;
const double PI = acos(-1.0);

void FFT(vector<cd> &A) {
int n = A.size();
if ( n == 1 ) return;
vector<cd> A0(n/2), A1(n/2); // divide
for ( int k = 0; 2 * k < n; ++k ) {
A0[k] = A[2*k];
A1[k] = A[2*k+1];
}
FFT(A0); // conquer
FFT(A1);
for ( int k = 0; 2 * k < n; ++k ) { // combine
cd x = cd(cos(2*PI*k/n), sin(2*PI*k/n));
A[k] = A0[k] + x * A1[k];
A[k+n/2] = A0[k] - x * A1[k];
}
}

void IFFT(vector<cd> &A) {
for ( auto &p : A ) p = conj(p); // complex conjugate
// a + bi -> a - bi
FFT(A);
for ( auto &p : A ) p = conj(p); // complex conjugate
// **not needed for our purpose**
for ( auto &p : A ) p /= A.size(); // scale down (1/n)
}

vi multiply(vi p1, vi p2) {
int n = 1; // n needs to be a power of 2
while ( n < p1.size() + p2.size() - 1 )
n <<= 1;
vector<cd> A(p1.begin(), p1.end()); // prepare A and B for FFT calls
vector<cd> B(p2.begin(), p2.end());
A.resize(n);
B.resize(n);
FFT(A); // transform
FFT(B);
vector<cd> C(n); // perform the multiplication
for ( int k = 0; k < n; ++k )
C[k] = A[k] * B[k];
IFFT(C); // inverse transform
vi res; // prepare output
for ( auto &p : C )
res.push_back(round(p.real()));
res.resize(p1.size() + p2.size() - 1); // resize to original degree
return res;
}

void solve() {
    int n1, n2;
    vi a, b;
    cin >> n1 >> n1;
    for(int i=0; i<=n1; i++) {
        int k;
        cin >> k;
        a.push_back(k);
    }
    cin >> n2;
    for(int i=0; i<=n2; i++) {
        int k;
        cin >> k;
        b.push_back(k);
    }
    vi ans = multiply(a, b);
    cout << n1 + n2 << '\n';
    for(int i=0; i < n1+n2; i++) {
        cout << ans[i] << ' ';
    }
    cout << ans[n1+n2] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
