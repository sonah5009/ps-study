#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    unsigned n = 0, cmd = 0, X = 0;
    int point = -1;  // 스택 포인터, 처음엔 -1
    unsigned mat[1000000] = {0,};  // 스택 역할을 하는 배열
    cin >> n;  // 명령어 개수 입력

    for (unsigned i = 0; i < n; ++i) {
        cin >> cmd;  // 명령어 입력

        if (cmd == 1) {  // push
            cin >> X;
            mat[++point] = X;
        }
        else if (cmd == 2) {  // pop
            if (point < 0) {
                cout << "-1\n";
            } else {
                cout << mat[point--] << '\n';
            }
        }
        else if (cmd == 3) {  // size
            cout << point + 1 << '\n';
        }
        else if (cmd == 4) {  // empty
            if(point<0) cout << "1\n";
            else cout << "0\n";
        }
        else if (cmd == 5) {  // top
            if(point<0) cout << "-1\n";
            else cout << mat[point] << '\n';
        }
    }

    return 0;
}
