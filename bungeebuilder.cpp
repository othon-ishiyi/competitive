#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;

void solve() {
    int N;
    cin >> N;
    vector<int> v(N);
    
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    int big=0, low=0, diff = 0;

    for(int i=0; i<N; i++){
        if(v[i] >= big){
            diff = max(diff, big - low);
            big = v[i];
            low = big;
        }
        if(v[i] < low){
            low = v[i];
        }
    }

    big=0, low=0;

    for(int i=N-1; i>=0; i--){
        if(v[i] >= big){
            diff = max(diff, big - low);
            big = v[i];
            low = big;
        }
        if(v[i] < low){
            low = v[i];
        }
    }

    cout << diff;
}

int main() {
    solve();
    return 0;
}