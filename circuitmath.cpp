#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;

void solve() {
    int N;
    char c;
    bool a, b;
    stack<bool> s;
    vector<bool> v(26);
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> c;
        v[i] = (c == 'T');
    }

    while(scanf("%c", &c) != EOF){
        if(c == '\n' or c == ' ')
            continue;
        if(c == '+'){
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(a+b);
        }
        else if(c == '*'){
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(a*b);
        }
        else if(c == '-'){
            a = s.top();
            s.pop();
            s.push(a?false:true);
        }
        else{
            s.push(v[c-'A']);
        }
    }

    cout << (s.top()? "T":"F");
}

int main() {
    solve();
    return 0;
}