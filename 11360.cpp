#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>

using namespace std;

void transpose(vvi &A) {
    for(int i = 0; i < A.size(); i++) for(int j= 0; j < i; j++)
        swap(A[i][j], A[j][i]);
}

void row(vvi &A, int a, int b){
    for(int j=0; j < A[0].size(); j++)
        swap(A[a][j], A[b][j]);
}

void col(vvi &A, int a, int b){
    for(int j=0; j < A[0].size(); j++)
        swap(A[j][a], A[j][b]);
}

void inc(vvi &A){
    for(int i = 0; i < A.size(); i++) for(int j= 0; j < A[0].size(); j++)
        A[i][j] = (A[i][j]+1)%10;
}

void dec(vvi &A){
    for(int i = 0; i < A.size(); i++) for(int j= 0; j < A[0].size(); j++)
        A[i][j] = (A[i][j]+9)%10;
}

void solve(int testcase) {
    int N, op;
    cin >> N;
    vvi m(N);

    string line;

    for(int i=0; i < N; i++) {
        cin >> line;
        for(char c: line){
            m[i].push_back(c-'0');
        }
    }

    cin >> op;

    while(op--){
        cin >> line;

        if(line == "transpose") transpose(m);
        if(line == "inc") inc(m);
        if(line == "dec") dec(m);
        if(line == "row"){
            int a, b;
            cin >> a >> b;
            row(m, a-1, b-1);
        }
        if(line == "col"){
            int a, b;
            cin >> a >> b;
            col(m, a-1, b-1);
        }
    }

    cout << "Case #" << testcase << "\n";
    for(auto v: m){
        for(int u: v)
            cout << u;
        cout << "\n";
    }
}

int main() {
    int N, i=0;
    cin >> N;
    while(N--){
        solve(++i);
        cout << "\n";
    }
    return 0;
}