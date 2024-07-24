#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
    string s;
    

    while(cin >> s) {
        list<char> l;
        auto it = l.begin();
        for(char c: s){
            if(c == '[')
                it = l.begin();
            else if(c == ']')
                it = l.end();
            else
                l.insert(it, c);
        }
        for(char c: l)
            cout << c;
    
        cout << endl;
    }

    return 0;
}