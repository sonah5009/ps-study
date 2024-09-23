// std::set
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    string cmd="";
    int num=0, x=0; //연산의 수, x값
    set<int> s;
    cin >> num;
    for(int i=0; i<num; ++i) {
        cin >> cmd;
        if(cmd=="all") {
            for(int j=1; j<=20; j++)
                s.insert(j);
        }
        else if(cmd=="empty") {
            s.clear();
        }
        else {
            cin >> x;
            if(cmd=="add") s.insert(x);
            else if(cmd=="remove") s.erase(x);
            else if(cmd=="check") {
                if(s.find(x)!= s.end())   
                    cout << "1\n";
                else 
                    cout << "0\n";
                }
            else if(cmd=="toggle"){  // toggle
                if(s.find(x)!= s.end()) s.erase(x);
                else s.insert(x);
                }
        }
    }

    return 0;
}