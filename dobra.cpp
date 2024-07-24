#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

bitset<28> vow, cons;
string s;
ll ans = 0;
bool hasL;

ll pow(ll n, int k) {
    if(k == 0) return 1;
    if(k == 1) return n;
    if(k % 2) return pow(n, k-1) * n;
    ll aux = pow(n, k/2);
    return aux * aux;
}

void rb(int col, char last, char second_last, int numVow, int numCons) {
    bool v_ = (vow[last] and vow[second_last]);
    bool c_ = (cons[last] and cons[second_last]);
    if(col == s.size()) {
        if (hasL) {
            ans += pow(21, numCons) * pow(5, numVow);
        }
        else {
            ans += (pow(21, numCons) - pow(20, numCons)) * pow(5, numVow);
        }
        return;
    }
    if(s[col] == '_') {
        int i=0; // A
        if(!(v_ and vow[i]) and !(c_ and cons[i])) {
            s[col] = i;
            rb(col+1, i, last, numVow+1, numCons);
            s[col] = '_';
        }
        i=1; // B
        if(!(v_ and vow[i]) and !(c_ and cons[i])) {
            s[col] = i;
            rb(col+1, i, last, numVow, numCons+1);
            s[col] = '_';
        }
    }
    else {
        int i = s[col]-'A';
        if((v_ and vow[i]) or (c_ and cons[i])) {
            return;
        }
        rb(col+1, i, last, numVow, numCons);
    }
    
    
}

void solve() {
    cin >> s;
    char last = 'A' + 27;
    char second_last = 'A' + 26;

    hasL = false;
    for(char c: s) {
        if(c == 'L') hasL = true;
    }

    rb(0, last, second_last, 0, 0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vow.reset();
    cons.set();

    for(int i=0; i<28; i++) {
        char c = 'A' + i;
        if(c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U') {
            vow[i] = 1;
            cons[i] = 0;
        }
        cons[26] = cons[27] = 0;
    }

    solve();
    return 0;
}