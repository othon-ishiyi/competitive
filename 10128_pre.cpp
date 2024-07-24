/*The pre-computing is in 10128_pre.cpp*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define NMAX 13
vi perm = {1,2,3,4,5,6,7,8,9,10,11,12,13};
int last;

int result[NMAX][NMAX][NMAX] = {0};

void cnt() {
    int fwd = 0, bkw = 0, cnt_fwd=0, cnt_bkw=0;
    for(int i=0; i<=last; i++) {
        if(fwd < perm[i]) {
            fwd = perm[i];
            cnt_fwd++;
        }
    }
    for(int i=last; i>=0; i--) {
        if(bkw < perm[i]) {
            bkw = perm[i];
            cnt_bkw++;
        }
    }

    result[last][cnt_fwd-1][cnt_bkw-1]++;
}

void solve() {
    for(last=0; last<NMAX; last++) {
        perm = {1,2,3,4,5,6,7,8,9,10,11,12,13};
        do {
            cnt();
        } while(next_permutation(perm.begin(), perm.begin()+last+1));
    }

    cout << "{";
    for(int i=0; i<NMAX; i++){
        cout << "{";
        for(int j=0; j<NMAX; j++) {
            cout << "{";
            for(int k=0; k<NMAX; k++) {
                cout << result[i][j][k];
                if(k != NMAX-1) {
                    cout << ", ";
                }
            }
            cout << "}";
            if(j != NMAX-1) {
                cout << ", ";
            }
        }
        cout << "}";
        if(i != NMAX-1) {
            cout << ", ";
        }
    }
    cout << "}";   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}