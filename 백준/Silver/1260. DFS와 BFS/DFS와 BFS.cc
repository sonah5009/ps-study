#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n=0, m=0,v=0; // 정점 수, 간선 수, 탐색 시작 번호
    int a=0, b=0; // vector에 들어갈 정점 번호
    cin >> n >> m >> v;
    vector<int> graph[n+1];
    

    // graph 만들기
    while(m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        sort(graph[a].begin(), graph[a].end());  // 정렬
        sort(graph[b].begin(), graph[b].end());  // 정렬
    }
    
    // dfs
    stack<int> s;
    bool visited[n+1];
    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
    }


    
// 스택
    int tmp_v = v;
    s.push(tmp_v);
    while(!s.empty()) {
        tmp_v = s.top();
        s.pop();
        if(!visited[tmp_v]) {
            cout << tmp_v << ' ' ;
            visited[tmp_v] = true;
        }
        for(int j=graph[tmp_v].size()-1; j>=0; --j) {
            int element = graph[tmp_v][j];
            if(!visited[element]) {
                s.push(element);
            }            
        }   
    }
    cout << '\n';


    // dfs 완료

    // bfs
    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
    }
    visited[v]=true;    // 탐색 시작
    // bfs queue
    queue<int> q;
    q.push(v);
    cout << q.front();
    q.pop();

    for(int i=0; i<n; ++i) {
        for(int j=0; j<graph[v].size(); ++j){
            int y = graph[v][j];
            if(!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
        if(!q.empty()) {
            v = q.front();
            q.pop();
            cout << ' ' << v;
        }
    }
    return 0;
}