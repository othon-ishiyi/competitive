#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;

void solve(int c) {
    string A;
    int mod = 1e9 + 7;
    int S = 0;
    int a, b;
    int u, v;

    cin >> A;

    if(A.size()%2 == 1){
        int k = A.size()/2;
        S += A[k]-'0';
        a = k-1;
        b = k+1;
    }
    else{
        a = A.size()/2-1;
        b = a+1;
    }

    while(a >= 0){
        u = A[a--] - '0';
        v = A[b++] - '0';
        
        S = (S << 1) + (u|v);

        if(S >= mod)
            S = S%mod;

        S = (S << 1) + (u&v);

        if(S >= mod)
            S = S%mod;
    }

    cout << "Case #" << c << ": " <<  S << endl;
}

int main() {

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        solve(i+1);
    }

    return 0;
}