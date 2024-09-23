// 너의 평점은
#include <iostream>
#include <string>
using namespace std;
int main() {
    string grade;
    double credit=0, total_credit=0;
    double result=0.0;
    int cnt =0;
    while(++cnt) {
        if (cnt>20) break;
        cin >> grade >> credit >> grade;
        if (grade[0]!='P')
            total_credit += credit;

        if (grade[0]=='A'){
            if(grade[1]=='+')   result += credit*4.5;
            else result += credit*4.0;
        }
        else if(grade[0]=='B'){
            if(grade[1]=='+')   result += credit*3.5;
            else result += credit*3.0;
        }
        else if(grade[0]=='C'){
            if(grade[1]=='+')   result += credit*2.5;
            else result += credit*2.0;
        }
        else if(grade[0]=='D'){
            if(grade[1]=='+')   result += credit*1.5;
            else result += credit*1.0;
        }
        grade = "";
    }
    result /=total_credit;
    cout << result;
    return 0;
}