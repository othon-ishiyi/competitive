#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool change(char cur_axis, int dir_sign, char dir_axis) {
    if(cur_axis == 'x' && dir_sign == -1) return true;
    if(cur_axis == 'y' && dir_axis == 'y' && dir_sign == 1) return true;
    if(cur_axis == 'z' && dir_axis == 'z' && dir_sign == 1) return true;
    return false;

}

void solve(int L) {
    string s;
    char cur_axis = 'x', dir_axis;
    int cur_sign = 1, dir_sign;

    while(--L) {
        cin >> s;

        dir_axis = s[1];

        if(dir_axis != 'o'){
            dir_sign = (s[0] == '+'? 1:-1);

            if(change(cur_axis, dir_sign, dir_axis)) {
                cur_sign *= -1;
            }
            

            if(cur_axis == 'x'){
                cur_axis = dir_axis;
            }

            else if(cur_axis == 'y') cur_axis = (dir_axis == 'y'? 'x':'y');
            else if(cur_axis == 'z') cur_axis = (dir_axis == 'z'? 'x':'z');
        }
    }

    cout << (cur_sign==1? '+':'-') << cur_axis << '\n';
}

int main() {
    int L;
    cin >> L;
    while(L != 0){
        solve(L);
        cin >> L;
    }
    return 0;
}