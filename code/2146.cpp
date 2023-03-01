#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N, map[101][101];
bool visit[101][101];
int idx[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void DFS(int i, int j, int num){ // 한 섬은 같은 숫자로 표시
    map[i][j] = num;
    for (int k=0;k<=N;k++){
        int a = i+idx[k][0], b = j+idx[k][1];
        if (a<1 || a>N || b<1 || b>N || map[a][b] != 0) continue;
        DFS(a,b,num);
    }
}

int BFS(int num){
    // 섬을 구성하는 index queue에 넣기
    queue<pair<int,int>> q;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (map[i][j] == num){
                q.push(pair<int,int>(i,j));
                visit[i][j] = true;
            } 
        }
    }

    // 다른 섬에 도달할때까지 BFS 수행
    int length = 0;
    bool found = false;
    while (!q.empty()){
        int size = q.size();
        for (int i=0;i<size;i++){
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (map[x][y] >0 && map[x][y] != num){
                found = true;
                break;
            }
            for (int k=0;k<4;k++){
                int a = x+idx[k][0], b = y+idx[k][1];
                if (a<1 || a>N || b<1 || b>N || visit[a][b]) continue;
                q.push(pair<int,int>(a,b));
                visit[a][b] = true;
            }
        }
        if (found) break;
        length ++;
    }   
    return length;
}

int main(){
    cin>>N;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            int input;
            cin>>input;
            if (input == 0) map[i][j] = -1;
        }
    }

    int island = 0;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (map[i][j] == 0){
                island++;
                DFS(i,j,island);
            }
        }
    }
    int ans = 10000;
    for (int i=1;i<=island;i++){
        memset(visit,false,sizeof(visit));
        ans = min(ans,BFS(i)-1);
    }
    cout<<ans<<endl;

    return 0;
}
