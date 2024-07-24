#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;


void solve() {
    int n, reverse = 0;
    deque<int> q;
    string com, line, num;

    cin >> com >> n >> line;
        

    line = line.substr(1, line.size());
    line = line.substr(0, line.size()-1);
    stringstream ss(line);
    while(getline(ss, num, ',')){
        q.push_back(stoi(num));
    }


    for(char cmd: com){
        if(cmd == 'R'){
            reverse ^= 1;
        }
        else {
            if(q.empty()){
                cout << "error\n";
                return;
            }
            reverse? q.pop_back(): q.pop_front();
        }
    }

    cout << '[';

    if(reverse){
        for(auto it = q.end()-1; it >= q.begin(); it--){
            cout << *it;
            if(it != q.begin()) cout << ',';
        }
    }
    else{
        for(auto it = q.begin(); it < q.end(); it++){
            cout << *it;
            if(it != q.end()-1) cout << ',';
        }
    }

    cout << "]\n";
}

int main() {
    int N;
    cin >> N;
    while(N--)
        solve();
    return 0;
}