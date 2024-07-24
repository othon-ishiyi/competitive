#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(int S, int B) {
    vector<int> L, R;
    for(int i = 0; i < S; i++){
        L.push_back(i-1);
        R.push_back(i+1);
    }

    while(B--){
        int l, r;
        cin >> l >> r;

        if(r != S){
            L[r] = L[l-1];
            if(R[r-1] < S)
                L[R[r-1]] = L[l-1];
        }
        if(l != 1) {
            R[l-2] = R[r-1];
            if(L[l-1] >= 0)
                R[L[l-1]] = R[r-1];
        }

        if(L[l-1] >= 0) cout << L[l-1] + 1 << " ";
        else cout << "* ";
        if(R[r-1] < S) cout << R[r-1] + 1;
        else cout << "*";

        cout << "\n";
    }

    cout << "-\n";


}

int main() {
    int S, B;
    while(cin >> S >> B){
        if(S != 0)
            solve(S, B);
        else
            return 0;
    }
    
    return 0;
}