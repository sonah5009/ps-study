// 스택 2
// 두 줄 추가, endl -> \n !!
// 시간 초과: 둘 중에 하나만 하면 시간 초과 걸림

// 문제풀이
// 1.`ios:sync_with_stdio(false)`: C++의 `cin`/`cout` and C의 `scanf`/`printf`를 동기화하는 기능을 끄면, 입출력 성능이 크게 향상됨.
// 2.`cin.tie(NULL)`: `cin`과 `cout의 연결을 끊어 `cin이 불필요하게 `cout`을 기다리지 않도록 함 -> 성능 최적화
// 3. endl: `endl`은 출력 후 버퍼를 flush하는 기능이 있어 시간이 오래 걸림. `\n`사용시 더 빠름. => 버퍼링 최소화
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);  // 입출력 속도 향상
    cin.tie(NULL);  // 입력과 출력의 버퍼를 분리

    unsigned n = 0, cmd = 0, X = 0; // 명령 개수, 명령어(1-5), 정수 X, stack 위치
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
            cout << (point < 0 ? "1\n" : "0\n");
        }
        else if (cmd == 5) {  // top
            if (point < 0) {
                cout << "-1\n";
            } else {
                cout << mat[point] << '\n';
            }
        }
    }

    return 0;
}
