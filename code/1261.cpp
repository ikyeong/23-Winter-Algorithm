#include <iostream>
#include <deque>
using namespace std;
int n,m;
int graph[100][100], dist[100][100];
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

void DFS(){
    deque<pair<int,int>> dq; // 0-1 DFS는 deque 사용
    dq.push_back({0,0});
    dist[0][0] = 0;

    while(!dq.empty()){
        int x = dq.front().first, y = dq.front().second;
        dq.pop_front();
        for (int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >=n || ny <0 || ny >= m) continue;
            if (dist[nx][ny] == 10000){
                if (graph[nx][ny]){
                    dist[nx][ny] = dist[x][y] + 1;
                    dq.push_back({nx,ny}); // 가중치가 1 이면 뒤에 node를 추가
                }else{
                    dist[nx][ny] = dist[x][y]; 
                    dq.push_front({nx,ny}); // 가중치가 0 이면 앞에 node를 추가
                }
            }
        }
    }
}

int main(){
    cin>>m>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            char c;
            cin>>c;
            graph[i][j] = c - '0';
            dist[i][j] = 10000;
        }
    }
    DFS();
    cout<<dist[n-1][m-1]<<endl;
    return 0;
}
