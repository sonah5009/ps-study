#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MN = 1001;

vector<int> g[MN]; //인접 리스트
bool vst[MN]; //방문 여부
void dfs(int N) { //DFS
    vst[N] = true; //방문 체크
    cout << N << ' '; //방문한 노드 번호 출력
    for(int e : g[N]) { //방문한 노드로부터 인접 리스트를 확인
        if(!vst[e]) dfs(e); //방문하지 않은 노드 방문
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, V; cin >> N >> M >> V;
    for(int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); //인접리스트 추가
        g[v].push_back(u);
    }
    for(int i = 1; i <= N; i++) { //정점 번호 오름차순으로 정렬
        sort(g[i].begin(), g[i].end());
    }
    dfs(V); //V번 정점부터 DFS
    cout << "\n" << V; //DFS출력 마지막을 나타내는 개행 후 BFS 시작정점 V출력
    queue<int> q; //BFS에 사용할 queue
    memset(vst, 0, sizeof(vst)); //방문 배열 초기화
    q.push(V); //시작 정점 queue에 추가
    vst[V] = true; //시작 정점 방문 체크
    while(!q.empty()) { //모든 정점을 방문할 때까지
        int now = q.front(); q.pop(); //queue의 첫 번째 pop
        for(int e : g[now]) { //인접리스트 확인
            if(!vst[e]) { //방문하지 않은 노드 발견할 경우
                cout << ' ' << e; //정점 출력
                vst[e] = 1; //방문 체크
                q.push(e); //queue에 추가
            }
        }
    }
}