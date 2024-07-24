#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vector<int> var_vector(26);

int var(char var_name){
    return var_vector[var_name - 'A'];
}

class cmd{
public:
    int value(std::string x, char c){
        if(isdigit(x[0])){
            return stoi(x);
        }
        else {
            if(c == 'a'){
                is_var_a = true;
            }
            if(c == 'b'){
                is_var_b = true;
            }
            return x[0];
        }
    }
    void print(string line, bool is_ln) {
        size_t start = line.find_first_of('\"');
        size_t end = line.find_last_of('\"');

        if(start != line.npos){
            is_sentence = true;
            sentence = line.substr(start+1, end-start-1);
        }
        else {
            // considering no spaces at the end of line
            is_sentence = false;
            a = line[line.size()-1];
        }

        if(is_ln){
            sentence += "\n";
        }
    }

    void let(string line) {
        var_name = line[4];

        int i = 8, aux = 0;
        while(line[i+aux] != ' ' and line[i+aux] != '\0')
            aux++;

        sa = line.substr(i, aux);
        a = value(sa, 'a');
        i += aux;
        
        if(line[i] != '\0'){
            op = "";
            op.push_back(line[++i]);
            sb = line.substr(i+2, line.npos);
            b = value(sb, 'b');
        }


    }

    void ifgoto(string line) {
        int i = 3;
        bool is_goto = false;

        int aux = 0;
        while(line[i+aux] != ' ' and line[i+aux] != '\0')
            aux++;
        sa = line.substr(i, aux);
        i += aux+1;

        aux = 0;
        while(line[i+aux] != ' ' and line[i+aux] != '\0')
            aux++;
        op = line.substr(i, aux);
        i += aux+1;

        sb = line.substr(i, line.npos);

        while(line[i] != ' ' and line[i] != '\0')
            i++;

        a = value(sa, 'a');
        b = value(sb, 'b');

        char statement[1024];
        sscanf(line.substr(line.find_first_of("1234567890", i), line.npos).c_str(), "%s", statement);
        gt = stoi(statement);
    }

    cmd (string s){
        stringstream ss(s);
        string n;
        getline(ss, n, ' ');
        label = stoi(n);
        getline(ss, line, '\0');
        if(line[0] == 'P'){
            //PRINT or PRINTLN
            print(line, (line[5]=='L'));
            return;
        }
        if(line[0] == 'L'){
            //LET
            let(line);
            return;
        }
        if(line[0] == 'I'){
            ifgoto(line);
        }
    }

    int execute (){
        if(line[0] == 'P'){
            //PRINT or PRINTLN
            if(!is_sentence){
                cout << var(a);
            }
            cout << sentence;
            return -1;
        }
        if(line[0] == 'L'){
            int a_ = is_var_a? var(a):a;
            int b_ = is_var_b? var(b):b;
            if(op == "+") var_vector[var_name-'A'] = a_+b_;
            else if(op == "-") var_vector[var_name-'A'] = a_-b_;
            else if(op == "*") var_vector[var_name-'A'] = a_*b_;
            else if(op == "/") var_vector[var_name-'A'] = a_/b_;
            return -1;
        }
        if(line[0] == 'I'){
            int a_ = is_var_a? var(a):a;
            int b_ = is_var_b? var(b):b;
            bool is_goto;
            if(op == "=") is_goto = (a_ == b_);
            else if(op == "<") is_goto = (a_ < b_);
            else if(op == ">") is_goto = (a_ > b_);
            else if(op == "<>") is_goto = (a_ != b_);
            else if(op == "<=") is_goto = (a_ <= b_);
            else if(op == ">=") is_goto = (a_ >= b_);

            if(is_goto){
                return gt;
            }
            return -1;
        }   
        return -1;
    }

    int label, gt, a=0, b=0;
    bool is_sentence, is_var_a = false, is_var_b = false;
    char var_name;
    string sentence, line, op="+";
    string sa="", sb="";
};


bool cmp(const cmd &lhs, const cmd &rhs){
    return lhs.label < rhs.label;
}



void solve() {
    vector<cmd> commands;
    string s;

    while(getline(cin, s)){
        commands.push_back(cmd(s));     
    }

    sort(commands.begin(), commands.end(), cmp);

    unordered_map<int, int> index;

    int i = 0;
    for(auto it = commands.begin(); it != commands.end(); ++it){
        index[it->label] = i++;
    }

    for(int i = 0; i < index.size();){
        int aux = commands[i].execute();
        if(aux != -1) i = index[aux];
        else i++;
    }
}

int main() {
    /* ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); */

    solve();
    return 0;
}