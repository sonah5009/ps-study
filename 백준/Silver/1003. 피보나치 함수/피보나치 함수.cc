#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T=0, N=0; // 케이스 개수, 사용자 입력(0<=N<=40)
    int max=1; // N에 따라 max 값 갱신

    vector<vector<int> > v(41, vector<int>(2)); 

    // 초깃값 설정: f(0)={1,0}, f(1)
    v[0][0] = 1; v[0][1] = 0;
    v[1][0] = 0; v[1][1] = 1;

    cin >> T;
    while(T--){
        cin >> N;

        // N이 max값보다 크면 vector에 f(N)까지의 값 저장
        if (N > max) {
            for (int i = max + 1; i <= N; ++i) {
                v[i][0] = v[i-1][0] + v[i-2][0];
                v[i][1] = v[i-1][1] + v[i-2][1];
            }
            max = N;  // max 값 갱신
        }

        cout << v[N][0] << ' '<< v[N][1] << '\n';
    }
    
    return 0;
}