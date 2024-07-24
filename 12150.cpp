#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(int N) {
    vector<int> v(N, -1);
    int n, p;
    bool accept = true;

    for(int i = 0; i < N; i++){
        cin >> n >> p;
        int orig = i + p;

        if(orig >= N or orig < 0) accept = false;
        else if(v[orig] != -1) accept = false;
        else { 
            v[orig] = n;
        }
    }
    
    if(!accept){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < N; i++){
        cout << v[i];
        if(i != N-1)
            cout << " ";
    }

    cout << endl;
}

int main() {
    int N;

    while(cin >> N){
        if(N == 0)
            return 0;
        solve(N);
    }
    return 0;
}