#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int,int>>

using namespace std;

void solve(int N) {
    vi w(1<<N);
    int ans=0;

    for(int i=0; i<(1<<N); i++){
        cin >> w[i];
    }

    for(int i=0; i<(1<<N); i++){
        int s=0;
        for(int j=0; j<N; j++){
            s += w[(i ^ (1<<j))];
        }
        for(int j=0; j<N; j++){
            if(i < (i ^ (1<<j))) continue;
            int s_ = s;
            for(int k=0; k<N; k++){
                s_ += w[(i ^ (1<<j)) ^ (1<<k)];
            }
            ans = max(ans, s_);
        }
    }

    cout << ans << '\n';
}

int main() {
    int N;
    while(cin >> N){
        solve(N);
    }
    return 0;
}