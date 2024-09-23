#include <iostream>
#include <string>
using namespace std;
int main() {
    string name ="";
    getline(cin, name);
    unsigned int cnt = 0;
    while(name[cnt]<123 && name[cnt]>96) {
        ++cnt;
    }
    name[cnt++] = 63;
    name[cnt++] = 63;
    name[cnt++] = 33;
    for(unsigned int i=0; i<cnt; i++) {
        cout << name[i];
    }
    return 0;
}

// ascii
// ?: 63
// !: 33

// 예제 입력 1 
// joonas
// 예제 출력 1 
// joonas??!
