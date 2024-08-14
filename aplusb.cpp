#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

typedef complex<long double> cd;
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

vll multiply(vll p1, vll p2) {
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
vll res; // prepare output
for ( auto &p : C )
res.push_back(round(p.real()));
res.resize(p1.size() + p2.size() - 1); // resize to original degree
return res;
}

void solve() {
    int n;
    cin >> n;
    vll a(100010, 0);
    ll cnt_zero = 0;

    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        a[k+50000]++;
        if(!k)
            cnt_zero++;
    }

    vll p = multiply(a, a);
    for(int i=0; i<=100000; i++) {
        if(a[i]) {
            p[2*i] -= a[i];
        }
    }

    ll ans = 0;
    for(int i=50000; i<=150000; i++) {
        ans += ll(p[i]) * ll(a[i-50000]);
    }

    ans -= 2 * cnt_zero * (n-1);

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
