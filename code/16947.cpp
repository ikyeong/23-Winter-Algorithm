#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, pre[3001];
bool found, visit[3001], cycle[3001];
vector<vector<int>> map(3001);

//cycle 탐색
//BFS로 cycle까지의 거리 구하기

void findCycle(int x){
    visit[x] = true;
    for (int i=0;i<map[x].size();i++){
        if (found) return;
        int next = map[x][i];
        if (visit[next] && next != pre[x]){
            while (true){
                cycle[x] = true;
                if (x == next) break;
                x = pre[x];
            }
            found = true;
        }else if (!visit[next]){
            pre[next] = x;
            findCycle(next);
        }
    }
    visit[x] = false;
}

int BFS(int x){
    int count = 0;
    if (cycle[x]) return 0;
    queue<int> q;
    q.push(x);
    visit[x] = true;
    while (!q.empty()){
        int size = q.size();
        for (int i=0;i<size;i++){
            int front = q.front();
            q.pop();
            if (cycle[front]) return count;
            for (int j=0;j<map[front].size();j++){
                if (!visit[map[front][j]]){
                    q.push(map[front][j]);
                    visit[map[front][j]] = true;
                }
            }
        }
        count++;
    }
    return count;
}

int main(){
    cin>>N;
    for (int i=1;i<=N;i++){
        int x,y;
        cin>>x>>y;
        map[x].push_back(y);
        map[y].push_back(x);
    }
    findCycle(1);
    memset(visit,false,sizeof(visit));
    for (int i=1;i<=N;i++){
        cout<<BFS(i)<<" ";
        memset(visit,false,sizeof(visit));
    }
    return 0;
}
