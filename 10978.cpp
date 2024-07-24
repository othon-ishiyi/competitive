#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(int N) {
    vector<string> v(N,"");
    int it = 0;
    for(int w=0; w < N; w++){
        string card, name;

        cin >> card >> name;

        for(int j = 1; j < name.size();){
            it = (it+1)%N;
            if(v[it] == "") j++;
        }

        v[it] = card;
        if(w == N-1) break;
        while(v[it] != "") it = (it+1)%N;
    }


    for(int w=0; w < N; w++){
        cout << v[w];
        if(w != N-1)  cout << " ";
    }
    
    cout << "\n";
}

int main() {
    int N;

    while(true){
        cin >> N;
        if(N == 0){
            return 0;
        }

        solve(N);
    }
    return 0;
}