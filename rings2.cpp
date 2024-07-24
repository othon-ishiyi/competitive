#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int,int>>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vvi A(n);
    int empty_cells = 0, rings = 0;
    string line;

    for(int i=0; i<n; i++){
        cin >> line;
        for(char c: line){
            if(c == '.')
                A[i].push_back(0);
            else {
                A[i].push_back(-1);
                empty_cells++;
            }
        }
    }

    while(empty_cells){
        for(int i=0; i<n; i++) for(int j=0; j<m; j++){
            if(A[i][j] < 0){
                int top = A[max(0, i-1)][j];
                int bottom = A[min(n-1, i+1)][j];
                int left = A[i][max(0, j-1)];
                int right = A[i][min(m-1, j+1)];
                if(top == rings || bottom == rings || left == rings || right == rings || i == 0 || i == n-1 || j == 0 || j == m-1){
                    empty_cells--;
                    A[i][j] = rings+1;
                }
            }
        }
        rings++;
    }

    if(rings < 10){
        for(auto v: A) {
            for(int i: v){
                if(i == 0)
                    cout << "..";
                else
                    cout << '.' << i;
            }
            cout << '\n';
        }
    }
    else {
        for(auto v: A) {
            for(int i: v){
                if(i == 0)
                    cout << "...";
                else if (i >= 10)
                    cout << '.' << i;
                else
                    cout << ".." << i;
            }
            cout << '\n';
        }
    }
}

int main() {
    solve();
    return 0;
}