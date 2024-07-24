#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve() {
    int N, M, i = 0;
    string sentence, s;
    vector<string> v;

    cin >> N;

    cin.ignore();

    getline(cin, sentence);
    stringstream ss(sentence);

    while(getline(ss, s, ' ')){
        if(s != "?") v.push_back(s);
        else v.push_back("");
    }  

    cin >> M;

    while(M--) {
        int k = 0, idx;
        cin >> idx;
        idx--;

        string A,B;
        A = B = v[idx];

        while(A == "" && B == ""){
            k++;
            if(idx + k < N) B = v[idx+k];
            if(idx - k >= 0) A = v[idx-k];
        }

        if(A != "" and B != "" and k > 0) cout << "middle of " << A << " and " << B << "\n";
        else if(k == 0) cout << A << "\n";
        else if(A != "") {
            while(k--) cout << "right of ";
            cout << A << "\n";
        }
        else {
            while(k--) cout << "left of ";
            cout << B << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}