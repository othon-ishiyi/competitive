#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int a;

    while(true) {
        vector<int> princess, prince;
        set<int> available;
        for(int i = 1; i <= 52; i++){
            available.insert(i);
        }
        for(int i = 0; i < 3; i++){
            cin >> a;
            available.erase(a);
            princess.push_back(a);
        }

        sort(princess.begin(), princess.end());

        if(princess[0] == 0)
            return 0;

        for(int i = 0; i < 2; i++){
            cin >> a;
            available.erase(a);
            prince.push_back(a);
        }

        sort(prince.begin(), prince.end());

        int wins = 0;

        for(int i = 1; i >= 0; i--){
            auto p = upper_bound(princess.begin(), princess.end(), prince[i]);
            if(p == princess.end()){
                princess.erase(princess.begin());
                wins++;
            }
            else {
                princess.erase(p);
            }
        }

        if(wins == 0){
            cout << -1 << '\n';
        }
        else if (wins == 1){
            if(available.upper_bound(princess.back()) != available.end())
                cout << *(available.upper_bound(princess.back())) << "\n";
            else
                cout << -1 << '\n';
        }
        else {
            cout << *(available.upper_bound(0)) << "\n";
        }

    }
    return 0;
}