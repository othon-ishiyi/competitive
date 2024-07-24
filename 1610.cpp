#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int,int>>

using namespace std;

void solve(int N) {
    string name1, name2, ans="";
    vector<string> v;
    for(int i=0; i<N; i++){
        cin >> name1;
        v.push_back(name1);
    }

    sort(v.begin(), v.end());

    name1 = v[N/2 - 1];
    name2 = v[N/2];

    for(int i=0; i<name1.size(); i++){
        if(name1[i] == name2[i])
            ans.push_back(name1[i]);
        else{
            if(i+1 == name2.size()){
                if(name1[i]+1 != name2[i]){
                    if(i < name1.size()-1)
                        ans.push_back(name1[i]+1);
                    if(i == name1.size()-1)
                        ans.push_back(name1[i]);
                }
                else{
                    ans.push_back(name1[i++]);
                    while(i < name1.size()){
                        if(name1[i] == 'Z'){
                            ans.push_back('Z');
                            i++;
                        }
                        else
                            break;
                    }
                    if(i < name1.size()-1)
                        ans.push_back(name1[i]+1);
                    if(i == name1.size()-1)
                        ans.push_back(name1[i]);
                }
            }
            else {
                while(i < name1.size()){
                    if(name1[i] == 'Z'){
                        ans.push_back('Z');
                        i++;
                    }
                    else
                        break;
                }
                if(i < name1.size()-1)
                    ans.push_back(name1[i]+1);
                if(i == name1.size()-1)
                    ans.push_back(name1[i]);
            }
            break;   
        }
    }

    cout << ans << "\n";

}

int main() {
    int N;
    while(true){
        cin >> N;

        if(N == 0)
            return 0;
        solve(N);
    }
    return 0;
}