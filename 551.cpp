#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;


void solve() {
    string sentence;
    int i;

    map<char, char> m;
    m[']'] = '[';
    m['>'] = '<';
    m['}'] = '{';
    m[')'] = '(';
    m['\n'] = '\b';

    while(getline(cin, sentence)){
        int len = sentence.size();
        sentence.push_back(' ');
        int count = 0;
        int error = 0;
        stack<char> s;
        s.push(' ');

        // we're going to substitute "(*" to "\n"

        for(i=0; i<len; i++){
            char c = sentence[i];
            if(c == '[' or c == '{' or c == '<')
                s.push(c);
            else if(c == '('){
                if(sentence[i+1] == '*') {
                    i++;
                    count++;
                    s.push('\n');
                }
                else
                    s.push(c);
            }

            else if(c == ']' or c == '>' or c=='}' or c==')'){
                if(s.top() == m[c])
                    s.pop();
                else{
                    error = i-count+1;
                    break;
                }
            }

            else if(c=='*' and sentence[i+1] == ')'){
                if(s.top() == '\n'){
                    i++;
                    count++;
                    s.pop();
                }
                else{
                    error = i-count+1;
                    break;
                }
            }
        }


        if(error == 0){
            if(s.top() == ' ')
                cout << "YES" << '\n';
            else
                cout << "NO " << len-count+1 << '\n';
        }
        else {
            cout << "NO " << error << '\n';
        }
    }
}


int main() {
    solve();
    return 0;
}