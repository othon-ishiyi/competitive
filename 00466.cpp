#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvc vector<vector<char>>
#define vii vector<pair<int,int>>

using namespace std;

void reflect_vert(vvc &A){
    for(int i = 0; i <= (A.size()-1)/2; i++){
        for(int j = 0; j <= A[0].size(); j++){
            swap(A[i][j], A[A.size()-i-1][j]);
        }
    }
}

void rotate(vvc &A){
    vvc B = A;
    for(int i = 0 ; i < A.size(); i++)
        for(int j = 0; j < A[0].size(); j++){
            B[i][j] = A[A.size()-j-1][i];
        }
    A = B;
}

bool compare(vvc &A, vvc &B){
    for(int i = 0 ; i < A.size(); i++)
        for(int j = 0; j < A[0].size(); j++){
            if(A[i][j] != B[i][j])
                return false;
        }
    return true;
}

void solve(int N, int pattern) {
    vvc A(N), B(N);
    string s1, s2;
    for(int i = 0; i < N; i++){
        cin >> s1 >> s2;
        for(char c: s1)
            A[i].push_back(c);
        for(char c: s2)
            B[i].push_back(c);
    }

    if(compare(A, B)){
        cout << "Pattern " << pattern << " was preserved.";
        return;
    }

    rotate(A);

    if(compare(A, B)){
        cout << "Pattern " << pattern << " was rotated 90 degrees.";
        return;
    }

    rotate(A);

    if(compare(A, B)){
        cout << "Pattern " << pattern << " was rotated 180 degrees.";
        return;
    }

    rotate(A);

    if(compare(A, B)){
        cout << "Pattern " << pattern << " was rotated 270 degrees.";
        return;
    }

    rotate(A);
    reflect_vert(A);

    if(compare(A, B)){
        cout << "Pattern " << pattern << " was reflected vertically.";
        return;
    }

    rotate(A);

    if(compare(A, B)){
        cout << "Pattern " << pattern << " was reflected vertically and rotated 90 degrees.";
        return;
    }

    rotate(A);

    if(compare(A, B)){
        cout << "Pattern " << pattern << " was reflected vertically and rotated 180 degrees.";
        return;
    }

    rotate(A);

    if(compare(A, B)){
        cout << "Pattern " << pattern << " was reflected vertically and rotated 270 degrees.";
        return;
    }

    cout << "Pattern " << pattern << " was improperly transformed.";

}

int main() {
    int N, pattern = 1;
    while(cin >> N){
        solve(N, pattern++);
        cout << "\n";
    }
    return 0;
}